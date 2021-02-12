/* In this problem we simply use a 2d BIT and use it as a normal BIT. 
The complexity is O(log n) */
#include <iostream>
#include <bits/stdc++.h>
#include <string>


#define SIZE 1025

long bit[SIZE+1][SIZE+1] = {0};
long matrix[SIZE][SIZE] ={0};
long query(int x, int y){
    long sum =0;
    while(x>0){
        int y1=y;
        while(y1>0){
            sum += bit[x][y1];
            y1 -= (y1 & -y1);
        }
        x-= (x & -x);
    }
    return sum;
    
}
long getSumSquare(int x1,int y1, int x2,int y2){
    
    long res=0;
    res += query(x2+1,y2+1);
    res -= query(x1, y2+1);
    res -= query(x2+1,y1);
    res += query(x1,y1); 
    return res;
}

void update(int x, int y, int max, int value){
    int y1;
    
    while(x < max){
        y1= y;
        while(y1 <max){

            bit[x][y1] += value;
            y1 += (y1 & -y1);
        }
        x+=(x & -x);
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int tests;
    std::cin>>tests;
    for(int i=0; i<tests; i++){
        int size;
        std::cin>>size;

         memset(bit, 0, sizeof(bit));
         memset(matrix,0, sizeof(matrix));

        std::string op="";
        
        while(op != "END"){
            
            std::cin>>op;
            if(op == "SET"){
                long x,y,value;
                std::cin>>x>>y>>value;
                long newValue = value - matrix[x][y];
                matrix[x][y] = value;
                update(x+1,y+1,size+1,newValue);
            }
            else if(op =="SUM"){
                int x1, y1, x2, y2;
                std::cin>>x1>>y1>>x2>>y2;
                std::cout<<getSumSquare(x1,y1,x2,y2) << "\n";
            }
        }
    }
}