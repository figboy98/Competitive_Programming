/* The ideia is to use a map, using a set as the key and the times the set appears as the value.
When a set is not in the map, is inserted, if it is in the map then its value is increased.
The value of the most popular set is tracked and changed in each iteration, if needed.

-------Time complexity----------
Insert in the set and in the map costs O(logn)
So the overall complexity is O(n(logn)²)
*/
#include <iostream>
#include <map>
#include <set>
#include <iterator>

using namespace std;

set<int> readCoursesInput(){
    set<int> FrogChoices;
    int courseNumber;
    for (int i = 0; i < 5; i++){
        cin >> courseNumber;
        FrogChoices.insert(courseNumber);
    }

    return FrogChoices;

}
//Finds the number of frosh that choosed the most popular combinations of courses
int numberOfPrizes( map<set<int>, int> coursesPopularity,int mostPopular){
     map<set<int>, int>:: iterator itr;
    int prizes=0;
     for(itr=coursesPopularity.begin(); itr!=coursesPopularity.end(); itr++){
         if((itr->second) == mostPopular){
             prizes+=itr->second;
         }
     }
     return prizes;

}
int main(){
    int numFrosh, courseNumber;
    cin >> numFrosh;
  
  while (numFrosh != 0){
    map<set<int>, int> coursesPopularity;
    map<set<int>, int>:: iterator itr;
    set<int> coursesCombination;
    int mostPopular=1;
      
      for(int i=0; i<numFrosh;i++){
        coursesCombination = readCoursesInput();
        itr = coursesPopularity.find(coursesCombination);
        //If the combination os courses choosed already exists, then the number of people that choosed it is increased
        if(itr != coursesPopularity.end() ){
            itr->second +=1;
            if((itr->second) > mostPopular)
                mostPopular = itr->second;
        }
        else{
            coursesPopularity.insert({coursesCombination,1});
        }
      }

      cout << numberOfPrizes(coursesPopularity, mostPopular) << "\n";

      cin >> numFrosh;
        
  }
  return 0;
}