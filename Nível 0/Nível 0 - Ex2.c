#include <stdio.h>
#include <stdlib.h>

    /* Elabore um programa que leia um caractere e depois o imprima como um valor inteiro. Use a tabela ASCII. */

int main(){

    char caracter;
    printf("Digite um caracter qualquer: \n");
    scanf(" %c",&caracter);

    printf("%d",caracter);
    return 0;
}