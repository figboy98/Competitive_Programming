/* Solved using segment trees. Each node has 1 if the product is positive and -1 if the product is negative,
we don't save the actual values to avoid overflow.
The time complexity is O(nlogn) */

#include <iostream>
#include <algorithm>
#include <utility> 
#include <vector>
#include <string>

#define MAX  100000
#define MAX_ST  4*MAX+5
#define neutral 1

int segTree[MAX_ST];
int input[MAX];


int merge(int a, int b){
    if(a*b < 0){
        return -1;
    }
    else if(a*b >0){
        return 1;
    }
    return 0;
}
void update(int pos,int start, int end, int changePos, int value){
    if(start > changePos || end < changePos){
        return;
    }
    if( start==end && start==changePos){
        segTree[pos] = value;
    }
    else{
        int middle = start + (end-start)/2;
        update(pos*2, start, middle, changePos,value);
        update(pos*2+1, middle+1,end,changePos,value);
        segTree[pos] = merge(segTree[pos*2], segTree[pos*2+1]);
    }
    

}
int query(int pos, int start, int end, int queryStart, int queryEnd){
    if (start>queryEnd || end<queryStart){
        return neutral;
    } 
        
    if (start>=queryStart && end<=queryEnd){
        return segTree[pos];
    }

    int middle = start +(end-start)/2;
    int a = query(pos*2, start,middle,queryStart,queryEnd);
    int b = query((pos*2)+1, middle+1, end, queryStart,queryEnd); 

    return merge(a,b);
}
void build(int pos, int start, int end){
    if(start==end){
        segTree[pos] =input[start];
    }
    
    else{
        int middle =start+ (end -start)/2;
        build(pos*2, start, middle );
        build((pos*2)+1,middle+1,end );
        segTree[pos] = merge (segTree[pos*2], segTree[pos*2+1]);


    }
}

int main(){
    int numInts, numRounds, pos,val,start,end,result;
    std::string output="";
    char letter;

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    while(std::cin>>numInts){
        std::fill(input, input+MAX, 0);
        std::fill(segTree, segTree+MAX_ST, 0);
        output="";

        std::cin>>numRounds;
        for(int i=1; i<=numInts; i++){
            std::cin>>input[i];
        }
        build(1,1,numInts);

        for(int j=0; j<numRounds;j++){
            std::cin>>letter;
            if(letter == 'C'){
                std::cin>>pos>>val;
                input[pos] = val;
                update(1,1,numInts,pos,val);
            }
            else if(letter=='P'){
                std::cin>>start>>end;
                result=query(1,1,numInts,start,end);
                if(result >0){
                    output.append("+");
                }
                else if(result < 0){
                    output.append("-");
                }
                else{
                    output.append("0");
                } 

            }
        }
        std::cout<<output<<"\n";
    }
    return 0;

}