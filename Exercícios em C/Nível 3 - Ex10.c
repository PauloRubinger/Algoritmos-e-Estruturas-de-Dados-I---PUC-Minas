#include <stdio.h>
#include <stdlib.h>

/* Elabore uma função que receba como parâmetro um valor inteiro n e gere como saída um
triângulo lateral formado por asteriscos conforme o exemplo a seguir, em que usamos n = 4:
*
**
***
****
***
**
*       
                */

void asterisksGenerator(int n){

    int lineIndex = 1;
    int sumOfTheLine = 0;

    while (lineIndex <= n){

        printf("*");
        sumOfTheLine++;

        if (sumOfTheLine == lineIndex){
            
            printf("\n");
            lineIndex++;
            sumOfTheLine = 0;
        }
    }

    lineIndex = n - 1;

    while (lineIndex >= 1){

        printf("*");
        sumOfTheLine++;

        if (sumOfTheLine == lineIndex){

            printf("\n");
            lineIndex--;
            sumOfTheLine = 0;
        }
    }
}

int main(){

    int n;

    printf("Enter the value of n: \n");
    scanf("%d", &n);

    asterisksGenerator(n);

    return 0;
}