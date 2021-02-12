/* 
To solve this problem the bissectin method is used
*/

#include <iostream>
#include <cmath>
#include <iomanip>


double function(double a, double b, double c, double x){
    double res= a*x + b*sin(x) -c; 
    return res;
}
double findLowerBound(double a,double b,double c){
    int startValue = 0;
    int temp = 0;
    while(temp>0){
        temp = function(a,b,c,startValue);
        startValue-=1;
        
    }
    return startValue;

}
double findUpperBound(double a, double b, double c){
    int endValue = 0,temp=0;
    while( temp <=0){
        temp = function(a,b,c,endValue);
        endValue +=1;
    }
    return endValue;
}
double bissectionMethod(double a, double b, double c,double lowerBound, double upperBound){
    
    double res=0, error = 5 * pow(10,-8), currError;
    currError = abs(upperBound-lowerBound);
    double temp=0;
    while(currError > error){
        res = (lowerBound + upperBound)/2;
        temp = function(a,b,c,res);
        if(temp==0){
            return res;
        }
        if(temp * function(a,b,c,lowerBound) <0 ){
            upperBound = res;
        }
        else{
            lowerBound = res;
        }
        currError /=2;
        
    }
    return res;

}
int main(){
    
    int tests;
    double a,b,c,lowerBound,upperBound,res;
    std::cin>>tests;
    for(int i=0; i<tests; i++){
        std::cin>>a>>b>>c;
        lowerBound= findLowerBound(a,b,c);
        upperBound= findUpperBound(a,b,c);
        res = bissectionMethod(a,b,c,lowerBound,upperBound);
        std::cout<<std::fixed;
        std::cout<< std::setprecision(6);
        std::cout << res<<"\n";
       
    }
        return 0;
}