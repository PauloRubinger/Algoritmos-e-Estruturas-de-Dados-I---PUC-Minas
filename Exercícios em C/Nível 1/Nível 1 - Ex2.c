#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141592

/* Leia o valor do raio de um círculo. Calcule e imprima a área do círculo correspondente. A
área do círculo é A = π * raio 2 , sendo π = 3.141592. */

int main(){

    float raio;
    float area;
    
    printf("Digite o valor do raio do circulo: \n");
    scanf("%f", &raio);

    area = PI*(pow(raio,2));
    
    printf("A area do circulo e: %f \n", area);

    return 0;
}