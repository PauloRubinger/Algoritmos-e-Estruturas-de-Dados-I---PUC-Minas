#include <stdio.h>
#include <stdlib.h>

/* Escreva uma função recursiva que calcule a sequência dada por: 
1, se n = 1
2, se n = 2
2f(n - 1) + 3f(n - 2), se n > 2 */

int seq(int n){

    if (n < 1)
        return -1;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else
        return 2*seq(n - 1) + 3*seq(n - 2);
}

int main(){

    int n;
    int result;

    printf("Enter the value of N: \n");
    scanf("%d", &n);

    result = seq(n);
    if (result == -1)
        printf("** Invalid parameter ** \n");
    else
        printf("The result is %d \n", result);

    return 0;
}