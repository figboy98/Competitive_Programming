/*
To solve this problem we start from associating every unique number with the number of times it is received using the map data structure. We also save the input order to untie in the sorting when is needed.
After that we copy the map elements to a vector so it can be sorted. We sorte the numbers by its frequency in descending order. When there is a tie we use the input order to break it. The number that appears first comes first 
in the output.
Time complexity is O (nlogn)

*/
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

std::vector<long> inputOrder;
struct compareFrequency{
    bool operator()(const std::pair<long,int> a, const std::pair<long,int>  b){
        if(a.second > b.second) return true;
        if(a.second == b.second){ 
            auto itr = find(inputOrder.begin(), inputOrder.end(), a.first);
            int aIndex = std::distance(inputOrder.begin(), itr);
            itr = find(inputOrder.begin(), inputOrder.end(), b.first);
            int bIndex = std::distance(inputOrder.begin(), itr);
            return (aIndex - bIndex) <0;
        }
        return false;
    } 
};
int main(){
    int size, maxSize, num;
    std::  cin>> size;
    std:: cin >> maxSize;
    std:: map<long,int> frequency;
    std::vector<std::pair<long,int> > aux;
  

    std::pair<long,int> temp;


    for(int i=0; i<size; i++){
         std::cin >>num;
        auto itr = frequency.find(num);
        if(itr != frequency.end()){
            itr-> second +=1;
        }
        else{
            frequency.insert(std::pair<long,int> (num,1) );
            inputOrder.push_back(num);
        }
    }

    for(auto itr=frequency.begin(); itr != frequency.end();itr++){
        temp.first = itr->first;
        temp.second = itr->second;
        aux.push_back(temp);
    }

    sort(aux.begin(), aux.end(), compareFrequency());

    for(auto itr = aux.begin(); itr != aux.end(); itr++){
        for(int i=0; i < itr->second; i++){
            int j = itr->first;
            std::cout << (itr->first) << " ";
        } 
    }
       
  return 0;       
}