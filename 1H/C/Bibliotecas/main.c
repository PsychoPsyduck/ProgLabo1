#include <stdio.h>
#include <stdlib.h>
#include "Salidas.h"

int factorial(int)

int main()
{
    int num;
    int resultado;

    printf("Ingrese un numero a factoriar\n");
    scanf("%d", &num);

    factorial(num);

    resultado=factorial(num)
    printf(resultado)

    resturn 0;
}

int factorial(int num)
{

    int resultado;

    if(num==0)
    {
        resturn 1;
    }

    reultado=num*factorial(num-1);
    return(resultado);
}


/*    int num;
    int acum=1;
    int i;

    printf("Ingrese el numero a factoriar\n");
    scanf("%d", &num);

    for(i = num; i>0; i--)
    {
        acum = acum*i;
    }

    printf("%d", acum);

    return 0; /*
