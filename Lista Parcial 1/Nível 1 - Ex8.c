#include <stdio.h>
#include <stdlib.h>

/* Usando o comando switch, faça um programa que receba a altura e o sexo de uma pessoa e
calcule e mostre seu peso ideal, utilizando as seguintes fórmulas (em que “h” corresponde à altura):
• Homens: (72,7 * h) – 58
• Mulheres: (62,1 * h) – 44,7 */

int main(){

    float altura;
    char genero;

    printf("Digite sua altura em metros: \n");
    scanf("%f", &altura);
    printf("Digite o seu genero com 'f' para feminino e 'm' para masculino: \n");
    scanf(" %c", &genero);

    switch (genero)
    {
    case 'f':
        printf("O seu peso ideal e: %.2f", ((62.1*altura) - 44.7));
        break;
    case 'F':
        printf("O seu peso ideal e: %.2f", ((62.1*altura) - 44.7));
        break;
    case 'm':
        printf("o seu peso ideal e %.2f", ((72.7*altura) - 58));
    case 'M':
        printf("o seu peso ideal e %.2f", ((72.7*altura) - 58));
    default:
        break;
    }

    return 0;
}