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

//Prototipos das funcoes
void menu();
Pessoa ler_pessoa();
void imprimir_pessoa();

//Funcao para empilhar 
No* empilhar(No *topo);

//Desempilhar
No* desempilhar(No **topo);

void imprimir_pilha(No *topo);

//Funcao principal
int main(){
	No *remover, *topo = NULL;
	int opcao;
			
	do{
		menu();
		scanf("%d", &opcao);
		getchar();
		
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
				printf("\nOpcao invalida!\a\n");
		}		
	}while(opcao != 0);
	
	free(remover);
	free(topo);
	
	return 0;
}

//Funcoes
void menu(){
	printf("\nMENU DE OPCOES");
    printf("\n0 - Sair\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n");
    printf("Digite sua opcao: ");
}

Pessoa ler_pessoa(){
    Pessoa p;

    printf("\nDigite nome: ");
    fflush(stdin);
    gets(p.nome);
    printf("Data de nascimento DD MM AAAA:\n");
    printf("Dia: ");
    scanf("%d", &p.data.dia);
    printf("Mes: ");
    scanf("%d", &p.data.mes);
    printf("Ano: ");
    scanf("%d", &p.data.ano);
    printf("\n\n");
    return p;
}

void imprimir_pessoa(Pessoa p){
	printf("\nNome: %s\nData de nascimento: %d/%d/%d\n" , p.nome, p.data.dia, p.data.mes, p.data.ano);
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
	printf("\n|----------- FIM PILHA -----------|\n\n");
}










