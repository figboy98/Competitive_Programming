#include <iostream>
#include <limits.h>
#include <algorithm>

class Pos{
    public:
        int num;
        int index;
        Pos(){}
        Pos(int a, int b){
            num=a;
            index=b;
        }
        bool operator < (const Pos& str) const{
            return (num < str.num);    
        }
    
};

void solution(){
    int num;
    std::cin>>num;
    Pos answer[num+1];
    answer[0] = Pos(INT_MAX, 0);
    
    for(int i=1; i<=num; i++){
        int in;
        std::cin>>in;
        answer[i] = Pos(in,i);       
    }
    int n = sizeof(answer) / sizeof(answer[0]);

    std::sort(answer,answer+n);

    for(int i=0; i<num; i++){
        
        if(answer[i].num != answer[i+1].num && answer[i].num != answer[i-1].num){
            std::cout<<answer[i].index<<"\n";
            return;
        }
    }

    std::cout<<"-1\n";
    
}


int main(){
    int tests;
    std::cin>>tests;

    for(int i=0; i< tests; i++){
        solution();
    }
}