#include <stdio.h>
#include <stdlib.h>

/* Faça um programa que leia um vetor de oito posições. Em seguida, leia também dois valores X e Y quaisquer correspondentes 
a duas posições no vetor. Seu programa deverá exibir a soma dos valores encontrados nas respectivas posições X e Y.

In English: Create a program that reads an eight-position array. Then, read also two any X and Y values corresponding to two
positions in the array. Your program must display the sum of the two values found in the respective X and Y position. */

int main(){

    float vector[8];
    float x;
    float y;
    float sum = 0;

    for (int i = 0; i < 8; i++){
        printf("Enter the value of the position %d of the vector: \n", i);
        scanf("%f", &vector[i]);
    }

    printf("Enter the value of x corresponding of any value in the array: \n");
    scanf("%f", &x);

    printf("Enter any value to y corresponding of any value in the array: \n");
    scanf("%f", &y);

    for (int i = 0; i < 8; i++)
        if (vector[i] == x || vector[i] == y)
            sum += vector[i];

    printf("The sum of x and y is: %f \n", sum);
    
    return 0;
}