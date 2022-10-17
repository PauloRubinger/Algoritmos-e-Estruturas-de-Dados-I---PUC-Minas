#include <stdio.h>
#include <stdlib.h>

/* Faça um programa que calcule e mostre a soma dos 50 primeiros números pares. */

int main(){

    int soma = 0;

    for (int i = 0; i <= 98; i = i + 2)
        soma = soma + i;
    
    printf("A soma dos 50 primeiros numeros pares e: %d \n", soma);

    return 0;
}

