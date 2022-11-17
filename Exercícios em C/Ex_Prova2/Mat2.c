#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Gere uma matriz 3x3 de números inteiros (não precisa ler do teclado os valores).
Calcule a variância de tais valores e o desvio padrão */

void imprimeMatriz(int matriz[3][3]){

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++)
            printf("%d ", matriz[i][j]);
        printf("\n");
    }
}

float calculaMedia(int matriz[3][3]){

    float soma = 0;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            soma += matriz[i][j];

    return soma/9;
}

float calculaVariancia(int matriz[3][3], float media){

    float numerador = 0;
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            numerador += pow((matriz[i][j] - media),2);
        }
    }
    printf("%f", numerador);
    return numerador/(9-1);
}

float calculaDP(int matriz[3][3], float variancia){

    return sqrt(variancia);
}

int main(){

    int matriz[3][3] = {{3,5,8},{1,3,2},{5,10,7}};
    float media;
    float variancia;
    float desvioPadrao;

    imprimeMatriz(matriz);
    media = calculaMedia(matriz);
    printf("O valor da media e: %f \n", media);
    variancia = calculaVariancia(matriz, media);
    printf("O valor da variancia e: %f \n", variancia);
    desvioPadrao = calculaDP(matriz, variancia);
    printf("O desvio padrao e: %f \n", desvioPadrao);

}