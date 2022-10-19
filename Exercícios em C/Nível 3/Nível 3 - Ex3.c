#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926535

/* Escreva uma função para o cálculo do volume de uma esfera, V = 4/3π * r 3 ,em que valor
do raio r deve ser passado por parâmetro. O valor deve ser retornado por valor para função
main e impresso */

float calcVolume(float radius){

return ((4*PI/3)*pow(radius,3));

}

int main(){

    float radius;
    float volume;

    printf("Enter the sphere radius value: \n");
    scanf("%f", &radius);

    volume = calcVolume(radius);
    printf("The volume of the sphere is %f \n", volume);

    return 0;
}