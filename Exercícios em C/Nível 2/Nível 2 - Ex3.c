#include <stdio.h>
#include <stdlib.h>

// Faça um programa que leia 10 inteiros positivos, ignorando não positivos, e imprima sua média.

int main(){

    float soma = 0;
    int numeros_lidos = 0;

    
        for (int i = 0; i < 10; i++){
            printf("Digite um numero inteiro: \n");
            scanf("%d", &numeros_lidos);
            if (numeros_lidos >= 0)
                soma = soma + numeros_lidos;
            else
                i--;
        }
    
            printf("A media dos numeros lidos e: %.2f \n", (soma/10));

    return 0;
}