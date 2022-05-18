#include <stdio.h>
#include <time.h>
/*
    Faca um programa que some o conteudo de 2 votores de tamanho 25 e armazenhe o resultado em um terceiro vetor. 
	Imprima os tres vetores na tela.
*/
int main(){
	int i, t = 10;
	int vet1[t], vet2[t], vet3[t];
	
	srand(time(NULL));//usando o tempo como semente para geracao de numero aleatorio
	
	for(i=0; i<t; i++){
		vet1[i] = rand() % 100; //gerar numeros aleatorio
		vet2[i] = rand() % 100;
		vet3[i] = vet1[i] + vet2[i];
	}
	printf("Vetor 1\n");
	for(i=0; i<t; i++){
		printf("Valor %3d: %d\n", i+1, vet1[i]);
	}
	
	printf("\nVetor 2\n");
	for(i=0; i<t; i++){
		printf("Valor %3d: %d\n", i+1, vet2[i]);
	}
	
	printf("\nVetor 3\n");
	for(i=0; i<t; i++){
		printf("Valor %d: %3d + %3d = %4d\n", i+1, vet1[i], vet2[i],vet3[i]);
	}
	
	return 0;
}










