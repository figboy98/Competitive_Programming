/* Solved using offline queryes as described in this article https://codeforces.com/blog/entry/15890 
Since the lookup in the segment tree is O(logn) the complexety is O(nlogn) */

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_ST 4*30000 +5
#define NEUTRAL 0
class Query{
    
    public:
        int index;
        int left;
        int right;
        int k;
        public:
            Query(){
                index=0;
                left=0;
                right=0;
                k=0;
            }

            Query(int l, int r, int a, int i){
                left=l;
                right=r;
                k =a;
                index =i;
            }  

        bool operator < (const Query&a){
            return k < a.k;
        }  
};

class Input{
    public:
        int index;
        int value;
            Input(){
            }
            Input(int a,int b){
                index=a;
                value=b;
            }

            bool operator < (const Input& a ){
                return value < a.value;
            }
};


int segTree[MAX_ST];





int merge(int a, int b){
    return a+b;
}


int  makeQuery(int pos, int start, int end,int queryStart, int queryEnd){
     if (start>queryEnd || end<queryStart){
         return NEUTRAL;
    }

    if(start>= queryStart && end <=queryEnd){
        return segTree[pos];

    }
    else{
        int middle = start +(end-start)/2;
        int a =  makeQuery(pos*2, start, middle, queryStart,queryEnd);
        int b = makeQuery((pos*2)+1, middle+1, end, queryStart, queryEnd);
        return merge(a,b);
    }
}


void update(int pos, int start, int end, int changePos){

    if(start > changePos || end <changePos){
        return;
    }
    if(start == changePos && end ==changePos){
        segTree[pos]=0;
    }
    else{

        int middle = start + (end-start)/2;
        update(pos*2, start, middle, changePos);
        update(pos*2+1, middle+1, end, changePos);
        segTree[pos]= merge(segTree[pos*2], segTree[pos*2+1]);
    }
}



void build(int pos, int start, int end){
     if(start == end){
         segTree[pos] =1;
     }
    else{
        int middle = start +(end-start)/2;

        build(pos*2, start, middle);
        build(pos*2+1, middle+1, end);
        segTree[pos] = merge(segTree[pos*2],segTree[pos*2+1]);
    }

}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int inputNum;
    int queriesNum;
    int left, right, k;
    int in;
    std::cin >> inputNum;
    
    std::vector<Input> input;
    input.push_back(Input(0,0));
    
    for(int i=1; i<=inputNum;i++){
        std::cin>>in;
        input.push_back(Input(i,in));

    }

    std::cin>> queriesNum;
    int answer[queriesNum+1];

      std::vector<Query> query ;
      query.push_back(Query(0,0,0,0));

    for(int i=1; i<=queriesNum; i++){
        std::cin >>left;
        std::cin >> right;
        std::cin >> k;
        Query temp = Query(left,right,k, i);
        query.push_back(temp);
    }
    build(1,1,inputNum);

    std::sort(query.begin()+1, query.end());
    
    std::sort(input.begin()+1, input.end());
    

    int j=1;
    for(int i=1; i<=queriesNum; i++){
        while(input[j].value <= query[i].k && j <= inputNum){
            update(1,1,inputNum, input[j].index);
            j++;
        }
        int temp = makeQuery(1,1,inputNum, query[i].left, query[i].right);
        answer[query[i].index] = temp; 
        
    }


    for(int i=1; i<=queriesNum; i++){
        std::cout<<answer[i] <<"\n";
    }
    return 0;
}
