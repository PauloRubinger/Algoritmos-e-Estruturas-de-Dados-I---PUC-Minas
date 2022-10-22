#include <stdio.h>
#include <stdlib.h>

/* Elabore uma função que receba como parâmetro um valor inteiro n e gere como saída n
linhas com pontos de exclamação, conforme o exemplo a seguir, em que usamos n = 5:
!
!!
!!!
!!!!
!!!!!           */

void excGenerator(int n){

    int sumOfTheLine = 0;
    int lineIndex = 1;

    while (lineIndex <= n){
        printf("!");
        sumOfTheLine++;
        
        if (sumOfTheLine == lineIndex){
            printf("\n");
            lineIndex++;
            sumOfTheLine = 0;
        }
    }
}

int main(){

    int n;
    printf("Enter the number of lines: \n");
    scanf("%d", &n);

    excGenerator(n);

    return 0;
}
