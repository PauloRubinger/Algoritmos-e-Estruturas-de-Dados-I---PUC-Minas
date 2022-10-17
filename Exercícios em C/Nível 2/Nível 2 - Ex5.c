#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Em matemática, o número harmônico designado por Hn define-se como o enésimo termo da
série harmônica. Ou seja: Hn = 1 + 1/2 + 1/3 + 1/4 + 1/5 + ... + 1/n 
Apresente um programa que calcule o valor de qualquer Hn */

int main(){

    int enesimo_termo = 0;
    float serie_harmonica = 0.0;

    printf("Digite um numero para descobrir qual o valor da serie harmonica para o n igual ao valor que escolheu: \n");
    scanf("%d", &enesimo_termo);

    for (int i = 1; i <= enesimo_termo; i++){
        serie_harmonica = serie_harmonica + pow(i,-1);
    }
    printf("O valor da serie harmonica para n = %d e: %.5f \n", enesimo_termo, serie_harmonica);

    return 0;
}