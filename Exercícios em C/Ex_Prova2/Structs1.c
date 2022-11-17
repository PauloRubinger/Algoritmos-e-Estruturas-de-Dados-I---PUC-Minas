#include <stdio.h>
#include <stdlib.h>

/* Implemente um programa que leia o nome, a idade e o endereço de uma pessoa e armazene esses dados em uma estrutura. 
Em seguida, imprima na tela os dados da estrutura lida. */

typedef struct {

    char nome[50];
    int idade;
    char endereco[150];

}cadastro;

int main(){

    cadastro c1 = {"Joao", 23, "Rua Alegre, 123"};
    printf("O nome e %s, a idade e %d e o endereco e %s \n", c1.nome, c1.idade, c1.endereco);
    
    return 0;
}
