#include<iostream>
using namespace std;

int main(){
  int size;
  int mainDiagonal=0,secundaryDiagonal=0;
  cin>>size; //size og array
  int  arr[size];
  int mainAux=0, secundaryAux=size-1; // used to know the index of relevant values for main and secundary diagonal

  for(int i=0; i<size;i++){
    for(int j=0; j<size;j++){
      int input;
      cin>>input;
      arr[j]=input;
  }
  mainDiagonal+=arr[mainAux];
  secundaryDiagonal+=arr[secundaryAux];
  mainAux++; // the next number of main diagonal is in the next position
  secundaryAux--; //the next number of secundary diagonal is in the previous position
}

int res = mainDiagonal-secundaryDiagonal;
if(res<0) cout<< res*-1<<endl; //if the number is negative is transformed in a positive
else cout<< res<<endl;
return 0;
}
