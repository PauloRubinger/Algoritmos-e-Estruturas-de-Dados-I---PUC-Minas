#include <stdio.h>
#include <stdlib.h>

/* Leia uma matriz de tamanho 3 × 3. Em seguida, imprima a soma dos valores
contidos em sua diagonal principal. */

float** allocMatriz(int rows, int columns){

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
        for (int j = 0; j < columns; j++){
            printf("%f ", matriz[i][j]);
        }
        printf("\n");
    }
}

void sumMainDiagonal(float **matriz, int rows, int columns){

    float sum = 0;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++){
            if (i == j)
                sum += matriz[i][j];
        }
    printf("The sum of the elements of the main diagonal is: %f \n", sum);
}

void freeMatriz(float **matriz, int rows){

    if (matriz == NULL)
        return;

    for (int i = 0; i < rows; i++)
        free(matriz[i]);
    
    free(matriz);
}

int main(){

    int rows = 3;
    int columns = 3;
    float **matriz = allocMatriz(rows, columns);   
    readMatriz(matriz, rows, columns);
    printMatriz(matriz, rows, columns);
    sumMainDiagonal(matriz, rows, columns);
    freeMatriz(matriz, rows);

    return 0;
}