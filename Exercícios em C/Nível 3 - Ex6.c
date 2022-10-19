#include <stdio.h>
#include <stdlib.h>

/* Elabore uma função que receba três números inteiros como parâmetro, representando horas,
minutos e segundos. A função deve retornar por referencia esse horário convertido em
segundos. */

int convertToSeconds(int *hours, int *minutes, int *seconds){

    printf("Enter the value in hours: \n");
    scanf("%d", &*hours);
    printf("Enter the value in minutes: \n");
    scanf("%d", &*minutes);
    printf("Enter the value in seconds: \n");
    scanf("%d", &*seconds);

    return *hours*3600 + *minutes*60 + *seconds;

}

int main(){

    int hours = 0;
    int minutes = 0;
    int seconds = 0;
    int result;

    result = convertToSeconds(&hours, &minutes, &seconds);
    printf("\n%d", result);

    return 0;
}