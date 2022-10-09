#include <stdio.h>
#include <stdlib.h>

// Faça um programa que leia dois números e mostre qual deles é o maior.

int main(){

    float num1;
    float num2;

    printf("Digite o primeiro numero: \n");
    scanf("%f", &num1);
    printf("Digite o segundo numero \n");
    scanf("%f", &num2);

    if (num1 > num2)
        printf("O maior numero e %.2f \n", num1);
    else
        printf("O maior numero e %.2f \n", num2);

    return 0;
}