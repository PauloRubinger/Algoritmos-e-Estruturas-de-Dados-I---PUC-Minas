#include <stdio.h>
#include <stdlib.h>

/* Faça um programa que possua um array de nome A que armazene seis números inteiros. O programa deve executar os seguintes passos:
a) Atribua os seguintes valores a esse array: 1, 0, 5, −2, −5, 7.
b) Armazene em uma variável a soma dos valores das posições A[0], A[1] e A[5] do array e mostre na tela essa soma.
c) Modifique o array na posição 4, atribuindo a essa posição o valor 100.
d) Mostre na tela cada valor do array A, um em cada linha.

In English: Create a program with an array named A that store six integer numbers. The program must execute the following steps:
a) Assign the following values to this array: 1, 0, 5, -2, -5, 7.
b) Store in a variable the sum of the values of the positios A[0], A[1] and A[5] of the array and show the sum on the screen.
c) Modify the array at position 4, assigning the value 100 to this position.
d) Show on the screen each value of the array A, one per row */

int main(){

    int a[6] = {1, 0, 5, -2, -5, 7};
    int sum = a[0] + a[1] + a[5];
    a[4] = 100;

    printf("%d \n", sum);

    for (int i = 0; i < 6; i++)
        printf("[%d]\n", a[i]);

    return 0;
}