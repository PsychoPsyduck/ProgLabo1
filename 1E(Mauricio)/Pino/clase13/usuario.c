#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "usuario.h"

int usuario_buscarPorId(Usuario* array,int limite, int id);

int usuario_init(Usuario* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].isEmpty=1;
        }
    }
    return retorno;
}

int usuario_alta(Usuario* array,int limite)
{
    int retorno = -1;
    int i;
    char nombre[50];
    char password[50];
    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",nombre,40,2))
            {
                if(!getValidString("\nPassword? ","\nEso no es una password","El maximo es 40",password,40,2))
                {
                    retorno = 0;
                    strcpy(array[i].nombre,nombre);
                    strcpy(array[i].password,password);
                    array[i].idUsuario = proximoId();
                    array[i].isEmpty = 0;
                }
            }

        }
    }
    return retorno;
}

int usuario_modificacion(Usuario* array,int limite, int id)
{
    int retorno = -1;
    int indexAModificar;
    char buffer[50];

    indexAModificar = usuario_buscarPorId(array,limite,id);
    if(indexAModificar>=0)
    {
        if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",buffer,40,2))
        {
            retorno = -2;
            strcpy(array[indexAModificar].nombre,buffer);
            if(!getValidString("\nPassword? ","\nEso no es un Password","El maximo es 40",buffer,40,2))
            {
                retorno = 0;
                strcpy(array[indexAModificar].password,buffer);

            }
        }
        else
        {
            retorno = -3;
        }
    }
    return retorno;
}

int usuario_baja(Usuario* array,int limite, int id)
{
    int indexAEliminar;
    int retorno=-1;
    indexAEliminar = usuario_buscarPorId(array,limite,id);
    if(indexAEliminar>=0)
    {
        array[indexAEliminar].isEmpty=1;
        retorno=0;
    }
    return retorno;
}


/*[-------------------------------------------------------------------------------------------]*/
int usuario_buscarPorId(Usuario* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idUsuario==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
