/* Since the problem only asks for the value of a certain element instead of the cumulative sum, we only  increase the value of l in the range update and decrease by the same number the value of r+1.
When we want to get the number of a element we just iterate from 0 to the element adding the values in the array.
The "trick" used in this problem is described here: https://www.geeksforgeeks.org/binary-indexed-tree-range-updates-point-queries/
The complexity is O(queries*n) */

#include <iostream>

void rangeUpdate(int start, int end, int size, int value,int *bit){
    
    bit[start]+=value;
    bit[end+1] -=value;
}

int readIndex(int index, int *bit){
    int counter=0;
    
    for(int i=0; i<=index;i++){
        counter+=bit[i];
    }
    return counter;
}


int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int tests;
    std::cin>>tests;

    for(int i=0; i<tests; i++){
        int size, updates;
        std::cin>>size>>updates;
        int bit[size]={0};
        for(int j=0; j<updates;j++){
            int left, right, value;
            std::cin>>left>>right>>value;
            rangeUpdate(left,right,size,value,bit);
        }
        int queries;
        std::cin >>queries;
        for(int k=0; k<queries; k++){
            int index;
            std::cin>>index;
            std::cout<<readIndex(index,bit)<<"\n";
        }
    }
}