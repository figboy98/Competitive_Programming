/* Classical application of Prim's algorithm
Time complexity is O(n^2), n is the number of nodes(buildings) */

#include <iostream>
#include <vector>
#include <set>
#include <array>
#include <limits.h>
#include <queue>

#define INF (INT_MAX/2)


void buildGraph(std::vector<std::vector<std::pair<int,int>>> &graph, int size ){
    int start,end,distance;
    for(int i=0; i<size; i++){
        std::cin>>start>>end>>distance;
        graph[start].push_back(std::make_pair(end,distance));
        graph[end].push_back(std::make_pair(start,distance));
    }
}
int minDistance(std::vector<int> distances, std::vector<bool> visited){
    int min = INF;
    int index;
    int size = distances.size();
    for(int i=1; i<size; i++){
        if( !visited[i] && distances[i] < min){
            min = distances[i];
            index=i;
        }

    }
    return index;
}
void prim(std::vector<std::vector<std::pair<int,int>>> graph ,std::vector<int> &distances){
    int size = distances.size();
    std::vector<bool> visited;
    std::vector<int> parent(size);
    distances.assign(size,INF);
    visited.assign(size,false);
    distances[1] =0;
    parent[1] = -1;
    
    std::set<int> queue;    


    for(int i=1; i<size; i++){
         int v = minDistance(distances, visited);
         visited[v] = true;
       
        std::vector<std::pair<int,int>>::iterator it;
        
        for(it = graph[v].begin(); it!= graph[v].end(); it++){
            int to = it->first;
            int weigth = it->second;
            
            
            if(visited[to] ==false){
                
                if(weigth < distances[to]){
                   distances[to] = weigth;
                }
                
            }
        }
    }
}

int getCost(std::vector<int> distances, int price){

    int size = distances.size();
    int cost=0;
    for(int i=1; i<size;i++){
        cost+=distances[i];

    }
    return cost*price;

}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int tests;
    std::cin>>tests;

    for(int i=0; i<tests; i++){
        int price, buildings, streets;
        std::cin>>price>>buildings>>streets;
        std::vector<std::vector<std::pair<int,int>>> graph(buildings+1);
        std::vector<int> distances(buildings+1);

        buildGraph(graph, streets);
        prim(graph,distances);
        std::cout<<getCost(distances,price)<<"\n";
    }
}