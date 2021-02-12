/* To solve this problem we generate all possibles prime numbers starting in the given number changing only 1 digit, 
creating a graph where the depth of the graph where the first appearence of the desired number corresponds to the 
smallest number of changes possible  to reach that number */

#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <vector>

#define MAX 10000
#define null -1

bool visited[MAX] = {false};

bool isPrime(int num){
     
    if (num <= 1) 
        return false; 
    if (num <= 3) 
        return true; 
  
    if (num % 2 == 0 || num % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= num; i = i + 6) 
        if (num % i == 0 || num % (i + 2) == 0) 
            return false; 
  
    return true;
} 

int vecToInt(int vec[5]){
    int num=0;
    int sum=1;
    for(int i=4; i>=1; i--){
        num += vec[i] *sum;
        sum*=10;
    }
    return num;
}

std::vector<int> nextPrimes(int num){
    std::vector<int> primeNumbers;
    int number[5];
    int test[5];
    int res=10;   
    for(int i=4; i>=1; i--){
        number[i] =num %res;
        test[i] = num %res;
        num /=10;
    }

    for(int i=1; i<=4; i++){
        int j;
        if(i==1) j=1;
        else j=0;
        int aux = number[i];
        for(j; j<=9; j++){
            number[i] =j;
            int temp = vecToInt(number);
            if( isPrime(temp) && !visited[temp]){
                primeNumbers.push_back(temp);
            }
        }
        number[i] = aux;
    }
    return primeNumbers;
}

int buildPath(int origin, int dest){
    std::queue<int> child;
    int counter =0;
    bool found =false;

    child.push(origin);
    child.push(null);
    
    visited[origin] = true;
    
    while(!child.empty()){
        int num = child.front();
        child.pop();

        if(num == null){
            counter++;
            child.push(null);
            if(child.front() == null) break;
        }

        if(num == dest){
            found = true;
            break;
            
        } 
        if(num !=null){
            std::vector<int> nextChild = nextPrimes(num);
            std::vector<int>::iterator it;

            for(it = nextChild.begin(); it!=nextChild.end(); it++){
                if(!visited[*it]){
                    child.push(*it);   
                    visited[*it] = true;
                }
            }
        }

    }
        if(found)
            return counter;
        return -1;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int tests;
    std::cin>>tests;
    for(int i=0; i<tests; i++){
        int origin, dest;
        std::cin>>origin>>dest;
        int res = buildPath(origin,dest);
        if(res ==-1) std::cout<<"Impossible";
        else std::cout <<res <<"\n";
        memset(visited, false, MAX);
    }
}