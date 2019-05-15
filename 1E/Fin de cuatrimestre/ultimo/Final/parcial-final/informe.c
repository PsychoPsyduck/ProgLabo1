#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "informe.h"
#include "utn.h"

int contarAvisosPausados(Aviso* array, int limite, int id);
int contarAvisosActivos(Aviso* array, int limite, int id);
int contarAvisos(Aviso* array, int limite, int id);
int contarPublicacionesRubro(Aviso* array, int limite, int rubro);
int contarPublicaciones(Aviso* array, int limite, int rubro);

int informe_masAvisos(Cliente* arrayC,int limiteC, Aviso* arrayA, int limiteA)
{
    int retorno = -1;
    int i;
    int maximoAvisos=0;
    int auxIndiceCliente;

    if(limiteC > 0 && arrayC != NULL)
    {
        retorno = 0;
        for(i=0;i<limiteC-1;i++)
        {
            if(maximoAvisos < contarAvisos(arrayA,limiteA, arrayC[i].idCliente))
            {
                maximoAvisos=contarAvisos(arrayA,limiteA, arrayC[i].idCliente);
                auxIndiceCliente=i;
            }
        }
    }
    printf("%s - %s - %s- Id Cliente: %d - Cantidad de avisos: %d\n",arrayC[auxIndiceCliente].nombre, arrayC[auxIndiceCliente].apellido, arrayC[auxIndiceCliente].cuit, arrayC[auxIndiceCliente].idCliente, maximoAvisos);
    return retorno;
}

int contarAvisos(Aviso* array, int limite, int id)
{
    int i;
    int contador = -1;

    if(limite > 0 && array != NULL)
    {
        contador = 0;
        for(i=0;i<limite-1;i++)
        {
            if(!array[i].isEmpty && id == array[i].idCliente)
            {
                contador++;
            }
        }
    }
    return contador;
}

int informe_masAvisosActivos(Cliente* arrayC,int limiteC, Aviso* arrayA, int limiteA)
{
    int retorno = -1;
    int i;
    int maximoAvisos=0;
    int auxIndiceCliente;

    if(limiteC > 0 && arrayC != NULL)
    {
        retorno = 0;
        for(i=0;i<limiteC-1;i++)
        {
            if(maximoAvisos < contarAvisosActivos(arrayA,limiteA, arrayC[i].idCliente))
            {
                maximoAvisos=contarAvisosActivos(arrayA,limiteA, arrayC[i].idCliente);
                auxIndiceCliente=i;
            }
        }
    }
    printf("%s - %s - %s- Id Cliente: %d - Avisos activos: %d\n",arrayC[auxIndiceCliente].nombre, arrayC[auxIndiceCliente].apellido, arrayC[auxIndiceCliente].cuit, arrayC[auxIndiceCliente].idCliente, maximoAvisos);
    return retorno;
}

int contarAvisosActivos(Aviso* array, int limite, int id)
{
    int i;
    int contador = -1;

    if(limite > 0 && array != NULL)
    {
        contador = 0;
        for(i=0;i<limite-1;i++)
        {
            if(!array[i].isEmpty && array[i].estado && id == array[i].idCliente)
            {
                contador++;
            }
        }
    }
    return contador;
}


int informe_masAvisosPausados(Cliente* arrayC,int limiteC, Aviso* arrayA, int limiteA)
{
    int retorno = -1;
    int i;
    int maximoAvisos=0;
    int auxIndiceCliente;

    if(limiteC > 0 && arrayC != NULL)
    {
        retorno = 0;
        for(i=0;i<limiteC-1;i++)
        {
            if(maximoAvisos < contarAvisosPausados(arrayA,limiteA, arrayC[i].idCliente))
            {
                maximoAvisos=contarAvisosPausados(arrayA,limiteA, arrayC[i].idCliente);
                auxIndiceCliente=i;
            }
        }
    }
    printf("%s - %s - %s- Id Cliente: %d - Avisos pausados: %d\n",arrayC[auxIndiceCliente].nombre, arrayC[auxIndiceCliente].apellido, arrayC[auxIndiceCliente].cuit, arrayC[auxIndiceCliente].idCliente, maximoAvisos);
    return retorno;
}

