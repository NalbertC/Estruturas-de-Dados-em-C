#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	int valor;
	struct no *proximo;
} No;

typedef struct {
	No *prim;
	No *fim;
	int tam;
} Fila;

void criar_fila(Fila *fila) {
	fila->prim = NULL;
	fila->fim = NULL;
	fila->tam = 0;
}

void inserir_na_fila(Fila *fila, int num);

No* remover_da_fila(Fila *fila);

void imprimir(Fila *fila);

int main() {
	No *r;
	Fila fila;
	int opcao, valor;
	
	criar_fila(&fila);
	
	do{
		printf("\n0 - Sair\n1 - Inserir\n2 - Remover\n3 - Imprimir\nDigite sua opcao: ");
		scanf(" %d", &opcao);
		getchar();
		
		switch(opcao){
		case 0:
			printf("\nSaindo...........\n");
			break;
		case 1:
			printf("\nDigite um valor: ");
			scanf(" %d", &valor);
			inserir_na_fila(&fila, valor);
			break;
		case 2:
			r = remover_da_fila(&fila);
			if(r){
				printf("\nRemovido: %d\n", r->valor);
				free(r);
			}
			break;
		case 3:
			imprimir(&fila);
			break;
		default:
			printf("\nOpcao invalida!\n\a");
		}
		
	}while(opcao != 0);
	

	return 0;
}


void inserir_na_fila(Fila *fila, int num){
	No *novo = malloc(sizeof(No));
	if(novo){
		novo->valor = num;
		novo->proximo = NULL;
		if(fila->prim == NULL){
			fila->prim = novo;
			fila->fim = novo;
		}
		else{
			fila->fim->proximo = novo;
			fila->fim = novo;
		}
		fila->tam++;
	}
	else
		printf("\nErro ao alocar memoria!\n");
}

No* remover_da_fila(Fila *fila){
	No *remover = NULL;
	
	if(fila->prim){
		remover = fila->prim;
		fila->prim = remover->proximo;
		fila->tam--;
	}
	else
		printf("\n\tPilha vazia\n");
	return remover;
}

void imprimir(Fila *fila){
	No *aux = fila->prim;
	printf("\t----------FILA----------\n\t");
	while(aux){
		printf("%d ", aux->valor);
		aux = aux->proximo;
	}
	printf("\n\t--------FIM FILA--------\n");
	
}

