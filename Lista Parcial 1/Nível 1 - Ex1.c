#include <stdio.h>
#include <stdlib.h>

// Faça um programa que leia um número inteiro e retorne seu antecessor e seu sucessor. //

int main(){

    int numero;
    int antecessor;
    int sucessor;

    printf("Digite um numero inteiro: \n");
    scanf("%d", &numero);

    antecessor = numero - 1;
    sucessor = numero + 1;

    printf("O antecessor do numero e %d e o sucessor e %d \n", antecessor, sucessor);

    return 0;
}