#include <stdio.h>
#include <stdlib.h>

/*
	Faca um programa que leia 10 numeros reais e os armazene em um vetor. Em seguida, leia um codigo inteiro e faca uma das acoes abaixo:
	0 - finaliza o programa;
	1 - imprime o vetor na ordem do inicio ao fim;
	2 - imprime o vetor na ordem inversa (do fim para o inicio).
	
	O programa deve funcionar ate que o usuario digite 0 para finalizar.

*/

int main(){
	
	int i, codigo;
	int t = 10;
	float vet[t];
	
	for(i=0; i<t; i++){
		printf("Digite o valor para a posicao %d: ", i+1);
		scanf(" %f", &vet[i]);
	}
	
	do{
		printf("\nMenu de Opcoes:\n0 - Sair\n1 - Imprimir na ordem normal\n2 - Imprimir na ordem inversa\nSua opcao: ");
			scanf(" %d", &codigo);
			
		switch(codigo){	
			case 0:
				printf("\nSaindo........\n");
				break;
				
			case 1:
				printf("\nVetor na ordem normal\n");
				for(i=0; i<t; i++){
					printf("%.2f ", vet[i]);
				}
				printf("\n");
				break;
				
			case 2:
				printf("\nVetor na ordem inversa\n");
				for(i=t-1; i>=0; i--){
					printf("%.2f ", vet[i]);
				}
				printf("\n");
				break;
			default:
				printf("Opcao invalida!\n");
		}
		
	}while(codigo != 0);
	
	
	
	
	
	
	return 0;
}
