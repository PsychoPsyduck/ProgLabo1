#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

static float isValidAltura(float alturaFuncion);
static int isValidCuit(char* cuitFuncion);
static int isValidNombre(char* nombreFuncion);
static int isValidApellido(char* apellidoFuncion);
static int isValidDni(char* dniFuncion);

//-----------------------
Cliente* cliente_new()
{
    return malloc(sizeof(Cliente));
}

Cliente* cliente_newNuevo(char* dni,int id, char* nombre, char* apellido, float altura, char* cuit)
{

    int retorno = -1;
    Cliente* this = cliente_new();
    if(!cliente_setCuit(this,cuit) && !cliente_setNombre(this,nombre) && !cliente_setApellido(this, apellido)
    && !cliente_setDni(this,dni) && !cliente_setAltura(this, altura))
       {

            retorno = 1;
            if(id>=0)
            {
                cliente_setId(this, id);
                retorno=0;
            }
                else
                {
                    cliente_setNewId(this);
                }
       }

    if(!retorno)
    {
            return this;
    }

    else
    {
        cliente_delete(this);
        return NULL;
    }
}

void cliente_delete(Cliente* this)
{
    free(this);
}

/*int  cliente_setEdad(Cliente* this, int edad)
{
    int retorno = -1;
    if(this != NULL && edad >= 0)
    {
        retorno = 0;
        this->edad = edad;
    }
    return retorno;
}

int cliente_getEdad(Cliente* this, int* edad)
{
    int retorno = -1;
    if(this != NULL && edad != NULL)
    {
        retorno = 0;
        *edad = this->edad;
    }
    return retorno;

}*/

int cliente_setAltura(Cliente* this, float alturaFuncion)
{
    int retorno = -1;

    if(this!=NULL && isValidAltura(alturaFuncion))
    {
        this->altura = alturaFuncion;
        retorno = 0;
    }
    return retorno;
}

int cliente_getAltura(Cliente* this, float* alturaFuncion)
{
    int retorno = -1;

    if(this!=NULL && alturaFuncion !=NULL)
    {
        *alturaFuncion = this->altura;
        retorno = 0;
    }
    return retorno;
}

static float isValidAltura(float alturaFuncion)
{
    return 1;
}

//------------------------------------------------------------------------------------------------------
int cliente_setCuit(Cliente* this, char* cuitFuncion)
{
    int retorno = -1;

    if(this!=NULL && cuitFuncion != NULL && isValidCuit(cuitFuncion))
    {
        strcpy(cuitFuncion,this ->cuit);
        retorno = 0;
    }
    return retorno;
}

int cliente_getCuit(Cliente* this, char* cuitFuncion)
{
    int retorno = -1;

    if(this!=NULL && cuitFuncion !=NULL)
    {
          strcpy(this ->cuit,cuitFuncion);
        retorno = 0;
    }
    return retorno;
}

static int isValidCuit(char* cuitFuncion)
{
    return 1;
}

//-------------------------------------------------------------

int cliente_setNombre(Cliente* this, char* nombreFuncion)
{
    int retorno = -1;

    if(this!=NULL && nombreFuncion != NULL && isValidNombre(nombreFuncion))
    {
        strcpy(nombreFuncion , this ->nombre);
        retorno = 0;
    }
    return retorno;
}

int cliente_getNombre(Cliente* this, char* nombreFuncion)
{
    int retorno = -1;

    if(this!=NULL && nombreFuncion !=NULL)
    {
         strcpy(this ->nombre,nombreFuncion);
        retorno = 0;
    }
    return retorno;
}

int isValidNombre(char* nombreFuncion)
{
    return 1;
}

//----------------------------------------------------

int cliente_setApellido(Cliente* this, char* apellidoFuncion)
{
    int retorno = -1;

    if(this!=NULL && apellidoFuncion != NULL && isValidApellido(apellidoFuncion))
    {
        strcpy(apellidoFuncion , this ->apellido);
        retorno = 0;
    }
    return retorno;
}

int cliente_getApellido(Cliente* this, char* apellidoFuncion)
{
    int retorno = -1;

    if(this!=NULL && apellidoFuncion !=NULL)
    {
         strcpy(this ->apellido,apellidoFuncion);
        retorno = 0;
    }
    return retorno;
}

static int isValidApellido(char* apellidoFuncion)
{
    return 1;
}

//-----------------------------------------------------

int cliente_setDni(Cliente* this, char* dniFuncion)
{
    int retorno = -1;

    if(this!=NULL && dniFuncion != NULL && isValidDni(dniFuncion))
    {
        strcpy(dniFuncion,this ->dni);
        retorno = 0;
    }
    return retorno;
}

int cliente_getDni(Cliente* this, char* dniFuncion)
{
    int retorno = -1;

    if(this!=NULL && dniFuncion !=NULL)
    {
        strcpy(this ->dni,dniFuncion);
        retorno = 0;
    }
    return retorno;
}


static int isValidDni(char* dniFuncion)
{
    return 1;
}

//--------------------------------------------------------------------

int cliente_setNewId(Cliente* this)
{
    static int ultimoId = -1;

    int retorno = -1;

    if(this!=NULL)
    {
       ultimoId++;
       this ->id = ultimoId;
       retorno = 0;
    }
    return retorno;
}

int cliente_getId(Cliente* this, int* idFuncion)
{
    int retorno = -1;

    if(this!=NULL && idFuncion !=NULL)
    {
        *idFuncion = this ->id;
        retorno = 0;
    }
    return retorno;
}

int cliente_setId(Cliente* this, int idFuncion)
{
    static int ultimoId = -1;
    int retorno = -1;

    if(this!=NULL)
    {
       if(idFuncion > ultimoId)
       {
           ultimoId = idFuncion;
       }
       this ->id = idFuncion;
       retorno = 0;
    }
    return retorno;
}

Cliente* arrayCliente_getById(Cliente* array[], int cantidadElementos, int idFuncion)
{
    Cliente* retorno = NULL;
    int auxiliarId;
    int i;
    for(i=0; i<cantidadElementos; i++)
    {
        cliente_getId(array[i],&auxiliarId);
        if(auxiliarId == idFuncion)
        {
            retorno = array[i];
            break;
        }
    }
    return retorno;
}















