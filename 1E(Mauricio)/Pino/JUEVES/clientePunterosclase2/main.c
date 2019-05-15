#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"

void arrayClienteAdd(Cliente** array,int cantidadMaxima,int* cantidadActual,char* dni, char* nombre, char* apellido, char* cuit, float altura, int id);
void cargar(Cliente** array,int cantidadMaxima,int* cantidadActual);
void modificar(Cliente** array,int cantidadAtual);
void mostrar(Cliente** array,int cantidadActual);
int guardarTodo(Cliente** array,int cantidadActual);

int main()
{
    Cliente* arrayPunteroClientes[4000];
    int qtyActualArrayClientes = 0;
    int qtyMaximaArrayClientes = 4000;

    cargar(arrayPunteroClientes,qtyMaximaArrayClientes,&qtyActualArrayClientes);
    modificar(arrayPunteroClientes,qtyActualArrayClientes);
    mostrar(arrayPunteroClientes,qtyActualArrayClientes);
    guardarTodo(arrayPunteroClientes,qtyActualArrayClientes);


    return 0;
}

void arrayClienteAdd(Cliente** array,int cantidadMaxima,int* cantidadActual,char* dni, char* nombre, char* apellido, char* cuit, float altura, int id)
{
        array[*cantidadActual] = cliente_newP(dni, nombre, apellido, cuit, altura, id);
        (*cantidadActual)++;
        //validar
}

//Carga si el archivo tiene informacion
void cargar(Cliente** array,int cantidadMaxima,int* cantidadActual)
{
    char dni[50];
    char nombre[50];
    char apellido[50];
    char cuit[50];
    float altura;
    int id;
    int r;
    FILE *cliente;
    if((cliente=fopen("data.txt","r"))!=NULL)
    {
        do
        {
            r = fscanf(cliente,"%d,%[^,],%[^,],%[^,],%[^,],%f\n",&id,dni,nombre,apellido,cuit,&altura);
            if(r==6)
            {
                arrayClienteAdd(array,cantidadMaxima,cantidadActual,dni,nombre,apellido,cuit,altura,id);
                //printf("id:%d\nnombre:%s\napellido:%s\ncuit:%s\naltura:%.2f\n-----------------------------\n",id,nombre,apellido,cuit,altura);
            }
        }while(!feof(cliente));
        fclose(cliente);
    }
}


void mostrar(Cliente** array,int cantidadActual)
{
    int i;
    int id;
    char dni[50];
    char cuit[50];
    char apellido[50];
    char nombre[50];
    float altura;
    for(i=0;i<cantidadActual;i++)
    {
        cliente_getId(*(array+i), &id);
        cliente_getDni(*(array+i), dni);
        cliente_getNombre(*(array+i), nombre);
        cliente_getApellido(*(array+i), apellido);
        cliente_getCuit(*(array+i), cuit);
        cliente_getAltura(*(array+i), &altura);
        printf("id:%d\nnombre:%s\napellido:%s\ndni:%s\ncuit:%s\naltura:%.2f\n-----------------------------\n",id,nombre,apellido,dni,cuit,altura);
    }
}


void modificar(Cliente** array,int cantidadActual)
{
    int i;
    Cliente* auxiliarCliente;
    for(i=0;i<5;i++)
    {
        auxiliarCliente = arrayCliente_getById(array,cantidadActual,i);
        if(auxiliarCliente != NULL)
        {
            cliente_setAltura(auxiliarCliente, 22);
        }
    }
}


int guardarTodo(Cliente** array,int cantidadActual)//hacer un backap del txt, borrar el original y volver a guardarlo
{
    int retorno = -1;
    int i;
    int id;
    char dni[50];
    char cuit[50];
    char apellido[50];
    char nombre[50];
    float altura;
    FILE *cliente;
    if((cliente=fopen("data.txt","w"))!=NULL)
    {
        retorno=0;
        for(i=0;i<cantidadActual;i++)
        {
        cliente_getId(*(array+i), &id);
        cliente_getCuit(*(array+i), cuit);
        cliente_getNombre(*(array+i), nombre);
        cliente_getApellido(*(array+i), apellido);
        cliente_getDni(*(array+i), dni);
        cliente_getAltura(*(array+i), &altura);
        fprintf(cliente,"%d,%s,%s,%s,%s,%.2f\n",id,nombre,apellido,dni,cuit,altura);
        }
        fclose(cliente);
    }
    return retorno;
}

//hacer un remove/quitar id.
//parsen, divide una texto en variables
//strtok
