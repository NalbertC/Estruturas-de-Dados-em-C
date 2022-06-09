#include <stdio.h> 
#include <stdlib.h>

//
// Arvore binaria
//

typedef struct no{
	int valor;
	struct no *direita, *esquerda;
}NoArv;

NoArv* inserir_versao_1(NoArv *raiz, int num){
	if(raiz == NULL){
		NoArv *aux = malloc(sizeof(NoArv));
		aux->valor = num;
		aux->esquerda = NULL;
		aux->direita = NULL;
		return aux;
	}
	else{
		if(num < raiz->valor)
			raiz->esquerda = inserir_versao_1(raiz->esquerda, num);		
		else 
			raiz->direita = inserir_versao_1(raiz->direita, num);
		return raiz;		
	}
}

void imprimir_versao_1(NoArv *raiz){
	if(raiz){
		printf("%d ", raiz->valor);
		imprimir_versao_1(raiz->esquerda);
		imprimir_versao_1(raiz->direita);
	}
}

void imprimir_versao_2(NoArv *raiz){
	if(raiz){
		imprimir_versao_2(raiz->esquerda);
		printf("%d ", raiz->valor);
		imprimir_versao_2(raiz->direita);
	}
}

void menu(){
	printf("\nMENU DE OPCOES:\n0 - Sair\n1 - Inserir\n2 - Imprimir\n");
	printf("Digite sua opcao: ");
}

int main (){
	NoArv *raiz = NULL;
	int opcao, valor;
	
	do{
		menu();
		scanf(" %d", &opcao);
		
		switch(opcao){
			case 0:
				printf("\nSaindo..............\n");
				break;
			case 1:
				printf("\nDigite o valor: ");
				scanf(" %d", &valor);
				raiz = inserir_versao_1(raiz, valor);
				break;
			case 2:
				printf("\n\tPrimeira impresao por ordem de entrada: \n\t");
				imprimir_versao_1(raiz);
				printf("\n");
				
				printf("\n\tSegunda impresao ordenado: \n\t");
				imprimir_versao_2(raiz);
				printf("\n");
				
				break;
			default:
				printf("\nOpcao invalida!\a\n");
		}	
	}while(opcao != 0);

	
	return 0;
}


