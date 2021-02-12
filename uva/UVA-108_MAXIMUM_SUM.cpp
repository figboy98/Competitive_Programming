/* The idea of the algorithm is to save the cumulative sums of the input in a matrix, and then
search the square with the biggest sum, changing the start and end coordinates of the square anda
saving the max value.
The time complexity is O(n^4) */
#include <iostream>
#include <bits/stdc++.h>
#include <string>
#define SIZE 110


void build(int size, int matrix[SIZE][SIZE], int bit[SIZE][SIZE]){
    for(int i=1; i<=size;i++){
        int val=0;
        for(int j=1; j<=size; j++){
            int val=0;
            val += bit[i][j-1] + bit[i-1][j] - bit[i-1][j-1];
            val += matrix[i][j];
            bit[i][j] = val;
        }
    }
}

int getSumSquare(int startRow,int startCol, int endRow,int endCol,int bit[SIZE][SIZE]){
    int sum=0;
    sum = bit[endRow][endCol];
    sum-= bit[startRow-1][endCol];
    sum-= bit[endRow][startCol-1];
    sum+= bit[startRow-1][startCol-1];
    return sum;
}


int getMax(int size, int bit[SIZE][SIZE]){
    int result = INT_MIN;

    for(int startRow=1; startRow<=size; startRow++){
        for(int startCol=1; startCol<=size; startCol++){
            for(int endRow =startRow; endRow<=size; endRow++ ){
                int sum=0;
                for(int endCol=startCol; endCol<=size; endCol++){
                    sum = getSumSquare(startRow, startCol, endRow, endCol, bit);
                    result = std::max(sum,result);
                }
            }
        }
    }
    return result;
}

int main(){
    int size;
    std::cin>>size;
    int matrix[SIZE][SIZE]={0};
    int bit[SIZE][SIZE] ={0};
    
    int num;
    for(int i=1; i<=size;i++){
        for(int j=1; j<=size;j++){
            std::cin>>num;
            matrix[i][j] = num;
        }
    }
    build(size, matrix,bit);

    int sums[SIZE][SIZE] ={0};
    std::cout<<getMax(size,bit)<<"\n";
    
}