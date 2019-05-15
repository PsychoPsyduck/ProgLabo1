#include <stdio.h>
#include <stdlib.h>
#define V 3
int main()
{
    int* p;
    int* aux;
    int i;

    p = (int*) malloc(sizeof(int)*V);

    for(i=0; i<V; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", p+i);
    }


    for(i=0; i<V; i++)
    {
        printf("\n%d\n", *(p+i));
    }

    aux =(int*) realloc(p,sizeof(int)*(V+2));
    if(aux!=NULL)
    {
        p=aux;
        for(i=3; i<V+2; i++)
        {
            printf("Ingrese un numero: ");
            scanf("%d", p+i);
        }
        printf("\nluego del realloc\n");
        for(i=0; i<V+2; i++)
        {
            printf("\n%d\n", *(p+i));
        }

        aux = realloc(p,sizeof(int)*2);
        if(aux!=NULL)
        {
            p=aux;
            printf("Lo achique\n");
            for(i=0; i<5; i++)
            {
                printf("\n%d\n", *(p+i));
            }

        }
    }



    return 0;
}
