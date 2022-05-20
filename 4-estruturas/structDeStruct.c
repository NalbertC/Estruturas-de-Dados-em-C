#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Data{
	int dia, mes, ano;
};

typedef struct { // Tipo definido pelo usuario 
	char nome[50];
	struct Data data;	
}Pessoa; // Definir  Pessoa do tipo struct com os dados nome e data;

Pessoa ler_pessoa();

void imprimir_pessoa();

int main(){

	Pessoa p;
	
	p = ler_pessoa();

	imprimir_pessoa(p);

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



