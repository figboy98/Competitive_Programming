#include <iostream>
#include <stdlib.h>
#include <time.h>       


void findPerm(int perm){  

    int pos[perm+1];
    int j=1;
    for(int i=1; i<=perm+1; i++){
        pos[i] =i;
    }

    int size=0;
    int i=1;
    while(size<perm){
        for(int j=perm; j>0;j--){
            
            if(pos[j]!=i && pos[j] !=-1 ){
                std::cout<<pos[j] <<" ";
                size++;
                pos[j] =-1;
                i++;
                break;
            }
        }
    }
    std::cout <<"\n";
}


int main(){
        srand (time(NULL));
    int tests;
    std::cin>>tests;
    for(int i=0; i<tests;i++){
        int perm;
        std::cin>>perm;
        findPerm(perm);
    }
}