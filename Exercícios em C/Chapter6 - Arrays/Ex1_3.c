#include <stdio.h>
#include <stdlib.h>

/* Faça um programa que leia cinco valores e os armazene em um vetor. Em seguida, mostre todos os valores lidos juntamente 
com a média dos valores.
In English: Create a program that reads five values and keep them in an array. After that, show all the read values on the screen 
along with the average of the values */

void readVector(float *vector, int n){

    printf("Enter the five values of the array: \n");

    for (int i = 0; i < n; i++)
        scanf("%f", &vector[i]);
}

void printVector(float *vector, int n){

    float sum = 0;

    for (int i = 0; i < n; i++){
        printf("[%f]", vector[i]);
        sum += vector[i];
    }

    printf("\nThe average of the values is: %f \n", sum/n);
}

int main(){

    int n = 5;
    float vector[n];

    readVector(vector, n);
    printVector(vector, n);

    return 0;
}