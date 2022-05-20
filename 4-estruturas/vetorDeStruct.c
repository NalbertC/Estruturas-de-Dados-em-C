#include <stdio.h>
#include <stdlib.h>


typedef struct{
	int dia, mes, ano;
}Data;

typedef struct { 
	char nome[50];
	Data data;	
}Pessoa; 

Pessoa ler_pessoa();

void imprimir_pessoa(Pessoa p);

int main(){
	int t, i;
	
	printf("Quantidade de cadastro: ");
	scanf(" %d", &t);
	
	Pessoa cadastro[t];
	for(i=0; i<t; i++){
		cadastro[i] = ler_pessoa();
	}
	
	printf("Pessoas cadastradas:\n");
	for(i=0; i<t; i++){
		imprimir_pessoa(cadastro[i]);
	}

	
	return 0;
}


Pessoa ler_pessoa(){
	
    Pessoa p;

    printf("\nDigite nome: ");
    fflush(stdin);
    gets(p.nome);
    printf("Data de nascimento DD MM AAAA:\n");
    scanf(" %d %d %d", &p.data.dia, &p.data.mes, &p.data.ano);
    return p;
}

void imprimir_pessoa(Pessoa p){
	printf("\nNome : %s\n", p.nome);
	printf("Data de nascimento: %d/%d/%d\n\n", p.data.dia, p.data.mes, p.data.ano);
}





