#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Faça um programa que leia um valor inteiro e positivo N, calcule o mostre o valor E, conforme a fórmula a seguir: 
E = 1/1! + 1/2! + 1/3! + ... + 1/N! */

int main(){

    int enesimo_termo;
    double fatorial = 1;
    double valor_E = 0;

    printf("Digite o enesimo termo da sequencia para descobrir o valor da serie: \n");
    scanf("%d", &enesimo_termo);

    for (int i = 1; i <= enesimo_termo; i++){
        fatorial = fatorial*i;
        valor_E = valor_E + pow(fatorial,-1);
    }    

    printf("O valor de E e: %lf", valor_E);

    return 0;
}