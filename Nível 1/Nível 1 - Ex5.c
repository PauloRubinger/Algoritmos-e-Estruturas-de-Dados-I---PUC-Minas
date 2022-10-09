#include <stdio.h>
#include <stdlib.h>

/* Escreva um programa que, dada a idade de um nadador, o classifique em uma das seguintes
categorias: 
Categoria       Idade
Infantil A      5-7
Infantil B      8-10
Juvenil A       11-13
Juvenil B       14-17
Sênior          > 18 */

int main(){

    int idade_nadador;

    printf("Digite a idade do nadador: \n");
    scanf("%d", &idade_nadador);

    if (idade_nadador >= 5 && idade_nadador <= 7)
        printf("A categoria do nadador e Infantil A \n");
    else if (idade_nadador >= 8 && idade_nadador <= 10)
        printf("A categoria do nadador e Infantil B \n");
    else if (idade_nadador >= 11 && idade_nadador <= 13)
        printf("A categoria do nadador e Juvenil A \n");
    else if (idade_nadador >= 14 && idade_nadador <= 17)
        printf("A categoria do nadador e Juvenil B \n");
    else if (idade_nadador >= 18)
        printf("A categoria do nadador e Senior \n");

    return 0;
}