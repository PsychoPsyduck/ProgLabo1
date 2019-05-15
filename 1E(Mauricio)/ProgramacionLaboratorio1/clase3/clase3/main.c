#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main()
{
    int primerNumero;
    int segundoNumero;
    float resultadoMain;
    char operador;
    int retorno;

    printf("Numero 1:\n");
    scanf("%d",&primerNumero);

    printf("Numero 2:\n");
    scanf("%d",&segundoNumero);

    printf("Ingrese el operador (+,-,*,/): ");
    fflush(stdin);
    scanf("%c", &operador);
    switch(operador)
    {
        case'+':
            retorno=sumaEnteros(primerNumero,segundoNumero,&resultadoMain);
            if(retorno==0)
            {
                printf("\nEl resultado es: %.2f", resultadoMain);
            }
            else
            {
                printf("\nERROR");
            }
            break;
        case'-':
            retorno=restaEnteros(primerNumero,segundoNumero,&resultadoMain);
            if(retorno==0)
            {
                printf("\nEl resultado es: %.2f", resultadoMain);
            }
            else
            {
                printf("\nERROR");
            }
            break;
        case'*':
            retorno=multiplicaEnteros(primerNumero,segundoNumero,&resultadoMain);
            if(retorno==0)
            {
                printf("\nEl resultado es: %.2f", resultadoMain);
            }
            else
            {
                printf("\nERROR");
            }
            break;
        case'/':
            retorno=divideEnteros(primerNumero,segundoNumero,&resultadoMain);
            if(retorno==0)
            {
                printf("\nEl resultado es: %.2f", resultadoMain);
            }
            else
            {
                printf("\nERROR");
            }
            break;
    }

    return 0;
}
