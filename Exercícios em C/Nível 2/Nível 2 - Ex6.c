#include <stdio.h>
#include <stdlib.h>

/* Escreva um programa que leia um número inteiro positivo N e em seguida imprima N linhas
do chamado triângulo de Floyd:
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
16 17 18 19 20 21 */

int main(){

    int num_de_linhas = 0; // escolhidas pelo usuário
    int contagem_de_linhas = 1; // para definir onde o loop se encerra
    int indice_da_linha = 0; // para cálculo
    int soma_da_linha = 0; // para cálculo 

    printf("Digite o numero de linhas que deseja do triangulo de Floyd: \n");
    scanf("%d", &num_de_linhas);

    if (num_de_linhas == 1)
        printf("1");
    else{
        for (int j = 1; contagem_de_linhas < num_de_linhas ; j++){
            printf("%d ", j);
            soma_da_linha += j;
            if (j == 1){
                printf("\n");
                indice_da_linha = 2;
                soma_da_linha = 0;
            }
            if (soma_da_linha == (indice_da_linha*((indice_da_linha*indice_da_linha)+1)/2)){
                printf("\n");
                contagem_de_linhas++;
                indice_da_linha++;
                soma_da_linha = 0;
            }
        }
    }

    return 0;
}