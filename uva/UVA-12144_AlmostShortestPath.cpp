/* To solve this problem first is used the dijkstra's algorithm to find the best path, then all the best paths are removed from the grap and dijkstra's algorithm is used again. 
If we get a result different than infinite, it means that it's possible to have a second best path, otherwise there isn't any second best path

Time complexity is O(|E|log|V|), being E the edges and V the vertices  */
#include <iostream>
#include <vector>
#include <set>
#include <limits.h>
#include <queue>



#define INF (INT_MAX/2)

void removePath(int parent, int pos, std::vector<std::vector<std::pair<int,int>>> &graph){
    std::vector<std::pair<int,int>>::iterator it;
 
     for(it=graph[parent].begin(); it!= graph[parent].end(); it++){
        if( it->first == pos){
            graph[parent].erase(it);
            break;
        }
    }
}
void removeBestPaths(int pos,std::vector<std::vector<int>> parents,std::vector<std::vector<std::pair<int,int>>> &graph){

    std::queue<std::pair<int,int>> queue;
    std::vector<int>::iterator it;

    for(it = parents[pos].begin(); it!= parents[pos].end(); it++){
        queue.push(std::make_pair(*it,pos));
    }
    

    while(!queue.empty()){
        int start = queue.front().first;
        int to = queue.front().second;
        queue.pop();
        if(start != to){
            for(it = parents[start].begin(); it != parents[start].end(); it++){
                queue.push(std::make_pair(*it,start));
            }
        removePath(start,to,graph);
        }
    }

}
void dijkstra(int start,std::vector<std::vector<std::pair<int,int>>>&graph, std::vector<int> &distance, std::vector<std::vector<int>> &parent){
   
    int size = graph.size();
    
    distance.assign(size,INF );

    distance [start]=0;
    parent[start].push_back(start);
    
    //<distance, position>
    
    std::set<std::pair<int,int>> queue;
    
    queue.insert({0,start});

    while(!queue.empty()){
        int vertex = queue.begin()->second;
        queue.erase(queue.begin());
       
        std::vector<std::pair<int,int>>::iterator it;
        for(it = graph[vertex].begin(); it!= graph[vertex].end(); it++){
            int to = it->first;
            int weigth = it->second;

            if(distance[vertex] + weigth < distance[to]){
                queue.erase({distance[to], to});
                distance[to] = distance[vertex] + weigth;
                queue.insert({distance[to], to });
                parent[to].clear();
            
            }
            if(distance[vertex] + weigth == distance[to])
                parent[to].push_back(vertex);
        }
    }
}

int findSecondBestPath(int start, int end, std::vector<int> &distances, std::vector<std::vector<int>> &parents, std::vector<std::vector<std::pair<int,int>>> &graph){
    
    dijkstra(start,graph, distances, parents);
   
    removeBestPaths(end,parents,graph);
    dijkstra(start, graph,distances,parents);
        
    int secondBest = distances[end];
    if(secondBest == INF){
        return -1;
    }        
    
    return secondBest;
}
void buildGraph(std::vector<std::vector<std::pair<int,int>>> &graph, int size ){
    int start,end,distance;
    for(int i=0; i<size; i++){
        std::cin>>start>>end>>distance;
        graph[start].push_back(std::make_pair(end,distance));
    }
}


int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int points, roads;
    std::cin>>points>>roads;
    while(points !=0 || roads!=0){
        std::vector<std::vector<std::pair<int,int>>> graph(points);
        std::vector<int> distances;
        std::vector<std::vector<int>> parents(points);
        int start, end;
        std::cin>>start>>end;
        buildGraph(graph, roads);
        int answer = findSecondBestPath(start, end, distances, parents,graph);
        std::cout<<answer<<"\n";
        std::cin>>points>>roads;

    }

}