#include <stdio.h>
#include <stdlib.h>

/* Escreva uma função que receba por parâmetros dois valores inteiros x e y e calcule e retorne
o resultado de x y para o programa principal. Não use nenhuma função (biblioteca) pronta
para isso. O valor deve ser retornado por referencia para função main e impresso. 
x^y without using the library math.h */

float exponential(int *x, int *y){

    printf("Enter the value of the base: \n");
    scanf("%d", &*x);
    printf("Enter the value of the exponent: \n");
    scanf("%d", &*y);

    float result = 1.0;
    if (*y == 0)
        return result;
    else if (*y > 0){
        for (int i = 1; i <= *y; i++)
            result = result*(*x);

        return result;
    }
    else{
        for (int i = 1; i <= -(*y); i++)
            result = result*((float)1/(*x));
            
        return result;
    }
}

int main(){

    int x = 3;
    int y = -2;
    float result;

    result = exponential(&x,&y);
    printf("The value of %d to the power of %d is: %f \n", x, y, result);

    return 0;
}