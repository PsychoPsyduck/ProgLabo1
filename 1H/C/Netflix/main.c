#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
     int idSerie;
     char titulo[20];
     //genero(idGenero, descripcion); //FK: Foreign Key //Cardinalidad
     int duracion;
     //int director; //FK: Foreign Key //Cardinalidad
     int temporadas;
}eSerie;


typedef struct
{
    int idDirector; //PK: Primary Key
    char nombre[20];
    char nacionalidad[20];
}eDirector;

typedef struct
{
    int idCliente;
    char nombre[20];
    int idSerie;
}eCliente;

typedef struct
{
    int idGenero; //PK: Primary Key
    char descripcion[20];
}eGenero;


void inicializarCliente(eCliente[]);
void inicializarSerie(eSerie[]);

void mostrarDatosCliente(eCliente[]);
void mostrarDatosSerie(eSerie[]);

void mostrarClienteConSerie(eCliente[], eSerie[]);

int main()
{
    int opcion;
    eCliente clientes[4];
    eSerie series[4];

    do
    {
        printf("1.Cargar\n2.Mostrar datos\n3.Mostrar clientes con nombre de serie\n8.Salir\nElija una Opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                inicializarCliente(clientes);
                inicializarSerie(series);
                break;

            case 2:
                mostrarDatosCliente(clientes);
                mostrarDatosSerie(series);
                break;

            case 3:
                mostrarClienteConSerie(clientes, series);
                break;

            case 4:

                break;
        }
    }while(opcion!=8);

    return 0;
}

void inicializarCliente(eCliente clientes[])
{
    int idClienteHC[]= {100,101,102,103};
    char nombreHC[][50]= {"Juan","Luis","Mario","Pepe"};
    int serieHC[]= {1, 1, 4, 3};
    int i;


    for(i=0; i<4; i++)
    {
        clientes[i].idCliente=idClienteHC[i];
        strcpy(clientes[i].nombre,nombreHC[i]);
        clientes[i].idSerie=serieHC[i];
    }
}

void inicializarSerie(eSerie series[])
{
    int idSerieHC[]= {1,2,3,4};
    char tituloHC[][50]= {"Friends","Vikings","Lost","Got"};
    int duracionHC[]= {40, 50, 50, 55};
    int temporadasHC[]= {10, 5, 6, 7};
    int i;


    for(i=0; i<4; i++)
    {
        series[i].idSerie=idSerieHC[i];
        strcpy(series[i].titulo,tituloHC[i]);
        series[i].duracion=duracionHC[i];
        series[i].temporadas=temporadasHC[i];
    }
}

void mostrarDatosCliente(eCliente clientes[])
{
    int i;

    for(i=0; i<4; i++)
    {
        printf("%d--%s--%d\n", clientes[i].idCliente, clientes[i].nombre, clientes[i].idSerie);
    }
}

void mostrarDatosSerie(eSerie series[])
{
    int i;

    for(i=0; i<4; i++)
    {
        printf("%d--%s--%d--%d\n", series[i].idSerie, series[i].titulo, series[i].duracion, series[i].temporadas);
    }
}

void mostrarClienteConSerie(eCliente clientes[], eSerie series[])
{
    int i;
    int j;

    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            if(clientes[i].idSerie == series[j].idSerie)
            {
                printf("%s--%s", clientes[i].nombre, series[j].titulo);
                break;
            }
        }
    }
}