int contarAvisosPausados(Aviso* array, int limite, int id)
{
    int i;
    int contador = -1;

    if(limite > 0 && array != NULL)
    {
        contador = 0;
        for(i=0;i<limite-1;i++)
        {
            if(!array[i].isEmpty && !array[i].estado && id == array[i].idCliente)
            {
                contador++;
            }
        }
    }
    return contador;
}

int informe_totalRubro(Aviso* arrayA, int limiteA, int rubro)
{
    int retorno = -1;
    int i;
    int cantAvisos=0;
    int auxIndicePublicacion;

    if(limiteA > 0 && arrayA != NULL)
    {
        retorno = 0;
        for(i=0;i<limiteA-1;i++)
        {
            if(arrayA[i].numeroRubro == rubro)
            {
                cantAvisos=contarPublicacionesRubro(arrayA,limiteA, rubro);
                auxIndicePublicacion=i;
            }
        }
    }
    if(cantAvisos>0)
    {
        printf("Rubro: %s - Cantidad de avisos: %d\n",arrayA[auxIndicePublicacion].textoAviso, cantAvisos);
    }
    else
    {
        printf("El rubro no tiene publicaciones");
    }

    return retorno;
}

int contarPublicacionesRubro(Aviso* array, int limite, int rubro)
{
    int i;
    int contador = -1;

    if(limite > 0 && array != NULL)
    {
        contador = 0;
        for(i=0;i<limite-1;i++)
        {
            if(!array[i].isEmpty && rubro == array[i].numeroRubro)
            {
                contador++;
            }
        }
    }
    return contador;
}

int informe_rubroMasActivas(Aviso* arrayA, int limiteA)
{
    int retorno = -1;
    int i;
    int maximoAvisos=0;
    int auxIndicePublicacion;

    if(limiteA > 0 && arrayA != NULL)
    {
        retorno = 0;
        for(i=0;i<limiteA-1;i++)
        {
            if(!arrayA[i].isEmpty && maximoAvisos < contarPublicaciones(arrayA,limiteA, arrayA[i].numeroRubro))
            {
                maximoAvisos=contarPublicaciones(arrayA,limiteA, arrayA[i].numeroRubro);
                auxIndicePublicacion=i;
            }
        }
    }
    if(maximoAvisos>0)
    {
        printf("Rubro: %s - Cantidad de avisos: %d\n",arrayA[auxIndicePublicacion].textoAviso, maximoAvisos);
    }
    else
    {
        printf("No hay publicaciones");
    }

    return retorno;
}

int contarPublicaciones(Aviso* array, int limite, int rubro)
{
    int i;
    int contador = -1;

    if(limite > 0 && array != NULL)
    {
        contador = 0;
        for(i=0;i<limite-1;i++)
        {
            if(!array[i].isEmpty && array[i].estado && rubro == array[i].numeroRubro)
            {
                contador++;
            }
        }
    }
    return contador;
}

int informe_rubroMenosActivas(Aviso* arrayA, int limiteA)
{
    int retorno = -1;
    int i;
    int maximoAvisos=limiteA+1;
    int auxIndicePublicacion;

    if(limiteA > 0 && arrayA != NULL)
    {
        retorno = 0;
        for(i=0;i<limiteA-1;i++)
        {
            if(!arrayA[i].isEmpty && maximoAvisos > contarPublicaciones(arrayA,limiteA, arrayA[i].numeroRubro))
            {
                maximoAvisos=contarPublicaciones(arrayA,limiteA, arrayA[i].numeroRubro);
                auxIndicePublicacion=i;
            }
        }
    }
    if(maximoAvisos>0)
    {
        printf("Rubro: %s - Cantidad de avisos: %d\n",arrayA[auxIndicePublicacion].textoAviso, maximoAvisos);
    }
    else
    {
        printf("No hay publicaciones");
    }

    return retorno;
}
