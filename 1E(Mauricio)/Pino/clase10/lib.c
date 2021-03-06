#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "lib.h"
#include "utn.h"
#define TAM 10

/** \brief Inicializa un array de elementos fantasma
 *
 * \param array Fantasma*
 * \param limite int
 * \return int
 *
 */
int fantasma_init(Fantasma* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite>0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].isEmpty=1;
        }
    }
    return retorno;
}

int fantasma_mostrarDebug(Fantasma* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite>0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            printf("[DEBUG] - %d - %s - %d\n", array[i].idFantasma, array[i].nombre, array[i].isEmpty);
        }
    }
    return retorno;
}

int fantasma_mostrar(Fantasma* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite>0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
            {
                printf("[REALISE] - %d - %s - %d\n", array[i].idFantasma, array[i].nombre, array[i].isEmpty);
            }
        }
    }
    return retorno;
}

int fantasma_alta(Fantasma* array,int limite)
{
    int retorno = -1;
    int i;
    char buffer[50];
    if(limite>0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i>=0)
        {
            if(!getValidString("Nombre? \n","\nEso no es un nombre","\nEl maximo de caracteres es 40",buffer,40,2))//Libreria UTN
            {
                retorno = 0;
                strcpy(array[i].nombre,buffer);
                array[i].idFantasma = proximoId();
                array[i].isEmpty = 0;
            }
            else
            {
                retorno=-3;
            }
        }
        else
        {
            retorno=-2;
        }
    }

    return retorno;
}

int fantasma_baja(Fantasma* array,int limite,int id)
{
    int retorno = -1;
    int i;
    if(limite>0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(array[i].idFantasma == id && !array[i].isEmpty)
            {
                array[i].isEmpty = 1;
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

int fantasma_modificacion(Fantasma* array,int limite,int id)
{
    int retorno = -1;
    int i;
    char buffer[50];
    if(limite>0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(array[i].idFantasma == id && !array[i].isEmpty)
            {
                if(!getValidString("Nombre? \n","\nEso no es un nombre","\nEl maximo de caracteres es 40",buffer,40,2))//Libreria UTN
                {
                    retorno = 0;
                    strcpy(array[i].nombre,buffer);
                }
                else
                {
                    retorno=-3;
                }
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

int fantasma_ordenar(Fantasma* array,int limite,int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Fantasma auxiliarEstructura;
    if(limite>0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite;i++)
            {
                if(!array[i].isEmpty && !array[i+1].isEmpty)
                {
                    if((strcmp(array[i].nombre, array[i+1].nombre) > 0 && orden) || (strcmp(array[i].nombre, array[i+1].nombre) < 0 && !orden))
                    {
                        auxiliarEstructura = array[i];
                        array[i] = array [i+1];
                        array[i+1] = auxiliarEstructura;
                        flagSwap=1;
                    }
                }
            }
        }while(flagSwap);
    }

    return retorno;
}

int buscarLugarLibre(Fantasma* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite>0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int proximoId()
{
    static int proximoId = -1; //guarda la variable, esta linea se ejecuta solo la primera vez. una segunda ya no y guarda el valor
    proximoId++;
    return proximoId;
}
