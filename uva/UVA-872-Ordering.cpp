/* To solve this problem is used topological sorting with backtracking to print all possible orders */

#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <algorithm>

class Node{
    public:
        char letter;
        std::vector<char> neighbours;
        int degree=0;
        bool visited=false;

        Node(char a){
            letter = a;
        }

        void insertNode(char a){
            neighbours.push_back(a);
        }
};

void buildGraph(std::unordered_map<char,Node*> &graph, std::string str){
    int size = str.length();

    for(int i=0; i<size; i++){
        char aux = str.at(i);
        if(aux != ' '){
            Node *node = new Node(aux);
            graph[aux] = node;
        }
    }
}

void insertRestrictions(std::unordered_map<char,Node*> &graph, std::string str){
    int size = str.length();

    for(int i=0; i+2<size; i+=4){
        char first,second;
        first = str.at(i);
        second =str.at(i+2);
        graph[first]->insertNode(second);
        graph[second]->degree++;
    }
}

void findAllSortings(std::unordered_map<char,Node*> graph, std::vector<char> &list, std::vector<std::vector<char>> &orders){

    for(auto it :graph){
        char curr = it.second->letter;
        if(graph[curr]->degree ==0 && graph[curr]->visited == false){

            for(char tmp : graph[curr]->neighbours){
                graph[tmp]->degree--;
            }
            list.push_back(graph[curr]->letter);
            graph[curr]->visited=true;

            findAllSortings(graph,list,orders);


            //Backtracking
            for(char tmp : graph[curr]->neighbours){
                graph[tmp]->degree++;
            }

            list.erase(list.end()-1);
            graph[curr]->visited=false;

            }
        }

        if(list.size() == graph.size()){
            std::vector<char> temp;
            for(char tmp: list){
                temp.push_back(tmp);   
            }
            orders.push_back(temp);
        }
    }




int main(){
    int tests;
    std::cin>>tests;
    std::string str;
    getline(std::cin, str);
    for(int i=0; i<tests; i++){
        std::unordered_map<char,Node*> graph;
        std::vector<char> list;
        std::vector<std::vector<char>> order;
        getline(std::cin, str);
        getline(std::cin, str);

        buildGraph(graph, str);
        getline(std::cin, str);
        insertRestrictions(graph, str);
        findAllSortings(graph, list,order);

        if(i>0) std::cout<<"\n";
        if(order.size()==0){
            std::cout<<"NO"<<"\n";
        }
        else{
            std::sort(order.begin(), order.end());
            for(auto it=order.begin(); it != order.end(); it++){
                std::vector<char> temp = *it;
                std::cout<<temp[0];
                
                for(auto j = temp.begin()+1; j!= temp.end(); j++){
                    std::cout<<" "<<*j;
                }
                std::cout<<"\n";
            }
        }
            
        }
        
}
