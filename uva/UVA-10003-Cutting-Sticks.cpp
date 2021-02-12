/* The ideia to solve this problem is to start by making a cut and then find the best order for the next cut by testing in both sticks produced by the first cut every possible 
cut and save the best, i.e the one with the minimum cost. Each sub problem is saved in the dp table for future use, to avoid  compute the same sub problem again.

The idea for solving the problem is described in the book Competitve Programming 3 Cap 3.5.3

The time complexity is O(n^3)

*/

#include <iostream>
#include <bits/stdc++.h>

#define MAX 55


void findBest(int left, int right, int dp[MAX][MAX], int cutsArr[MAX]){

    if(left+1 == right){
        dp[left][right]=0;
        return;
    }

    if(dp[left][right] != 0 ){
        return;
    }
    int res = INT_MAX;
    for(int i=left+1; i<right; i++){
        findBest(left, i, dp, cutsArr);
        findBest(i, right, dp, cutsArr);
        res = std::min(res, dp[left][i] + dp[i][right] + cutsArr[right]- cutsArr[left]);
    }
    dp[left][right] = res;
}

int main(){
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);


    int length;
    std::cin>>length;
    while(length !=0){
        int cuts;
        std::cin>>cuts;
        int cutsArr[MAX];
        for(int i=1; i<=cuts; i++){
            std::cin>>cutsArr[i];
        }
        int dp[MAX][MAX];
        cutsArr[0]=0;
        cutsArr[cuts+1] = length;
        memset(dp, 0, sizeof(dp));
        findBest(0, cuts+1,dp, cutsArr);
        int ans = dp[0][cuts+1];
        std::cout<<"The minimum cutting is " <<ans <<".\n";
        std::cin>>length;
    }
}