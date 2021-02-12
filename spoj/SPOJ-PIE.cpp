/*
To solve this problem we use the pie volume in ascending order as a function and we try to divide each pie for a certain volume to get the pieces of pie.
The volume we use to get the pieces is found using binary search. When we get more pieces of pie than friends whe know that the volume of each pie can be bigger, 
or needs to me smaller otherwise.
Time complexity is O(n*log(n))

*/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>


double long maxError = pow(10,-5);
std::vector<double long> pieVolume;
int friends, numPie;


int VolumeFunction(double long volume){
     double long numPieces=0;
     for(int i=0; i<pieVolume.size(); i++){
         int temp =(int) (pieVolume[i] / volume);
         numPieces +=temp;
     }
     return  numPieces;
 } 



double long findMaxPieVolume(){
    double long maxVolume, start=0, end=pieVolume[numPie-1];
    
    double long currError = end-start;
    while(currError >= maxError){
        
        maxVolume = (start+end)/2.0;
        
        double long numPieces = VolumeFunction(maxVolume);
        if(numPieces>=friends)
            start=maxVolume;
        else
           end=maxVolume; 

        currError=(end-start);
    }
    return maxVolume;

}
    
int main(){
    int tests,radii;
    
    std::cin>>tests;

    for(int i=0; i<tests; i++){
        pieVolume.clear();
        std::cin>>numPie>>friends;
        friends++;
        for(int j=0; j<numPie; j++){
            std::cin >>radii;
            pieVolume.push_back(radii*radii*M_PI);
        }
        std::sort(pieVolume.begin(), pieVolume.end());
        double long res = findMaxPieVolume();
        std::cout << std::fixed;
        std::cout << std::setprecision(4);
        std::cout << res << "\n";

    }
}