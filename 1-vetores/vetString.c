#include <stdio.h>
/*
	Vetor para armazenar uma palavra ou frase 
*/

int main(){
	int i;
	char palavra[30];
	char frase[100];
	
	//Vetor de string inicializa de forma diferente para leituras apartir do teclado
	printf("Digite uma palavra sem espaco: ");
	scanf("%s", palavra); //Le apenas caracteres sem espaco e sem enter 
	printf("A palavra digitada foi: %s\n", palavra); 
	fflush(stdin); //Limpar buffer do teclado
	
	printf("\nDigite uma frase: ");
	fgets(frase, 100, stdin); //Le os espacos entre palavras
	printf("A frase digitada foi : %s", frase);
	
	return 0;
}
