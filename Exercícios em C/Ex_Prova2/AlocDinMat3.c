#include <stdio.h>
#include <stdlib.h>

/* Fa¸ca um programa que leia uma matriz de tamanho 5 × 5. Calcule e imprima a
soma dos elementos dessa matriz que est˜ao acima da diagonal principal. */

float **allocMatriz(int rows, int columns){

    float **p;

    if (rows < 1 || columns < 1){
        printf("** Invalid parameters ** \n");
        exit(1);
    }

    p = (float**)calloc(5,sizeof(float));
    if (p == NULL){
        printf("** Could not allocate memory ** \n");
        exit(1);
    }

    for (int i = 0; i < rows; i++){
        p[i] = (float*)calloc(columns, sizeof(float));
        if (p[i] == NULL){
            printf("** Could not allocate memory ** \n");
            exit(1);
        }
    }
    return (p);
}

void readMatriz(float **matriz, int rows, int columns){

    for (int i = 0; i < rows; i++)
        for(int j = 0; j < columns; j++){
            printf("Enter the value of the element [%d][%d]: \n", i, j);
            scanf("%f", &matriz[i][j]);
        }
}

void printMatriz(float **matriz, int rows, int columns){

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++)
            printf("%f ", matriz[i][j]);
        printf("\n");
    }
}

void sumAboveMainDiagonal(float **matriz, int rows, int columns){

    float sum = 0;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            if (j > i)
                sum += matriz[i][j];

    printf("The sum of the elements above the main diagonal is: %f \n", sum);

}

void freeMatriz(float **matriz, int rows){

    if (matriz == NULL)
        return;

    for (int i = 0; i < rows; i++)
        free(matriz[i]);
    
    free(matriz);
}

int main(){

    int rows = 5;
    int columns = 5;
    float **matriz = allocMatriz(rows, columns);   
    readMatriz(matriz, rows, columns);
    printMatriz(matriz, rows, columns);
    sumAboveMainDiagonal(matriz, rows, columns);
    freeMatriz(matriz, rows);

    return 0;
}