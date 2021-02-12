/* To solve this problem we use an array to store the cumulative sum of the input and we use dynamic programming to
save compute and save the maximum difference of points that the player A can have starting first for each sub sequence possible.
In the computation of the values we use the minimax principle, where we search the best value starting from the left and the best 
value starting from the right for every sub sequence

The time complexity is O(n^3) */

#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#define MAX 102


int minimax(int left, int right, int cumSum[MAX], int dp[MAX][MAX]){

    if(dp[left][right] !=0) 
        return dp[left][right];
    
    int temp =0;
    //Search int the right part of the game tree
    for(int i=left+1; i<=right; i++){
        temp =  std::min(temp, minimax(i,right,cumSum,dp));
    }
    //Search in the left part of the game tree
    for(int i=left; i<right; i++){
        temp = std::min(temp, minimax(left,i,cumSum,dp));
    }

    dp[left][right] = cumSum[right] - cumSum[left-1] - temp;
    return dp[left][right];

}


int main(){
    int nums;
    std::cin>>nums;
    while(nums!=0){
        int arr[MAX],cumSum[MAX];
        int dp[MAX][MAX];
        memset(dp, 0, sizeof(dp));
        for(int i=1; i<=nums; i++){
            std::cin>>arr[i];
            cumSum[i] = arr[i] + cumSum[i-1];
        }
        int res = minimax(1, nums, cumSum,dp);
        res = 2*res - cumSum[nums];
        std::cout << res <<"\n";
        std::cin>>nums;
    }
}