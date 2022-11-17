#include <stdio.h>
#include <stdlib.h>

/* Faça um programa que preencha um vetor com 10 números reais. Em seguida, calcule e mostre na tela a quantidade de números 
negativos e a soma dos números positivos desse vetor.

In English: Create a program that fills a vector with 10 float numbers. Then, calculate and show on the screen the amount of
negative numbers and the sum of the positive numbers of this vector. */

void readVector(float *vector, int n){

    for (int i = 0; i < n; i++){
        printf("Enter the value of the %d position of the vector: \n", i);
        scanf("%f", &vector[i]);
    }
}

void printVector(float *vector, int n){

    for (int i = 0; i < n; i++)
        printf("[%f]", vector[i]);
}

void calculateVector(float *vector, int n){

    int qtyNegativeNumbers = 0;
    float sumPositiveNumbers = 0;

    for (int i = 0; i < n; i++){
        if (vector[i] < 0)
            qtyNegativeNumbers++;
        else if (vector[i] > 0)
            sumPositiveNumbers += vector[i];
    }

    printf("\nThe amount of negative numbers is: %d \n", qtyNegativeNumbers);
    printf("The sum of positive numbers is: %.2f \n", sumPositiveNumbers);

}

int main(){

    int n = 10;
    float vector[n];

    readVector(vector, n);
    printVector(vector, n);
    calculateVector(vector, n);

    return 0;
}