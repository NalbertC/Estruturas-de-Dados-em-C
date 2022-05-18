#include <stdio.h>
/*
    Faca um programa que preencha um vetor de inteiros de temanho 10 pedindo  valores ao usuario.
    Em seguida, calcule e salve num  segundo vetor o quadrado de cada elemento do primeiro vetor.
    Por fim imprima os dois vetores na tela
*/

int main(){
	
	int i, t = 2;
	int vet[t], vetQuad[t];
	
	for(i=0; i<t; i++){
		printf("Digite o %do valor: ", i+1);
		scanf(" %d", &vet[i]);
		vetQuad[i] = vet[i] * vet[i];
	}
	printf("\nVetor 1\n");
	
	
	for(i=0; i<t; i++){
		printf("Posicao %d: %d\n", i+1, vet[i]);
		
	}
	printf("\nVetor 2\n");
	
	for(i=0; i<t; i++){
		printf("Posicao %d: %d\n", i+1, vetQuad[i]);			
	}
	
	return 0;
}















