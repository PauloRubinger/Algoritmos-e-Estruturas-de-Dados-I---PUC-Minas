#include <stdio.h>
#include <stdlib.h>

    /* Elabore um programa que leia um caractere e depois o imprima como um valor inteiro. Use a tabela ASCII. */

int main(){

    char caractere;
    printf("Digite um caractere qualquer: \n");
    scanf(" %c",&caractere);

    printf("%d",caractere);
    return 0;
}
