#include <stdio.h>
#include <stdlib.h>

/* Faça um programa que receba do usuário dois arrays, A e B, com 10 números inteiros cada. Crie um novo array C 
calculando C = A − B. Mostre na tela os dados do array C.

In English: Write a program that receives from the user two arrays, A and B, with 10 integer numbers each. Create a new array C
so that C = A - B. Display the C data. */

void readVectors(int *vectorA, int *vectorB, int n){

    for (int i = 0; i < n; i++){
        printf("Enter the value of the position %d of the vector A: \n", i);
        scanf("%d", &vectorA[i]);
    }
    
    for (int i = 0; i < n; i++){
        printf("Enter the value of the position %d of the vector B: \n", i);
        scanf("%d", &vectorB[i]);
    }
}

void printVectors(int *vectorA, int *vectorB, int n){

    printf("A:");
    for (int i = 0; i < n; i++)
        printf("[%d]", vectorA[i]);

    printf("\nB:");

    for (int i = 0; i < n; i++)
        printf("[%d]", vectorB[i]);

    printf("\nC:");
}

void calculateC(int *vectorA, int *vectorB, int n){

    int vectorC[n];
    for (int i = 0; i < n; i++){
        vectorC[i] = vectorA[i] - vectorB[i];
        printf("[%d]", vectorC[i]);
    }
}

int main(){

    int n = 10;
    int vectorA[n];
    int vectorB[n];

    readVectors(vectorA, vectorB, n);
    printVectors(vectorA, vectorB, n);
    calculateC(vectorA, vectorB, n);

    return 0;
}