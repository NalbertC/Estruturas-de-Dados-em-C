#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
    Tabela HASH
    - Estruturas de dados utilizada para
    tornar o processo de busca mais
    eficiente.

    TAMANHO
    Quantidade máxima de elementos na tabela.
    M = 2 * 6 (primo mais proximo) = 11

    FUNCAO DE ESPALHAMENTO
    Funcao que gera um codigo a ser utiliizado como indice de acesso na tabela.
    chave % M

    COLISOES
    Ocorre uma colisao quando a funcao de espalhamento
    gera o mesmo codigo para chaves diferentes.

    FATOR DE CARGA
    Quantidade de elementos dividido pelo Tamanho da tabela.
    fc = 6/11 = 0,54

*/
/*
    Tabela HASH - Linear com vetor
*/
#define TAM  31
// 2 *31 = 30 -> 31
void inicializarTabela(int t[]){
    int i;

    for(i = 0; i < TAM; i++)
        t[i] = 0;
}

int funcaoHash (int chave){ // espalhamento
    return chave % TAM;
}

void inserir(int t[], int valor){
    int id = funcaoHash(valor);
    while(t[id] != 0){
        id = funcaoHash(id + 1);
    }
    t[id] = valor;
}

int busca(int t[], int chave){
    int id = funcaoHash(chave);
    while(t[id] != 0){
       if(t[id] == chave)
            return t[id];
       else {
            id = funcaoHash(id + 1);
       }
    }
    return 0;
}

void imprimirTabela(int t[]){
    int i;
    for(i = 0; i < TAM; i++){
        printf("%d = %d\n", i , t[i]);
    }

}

void menu(){
	printf("\nMENU DE OPCOES:\n0 - Sair\n1 - Inserir\n2 - Buscar\n3 - Imprimir\n");
	printf("Digite sua opcao: ");
}



int main(){
    srand(time(NULL));
    int opcao, valor, retorno, tabela[TAM];
    int i;
    inicializarTabela(tabela);
    do{
        menu();
        scanf(" %d", &opcao);
        switch(opcao){
        case 0:
            printf("\nSaindo..............\n");
            break;
        case 1:
            //printf("\nQual valor deseja inserir? ");
            //scanf(" %d", &valor);
            //inserir(tabela, valor);
            for(i = 0; i < 15; i++){
                valor = rand() % 1000;
                inserir(tabela, valor);
            }

            break;
        case 2:
            printf("\nQual valor deseja buscar? ");
            scanf(" %d", &valor);
            retorno = busca(tabela, valor);
            if(retorno != 0)
                printf("\tValor encontrado: %d\n", retorno);
            else
                printf("\tValor nao encontrado!\n");
            break;
        case 3:
            imprimirTabela(tabela);
            break;
        default:
            printf("\nOpcao invalida!\n\a");
        }
    }while(opcao != 0);

    return 0;
}

















