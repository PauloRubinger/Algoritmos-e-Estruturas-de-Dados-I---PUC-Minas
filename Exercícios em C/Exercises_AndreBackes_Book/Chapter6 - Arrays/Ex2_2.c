#include <stdio.h>
#include <stdlib.h>

/* Faça um programa que leia uma matriz de tamanho 4 × 4. Imprima na tela o maior valor contido nessa matriz 
e a sua localização (linha e coluna).

In English: Create a program that reads an array of size 4 x 4. Print on the screen the highest value contained in this array
and its localization (row and column). */

void readArray(float arrayA[4][4], int num_rows, int num_col){

    for (int i = 0; i < num_rows; i++)
        for (int j = 0; j < num_col; j++){
            printf("Enter the value of A%d%d: \n", i, j);
            scanf("%f", &arrayA[i][j]);
        }
}

void printArray(float arrayA[4][4], int num_rows, int num_col){

    for (int i = 0; i < num_rows; i++){
        for (int j = 0; j < num_col; j++)
            printf("%f ", arrayA[i][j]);
        printf("\n");
    }
}

void calcHighestValue(float arrayA[4][4], int num_rows, int num_col){

    float highestValue = 0;

    for (int i = 0; i < num_rows; i++)
        for (int j = 0; j < num_col; j++)
            if (arrayA[i][j] > highestValue)
                highestValue = arrayA[i][j];

    printf("\nThe highest value of this array is %f \n", highestValue);
    
}

int main(){

    int num_rows = 4;
    int num_col = 4;
    float arrayA[num_rows][num_col];

    readArray(arrayA, num_rows, num_col);
    printArray(arrayA, num_rows, num_col);
    calcHighestValue(arrayA, num_rows, num_col);

    return 0;
}