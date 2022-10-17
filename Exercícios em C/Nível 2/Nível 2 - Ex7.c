#include <stdio.h>
#include <stdlib.h>

/*Faça um programa que calcule e escreva o valor de S:
S = 1/1 + 3/2 + 5/3 + 7/4 + ... + 99/50 */

int main(){

    double valor_S = 0;
    int denominador = 1;

    for (int i = 1; i <= 99; i = i + 2, denominador++)
        valor_S += (double)i/denominador;
        
    printf("O valor de S e: %.9f", valor_S);

    return 0;
}