#include <stdio.h>
#include <stdlib.h>

/*Elabore um programa que faça a leitura de vários números inteiros até que se digite um
número negativo. O programa tem de retornar o maior e o menor número lido.*/

int main(){

    int numero_lido = 0;
    int maior_numero = 0;
    int menor_numero = 9999999;

        while (numero_lido >= 0)
        {
            printf("Digite um numero inteiro: \n");
            scanf("%d", &numero_lido);
            if (numero_lido > maior_numero)
                maior_numero = numero_lido;
            if (numero_lido < menor_numero && numero_lido >= 0)
                menor_numero = numero_lido;
        }
        
        printf("O maior numero lido e: %d e o menor numero lido e %d", maior_numero, menor_numero);

    return 0;
}