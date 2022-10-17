#include <stdio.h>
#include <stdlib.h>

/* Faça um algoritmo que leia um número positivo e imprima seus divisores. Exemplo: os
divisores do número 66 são: 1, 2, 3, 6, 11, 22, 33 e 66. */

int main(){

    int numero;

    printf("Digite um numero inteiro positivo para descobrir os seus divisores: \n");
    scanf("%d", &numero);

    for (int i = 1; i <= numero; i++)
        if (numero%i == 0)
            printf("%d\t", i);

    return 0;
}