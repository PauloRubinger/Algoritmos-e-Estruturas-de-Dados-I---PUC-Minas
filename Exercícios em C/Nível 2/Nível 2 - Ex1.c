#include <stdio.h>
#include <stdlib.h>

/* Faça um programa que leia um número inteiro positivo N e imprima todos os números
naturais de 0 até N em ordem crescente. */

int main(){

    int numero;

    printf("Digite um numero inteiro: \n");
    scanf("%d", &numero);

    for (int i = 0; i <= numero; i++)
        printf("%d\t", i);

    return 0;
}