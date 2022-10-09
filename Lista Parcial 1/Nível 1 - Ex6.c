#include <stdio.h>
#include <stdlib.h>

/* Faça um programa que leia a altura e o peso de uma pessoa. De acordo com a tabela a
seguir, verifique e mostre qual a classificação dessa pessoa.
Altura (m)                  Peso (kg)
                            Até 60      60-90       Acima de 90
Menor do que 1,20             A           D              G
1,20 - 1,70                   B           E              H
Maior do que 1,70             C           F              I          */

int main(){

    float altura;
    float peso;

    printf("Qual a altura em metros? \n");
    scanf("%f", &altura);
    printf("Qual o peso em kg? \n");
    scanf("%f", &peso);

    if (altura < 1.20)
        if (peso < 60)
            printf("A categoria desta pessoa e A \n");
        else if (peso >= 60 && peso < 90)
            printf("A categoria desta pessoa e D \n");
        else
            printf("A categoria desta pessoa e G \n");
    else if (altura >= 1.20 && altura < 1.70)
            if (peso < 60)
                printf("A categoria desta pessoa e B \n");
            else if (peso >= 60 && peso < 90)
                printf("A categoria desta pessoa e E \n");
            else
                printf("A categoria desta pessoa e H \n");
    else
        if (peso < 60)
            printf("A categoria desta pessoa e C \n");
        else if (peso >= 60 && peso < 90)
            printf("A categoria desta pessoa e F \n");
        else
            printf("A categoria desta pessoa e I \n");
    
    return 0;
}