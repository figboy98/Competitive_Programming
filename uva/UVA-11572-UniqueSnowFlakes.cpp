/* The ideia is to use a map using the snowflake size as key and the index of the last seen time as the value.
A counter is used to count the number of unique elements found so far.
When a repeated snowflake is found the index of the last time it whas seen is compared with the 
last index where a repeated snowflake was found previously, and the max value of both is saved, and the value of counter
is updated, removing the block where the repeated element was found
In each iteration the value of counter is compared with the current answer, and answers becomes the max value
of both.

Algorithm inspired in this article https://www.davidudelson.com/blog/2015/07/23/uva-11572-unique-snowflakes/

------Time complexity-------------
O(nlogn)
*/

#include <iostream>
#include <map>
#include <algorithm>


int main(){
    std::map<int, int> lastPosition;
    int counter, blockedIndex, answer,tests,snowflakeSize,snowflakeLastSeen,numSnowflakes;
    std::cin >> tests;
    
    for(int i=0; i<tests; i++){
        std::cin >> numSnowflakes;
        lastPosition.clear();
        counter=0;
        answer=0;
        blockedIndex=0;
        for(int i=1; i<=numSnowflakes; i++){
            std::cin >>snowflakeSize;
            snowflakeLastSeen = lastPosition[snowflakeSize];
            
            if(snowflakeLastSeen != 0){
                blockedIndex = std::max(blockedIndex,snowflakeLastSeen);
                counter = i-blockedIndex-1;
            } 
            counter++;
            answer=std::max(answer,counter);
            lastPosition[snowflakeSize]=i;
        }
        std::cout << answer << "\n";
    } 
    return 0;
}