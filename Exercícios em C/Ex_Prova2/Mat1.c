#include <stdio.h>
#include <stdlib.h>

/* Crie um programa que leia do teclado 9 valores inteiros, armazene em uma matriz 3x3, e em seguida mostra na tela os 
valores lidos em forma matricial */

void leMatriz(float matriz[3][3]){

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++){
            printf("Enter the value of matriz[%d][%d]: \n", i, j);
            scanf("%f", &matriz[i][j]);
        }
}

void imprimeMatriz(float matriz[3][3]){

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++)
            printf("%f ", matriz[i][j]);
        printf("\n");
    }
}

int main(){

    float matriz[3][3];

    leMatriz(matriz);
    imprimeMatriz(matriz);

    return 0;
}