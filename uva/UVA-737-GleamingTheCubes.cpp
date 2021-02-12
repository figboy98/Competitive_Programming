/* We save the most left coordinates of the cube in descending order and the right most coordinates in the asceding order to get the intersection and then the volume is calculated with those intersections 
Most of the work is sorting the vectors, and the sort function is c++ is in the worst case O(nlogn) */

#include <iostream>
#include <bits/stdc++.h>
#include <vector>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int numCubes;
    std::cin >>numCubes;
     while(numCubes!=0){
         std::vector<int> xRight;
         std::vector<int> xLeft;
         std::vector<int> yRight;
         std::vector<int> yLeft;
        std::vector<int> zRight;
        std::vector<int> zLeft;

        for(int i=0; i<numCubes;i++){
            int x,y,z,l;
            std::cin>>x>>y>>z>>l;
            xLeft.push_back(x);
            yLeft.push_back(y);
            zLeft.push_back(z);
            xRight.push_back(x+l);
            yRight.push_back(y+l);
            zRight.push_back(z+l);
        }
        sort(xLeft.begin(), xLeft.end(), std::greater<int>());
        sort(yLeft.begin(), yLeft.end(), std::greater<int>());
        sort(zLeft.begin(), zLeft.end(), std::greater<int>());

        sort(xRight.begin(), xRight.end());
        sort(yRight.begin(), yRight.end());
        sort(zRight.begin(), zRight.end());

        int vol =((xRight[0]-xLeft[0]) * (yRight[0]- yLeft[0]) * (zRight[0]-zLeft[0])) ;
        if(vol <0) vol=0;
        std::cout<<vol<<"\n";
        std::cin >> numCubes;
     }

}

