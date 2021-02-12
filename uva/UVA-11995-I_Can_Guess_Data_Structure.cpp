/* The idea of the algorithm is just to insert the input in all data structures and compare the real output of each one with the 
output that we are expecting and based on the result exclude the data structures that did not matched.

Time complexity
The data structure with the biggest cost to insert is the priority queue with O(logn)
Overall complexity is O(nlogn)

*/

#include <iostream>
#include <stack>
#include <queue>

bool isStack = true;
bool isQueue = true;
bool isPriorityQueue = true;

void insertNumber(int num,std::stack<int> &stack, std::queue<int> &queue, std::priority_queue<int> &priorityQueue){
    stack.push(num);
    queue.push(num);
    priorityQueue.push(num);
}
void checkOutput(int num,std::stack<int> &stack, std::queue<int> &queue, std::priority_queue<int> &priorityQueue){
    int stackNum,queueNum,priorityQueueNumb;
    
    if(stack.size()==0){
        isStack=false;
        isQueue=false;
        isPriorityQueue=false; 
        return;
    }
    stackNum = stack.top();
    stack.pop();
    queueNum = queue.front();
    queue.pop();
    priorityQueueNumb = priorityQueue.top();
    priorityQueue.pop();

    if(num != stackNum)
        isStack = false;
    if(num != queueNum)
        isQueue = false;
    if(num != priorityQueueNumb)
        isPriorityQueue=false; 
    
}
void readInput(int numCommands, std::stack<int> &stack, std::queue<int> &queue, std::priority_queue<int> &priorityQuee){
   
    int num1,num2;
    for(int i=0; i<numCommands; i++){
        std::cin>>num1>>num2;
        if(num1==1){
            insertNumber(num2,stack,queue,priorityQuee);
        }
        else if (num1==2){
            checkOutput(num2,stack,queue,priorityQuee);
        }
    }

}

void checkDataStructure(){
    
    if (isStack && !isQueue && !isPriorityQueue){
        std::cout<<"stack\n";
    }
    else if(!isStack && isQueue && !isPriorityQueue){
        std::cout << "queue\n";
    }
    else if(!isStack && !isQueue && isPriorityQueue){
        std::cout <<"priority queue\n";
    }
    else if(!isStack && !isQueue && !isPriorityQueue) {
        std::cout <<"impossible\n";
    } 
    else{
       std::cout <<"not sure\n"; 

    }
}
void resetFlags(){
    isStack=true;
    isQueue =true;
    isPriorityQueue=true;
}
int main(){
    int numComands;
    std::cin>>numComands;
    
    while(numComands !=EOF && !std::cin.fail()){
        std::stack<int> stack;
        std::queue<int> queue;
        std::priority_queue<int> priorityQueue;
        readInput(numComands, stack, queue, priorityQueue);
        checkDataStructure();
        resetFlags();
        std::cin>>numComands;
    }
    return 0;

}



