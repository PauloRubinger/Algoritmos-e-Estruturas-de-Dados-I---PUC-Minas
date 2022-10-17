#include <stdio.h>
#include <stdlib.h>

/* A importância de R$780.000,00 será dividida entre três ganhadores de um concurso, sendo:
i) O primeiro ganhador receberá 46% do total.
ii) O segundo receberá 32% do total.
iii) O terceiro receberá o restante.
Calcule e imprima a quantia recebida por cada um dos ganhadores */

int main(){

    printf("O primeiro ganhador recebera R$%.2f, o segundo recebera R$%.2f\
 e o terceiro recebera R$%.2f \n", 780000*0.46, 780000*0.32, 780000*0.22);

    return 0;
}