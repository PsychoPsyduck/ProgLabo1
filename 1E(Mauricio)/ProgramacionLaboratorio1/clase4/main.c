#include <stdio.h>
#include <stdlib.h>
#include "Clase4.h"

int main()
{
    char edad;

    if(getChar("edad: ", "repeti ", 3, 'a', 'z', &edad)==0)
    {
        printf("Edad es: %c", edad);
    }
    else
    {
        printf("No se edad");
    }

    return 0;
}

