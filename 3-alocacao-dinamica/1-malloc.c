#include <stdio.h>
#include <stdlib.h>
/*
	Funcao 	- malloc();
	Formato void* malloc(size_t quantidade de bytes); size_t tipo inteiro sem sinal;
	Retorna um ponteiro com o endereco do inicio do espaco de memoria alocado;
	sizeof(); calcular um tipo de dados, ou seja, a quantidade de bytes;
	
	ex: malloc(5 * sizeof(int)); Alocar memoria para 5 dados tipo inteiro;
	
	A funcao nao trata lixo de memoria;
*/

void escrever(int *numeros, int n);
void endereco_da_memoria(int *numeros, int n);

int main(){
	
	int *numeros;
	int n, i;
	
	printf("Digite a quantidade de numeros: ");
	scanf(" %d", &n);
	
	numeros = malloc(n*sizeof(int));
	
	if(numeros == NULL){
		printf("Erro ao alocar memoria!");
		exit(1);
	}
	printf("\nConteudo da memoria antes da insercao dos valores: ");
	escrever(numeros, n);
	
	printf("\nInserir valores:\n");
	for(i=0; i<n; i++){
		printf("%do valor: ", i+1);
		scanf(" %d", &numeros[i]);
	}
	
	printf("\nValores inseridos: ");
	escrever(numeros, n);
	endereco_da_memoria(numeros, n);
	
	free(numeros);
	
	return 0;
}

void escrever(int *numeros, int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d, ", numeros[i]);
	}
	printf("\n");
}

void endereco_da_memoria(int *numeros, int n){
	int i;
	printf("\nEndereco da memoria alocada: ");
	for(i=0; i<n; i++){
		printf("%d, ", &numeros[i]);
	}
	printf("\n");
}









