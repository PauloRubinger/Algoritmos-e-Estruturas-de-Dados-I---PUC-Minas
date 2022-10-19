#include <stdio.h>
#include <stdlib.h>

// Escreva uma função que receba por parâmetro dois números e retorne por valor o maior deles.

void compareNumbers(float number1, float number2){
    
    if (number1 > number2)
        printf("O maior numero e o %.2f \n", number1);
    else
        printf("O maior numero e o %.2f \n", number2);
}

int main(){

    float number1 = 0;
    float number2 = 0;
    float retorno;

    printf("Digite o primeiro numero: \n");
    scanf("%f", &number1);
    printf("Digite o segundo numero: \n");
    scanf("%f", &number2);

    compareNumbers(number1, number2);

    return 0;
}