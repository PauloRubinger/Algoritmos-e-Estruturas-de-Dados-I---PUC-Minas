#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Calcular e imprimir na tela uma matriz de tamanho 10 × 10, em que seus
elementos são da forma:
A[i][j] = 2i + 7j–2 se i < j
A[i][j] = 3i^2 –1 se i = j
A[i][j] = 4i^3 + 5j^2 + 1 se i > j */

double **allocMatriz(int rows, int columns){

    double **p;

    if (rows < 1 || columns < 1){
        printf("** Invalid parameters ** \n");
        exit(1);
    }

    p = (double**)calloc(5,sizeof(double));
    if (p == NULL){
        printf("** Could not allocate memory ** \n");
        exit(1);
    }

    for (int i = 0; i < rows; i++){
        p[i] = (double*)calloc(columns, sizeof(double));
        if (p[i] == NULL){
            printf("** Could not allocate memory ** \n");
            exit(1);
        }
    }
    return (p);
}

void fillMatriz(double **matriz, int rows, int columns){

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            if (i < j)
                matriz[i][j] = 2*i + 7*j - 2;
            else if (i == j)
                matriz[i][j] = 3*pow(i,2) - 1;
            else
                matriz[i][j] = 4*pow(i,3) + 5*pow(j,2) + 1;
}

void printMatriz(double **matriz, int rows, int columns){

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++)
            printf("%f ", matriz[i][j]);
        printf("\n");
    }
}

void freeMatriz(double **matriz, int rows){

    if (matriz == NULL)
        return;

    for (int i = 0; i < rows; i++)
        free(matriz[i]);
    
    free(matriz);
}

int main(){

    int rows = 10;
    int columns = 10;
    double **matriz = allocMatriz(rows, columns);

    fillMatriz(matriz, rows, columns);
    printMatriz(matriz, rows, columns);
    freeMatriz(matriz, rows);

    return 0;
}