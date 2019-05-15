#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

int main()
{
    char array[10];
    int i;
    int len;
    int numero;

    printf("Ingrese: \n");
    fgets(array, sizeof(array), stdin);
    len=strlen(array);

    for(i=0; i<len; i++)
    {
        if(array[i]<='0' || array[i]>='9')
        {
            printf("ok");
            break;
        }
        else if(i=len-1)
        {
            numero=atoi(array);
            printf("error, ingresaste: %d", numero);

        }
    }




    return 0;
}
