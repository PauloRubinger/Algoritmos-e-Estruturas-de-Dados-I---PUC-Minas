#include <stdio.h>
#include <stdlib.h>

/* Faça uma função recursiva que receba um número inteiro positivo N e imprima todos os números naturais de 0 até N
em ordem crescente */

void ascendingOrder(int number, int i){

    printf("%d ", i);

    if (i == number)
        return;
    else{
        i++;
        ascendingOrder(number, i);
    }
}

int main(){

    int number;
    int i = 0;

    printf("Enter the value of N: \n");
    scanf("%d", &number);

    ascendingOrder(number, i);

    return 0;
}