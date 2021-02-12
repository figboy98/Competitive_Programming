/* The ideia of the algorithm is to save the value of bills in a multiset to be ordered in ascending order. At the end of each day 
remove the first (bill with the min value) and the last (bill with the max value) from the multiset and add the difference to 
the total value to be paid

-----Time complexity---------
Inserting in the multiset cost O(logn), so the overall complexity is O(nlogn)

*/

#include <iostream>
#include <set>



int getDayPrize(std::multiset<int>& bills){
    
    auto maxItr = prev(bills.end());
    auto minItr = bills.begin();
    
    bills.erase(maxItr);
    bills.erase(minItr);
    
    return (*maxItr - *minItr);
}
long simulatePromotion(int numDays){
    std::multiset<int> bills;
    int numBills,billValue;
    long prize=0;

    for(int i=0; i<numDays; i++){
        std::cin >> numBills;
        for(int j=0; j<numBills;j++){
            std::cin>> billValue;
            bills.insert(billValue);
        }
        prize+=getDayPrize(bills);
    }
    return prize;
}
int main(){
     std::ios::sync_with_stdio(false);

    int numDays;
    std::cin>> numDays;

    while(numDays !=0 ){
        std::cout<< simulatePromotion(numDays)<<"\n";
        std::cin>>numDays;
    }
}