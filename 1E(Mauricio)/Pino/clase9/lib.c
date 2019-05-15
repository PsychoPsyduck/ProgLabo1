#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int cargarProducto(EProducto listaProductos[], int indice, int cantidad)
{
    if(indice<cantidad)
    {
        printf("Ingrese nombre del producto: ");
        fflush(stdin);
        gets(listaProductos[indice].nombre);
        printf("Ingrese una descripcion: ");
        fflush(stdin);
        gets(listaProductos[indice].descripcion);
        printf("Ingrese un precio: $");
        fflush(stdin);
        scanf("%f", &listaProductos[indice].precio);
        listaProductos[indice].flagLibre = 0;
    }
    return 0;
}

int mostrarProducto(EProducto listaProductos[], int indice)
{
    printf("Producto: %s\n", listaProductos[indice].nombre );
    printf("%s\n", listaProductos[indice].descripcion);
    printf("$%.2f\n", listaProductos[indice].precio);
    return 0;
}

int buscarVacio(EProducto listaProductos[], int cantidad)
{
    int i;
    int auxIndice;
    if(cantidad>0)
    {
        for(i=0; i<cantidad; i++)
        {
            if(listaProductos[i].flagLibre)
            {
                auxIndice=i;
                break;
            }
        }
    }
    return auxIndice;
}
