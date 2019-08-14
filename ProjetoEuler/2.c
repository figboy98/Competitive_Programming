//Pojeto Euler
//Problema 2
//Soma dos números pares da sequência de Fibonacci até 4 milhões

#include <stdio.h>
#define MAX 40000000000
int even(int n){
		if(n%2==0){
			return 0;
		}
	}


int fibonacci(){
	
		int vec[4];
		vec[0]=1, vec[1]=2;
		unsigned int  soma=0;
		int k=1;
		
		
		int i=2;
	
			while( k >0 ){
				
			vec[i]=vec[i-2]+vec[i-1];
			int temp1=vec[i];
			
			if(temp1 > MAX){
				break;
			}
			else{
				if((even(temp1))==0){
					soma=soma+temp1;
				}
			}
			
			vec[i+1]=vec[i-1] + vec[i];
			int temp2=vec[i+1];
			
			if(temp2 > MAX){
				break;
			}
			else{
				if((even(temp2))==0){
					soma=soma+temp2;
				}
			}
			
			vec[0]=temp1;
			vec[1]=temp2;
		
			
		}
		
		return (soma+2);
	}
	
	int main(){
		
		unsigned int  soma=fibonacci();
		
		printf("%u", soma);
		return 0;
	}
	
	
	
		 
		
		
		
		
	
