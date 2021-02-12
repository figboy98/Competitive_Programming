/* To solve the problem we use the approach of longest common subsequence, but for words instead of characters.
After that we backtrack the matrix to print the words that are common
Time complexity is O(mn), where m and n are the number of words present in each text */

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>



void LCS(std::vector<std::string> &str1, std::vector<std::string>&str2){
    int matrix[str2.size()][str1.size()];
    memset(matrix,0, sizeof(matrix));
    
    for(int i=0; i<str2.size(); i++){
        for(int j=0; j<str1.size(); j++){
            if(i==0 || j==0){
                matrix[i][j] =0;
            }
            else if(str1[j] == str2[i]){
                int temp = 1 + matrix[i-1][j-1];
                matrix[i][j] = temp;
            }
            else{
                int temp = std::max(matrix[i][j-1], matrix[i-1][j]);
                matrix[i][j] = temp;
            }

        }
    }
    
    int lines = str2.size();
    int cols = str1.size();
    int index= matrix[lines-1][cols-1];
    int size = index;

    std::string words[index];
    index--;
    cols--;
    lines--;
    
    while(lines > 0 && cols>0){
        if(str1[cols] == str2[lines]){
            words[index] = str1[cols];
            index--;
            cols--;
            lines--;
        }
        else if(matrix[lines][cols-1] > matrix[lines-1][cols]){
            cols--;
        }
        else{
            lines--;
        }

    }
    for(int i=0; i<size; i++){    
        std::cout<<words[i];
        if(i!=size-1){
            std::cout<<" ";
        }
    }
    std::cout<<"\n";
}




int  main(){
    std::string str;
    
    while(std::cin>>str){
        std::vector<std::string> str1, str2;
        str1.push_back("");
        str2.push_back("");
        str1.push_back(str);
        
        std::cin>>str;
        while(str!= "#"){
            str1.push_back(str);
            std::cin >>str;
        }
        std::cin>>str;
        
        while(str != "#"){
            str2.push_back(str);
            std::cin >>str;
        }
        LCS(str1,str2);

    }
    
}
   