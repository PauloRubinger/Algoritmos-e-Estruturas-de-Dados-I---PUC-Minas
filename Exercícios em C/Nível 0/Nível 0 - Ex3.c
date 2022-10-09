#include <stdio.h>
#include <stdlib.h>

    /* Faça um programa que leia dois números inteiros e depois os imprima na ordem inversa em que eles foram lidos. */

int main(){

    int num1;
    int num2;
    int a;
    int b;

    printf("Digite um numero inteiro: \n");
    scanf("%d",&num1);
    printf("Digite outro numero inteiro \n");
    scanf("%d",&num2);

    a = num2;
    b = num1;

    printf("Os numeros sao: %d e %d", a,b);

    return 0;
}