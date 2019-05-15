#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

int main()
{
    char pChar;
    char aux[TAM];
    int i;
    int contador;



    for(i=0; i<TAM; i++)
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(aux[i]);
    }

    contador = strlen(aux)+1;



    return 0;
}
