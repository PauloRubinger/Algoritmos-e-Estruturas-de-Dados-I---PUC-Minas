#include <stdio.h>
#include <stdlib.h>

/* Crie uma estrutura capaz de armazenar o nome e a data de nascimento de uma pessoa. Agora, escreva um programa que 
leia os dados de seis pessoas. Imprima todos os dados lidos. Calcule e exiba os nomes da pessoa mais nova e da mais velha. */

typedef struct {

    char nome[50];
    int idade;

}cadastro;

int main(){

    cadastro c[6];
    int maisVelho = 0;
    int indiceDoMaisVelho;

    for (int i = 0; i < 6; i++){
        printf("Digite o nome da %d pessoa: \n", i + 1);
        scanf("%s", c[i].nome);
        printf("Digite a idade da %d pessoa \n", i + 1);
        scanf("%d", &c[i].idade);
    }

    for (int i = 0; i < 6; i++){
        printf("%s \n", c[i].nome);
        printf("%d \n", c[i].idade);
    }

    for (int i = 0; i < 6; i++){
        if (c[i].idade > maisVelho){
            maisVelho = c[i].idade;
            indiceDoMaisVelho = i;
        }
    }

    printf("A pessoa mais velha dessa lista e %s, com %d anos \n", c[indiceDoMaisVelho].nome, maisVelho);

    return 0;
}