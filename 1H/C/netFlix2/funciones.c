#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"

void cargarSeries(eSerie serie[], int tam )
{
    int i;
    int idSerie[] = { 1, 2, 3, 4, 5};
    int duracion[] = { 40, 40, 40, 20 };
    char titulo[][25] = { "BrBa", "Viking", "Gotham", "Glee", "OA" };
    int temporadas[] = { 5, 4, 5, 6, 6};

    for(i=0; i<tam; i++)
    {
        serie[i].idSerie=idSerie[i];
        serie[i].duracion=duracion[i];
        serie[i].temporadas=temporadas[i];
        strcpy(serie[i].titulo,titulo[i]);
    }
}

void cargarClientes(eCliente cliente[], int tam)
{
    int i;
    int idCliente[] = {100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    int serie[] = {1, 2, 2, 3, 1, 5, 4, 2, 1, 1};
    char nombre[][20] = {"Juan", "Pedro", "Pablo", "Maria", "Jesus", "Judas", "Mateo", "Juana", "Raul", "Beatriz"};

    for(i=0; i<tam; i++)
    {
        cliente[i].idCliente = idCliente[i];
        strcpy(cliente[i].nombre, nombre[i]);
        cliente[i].serie = serie[i];
    }
}
void mostrarSeries(eSerie serie[],int tam)
{
    int i;
    printf("Id serie\tTitulo\tDuracion\tTemporadas\n\n");
    for(i=0; i<tam; i++)
    {
        printf("\t%d\t%s\t%d\t\t%d\n", serie[i].idSerie, serie[i].titulo, serie[i].duracion, serie[i].temporadas);
    }
}
void mostrarClientes(eCliente cliente[], int tam)
{

    int i;
    printf("Id Cliente\tNombre\tidSerie\n\n");
    for(i=0; i<tam; i++)
    {
        printf("\t%d\t%s\t\t%d\n", cliente[i].idCliente, cliente[i].nombre, cliente[i].serie);
    }
}
void mostrarClienteYSerie(eCliente cliente[],eSerie serie[], int tamC, int tamS)
{
    int i,j;
    printf("Nombre\tSerie\n\n");

    for(i=0; i<tamC; i++)
    {
        for(j=0; j<tamS; j++)
        {
            if(cliente[i].serie == serie[j].idSerie)
            {
                printf("%s\t%s\n",cliente[i].nombre, serie[j].titulo);
                break;
            }
        }
    }

}
void mostrarSerieYCliente(eSerie serie[], eCliente cliente[], int tamS, int tamC)
{
    int i,j;
    for(i=0;i<tamS;i++)
    {
        printf("%s\n", serie[i].titulo);
        for(j=0; j<tamC; j++)
        {
            if(cliente[j].serie == serie[i].idSerie)
            {
                printf("\t%s\n",cliente[j].nombre);
            }
        }

    }
}
void serieMenosVista(eSerie serie[], eCliente cliente[], int tamS, int tamC)
{
    int i, j;
    eContador contador[tamS];
    for(i=0;i<tamS;i++)
    {
        contador[i].idSerie = serie[i].idSerie;
        contador[i].cont = 0;
    }

    for(i=0;i<tamS;i++)
    {
        for(j=0; j<tamC; j++)
        {

        }

    }
}
