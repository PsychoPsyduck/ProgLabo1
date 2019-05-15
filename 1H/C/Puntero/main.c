#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    /*int var = 9;
    int* pInt = NULL;

    pInt = &var; //es igual a la direccion de memoria de var.
    *pInt = 85; //modifica el contenido de var.

    printf("%d\n", var);
    printf("%d\n", *pInt);
    printf("%p\n", pInt);
    printf("%p\n", &var);
    printf("%p\n\n", &pInt);

    char var2;
    char* pChar2 =NULL;

    pChar2 = &var2;

    if(pChar != NULL)
    {
        printf("\nIngrese una letra: ");
        *pChar = getche();

        printf("\nLa letra ingresada es %c\n\n", *pChar2);
    }

    */
    //ARITMETICA DE PUNTEROS

    int var3=9;
    int* pInt3;
    pInt3 = &var3;


    printf("%d \n", pInt3);
    pInt3++;
    printf("%d \n", pInt3);
    printf("%d \n", pInt3 + 1);
    printf("%d \n", pInt3 + 2);
    printf("%d \n", pInt3 + 0);
    printf("%d \n", pInt3 - 1);





    return 0;
}

