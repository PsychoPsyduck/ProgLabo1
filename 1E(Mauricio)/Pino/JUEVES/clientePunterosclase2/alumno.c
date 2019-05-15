#include "alumno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static int ultimoId = -1;
int isValidDni(char* dni);
int isValidNombre(char* nombre);
int isValidApellido(char* apellido);
int isValidCuit(char* cuit);
static int isValidAltura(float altura);


Cliente* cliente_new()
{
    return malloc(sizeof(Cliente));
}


void cliente_delete(Cliente* this)
{
    free(this);
}


Cliente* cliente_newP(char* dni, char* nombre, char* apellido, char* cuit, float altura, int id)
{
    Cliente* this = cliente_new();

    if(!cliente_setDni(this, dni)
    && !cliente_setNombre(this, nombre)
    && !cliente_setApellido(this, apellido)
    && !cliente_setCuit(this, cuit)
    && !cliente_setAltura(this, altura))
    {
        if(id >= 0)
        {
            cliente_setId(this,id);
            return this;
        }
        else
        {
            cliente_setNewId(this);
            return this;
        }
    }

    cliente_delete(this);
    return NULL;//validar que si uno de los datos este mal que libere el espacio de memoria y tire un NULL,,, validar que no sea null
}


int cliente_setNewId(Cliente* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        ultimoId++;
        this->id = ultimoId;
        retorno = 0;
    }
    return retorno;
}


int cliente_setId(Cliente* this, int id)
{
    int retorno = -1;
    if(this != NULL)
    {
        if(id > ultimoId)
            ultimoId = id;

        this->id = id;
        retorno = 0;
    }
    return retorno;
}


int cliente_getId(Cliente* this, int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}


int cliente_setDni(Cliente* this, char* dni)
{
    int retorno = -1;
    if(this != NULL && dni != NULL && isValidDni(dni))
    {
        strcpy(this->dni,dni);
        retorno = 0;
    }
    return retorno;
}


int cliente_getDni(Cliente* this, char* dni)
{
    int retorno = -1;
    if(this != NULL && dni != NULL)
    {
        strcpy(dni,this->dni);
        retorno = 0;
    }
    return retorno;
}


int isValidDni(char* dni)
{
    return 1;
}


int cliente_setNombre(Cliente* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL && isValidNombre(nombre))
    {
        strcpy(this->nombre,nombre);
        retorno = 0;
    }
    return retorno;
}


int cliente_getNombre(Cliente* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        retorno = 0;
    }
    return retorno;
}


int isValidNombre(char* nombre)
{
    return 1;
}


int cliente_setApellido(Cliente* this, char* apellido)
{
    int retorno = -1;
    if(this != NULL && apellido != NULL && isValidApellido(apellido))
    {
        strcpy(this->apellido,apellido);
        retorno = 0;
    }
    return retorno;
}


int cliente_getApellido(Cliente* this, char* apellido)
{
    int retorno = -1;
    if(this != NULL && apellido != NULL)
    {
        strcpy(apellido,this->apellido);
        retorno = 0;
    }
    return retorno;
}


int isValidApellido(char* apellido)
{
    return 1;
}


int cliente_setCuit(Cliente* this, char* cuit)
{
    int retorno = -1;
    if(this != NULL && cuit != NULL && isValidCuit(cuit))
    {
        strcpy(this->cuit,cuit);
        retorno = 0;
    }
    return retorno;
}


int cliente_getCuit(Cliente* this, char* cuit)
{
    int retorno = -1;
    if(this != NULL && cuit != NULL)
    {
        strcpy(cuit,this->cuit);
        retorno = 0;
    }
    return retorno;
}


int isValidCuit(char* cuit)
{
    return 1;
}


int cliente_setAltura(Cliente* this, float altura)
{
    int retorno = -1;
    if(this != NULL && isValidAltura(altura))
    {
        this->altura = altura;
        retorno = 0;
    }
    return retorno;
}


int cliente_getAltura(Cliente* this, float *altura)
{
    int retorno = -1;
    if(this != NULL && altura != NULL)
    {
        *altura = this->altura;
        retorno = 0;
    }
    return retorno;
}


static int isValidAltura(float altura)
{
    return 1;
}


Cliente* arrayCliente_getById(Cliente** this,int cantidad,int id)
{
    Cliente* retorno = NULL;
    int i;
    int auxId;
    for(i=0;i<cantidad;i++)
    {
        cliente_getId(*(this+i),&auxId);
        if(auxId==id)
        {
            retorno = *(this+i);
            break;
        }
    }
    return retorno;
}


