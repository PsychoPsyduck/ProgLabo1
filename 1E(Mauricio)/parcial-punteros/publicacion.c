#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "publicacion.h"
#include "utn.h"

static int buscarLugarLibre(Aviso* array,int limite);
static int proximoId(void);

int publicacion_init(Aviso* array,int limite)
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

int publicacion_alta(Aviso* array,int limite, int auxIdCliente)
{
    int retorno = -1;
    int i;
    char aviso[65];
    int nroRubro;
    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            if(!getValidInt("\nRubro? ","\nEso no es un rubro valido",&nroRubro,0,500,2))
            {
                if(!getValidString("\nAviso: ","\nEso no es un aviso valido","El maximo es 65",aviso,75,2))
                {

                    retorno = 0;
                    strcpy(array[i].textoAviso,aviso);
                    array[i].numeroRubro = nroRubro;
                    array[i].idCliente = auxIdCliente;
                    //------------------------------
                    //------------------------------
                    array[i].estado = 1;
                    array[i].idAviso = proximoId();
                    array[i].isEmpty = 0;

                }
            }
            else
            {
                retorno = -3;
            }
        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}

int publicacion_mostrarDEB(Aviso* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
                printf("[RELEASE] - %d - %d - %s- %d- %d- %d\n",array[i].idCliente, array[i].numeroRubro, array[i].textoAviso, array[i].idAviso, array[i].estado, array[i].isEmpty);
        }
    }
    return retorno;
}

int publicacion_altaForzada(Aviso* array,int limite,int idC,int numRubro,char* txtAviso)
{
    int retorno = -1;
    int i;

    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(array[i].textoAviso,txtAviso);
            array[i].idCliente = idC;
            array[i].numeroRubro = numRubro;
            //------------------------------
            //------------------------------
            array[i].estado = 1;
            array[i].idAviso = proximoId();
            array[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}



int publicacion_pausar(Aviso* array,int limite, int indice)
{
    int retorno = -1;
    char continuar;
    if(indice>=0 && array[indice].estado)
    {
        printf("seguro que desea pausar? s/n\n");
        fflush(stdin);
        gets(&continuar);

        if(continuar == 's')
        {
            retorno = 0;
            array[indice].estado = 0;
            printf("\nSe ha pausado la publicacion");

        }
        else
        {
            printf("\nNo se ha pausado la publicacion");

        }
    }
    else
    {
        printf("\nLa publicaicon ya esta pausada");
    }
    return retorno;
}

int publicacion_reanudar(Aviso* array,int limite, int indice)
{
    int retorno = -1;
    char continuar;
    if(indice>=0 && !array[indice].estado)
    {
        printf("seguro que desea reanudado? s/n\n");
        fflush(stdin);
        gets(&continuar);

        if(continuar == 's')
        {
            retorno = 0;
            array[indice].estado = 1;
            printf("\nSe ha reanudado la publicacion");

        }
        else
        {
            printf("\nNo se ha reanudado la publicacion");

        }
    }
    else
    {
        printf("\nLa publicaicon ya esta activa");
    }
    return retorno;
}

int publicacion_buscarPorId(Aviso* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idAviso==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int publicacion_mostrar(Aviso* arrayA,int limiteA, Cliente* arrayC, int limiteC)
{
    int retorno = -1;
    int i;
    int indiceCliente;
    char cuitCliente[15];
    if(limiteA > 0 && arrayA != NULL)
    {
        retorno = 0;
        for(i=0;i<limiteA;i++)
        {
            indiceCliente=cliente_buscarPorId(arrayC, limiteC, arrayA[i].idCliente);
            strcpy(cuitCliente,arrayC[indiceCliente].cuit);
            if(!arrayA[i].isEmpty)
                printf("Aviso: %s - idCliente: %d - Rubro: %d - idAviso: %d - estado: %d - cuitCliente: %s\n", arrayA[i].textoAviso, arrayA[i].idCliente, arrayA[i].numeroRubro, arrayA[i].idAviso, arrayA[i].estado, cuitCliente);
        }
    }
    return retorno;
}

int publicacion_baja(Aviso* array,int limite, int id)
{
    int indiceAEliminar;
    int retorno=-1;
    indiceAEliminar = publicacion_buscarPorIdCliente(array,limite,id);
    if(indiceAEliminar>=0)
    {
        array[indiceAEliminar].isEmpty=1;
        retorno=0;
    }
    return retorno;
}

int publicacion_buscarPorIdCliente(Aviso* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty && array[i].idCliente==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
//-----------------------------------------
static int buscarLugarLibre(Aviso* array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

static int proximoId(void)
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}

