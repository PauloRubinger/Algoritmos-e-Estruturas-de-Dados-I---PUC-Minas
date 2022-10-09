#include <stdio.h>
#include <stdlib.h>

/* Leia quatro valores do tipo float. Calcule e exiba a média aritmética desses valores. */

int main(){

    float num1;
    float num2;
    float num3;
    float num4;

    printf("Digite o primeiro valor: \n");
    scanf("%f", &num1);
    printf("Digite o segundo valor: \n");
    scanf("%f", &num2);
    printf("Digite o terceiro valor: \n");
    scanf("%f", &num3);
    printf("Digite o quarto valor: \n");
    scanf("%f", &num4);

    printf("A media aritmetica dos quatro valores e: %.2f \n", ((num1+num2+num3+num4)/4));

    return 0;
}