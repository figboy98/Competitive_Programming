/* The idea is to sort each road  in decreasing order using the east city, and the west city in case of
a tie. Then for each road( x,y) the value in the BIT is updated by 1, and we read the cumulative sum from
y-1 to 1. With this we have how many roads have a y index smaller than the y index of the current road.
Since the roads are ordered every road that we found has crossings.
The complexity is O(klogm) */

#include <iostream>
#include <algorithm>

bool compare(std::pair<int,int> a, std::pair<int,int> b){
    if(a.first== b.first){
        return a.second > b.second;
    }
    return a.first > b.first;
}

long long read (int start, int *bit){
    long long counter=0;
    while(start >0){
        counter += bit[start];
        start -= (start & -start);
    }
    return counter;
}

void update(int start, int end , int *bit, int val){
    while(start<=end){
        bit[start] +=val;
        start +=(start &-start); 
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);

    int n,m,k;
    int tests;
    std::cin>> tests;

    for(int i=1; i<=tests;i++){
        std::cin >>n>>m>>k;
        std::pair<int,int> highways[k];
        int bit[m+1]={0};
        for(int j=0; j<k; j++){
            int a,b;
            std::cin>>a>>b;
            highways[j] = std::make_pair(a,b);
        }

        std::sort(highways, highways+k, compare);
        
        long long answer=0;
        for(int j=0; j<k; j++){
            update(highways[j].second,m, bit, 1);
            answer += read(highways[j].second-1, bit);
        }

        std::cout<<"Test case " <<i<<": "<< answer <<"\n";

    }
}