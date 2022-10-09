#include <stdio.h>
#include <stdlib.h>

// Faça um programa que converta uma letra maiúscula em letra minúscula. Use a tabela ASCII para isso.

int main(){

    char letra;

    printf("Digite uma letra maiuscula: \n");
    scanf(" %c", &letra);

    printf("%c", letra + 32);

    return 0;
}