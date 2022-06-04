#include <stdio.h>
#include <stdlib.h>

//node
typedef struct no {
	int valor;
	struct no *proximo;	
}No;

void menu(){
	printf("\nMENU DE OPCOES");
    printf("\n0 - Sair\n1 - Inserir\n2 - Remover\n3 - Imprimir\n");
    printf("Digite sua opcao: ");
}

void inserir_na_fila(No **fila, int num){
	No *aux, *novo = malloc(sizeof(No));
	
	if(novo){
		novo->valor = num; 
		novo->proximo = NULL; 
		
		//Insercao
		if(*fila == NULL) 
			*fila = novo; 
			
		else { 
			aux = *fila; 
			
			while(aux->proximo) 
				aux = aux->proximo; 
			aux->proximo = novo;
				
		}
				
	}else 
		printf("\nErro ao alocar memória!\n");
		
}

No* remover_da_fila(No **fila){
	No *remover = NULL;
	
	if(*fila){ 
		remover = *fila; 
		*fila = remover->proximo; 
	}
	else 
		printf("\nFila vazia!\n\n");
	return remover; 
}

void imprimir(No *fila){ 
	printf("\n\t----------FILA---------\n\t");
	if(fila == NULL)
		printf("\n\tSem elementos na fila\n");
	while(fila){ 
		printf(" %d", fila->valor); 
		fila = fila->proximo; 
	}
	
	printf("\n\t---------FIM FILA------\n\n");
}


int main(){
	No *remover, *fila = NULL;
	int opcao, valor;
	
	do{
		menu();
		scanf(" %d", &opcao);
		
		switch(opcao){
			case 0:
				printf("\n\nSaindo........\n");
				break;
				
			case 1:
				printf("\nDigite um valor: ");
				scanf(" %d", &valor);
				inserir_na_fila(&fila, valor);
				break;
				
			case 2:
				remover = remover_da_fila(&fila); 
				if(remover){
					printf("\nRemovido: %d\n\n", remover->valor);
					free(remover);
				}	
				break;
				
			case 3:
				imprimir(fila);				
				break;
				
			default:
				if(opcao !=0)
					printf("\nOpcao Invalida!\n");
		}
		
		
	}while(opcao != 0);
	
	return 0;
}
















