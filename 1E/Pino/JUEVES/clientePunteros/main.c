#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"

void mostrar(Cliente** array,int cantidad);
void cargar(Cliente** array,int cantidadMaxima,int* cantidadActual);
void modificar(Cliente** array,int cantidad);
void arrayClienteAdd(Cliente** array,int cantidadMaxima,int* cantidadActual,char* dni, char* nombre, char* apellido, char* cuit, float altura, int id);

int main()
{
    Cliente* arrayPunteroClientes[1000];
    int qtyActualArrayClientes = 0;
    int qtyMaximaArrayClientes = 4000;

    cargar(arrayPunteroClientes,qtyMaximaArrayClientes,&qtyActualArrayClientes);
    modificar(arrayPunteroClientes,qtyActualArrayClientes);
    mostrar(arrayPunteroClientes,qtyActualArrayClientes);
    return 0;
}

void arrayClienteAdd(Cliente** array,int cantidadMaxima,int* cantidadActual,char* dni, char* nombre, char* apellido, char* cuit, float altura, int id)
{
        array[*cantidadActual] = cliente_newP(dni, nombre, apellido, cuit, altura, id);
        (*cantidadActual)++;
        //validar
}


void cargar(Cliente** array,int cantidadMaxima,int* cantidadActual)
{
    int i;
    for(i=0;i<40;i++)
    {
        arrayClienteAdd(array,cantidadMaxima,cantidadActual,"41690795", "MATIAS", "CACERES", "23-41690795-3", i, -1);
    }
}


void mostrar(Cliente** array,int cantidad)
{
    int i;
    char cuit[50];
    float altura;
    for(i=0;i<cantidad;i++)
    {
        cliente_getCuit(*(array+i), cuit);
        cliente_getAltura(*(array+i), &altura);
        printf("\nCuit:%s-Altura:%.2f",cuit,altura);
    }
}


void modificar(Cliente** array,int cantidad)
{
    int i;
    Cliente* auxiliarCliente;
    for(i=5;i<10;i++)
    {
        auxiliarCliente = arrayCliente_getById(array,cantidad,i);
        if(auxiliarCliente != NULL)
        {
            cliente_setAltura(auxiliarCliente, 22);
        }
    }
}


//hacer un remove/quitar id.
