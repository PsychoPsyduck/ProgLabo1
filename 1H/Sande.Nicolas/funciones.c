#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"


void cargarDuenio(eDuenio listaDuenios[], int TAMDUENIO)
{
    int i;
    int contador;
    char continuar;

    do
    {
        i=obtenerEspacioLibreDuenios(listaDuenios, TAMDUENIO);

        printf("Ingrese identificador de duenio: ");
        scanf("%d", &listaDuenios[i].idDuenio);

        printf("Ingrese Nombre y Apellido: ");
        fflush(stdin);
        gets(listaDuenios[i].nombreYapellido);

        printf("Ingrese domicilio: ");
        fflush(stdin);
        gets(listaDuenios[i].direccion);

        printf("Ingrese numero de tarjeta: ");
        scanf("%d", &listaDuenios[i].nroTarjetaDeCredito);

        listaDuenios[i].estado=1;


        if(contador<TAMDUENIO)
        {
            printf("continuar? s/n ");
            fflush(stdin);
            gets(&continuar);
        }
        else
        {
            break;
        }

    }
    while(continuar=='s');
}


void cargarAutomovil(eAutomovil listaAutos[], int TAMAUTO)
{
    int i;
    int contador;
    char continuar;

    do
    {
        i=obtenerEspacioLibreAutos(listaAutos, TAMAUTO);

        printf("Ingrese patente: ");
        fflush(stdin);
        gets(listaAutos[i].patente);

        printf("Ingrese modelo: (1Alpha 2Ferrari 3Audi 4Otros)");
        scanf("%d", &listaAutos[i].marca);

        while(listaAutos[i].marca<1 || listaAutos[i].marca >4)
        {
            printf("Error. Reingrese modelo valido: (1Alpha 2Ferrari 3Audi 4Otros)");
            scanf("%d", &listaAutos[i].marca);
        }

        printf("Ingrese identificador de duenio: ");
        scanf("%d", &listaAutos[i].idDuenio);

        printf("Ingrese solo la hora de entrada: ");
        scanf("%d", &listaAutos[i].horaDeEntrada);

        while(listaAutos[i].horaDeEntrada<0 || listaAutos[i].horaDeEntrada >23)
        {
            printf("Hora invalida. Reingrese la hora de entrada: ");
            scanf("%d", &listaAutos[i].horaDeEntrada);
        }


        listaAutos[i].estado=1;


        if(contador<TAMAUTO)
        {
            printf("continuar? s/n ");
            fflush(stdin);
            gets(&continuar);
        }
        else
        {
            break;
        }

    }
    while(continuar=='s');
}



void ordenarListaAutos(eAutomovil listaAutos[], int TAMAUTO)
{
    int i,j;
    eAutomovil auxAutos;

    for(i=0; i<TAMAUTO-1; i++)
    {
        for(j=i+1; j<TAMAUTO; j++)
        {
            if(strcmp(listaAutos[i].patente, listaAutos[j].patente)<0)
            {
                auxAutos=listaAutos[i];
                listaAutos[i]=listaAutos[j];
                listaAutos[j]=auxAutos;
            }
        }

        for(j=i+1; j<TAMAUTO; j++)
        {
            if(listaAutos[i].horaDeEntrada < listaAutos[j].horaDeEntrada)
            {
                auxAutos=listaAutos[i];
                listaAutos[i]=listaAutos[j];
                listaAutos[j]=auxAutos;
            }
        }
    }

}

void mostrarAutosYDuenios(eDuenio listaDuenios[], eAutomovil listaAutos[], eMarca listaMarcas[], int TAMDUENIO, int TAMAUTO)
{
    int i,j;
    int aux;
    printf("\nDuenio\tAuto\n\n");


    for(i=0; i<TAMDUENIO; i++)
    {
        for(j=0; j<TAMAUTO; j++)
        {
            if(listaDuenios[i].idDuenio == listaAutos[j].idDuenio)
            {
                aux=listaAutos[j].idDuenio;
                printf("%s\t%d\n\n",listaDuenios[i].nombreYapellido, listaAutos[j].marca);
                break;
            }
        }

    }


}

void cargarMarca(eMarca listaMarcas[], int TAMMARCA)
{
    int i;
    int marca[] = {1, 2, 3, 4};
    char nombre[][11] = {"ALPHA_ROMEO", "FERRARI", "AUDI", "OTROS"};

    for(i=0; i<TAMMARCA; i++)
    {
        listaMarcas[i].marca = marca[i];
        strcpy(listaMarcas[i].nombre, nombre[i]);
    }
}

int obtenerEspacioLibreDuenios(eDuenio listaDuenios[], int TAMDUENIO)
{
    int i=-1;
    int auxIndice;

    for(i=0; i<TAMDUENIO; i++)
    {
        if(listaDuenios[i].estado!=1)
        {
            auxIndice=i;
            break;
        }
    }
    return(auxIndice);
}

int obtenerEspacioLibreAutos(eAutomovil listaAutos[], int TAMAUTO)
{
    int i=-1;
    int auxIndice;

    for(i=0; i<TAMAUTO; i++)
    {
        if(listaAutos[i].estado!=1)
        {
            auxIndice=i;
            break;
        }
    }
    return(auxIndice);
}
