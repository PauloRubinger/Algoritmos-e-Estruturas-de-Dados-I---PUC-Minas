#include <stdio.h>
#include <stdlib.h>

/* Escreva um programa que leia certa quantidade de números, imprima o maior deles e
quantas vezes o maior número foi lido. A quantidade de números a serem lidos deve ser
fornecida pelo usuário. */

int main(){

    int qtd_num;
    float numero_lido;
    float maior_numero = -999999.0;
    int qtd_maior_numero = 0;

    printf("Digite a quantidade de numeros a serem lidos: \n");
    scanf("%d", &qtd_num);

    for (int i = 0; i < qtd_num; i++){
        printf("Digite um numero: \n");
        scanf("%f", &numero_lido);
        if (numero_lido > maior_numero){
            maior_numero = numero_lido;
            qtd_maior_numero = 1;
            }
        else if (!(numero_lido < maior_numero)) // Funciona também com o numero_lido == maior_numero, porém quis testar o '!'
                qtd_maior_numero++;             
    }

    printf("O maior numero lido foi o %6.2f e ele foi lido %d vez(es) \n", maior_numero, qtd_maior_numero);

    return 0;
}