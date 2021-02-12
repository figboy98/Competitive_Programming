/* To solve this problem we use the same aproach of finding the edit distance to transform a string in another string, with the difference
that the other string is the reverse of the original string, in essence we are comparing each character with the character in the oposite position
in the string. When we are comparing two characters with a distance beetwen them of <2, then the edit distance is 0 because 2 characters are always
a palindrome. We start from the smallest string, meaning we resolve the problem bottom up.
The time complexity is O(n) */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string.h>



int palindrome(std::string str){
    int size = str.length();
    int matrix[size+1][size+1];
    memset(matrix,0, sizeof(matrix));

    for(int i=size-1;i>=0;i--)
        {
            for(int j=i+1;j<size;j++)
            {
                if(str[i]==str[j])
                {
                    matrix[i][j]=matrix[i+1][j-1];
                }
                else
                {
                    matrix[i][j]=std::min(matrix[i+1][j-1],std::min(matrix[i+1][j],matrix[i][j-1]))+1;
                }
            }
        }
    return matrix[0][size-1];

}


int main(){
    int tests;
    std::cin >>tests;

    for(int i=1; i<=tests; i++){
        std::string str;
        std::cin>>str;
        int res = palindrome(str);
        std::cout<<"Case "<<i<<": "<<res<<"\n";
    }
}