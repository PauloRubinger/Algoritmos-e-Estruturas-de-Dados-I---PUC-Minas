#include <stdio.h>
#include <stdlib.h>

/* Crie um programa que leia do teclado seis valores inteiros e em seguida mostre na tela os valores lidos na ordem inversa.

In English: Create a program that reads from the keyboard six integer numbers then show them in the reverse order on the screen */

void readVector(int *vector, int n){

    printf("Enter 6 integer number: \n");

    for (int i = 0; i < n; i++)
        scanf("%d", &vector[i]);
}

void printVector(int *vector, int n){

    for (int i = n - 1; i >= 0; i--)
        printf("[%d]", vector[i]);
}

int main(){

    int n = 6;
    int vector[n];

    readVector(vector, n);
    printVector(vector, n);

    return 0;
}