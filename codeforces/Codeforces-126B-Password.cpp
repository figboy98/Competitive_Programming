/* The idea for solving this problem is to calculate the prefix sufix array like in KMP algorithm and then use that array to check
if we can find a substring that is prefix, sufix and that appears in somewhere in the string 

The main cost is the calculating of the prefix sufix array that is done in O(n), n= string size */

#include <iostream>
#include <bits/stdc++.h>

#define MAX 1000005
char str[MAX];
char prefix[MAX];
int pi[MAX];


void prefixSuffix(int size ,char str[MAX]){

    pi[1]=0;
    int k=0;
    for(int i=2; i<size;i++){
        while(k >0 && str[k+1]!=str[i]){
            k = pi[k];
        }
        if(str[k+1] == str[i]){
            k++;
        }
        pi[i] =k;
    }

}

void printString(int size){
    for(int i=1; i<=size; i++){
        std::cout<<str[i];
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    char in;
    int i=1;
    bool flag = false;
    while(std::cin>>in){
        str[i] = in;
        i++;
    }
    prefixSuffix(i,str);
    int size=i;

    if(pi[size-1] ==0){
        std::cout<<"Just a legend";
        return 0;
    }
    int suffixSize = pi[size-1];
    
    for(int i=suffixSize+1; i<size-1; i++){
        if(pi[i] == suffixSize){
            printString(suffixSize);
            return 0;
        }
    }

    if(pi[suffixSize]==0){
         std::cout<<"Just a legend";
     }
     else{
        printString(pi[suffixSize]);

     }   
}