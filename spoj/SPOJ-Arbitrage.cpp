/*To solve this problem is used the Floyd-Warshall algorithm. When we find a path where the "distance" (value of currency) leads to a value greater than 1 it means that is possible to arbitrage 

Time complexity is  O(|V|³) */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

bool floydWarshall(std::vector<std::vector<double>> distances){

    int size = distances[0].size();

    for(int k=0; k<size; k++){
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                if(distances[i][j] < distances[i][k] * distances[k][j]){
                    distances[i][j] = distances[i][k] * distances[k][j];
                    if(i==j && distances[i][j] >1){
                        return true;
                    }
                }
            }
        }

    }
        return false;
    
}




int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int currencys;
    int rates;
    std::cin>>currencys;
    int cas =1;
    while(currencys !=0){
        std::vector<std::vector<double>> distances (currencys, std::vector<double> (currencys,0));
        std::unordered_map<std::string,int> graph;
        for(int i=0; i<currencys; i++){
            std::string tmp;
            std::cin>>tmp;
            graph.insert(std::make_pair(tmp,i));
        }

        std::cin>>rates;
        for(int i=0; i<rates; i++){
            double rate;
            std::string first, second;
            std::cin>>first>>rate>>second;
            int start, end;
            start = graph[first];
            end = graph[second];
            distances[start][end] = rate;
            
        }
        bool possible = floydWarshall(distances);
        if(possible){
            std::cout<<"Case " <<cas<<": Yes"<<"\n";
        }
        else{
            std::cout<<"Case " <<cas<<": No" <<"\n";

        }

        std::cin>>currencys;
        cas++;
    }

}