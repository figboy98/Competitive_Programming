/* To solve the problem we store and sort the points from right to left and then the lenght of the sunny part of the mountain is calculated.
To calculate that part first we calculate the length of the total side of the mountain and with a formula obtained from a rule of three the sunny side is calculated

Rule of three used
heigth of mountain -> total length 
heigth of sunny side -> x

Time complexity is O(n), n is the points */

#include <iostream>
#include <bits/stdc++.h>
#include <vector>


class Point{
    public:
    int x,y;
    Point(int a, int b){
        x=a;
        y=b;
    }

    
};

bool comparator (const Point &a, const Point &b){
        if( a.x > b.x) return true;
        return false;
    }
double hypotenuse(Point a, Point b){
    return sqrt( (double) (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}


double getLength(std::vector<Point> matrix){
    
    double length =0;
    int maxHeight =0;
    int size = matrix.size();

    for(int i=1; i<size;i++){
        Point a =matrix[i];
        Point b = matrix[i-1];
        if(a.y > maxHeight){
            double hypo = hypotenuse(a,b);
            double sunnyLength = hypo * (a.y - maxHeight) / ( a.y - b.y);
            length += sunnyLength; 
            maxHeight = a.y;
        }
    }
    return length;
}

int main(){
    int tests;
    std::cin>>tests;
    for(int i=0; i<tests; i++){
        std::vector<Point> matrix;
        int pairs;
        std::cin>>pairs;
        for(int i=0; i<pairs; i++){
            int x,y;
            std::cin>>x>>y;
            matrix.push_back(Point(x,y));
        }
        sort(matrix.begin(), matrix.end(), comparator);

        double length = getLength(matrix);
        std::cout << std::setprecision(2) << std::setiosflags(std::ios::fixed) << length << '\n';
    }

}