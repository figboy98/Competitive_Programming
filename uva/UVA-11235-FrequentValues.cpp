/* Solved using segment trees. In each tree node the most frequent value is saved and the frequency is also saved, 
then in the merge the border of both nodes are verified to see if together they have a number with a bigger
frequency than the max of both nodes.

Time complexety is O(nlogn) */

#include <iostream>
#include <algorithm>
#include <utility> 
#include <vector>

#define MAX 100000
#define MAX_ST 400005


class SegTreeNodes{
    public:
        int start;
        int end;
        int freq;
        int numb;
        SegTreeNodes(){
            start=0;
            end=0;
            freq=0;
            numb=0;
        }

        SegTreeNodes(int s, int e,int f, int n){
            start=s;
            end=e;
            freq=f;
            numb=n;
        }
        bool operator == (const SegTreeNodes &b) const {
            if(start == b.start && end==b.start && freq==b.freq && numb==b.numb){
                return true;
            }
            return false;
        }
        
};


int input[MAX];
SegTreeNodes segTree[MAX_ST];
SegTreeNodes neutral (0,0,0,0);
int cont=0;

bool verifyBorders(SegTreeNodes left, SegTreeNodes right, std::pair<int,int> & border){
    int counter=0;
    int key=0;
    int flag = false;
    
    if(input[left.end-1] == input[right.start-1]){
        flag = true;
        key = input[left.end-1];
        int i= left.end-1;
        while(input[i] == key && i>= left.start-1){
            counter++;
            i--;
        }
        i = right.start-1;
        while(input[i] == key && i <=right.end-1){
            counter++;
            i++;
        }
    }
    border = std::make_pair(counter,key);
    return flag;
}

SegTreeNodes merge(SegTreeNodes& left, SegTreeNodes& right){
    
    int freq=0;
    int freqBorder=0;
    int numb=0;
    std::pair<int,int> border;
    
    if(neutral== left ){
        
        return right;
    }
     if(right == neutral ){
        return left;
    }

    //If the most frequent numbers are the same we just need to add the frequencies of each
    
    if(left.numb == right.numb){
        freq= left.freq + right.freq;
        numb = left.numb;

    }
    //If the most frequent numbers are different then we want the biggest frequencie
    else{
        if(left.freq > right.freq){
            freq = left.freq;
            numb= left.numb;
        }
        else{
            freq = right.freq;
            numb = right.numb;
        }
    }

    if(verifyBorders(left,right,border)){
        if(border.first > freq){
            freq = border.first;
            numb = border.second;
        }
    }
    SegTreeNodes node(left.start, right.end, freq,numb);
    return node;
  }



void build(int pos, int start, int end){
    if(start==end){
        SegTreeNodes node(start,end,1, input[start-1]);
        segTree[pos] =node;
    }
    
    else{
        int middle =start+ (end -start)/2;
        build(pos*2, start, middle );
        build((pos*2)+1,middle+1,end );
        segTree[pos] = merge (segTree[pos*2], segTree[pos*2+1]);


    }
}


SegTreeNodes queryAux(int pos, int start, int end, int queryStart, int queryEnd){
   
    if (start>queryEnd || end<queryStart){
        return neutral;
    } 
        
    if (start>=queryStart && end<=queryEnd){
        return segTree[pos];
    } 

    int middle = start + (end-start)/2;
    SegTreeNodes a = queryAux(pos*2,start,middle,queryStart,queryEnd );
    SegTreeNodes b = queryAux(pos*2+1,middle+1,end,queryStart,queryEnd );

    SegTreeNodes node = merge(a,b);
    return node;
}

int query(int pos, int start,int end, int queryStart, int queryEnd){
    SegTreeNodes node = queryAux(pos,start,end,queryStart,queryEnd);
    return node.freq;
}

int main(){
    std::ios_base::sync_with_stdio(false);

    int numInts=1, numQueries;
    
    while(1){
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cin >>numInts>>numQueries;
        if(numInts==0) break;
        for(int i=0; i<numInts; i++){
            std::cin >> input[i];
        }
        build(1,1,numInts);
        for(int i=0; i<numQueries; i++){
            int start, end;
            std::cin>> start>>end;
            std::cout<<query(1,1,numInts,start,end)<<"\n";
        }
        

    }
}
