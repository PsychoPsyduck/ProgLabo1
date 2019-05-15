#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "producto.h"
#include "usuario.h"

int producto_buscarPorId(Producto* array,int limite, int id);

int producto_init(Producto* array,int limite)
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

int producto_alta(Producto* array,int limite)
{
    int retorno = -1;
    int i;
    int auxIdUsuario;
    char nombre[50];
    float auxPrecio;
    int auxStock;
    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            if(!getValidInt("\nId de usuario? ","\nEso no es un id valido","El maximo es 40",&auxStock,0,200,2))
            {
                if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 40",nombre,40,2))
                {
                    if(!getValidFloat("Precio?","\nPrecio no es valido\n",&auxPrecio,0,200,2))
                    {
                        if(!getValidInt("Stock?","\nStock no es valido\n",&auxStock,0,200,2))
                        {
                            retorno = 0;
                            array[i].idUsuario= auxIdUsuario;
                            strcpy(array[i].nombre,nombre);
                            array[i].precio = auxPrecio;
                            array[i].stock = auxStock;
                            array[i].idUsuario = proximoId();
                            array[i].isEmpty = 0;
                        }
                    }
                }
            }

        }
    }
    return retorno;
}

int producto_modificacion(Producto* array,int limite, int id)
{
    int retorno = -1;
    int indexAModificar;
    int auxPrecio;
    int auxStock;

    indexAModificar = producto_buscarPorId(array,limite,id);
    if(indexAModificar>=0)
    {
        if(!getValidInt("Stock?","\nStock no es valido\n",&auxPrecio,0,200,2))
        {
            retorno = -2;
            array[indexAModificar].precio = auxPrecio;
            if(!getValidInt("Stock?","\nStock no es valido\n",&auxStock,0,200,2))
            {
                retorno = 0;
                array[indexAModificar].stock = auxStock;
            }
        }
        else
        {
            retorno = -3;
        }
    }
    return retorno;
}

/*[-------------------------------------------------------------------------------------------]*/
int producto_buscarPorId(Producto* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idProducto==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
