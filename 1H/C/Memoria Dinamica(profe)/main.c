#include <stdio.h>
#include <stdlib.h>
#define T 5
int main()
{
    int vector[10]= {};
    int* pInt;
    int* pAux;
    int i;
    pInt = (int*) malloc(sizeof(int)* T);
    //pInt = calloc(T, sizeof(int));


    if(pInt!=NULL)
    {
        printf("CARGO LOS PRIMEROS 5\n");
        for(i=0; i<T; i++)
        {
            printf("Ingrese un numero: ");
            scanf("%d", pInt+i);
        }

        for(i=0; i<T; i++)
        {
            printf("%d\n", *(pInt+i));
        }

        pAux = (int*)realloc(pInt, sizeof(int)*(T+3));
        if(pAux!=NULL)
        {
            pInt=pAux;
            printf("CARGO 3 MAS\n");
            for(i=T; i<T+3; i++)
            {
                printf("Ingrese un numero: ");
                scanf("%d", pInt+i);
            }
            for(i=0; i<T+3; i++)
            {
                printf("%d\n", *(pInt+i));
            }

            pInt=realloc(pInt, sizeof(int)*2);
            printf("LOS DOS QUE ME QUEDARON\n");
            for(i=0; i<2; i++)
            {
                printf("%d\n", *(pInt+i));
            }

            free(pInt);
            free(pAux);

        }

    }
    else
    {
        printf("No hay espacio en memoria!!!");
    }





    return 0;
}
