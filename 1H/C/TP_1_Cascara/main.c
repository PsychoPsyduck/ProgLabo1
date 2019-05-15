#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;

    //(A) y (B) son inicializados en 0
    float x=0;
    float y=0;


    while(seguir=='s')
    {
        printf("Ingrese un numero de operacion. Recuerde que los valores estan iniciados en 0 \n");
        printf("1- Ingresar 1er operando (A=%f)\n", x);
        printf("2- Ingresar 2do operando (B=%f)\n", y);
        printf("3- Calcular la suma\n");
        printf("4- Calcular la resta\n");
        printf("5- Calcular la division\n");
        printf("6- Calcular la multiplicacion)\n");
        printf("7- Calcular el factorial\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        while(opcion<=0 || opcion>=10)
        {
            //Evita el ingreso erroneo del codigo de operacion
            printf("Error. Ingrese un numero de operacion valido. \n");
            scanf("%d",&opcion);
        }

        switch(opcion)
        {
            case 1:
                //Pide el ingreso del primer numero (A)
                x=primerIngreso();
                break;

            case 2:
                //Pide el ingreso del segundo numero (B)
                y=segundoIngreso();
                break;

            case 3:
                //Calcula la suma de ambos numeros
                suma(x, y);
                printf("\n");
                break;

            case 4:
                //Calcula la resta de ambos numeros
                resta(x, y);
                printf("\n");
                break;

            case 5:
                //Calcula la division de ambos numeros.
                //Si el divisor es 0, no realiza ninguna operacion
                division(x, y);
                printf("\n");
                break;

            case 6:
                //Calcula la multiplicacion de ambos numeros.
                multi(x, y);
                printf("\n");
                break;

            case 7:
                //Calcula el factorial de ambos numeros cargados.
                //Falla si el numero a calcular es mayor o igual a 14.
                //En caso de que sea 0, devuelve 1
                factorial(x, y);
                printf("\n");
                break;

            case 8:
                //Calcula cada una de las operaciones.
                //En caso de que el dividendo sea 0, devuelve una advertencia pero realiza el resto de los calculos.
                suma(x, y);
                printf("\n");
                resta(x, y);
                printf("\n");
                division(x, y);
                printf("\n");
                multi(x, y);
                printf("\n");
                factorial(x, y);
                printf("\n");
                break;

            case 9:
                seguir = 'n';
                break;
        }

        printf("Presione 'S' para continuar operando. \n");
        seguir=getch();
    }

    return 0;
}
