#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

/*typedef struct
{
    int director;
    char nombre[20];
    char nacionalidad[20];
}eDirector;*/

typedef struct
{
    int idSerie;
    char titulo[20];
    int duracion;
    int temporadas;
} eSerie;
typedef struct
{
    int idCliente;
    char nombre[20];
    int serie;
}eCliente;
typedef struct
{
    int idSerie;
    int cont;
}eContador;

void cargarSeries(eSerie serie[], int);
void cargarClientes(eCliente cliente[], int);
void mostrarSeries(eSerie serie[], int);
void mostrarClientes(eCliente cliente[], int);
void mostrarClienteYSerie(eCliente cliente[],eSerie serie[], int, int);
void mostrarSerieYCliente(eSerie serie[], eCliente cliente[], int, int);
void serieMenosVista(eSerie serie[], eCliente cliente[], int, int);
