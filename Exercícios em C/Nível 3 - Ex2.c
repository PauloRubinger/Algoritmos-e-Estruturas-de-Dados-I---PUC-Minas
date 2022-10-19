#include <stdio.h>
#include <stdlib.h>

// Escreva uma função que receba por parâmetro dois números e retorne por referência o maior deles.

float compareNumbers(float *number1, float *number2){
    
    if (*number1 > *number2)
        return *number1;
    else
        return *number2;
}

int main(){

    float number1 = 0;
    float number2 = 0;
    float retorno;

    printf("Digite o primeiro numero: \n");
    scanf("%f", &number1);
    printf("Digite o segundo numero: \n");
    scanf("%f", &number2);

    retorno = compareNumbers(&number1, &number2);
    printf("O maior numero e: %f", retorno);

    return 0;
}