#include <stdio.h>
#include <stdlib.h>

// Crie uma função recursiva que calcule um somatório de i, com i começando em 1 e indo até N.

int summation(int sum, int i, int number){
    
    if (i > number)
        return sum;
    else{
        sum += i;
        i++;
        summation(sum, i, number);
    }
}

int main(){

    int i = 1;
    int lastNumber;
    int sum = 0;
    int result;

    printf("Enter the value of the last number of the sequence: \n");
    scanf("%d", &lastNumber);

    result = summation(sum, i, lastNumber);
    printf("The result is: %d \n", result);

    return 0;
}