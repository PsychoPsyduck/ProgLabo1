#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort_insertionInt(int* array, int cantElementos)
{
    int i,j;
    int aux;
    for(i=1; i<cantElementos; i++)
    {
        aux=array[i];
        j=i-1;
        while(j>=0 && aux>array[j])
        {
            array[j+1] = array[j];
            j--;
        }
        array[j+1]=aux;
    }
}

/* SRTING:

    char array[50];
    char array2[]={"ingresa algo"};

    printf("%s \n", array2);
    fgets(array, sizeof(array), stdin);
    strcpy(array2, array);
    printf(array2);
*/
