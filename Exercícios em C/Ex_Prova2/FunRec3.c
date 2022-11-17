#include <stdio.h>
#include <stdlib.h>

/* Faça uma função recursiva que receba um número N e retorne o N-ésimo número de Pell. Este é dado por: 
0,                    se n = 0
1,                    se n = 1
2f(n - 1) + f(n - 2), se n >= 2 */

int nPell(int n){

    if (n < 0)
        return -1;
    else if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return 2*nPell(n - 1) + nPell(n - 2);

}

int main(){

    int n; //enésimo número de Pell
    int result;

    printf("Enter the value of N: \n");
    scanf("%d", &n);

    result = nPell(n);
    if (result == -1)
        printf("** Invalid parameters ** \n");
    else
        printf("The result is %d \n", result);

    return 0;
}