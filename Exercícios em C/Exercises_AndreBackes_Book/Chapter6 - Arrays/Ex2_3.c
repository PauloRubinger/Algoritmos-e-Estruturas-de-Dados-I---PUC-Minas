#include <stdio.h>
#include <stdlib.h>

/* Faça um programa que declare uma matriz de tamanho 5 × 5. Preencha com 1 a
diagonal principal e com 0 os demais elementos. Ao final, escreva a matriz obtida
na tela. 

In English: Create a program that declares an array of size 5 x 5. Fill with 1 to main diagonal and with 0 to the other 
elements. At the end, write the array obtained on the screen. */

void fillArray(float array[5][5], int rows, int columns){

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++)
            if (i == j)
                array[i][j] = 1;
            else
                array[i][j] = 0;
    }
}

void printArray(float arrayA[5][5], int rows, int columns){

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++)
            printf("%.2f ", arrayA[i][j]);
        printf("\n");
    }
}

int main(){

    int rows = 5;
    int columns = 5;
    float arrayA[rows][columns];

    fillArray(arrayA, rows, columns);
    printArray(arrayA, rows, columns);

    return 0;
}