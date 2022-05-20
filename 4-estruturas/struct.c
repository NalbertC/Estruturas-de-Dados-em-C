#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Data{
	int dia, mes, ano;
};


int main(){
	
	struct Data dataDeNascimento;
	
	printf("Digite a data do seu nascimento: DD/MM/AAAA\n");
	printf("Dia: ");
	scanf(" %d", &dataDeNascimento.dia); // Para acessar endereco de elemento da estrura usa-se o ponto;
	
	printf("Mes: ");
	scanf(" %d", &dataDeNascimento.mes);
	
	printf("Ano: ");
	scanf(" %d", &dataDeNascimento.ano);
	

	
	
	printf("\nData de nascimento: %d/%d/%d \n", dataDeNascimento.dia, dataDeNascimento.mes, dataDeNascimento.ano);
	
	
	
	return 0;
}










