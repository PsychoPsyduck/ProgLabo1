#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#define NUM_PEDIDOS 5

int main()
{
    int numeros[NUM_PEDIDOS];
    float promedio;
    float auxiliar;
    int i;
    int flag = 0;
    int numMaximo;
    int flag2 = 0;
    int numMinimo;
    int flag3 = 0;

    for(i = 0; i<NUM_PEDIDOS; i++)
    {
        if(getInt("Ingrese un numero: ", "Error, reingrese el numero: ", 5, 1, 1000, &numeros[i]) == 0)
        {
                printf("Numero %d: %d\n\n", i+1, numeros[i]);
        }
        if(flag != 0)
        {
            auxiliar = auxiliar + numeros[i];
        }
        else
        {
            auxiliar = numeros[i];
            flag = 1;
        }
    }
    promedio = auxiliar / NUM_PEDIDOS;
    printf("\nEl promedio de los numeros es: %.2f", promedio);

    for(i = 0; i<NUM_PEDIDOS; i++)
    {
        if(numeros[i] > numMaximo || flag2 == 0)
        {
            numMaximo = numeros[i];
            flag2 = 1;
        }
    }
    printf("\nEl numero maximo es: %d", numMaximo);

    for(i = 0; i<NUM_PEDIDOS; i++)
    {
        if(numeros[i] < numMinimo || flag3 == 0)
        {
            numMinimo = numeros[i];
            flag3 = 1;
        }
    }
    printf("\nEl numero minimo es: %d", numMinimo);

    return 0;
}

