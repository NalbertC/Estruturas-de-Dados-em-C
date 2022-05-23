#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dia, mes, ano;
}Data;

typedef struct{
    char nome[50];
    Data data;
}Pessoa;

//node
typedef struct no{ 
    Pessoa p; 
    struct no *proximo; 
}No;

//Prototipos 
Pessoa ler_pessoa();
void imprimir_pessoa();

//Funcao para empilhar 
No* empilhar(No *topo);

//Desempilhar
No* desempilhar(No **topo);

void imprimir_pilha(No *topo);

int main(){
	No *remover, *topo = NULL;
	int opcao;
	
	printf("OPCOES:\n0 - Sair\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n");
	scanf(" %d", &opcao);
	getchar();
	
	do{
		switch(opcao){
			case 0:
				printf("\nSaindo..........\n");
				break;
			case 1:
				topo = empilhar(topo);
				break;
			case 2:
				remover = desempilhar(&topo);
				if(remover){
					printf("\nElemento removido com sucesso!\n");
					imprimir_pessoa(remover->p);
				}else 
					printf("\nSem no a remover\n");
				break;
			case 3:
				imprimir_pilha(topo);
				break;
			default:
				printf("\nOpcao invalida!\n");
		}		
	}while(opcao != 0);
	
	free(remover);
	free(topo);
	
	return 0;
}

Pessoa ler_pessoa(){
	Pessoa p;
	
	printf("\nDigite um nome: ");
	fflush(stdin);
	gets(p.nome);
	printf("Data de nascimento: ");
	scanf(" %d%d%d", &p.data.dia, &p.data.mes, &p.data.ano);
	return p;
}

void imprimir_pessoa(Pessoa p){
	printf("\nNome: %s\nData de nascimento: %d/%d/%d" , p.nome, p.data.dia, p.data.mes, p.data.ano);
}

No* empilhar(No *topo){
	No *novo = malloc(sizeof(No));
	
	if(novo){
		novo->p = ler_pessoa();
		novo->proximo = topo;
		return novo;
		
	}else
		printf("\nERRO AO ALOCAR MEMORIA!\n");
	return NULL;
	free(novo);
}

No* desempilhar(No **topo){
	if(*topo){
		No *remover = *topo;
		*topo = remover->proximo;
		return remover;
		free(remover);
		
	}else
		printf("\nPilha vazia!\n");
	return NULL;
}

void imprimir_pilha(No *topo){
	printf("\n|------------- PILHA -------------|\n");
	while(topo){
		imprimir_pessoa(topo->p);
		topo = topo->proximo;
	}
	printf("\n|----------- FIM PILHA -----------|\n");
}










