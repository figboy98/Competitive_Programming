//Problema 1
//Multiplos de 3 ou de  5
//Soma dos multiplos de 3 ou de 5 até o número 1000, não incluindo o 1000
#include <stdio.h>
#define MAX 1000

int main(){
	int soma=0;
	for(int i=(MAX-1); i>0; i--){
		if(i%5 ==0 || i%3 ==0){
			soma=soma+i;
		}
	}
	
	printf("%d", soma);
	return 0;
}

