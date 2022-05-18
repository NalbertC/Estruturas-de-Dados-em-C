#include <stdio.h>
/*
	Vetor para entrada de numeros fracionados
*/

int main(){
	int i, t;
	t = 5;
	float vetFloat[t];
	
	for(i=0; i<t; i++){
		printf("Digite um valor fracionado para a posicao %d: ", i+1);
		scanf(" %f", &vetFloat[i]);
		
	}
	printf("\n");
	
	for(i=0; i<t; i++){
		printf("O valor digitado na posicao %d eh: %f\n", i+1, vetFloat[i]);
	}
	// usa-se comando %.2f Ex: para imprimir 2 valores depois da virgula, alterar  valor para imprimir valores desejados
	return 0;
}








