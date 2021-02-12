/* To solve this problem we traverse the map and we check if that position was already visited, if not then we add or increase  in the
map the value of the letter and we start a flood fill from that position to mark as visited all the connected letters.
In the end we transform the map to a vector to sort by the value.

Time complexity O(c*r), c = height and r = width of the map */


#include <iostream>
#include <stdio.h>
#include <map>
#include <bits/stdc++.h>

#define MAX 1000


void readGrid(int rows, int cols, char grid[MAX][MAX]){

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            std::cin>>grid[i][j];
        }
    }
}


void floodFill(int rows, int cols, int i, int j,char curr, char grid[MAX][MAX], bool visited[MAX][MAX]){
    int movesRows[] = {-1,1,0,0};
    int movesCols[] = {0,0,-1,1};

    if(i>rows || j>cols || i<0 || j<0){
        return;
    }

    if(visited[i][j] || grid[i][j] != curr){
        return;
    }

    else if(!visited[i][j] && grid[i][j]==curr) {
        for(int k=0; k<4;k++){
            visited[i][j] = true;
            floodFill(rows,cols,i+movesRows[k], j+movesCols[k],curr, grid, visited);
        }
    }


}


void findZones(int rows, int cols, char grid[MAX][MAX], bool visited[MAX][MAX], std::map<char,int> &zones){
    std::map<char,int>::iterator it;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols;j++){
            if(visited[i][j]==false){
                char curr = grid[i][j];
                it = zones.find(curr);
                if(it != zones.end()){
                    it->second = it->second+1;
                }
                else{
                    zones.insert(std::pair<char,int>(curr,1));
                }
                floodFill(rows,cols,i,j,curr,grid,visited);
            }
        }
    }

}
bool sorter(const std::pair<char,int> &a , const std::pair<char,int> &b){
    if(a.second == b.second){
        return a.first < b.first;
    }

    return a.second > b.second;
}

void sortMap(std::map<char,int> &zones, std::vector<std::pair<char,int>> &vec){
    std::map<char,int>::iterator it;

    for(it=zones.begin(); it !=zones.end();it++){
        char key;
        int val;
        vec.push_back(std::make_pair(it->first, it->second));

    }

    std::sort(vec.begin(), vec.end(), sorter);
}


int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int tests;
    std::cin>>tests;

    for(int i=1; i<=tests; i++){
        std::map<char, int> zones;
        int rows,cols;
        std::cin>>rows>>cols;
        char grid [MAX][MAX]={0};
        bool visited[MAX][MAX] = {false};
        readGrid(rows,cols,grid);
        findZones(rows,cols,grid,visited,zones);
        std::vector<std::pair<char,int>> vec;
        std::vector<std::pair<char,int>>::iterator it;
        sortMap(zones,vec);
        std::cout <<"World #" <<i<<"\n";
        for(it=vec.begin(); it!=vec.end(); it++){
            std::cout <<it->first << ": " <<it->second<<"\n";
        }


    }
}