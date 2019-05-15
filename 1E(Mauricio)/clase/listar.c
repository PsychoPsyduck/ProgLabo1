#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Contratacion.h"
#include "listar.h"
#include "pantalla.h"
#include "utn.h"

int promedioPrecioPantallas(Pantalla* array,int limite);
int cantDiasContratado(Contratacion* array,int limite,int id);
int promedioDiasContratado(Contratacion* array,int limite);

int listar_ordenarPrecioNombre(Pantalla* array,int limite)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Pantalla auxiliarEstructura;

    if(limite > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<limite-1;i++)
            {
                if(!array[i].isEmpty && !array[i+1].isEmpty)
                {
                    if(array[i].precio < array[i+1].precio) //******
                    {
                        auxiliarEstructura = array[i];
                        array[i] = array[i+1];
                        array[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                    else if(array[i].precio == array[i+1].precio)
                    {
                        if(strcmp(array[i].nombre,array[i+1].nombre) > 0)
                        {
                            auxiliarEstructura = array[i];
                            array[i] = array[i+1];
                            array[i+1] = auxiliarEstructura;
                            flagSwap = 1;
                        }
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}

int listar_mostar100oMenos(Pantalla* array,int limite)
{
    int i;
    int retorno = -1;

    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite-1;i++)
        {
            if(!array[i].isEmpty && array[i].precio <= 100)
            {
                printf("%d - %s - %f\n",array[i].idPantalla, array[i].nombre, array[i].precio);
            }
        }
    }
    return retorno;
}

int listar_superaPromedio(Pantalla* array,int limite)
{
    printf("\n promedio:%d \n", promedioPrecioPantallas(array,limite));
    int i;
    int retorno = -1;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite-1;i++)
        {
            if(!array[i].isEmpty && array[i].precio > (float)promedioPrecioPantallas(array,limite))
            {
                printf("%d - %s - %f\n",array[i].idPantalla, array[i].nombre, array[i].precio);
            }
        }
    }
    return retorno;
}

int listar_superaPromedioDias(Pantalla* arrayP, Contratacion* arrayC, int limite)
{
    printf("\n promedio:%d \n", promedioDiasContratado(arrayC,limite));
    int i;
    int retorno = -1;
    int pant;
    if(limite > 0 && arrayC != NULL)
    {
        retorno = 0;
        for(i=0;i<limite-1;i++)
        {
            if(!arrayC[i].isEmpty && cantDiasContratado(arrayC, limite, arrayC[i].idPantalla) >  promedioDiasContratado(arrayC,limite))
            {
                pant = pantalla_buscarPorId(arrayP,limite, arrayC[i].idPantalla);
                printf("%d - %s - %f\n",arrayP[pant].idPantalla, arrayP[pant].nombre, arrayP[pant].precio);
            }
        }
    }
    return retorno;
}

//-----------------------------------------
int promedioPrecioPantallas(Pantalla* array,int limite)
{
    int promedio = -1;
    int contador = 0;
    int i;

    if(limite > 0 && array != NULL)
    {
        promedio = 0;
        for(i=0;i<limite-1;i++)
        {
            if(!array[i].isEmpty)
            {
                contador++;
                promedio = promedio + array[i].precio;
            }
        }
        promedio = promedio/contador;
    }



    return promedio;
}

int promedioDiasContratado(Contratacion* array,int limite)
{
    int promedio = -1;
    int contador = 0;
    int i;
    if(limite > 0 && array != NULL)
    {
        promedio = 0;
        for(i=0;i<limite-1;i++)
        {
            if(!array[i].isEmpty)
            {
                contador++;
                promedio = promedio + array[i].dias;
            }
        }
        promedio = promedio/contador;
    }

    return promedio;
}

int cantDiasContratado(Contratacion* array,int limite,int id)
{
    int i;
    int sumador = -1;
    if(limite > 0 && array != NULL)
    {
        sumador=0;
        for(i=0;i<limite-1;i++)
        {
            if(!array[i].isEmpty && array[i].idPantalla == id)
            {
                sumador = sumador+array[i].dias;
            }
        }
    }
    return sumador;
}
