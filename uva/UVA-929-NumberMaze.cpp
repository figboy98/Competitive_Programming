/* To solve this problem the maze is turned to a graph and then dijkstra algorithm is applied to discover the minmum value.
A set is used as the queue because the set keeps the elements in ascending order.

Complexity is O(|E|log|V|), being E the edges and V the vertices */ 

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <set>

#define INF 100000
class Node{
    public:
        int weight;
        int pos;
        std::vector<int> neighbours;
        Node(int p,int w){
            pos =p;
            weight = w;
        }

        void addNeighbour(int pos){
            neighbours.push_back(pos);
        }

};


void readMaze(int rows, int cols, std::vector<std::vector<int>> &maze){
    for(int i=0; i<rows; i++){
        std::vector<int> tmp;
        for(int j=0; j<cols; j++){
            int num;
            std::cin>>num;
            tmp.push_back(num);
        }
        maze.push_back(tmp);
    }
}
void getNeighbours(std::vector<std::vector<int>> maze, std::vector<Node> & graph){
    int rowPos[] = {0,-1,0,1};
    int colsPos[] = {-1,0,1,0};
    int rows = maze.size();
    int cols = maze[0].size();

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            int x = i;
            int y = j;
            int currPos = i * cols + j;
            for(int k=0; k<4; k++){
                int xx = x+  rowPos[k];
                int yy = y + colsPos[k];
                if(xx <0 || xx >=rows || yy<0 || yy>=cols){
                    continue;
                }
                else{
                    int pos = xx * cols + yy;
                    graph[currPos].addNeighbour(pos);
                }
            }
            
        }
    }

}
void buildGraph(std::vector<std::vector<int>> maze, std::vector<Node> &graph){
    int rowPos[] = {0,-1,0,1};
    int colsPos[] = {-1,0,1,0};
    int pos=0;
    for(auto& row:maze){
        for(auto& col:row){
            Node *tmp = new Node(pos,col);
            graph.push_back(*tmp);
            pos++;
        }
    }

    getNeighbours(maze, graph);

}

int  dijkstra(int start,std::vector<Node> graph){
    std::vector<int> distance;
    std::vector<bool> visited;
    int dest = graph.size() -1;
    int size = graph.size();
    
    distance.assign(size,INF );

    distance [start] =graph[0].weight;
    //<distance, position>
    
    std::set<std::pair<int,int>> queue;
    
    queue.insert({0,start});

    while(!queue.empty()){
        int vertex = queue.begin()->second;
        queue.erase(queue.begin());
        if(vertex == dest){
           break;
        }
        Node curr = graph[vertex];

        for(auto edge : curr.neighbours){
            int to = edge;
            int weigth = graph[edge].weight;

            if(distance[vertex] + weigth < distance[to]){
                queue.erase({distance[to], to});
                distance[to] = distance[vertex] + weigth;
                queue.insert({distance[to], to });

            }
        }
    }

    return distance[size-1];       
} 


int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int tests,rows,cols;
    std::cin>>tests;
    for(int i=0; i<tests; i++){
        std::vector<std::vector<int>> maze;
        std::vector<Node> graph;
        std::cin>>rows>>cols;
        readMaze(rows,cols, maze);
        buildGraph(maze,graph);
        std::cout << dijkstra(0,graph)<<"\n";

    }
}