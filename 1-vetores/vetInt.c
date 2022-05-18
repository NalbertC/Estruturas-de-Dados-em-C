#include <stdio.h>
/*
	Vetor para entrada de numeros inteiros
*/

int main(){
	int i, t; 
	t = 5;
	int vetInt[t];
	
	for(i = 0; i<t; i++){
		printf("Digite o valor para a posicao %d: ", i+1);
		scanf(" %d", &vetInt[i]);
		
	}
	printf("\n");
	for(i=0; i<t; i++){
		printf("O valor digitado na posicao %d eh : %d\n", i+1, vetInt[i]);
		
	}

	return 0;
}
