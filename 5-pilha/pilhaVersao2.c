#include <stdio.h>
#include <stdlib.h>

//Estruturas de dados 
//Segunda versao de pilha

typedef struct{
    int dia, mes, ano;
}Data;

typedef struct{
    char nome[50];
    Data data;
}Pessoa;

typedef struct no{
	Pessoa p;
	struct no *proximo;
}No;

//Pilha
typedef struct{
	No *topo;
	int tam;
}Pilha;

//Prototipos das funcoes
void menu();

void criar_pilha(Pilha *pilha);

Pessoa ler_pessoa();

void imprimir_pessoa(Pessoa p);

void empilhar(Pilha *pilha);

No* desempilhar(Pilha *pilha);

void imprimir_pilha(Pilha *pilha);

// Funcao principal 
int main(){
	Pilha pilha;
	No *remover;
	int opcao;
	criar_pilha(&pilha);
	
	do{
		menu();
		scanf(" %d", &opcao);
		getchar();
			
		switch(opcao){
		case 0:
			printf("\nSaindo.........\n\n");
			break;
		case 1:
			empilhar(&pilha);
			break;
		case 2:
			remover = desempilhar(&pilha);
			if(remover){
				printf("\nElemento removido com sucesso!\n");
				imprimir_pessoa(remover->p);
				
				free(remover);
			}else 
				printf("\nSem no a remover\n");
			break;
		case 3:
			imprimir_pilha(&pilha);
			break;
		default:
			printf("\nOpcao invalida!\a\n");
				
		}
	}while(opcao != 0);
	
	return 0;
}
//Funcoes
void menu(){
	printf("\nMENU DE OPCOES");
    printf("\n0 - Sair\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n");
    printf("Digite sua opcao: ");
}

void criar_pilha(Pilha *pilha){
	pilha->topo = NULL;
	pilha->tam = 0;
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
    printf("\nNome: %s\nData: %2d-%2d-%4d\n", p.nome, p.data.dia, p.data.mes, p.data.ano);
}

void empilhar(Pilha *pilha){
	No *novo = malloc(sizeof(No));
	if(novo){
		novo->p = ler_pessoa();
		novo->proximo = pilha->topo;
		pilha->topo = novo;
		pilha->tam++;
		
	}else
		printf("\nERRO AO ALOCAR MEMORIA!\n");
		
	free(novo);
}

No* desempilhar(Pilha *pilha){
	if(pilha->topo){
		No *remover = pilha->topo;
		pilha->topo = remover->proximo;
		pilha->tam--;
		return remover;
	}else
		printf("\nPilha vazia!\n");
	return NULL;
}

void imprimir_pilha(Pilha *pilha){
	No *aux = pilha->topo;
	printf("\n|------------ PILHA tam: %d --------------|\n", pilha->tam);
	while(aux){
		imprimir_pessoa(aux->p);
		aux = aux->proximo;
	}
	printf("\n|-------------- FIM PILHA ----------------|\n");		
}





