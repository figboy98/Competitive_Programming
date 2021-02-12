/* To solve this problem we use the height and cost of each building as constants of a function and as variable the number of blocks to be removed from the each building
This variable is found using the concept of ternary search, eliminating 1/3 of the search space in every iteration.
Time complexity is O(n*log3(n))
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


long double  function(std::vector<std::pair<int ,int >> &buildings, float  x){
    long double  res=0;
    for(auto itr=buildings.begin(); itr!=buildings.end(); itr++){
        long double  cost = itr->second;
        long double  heigth = itr->first;
        res+= cost*abs(heigth-x);
    }
    return res;
}

long long ternarySearch(std::vector<std::pair<int ,int >> & buildings){
   long double  m1,m2;
    long double minRange=0.0;
    long double maxRange=10005.0;
   
    while((maxRange-minRange) > 0.00001){
        m1= (2*minRange + maxRange)/3;
        m2 = (minRange + 2*maxRange)/3;

        if(function(buildings,m1) < function(buildings,m2)){
            maxRange=m2;
        }
        else{
            minRange = m1;
        }
        
    }
    long long x = function(buildings, std::floor(minRange));
    long long y = function(buildings, std::ceil(minRange));
    return (std::min(x,y));
}
   



void readInput(std::vector<std::pair<int ,int >> & buildings){
     int  numBuilds,height,cost;
     std::cin >> numBuilds;
        for(int  j=0; j<numBuilds; j++){
            std::cin >> height;
            buildings.push_back(std::make_pair(height,0));
        }
        for(int  j=0; j<numBuilds;j++){
            std::cin>>cost;
            buildings[j].second=cost;
        }
}

int main(){
    int  tests;
    std::cin>>tests;
    std::vector<std::pair<int ,int >> buildings;
    for(int  i=0; i<tests; i++){
        readInput(buildings);
        std::cout<< ternarySearch(buildings)<<"\n";
        buildings.clear();
    }
    return 0;
}