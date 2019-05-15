#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "string.h"

void mostrar(Cliente* array[],int cantidad);
void cargar(Cliente* array[],int cantidad);
void modificar(Cliente* array[],int cantidad);

int main()
{
    Cliente* arrayPunteroClientes[50];
    cargar(arrayPunteroClientes,50);
    mostrar(arrayPunteroClientes,50);
    modificar(arrayPunteroClientes,50);
    mostrar(arrayPunteroClientes,50);
    return 0;
}

void cargar(Cliente* array[],int cantidad)
{
  int i;
  for(i=0;i<cantidad;i++)
  {
      array[i]= cliente_newNuevo("28506515",-1,"juan","perez",i,"20396645824");
  }
}

void mostrar(Cliente* array[],int cantidad)
{
    int i;
    float altura;
    char cuit[50];

    for(i=0; i<cantidad; i++)
    {
        cliente_getCuit(array[i],cuit);
        cliente_getAltura(array[i],&altura);
        printf("\nCuit: %s -- Altura: %f", cuit, altura);
    }
}

void modificar(Cliente* array[],int cantidad)
{
    int i;
    Cliente* auxiliarCliente;

    for(i=0; i<cantidad; i++)
    {
        auxiliarCliente = arrayCliente_getById(array,cantidad,i);
        if(auxiliarCliente != NULL)
        {
            cliente_setAltura(auxiliarCliente,88);
        }
    }
}
