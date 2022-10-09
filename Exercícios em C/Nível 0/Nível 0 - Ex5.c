#include <stdio.h>
#include <stdlib.h>

/* Escreva um programa que leia três variáveis: char, int e float. Em seguida, imprimaas de três maneiras diferentes: separadas por 
espaços, por uma tabulação horizontal e uma em cada linha. Use um único comando printf() para cada operação de escrita
das três variáveis. */

int main(){

    char palavra[20];
    int inteiro;
    float real;

    printf("Digite uma palavra: \n");
    fgets(palavra, 20, stdin);
    printf("Digite um numero inteiro: \n");
    scanf("%d", &inteiro);
    printf("Digite um numero real: \n");
    scanf("%f", &real);

    printf("%s %d %f\n", palavra, inteiro, real);
    printf("%s\t%d\t%f\n", palavra, inteiro, real);
    printf("%s\n%d\n%f\n", palavra, inteiro, real);

    return 0;
}