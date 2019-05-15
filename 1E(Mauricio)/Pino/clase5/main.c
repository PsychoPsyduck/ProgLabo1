#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int main()
{
    int array[6]={2, 5, 6, 9, 1, 8};
    sort_mostrarArrayNumerico(array, 6);
    printf("\n\n");
    if(!(sort_ordenarArrayNumerico(array, 6, 0)))
    {
        sort_mostrarArrayNumerico(array, 6);
    }

    return 0;
}
