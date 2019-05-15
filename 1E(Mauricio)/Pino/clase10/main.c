#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "lib.h"
#include "utn.h"
#define TAM 10

int main()
{
    Fantasma array[TAM];
    int menu;
    int auxiliarId;
    fantasma_init(array, TAM);

    do
    {
        getValidInt("1.Alta\n2.Baja\n3.Modificar\n4.Mostrar\n5.Ordenar\n8.Mostrar Debug\n9.Salir\n","\nNo valida\n",&menu,1,9,1);
        switch(menu)
        {
            case 1:
                fantasma_alta(array,TAM);
                break;
            case 2:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                fantasma_baja(array,TAM,auxiliarId);
                break;
            case 3:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                fantasma_modificacion(array,TAM,auxiliarId);
                break;
            case 4:
                fantasma_mostrar(array,TAM);
                break;
            case 5:
                fantasma_ordenar(array,TAM,0);
                break;
            case 8:
                fantasma_mostrarDebug(array,TAM);
                break;

        }

    }while(menu != 9);

    return 0;
}
