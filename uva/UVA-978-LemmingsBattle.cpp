/*The main idea of the algorithm is to use a multiset with the power of each soldier in both armys, since the multiset is
organized in ascent order, in each simulation we take the n last soldiers, the most powerfull ones, for the n battlefields.
The survivors are reinserted in the multiset. The simulations are repeated until at least one of the armys is empty.

-----Time complexity----------

Insertation in the multiset is O(logn)
Reading the input cost O(nlogn)
Each simulation costs O(klogn) being k the number of battlegrounds
Overall complexity is O(nlogn)


*/

#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>

std::multiset<int> greenArmy;
std::multiset<int> blueArmy;

void readSoldiersPowers(std::multiset<int> &army, int numSoldiers){
   
    int power;
    for(int i=0; i<numSoldiers; i++ ){
        std::cin >>power;
        army.insert(power);
    }
}
void getNextSoldiers(int *greenSoldiers, int *blueSoldiers, int &battleGrounds){
    int minGrounds = std::min (greenArmy.size(), blueArmy.size());
    if(minGrounds < battleGrounds)
        battleGrounds = minGrounds;


    for(int i=0; i<battleGrounds;i++){
        auto itr = prev(greenArmy.end());
        greenSoldiers[i] =*itr;
        greenArmy.erase(itr);
        itr = prev(blueArmy.end());
        blueSoldiers[i] = *itr;
        blueArmy.erase(itr);
    }    

}
void addSurvivors(int *greenSoldiers, int * blueSoldiers, int position){

    if(greenSoldiers[position] >0)
        greenArmy.insert(greenSoldiers[position]);
    if(blueSoldiers[position]>0)
        blueArmy.insert(blueSoldiers[position]);
}
void fight(int *greenSoldiers, int * blueSoldiers, int battleGrounds){
    int green,blue;
    for(int i=0; i<battleGrounds; i++){
        green = greenSoldiers[i];
        blue = blueSoldiers[i];
        greenSoldiers[i] = green-blue;
        blueSoldiers[i] = blue-green;
        addSurvivors(greenSoldiers,blueSoldiers,i);
    }
}

void simulateBattle(std::multiset<int> &greenArmy, std::multiset<int> &blueArmy, int battleGrounds){
    int greenSoldiers[battleGrounds];
    int blueSoldiers[battleGrounds];
    
    getNextSoldiers(greenSoldiers, blueSoldiers,battleGrounds);
    fight(greenSoldiers, blueSoldiers, battleGrounds);
}

void printSurvivors(std::multiset<int> &army){
    
    for(auto itr = army.rbegin(); itr != army.rend(); itr++){
        std::cout << *itr << "\n";
    }
}
int main(){
    int numTests, power, battleGrounds, greenSoldiers, blueSoldiers;
    std::cin >> numTests;
    
    for(int i=0; i<numTests;i++){
            std::cin >> battleGrounds;
            std::cin >> greenSoldiers;
            std::cin >> blueSoldiers;
            readSoldiersPowers(greenArmy, greenSoldiers);
            readSoldiersPowers(blueArmy, blueSoldiers);
        do{
            simulateBattle(greenArmy, blueArmy, battleGrounds);
        }while(greenArmy.size()!=0 && blueArmy.size()!=0);


        if(greenArmy.size()==0 && blueArmy.size()==0)
            std::cout << "green and blue died" <<"\n";
        else if (greenArmy.size()!=0){
            std::cout <<"green wins" << "\n"; 
            printSurvivors(greenArmy);
        }
        else{
            std::cout << "blue wins" << "\n";
            printSurvivors(blueArmy);
        }

        greenArmy.clear();
        blueArmy.clear();
        if(i<numTests-1)
            std::cout << "\n";

    }


    return 0;
}