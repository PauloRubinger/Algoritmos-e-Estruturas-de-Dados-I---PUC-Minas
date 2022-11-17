#include <stdio.h>
#include <stdlib.h>

/* Usando vetores, crie um programa que leia do teclado seis valores inteiros e em seguida mostra na tela os valores lidos

In English: By using arrays, create a program that reads from the keyboard six integer numbers then show them on the screen */


void readVector(int *vector, int n){

    printf("Enter 6 integer number: \n");
    
    for (int i = 0; i < n; i++)
        scanf("%d", &vector[i]);
}

void printVector(int *vector, int n){

    for (int i = 0; i < n; i++)
        printf("[%d]", vector[i]);
}

int main(){

    int n = 6;
    int vector[n];

    readVector(vector, n);
    printVector(vector, n);

    return 0;
}