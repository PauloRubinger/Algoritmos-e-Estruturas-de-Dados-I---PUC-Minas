#include <stdio.h>
#include <stdlib.h>

/* Escreva um programa que leia do teclado um vetor de 10 posições. Escreva na tela quantos valores pares foram armazenados
nesse vetor.

In English: Write a program that reads a ten-position array from the keyboard. Show on the screen how many even values were stored
in this array */

void readVector(int *vector, int n){

    for (int i = 0; i < n; i++){
        printf("Enter the value of the %d position of the vector: \n", i);
        scanf("%d", &vector[i]);
    }
}

void printVector(int *vector, int n){
    
    for (int i = 0; i < n; i++)
        printf("[%d]", vector[i]);
}

void evenVerify(int *vector, int n){

    int qtyEven = 0;

    for (int i = 0; i < n; i++)
        if (vector[i]%2 == 0)
            qtyEven++;
    
    printf("\nThe quantity of even numbers in this array is: %d \n", qtyEven);

}

int main (){

    int n = 10;
    int vector[n];

    readVector(vector, n);
    printVector(vector, n);
    evenVerify(vector, n);

    return 0;
}