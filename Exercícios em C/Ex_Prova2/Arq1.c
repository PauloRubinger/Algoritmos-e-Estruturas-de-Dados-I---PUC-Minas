#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Faça um programa que receba do usuário um arquivo texto e mostre na tela quantas linhas esse arquivo possui. */

int main(){

    FILE *arq;
    char nomeArq[20];
    char c;
    char linha[200];
    char fimDaLinha = '\n';
    int vezes = 0;
    
    printf("Digite o nome do arquivo que deseja abrir: \n");
    fgets(nomeArq, 20, stdin);

    arq = fopen("teste.txt", "r");

    if (arq == NULL){
        printf("** Erro de abertura **");
        exit(1);
    }

    while (fread(&c, sizeof(char), 1, arq)){
        if (c == fimDaLinha)
            vezes++;
    }

    printf("Quantidade de linhas: %d \n", vezes + 1);

    fclose(arq);

    return 0;

}