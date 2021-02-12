/* To solve this problem the longest increasing subsequence approach is used. One from start to end, and then from end to start.
We save the number os nums less than the number in the current position in boath times. In the end we compare those arrays searching
for the maximum value that corresponds to a wavio sequence
Time complexity is O(nlogn) */

#include <iostream>
#include <vector>
#include <algorithm>




void LIS(std::vector<int>& input, std::vector<int>& list) {
    int size = input.size();

    std::vector<int> dp(size);
    int lenght=0;
    for (int i = 0; i <size; i++) {
        
      int j = std::lower_bound(dp.begin(), dp.begin()+ lenght, input[i]) - dp.begin();
        dp[j] = input[i];
        
        if(j==lenght) lenght++;
        
        list[i] = j+1;
    }

}

int main(){
    int size,num;
    while(std::cin>>size){
        std::vector<int> lr(size);
        std::vector<int> rl(size);
        
        for(int i=0; i<size; i++){
            std::cin>>num;
            lr[i]=num;
            rl[size-i-1] = num; 
        }
        std::vector<int> lis(size);
     
        std::vector<int> lds(size);
     LIS(lr,lis);
     LIS(rl, lds);
    
    int maxWave=0;

    for(int i=0; i<size; i++){
        int value = std::min(lis[i], lds[size-i-1]);
        maxWave = std::max(maxWave, value*2-1);
    }
    std::cout<<maxWave<<"\n";
    
    }
}