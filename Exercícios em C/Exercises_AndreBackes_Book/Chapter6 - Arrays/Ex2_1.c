#include <stdio.h>
#include <stdlib.h>

/* Faça um programa que leia uma matriz de tamanho 3 × 3. Imprima na tela o menor valor contido nessa matriz. 

In English: Write a program that reads an array of size 3 x 3. Print on the screen the lowest value contained in this array. */

void readArray(float arrayA[][3]){

    for (int row = 0; row < 3; row++)
        for (int column = 0; column < 3; column++){
            printf("Enter the value of the element A%d%d: \n", row, column);
            scanf("%f", &arrayA[row][column]);
        }
}

void printArray(float arrayA[][3]){

    for (int row = 0; row < 3; row++){
        for (int column = 0; column < 3; column++)
            printf("%f ", arrayA[row][column]);
        printf("\n");
    }
}

void calcLowestValue(float arrayA[][3]){

    float lowestValue = 9999999999;

    for (int row = 0; row < 3; row++)
        for (int column = 0; column < 3; column++)
            if (arrayA[row][column] < lowestValue)
                lowestValue = arrayA[row][column];
    
    printf("\nThe lowest value of this array is: %f \n", lowestValue);

}

int main(){

    float arrayA[3][3];
    
    readArray(arrayA);
    printArray(arrayA);
    calcLowestValue(arrayA);

    return 0;
}