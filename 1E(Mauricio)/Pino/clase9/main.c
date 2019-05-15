#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#define CANT_PRODUCTOS 5

int main()
{
    EProducto listaProductos[CANT_PRODUCTOS];
    int i;
    int indice;
    for(i=0; i<CANT_PRODUCTOS; i++)
    {
        listaProductos[i].flagLibre=1;
    }
    int opcion;
    int seguir;
    do
    {
        printf("Ingrese una opcion: 1-2");
        fflush(stdin);
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1:
                indice=buscarVacio(listaProductos, CANT_PRODUCTOS);
                cargarProducto(listaProductos, indice, CANT_PRODUCTOS);
                break;
            case 2:
                for(i=0; i<CANT_PRODUCTOS; i++)
                {
                    mostrarProducto(listaProductos, i);
                }
                break;
        }
        printf("Desea continuar?");
        fflush(stdin);
        scanf("%d", &seguir);
    }while(seguir);
    return 0;
}
