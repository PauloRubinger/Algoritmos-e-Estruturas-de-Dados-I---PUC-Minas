#include <stdio.h>
#include <stdlib.h>

/* Faça um programa que receba do usuário um vetor X com 10 posições. Em seguida deverão ser impressos o maior e o menor elemento 
desse vetor.

In English: Create a program that receives from the user a 10-position vector. Then show on the screen the biggest and the smallest
element of this vector */

void readVector(float *x, int n){

    for (int i = 0; i < n; i++){
        printf("Enter the value of the %d position of the vector: \n", i);
        scanf("%f", &x[i]);
    }
}

void printVector(float *x, int n){
    
    for (int i = 0; i < n; i++)
        printf("[%f]", x[i]);
}

void compareNumbers(float *x, int n){

    float biggestNumber = 0;
    float smallestNumber = 9999999999;

    for (int i = 0; i < n; i++){
        if (x[i] > biggestNumber)
            biggestNumber = x[i];
        if (x[i] < smallestNumber)
            smallestNumber = x[i];
    }

    printf("\nThe biggest and the smallest number of the vector X is: %f and %f respectively \n", biggestNumber, smallestNumber);
}

int main(){

    int n = 10;
    float x[n];

    readVector(x, n);
    printVector(x, n);
    compareNumbers(x, n);

    return 0;
}