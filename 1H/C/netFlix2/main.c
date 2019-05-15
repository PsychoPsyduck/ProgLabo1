#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"
#define TAMSERIE 5
#define TAMCLIENTE 10

int main()
{
    eSerie series[TAMSERIE];
    eCliente clientes[TAMCLIENTE];
    int opcion;
    do
    {
        system("cls");
        printf("1 - Cargar series\n");
        printf("2 - Cargar clientes\n");
        printf("3 - Mostrar series\n");
        printf("4 - Mostrar cliente\n");
        printf("5 - Mostrar cliente \ serie\n");
        printf("6 - Mostrar serie \ cliente\n");
        printf("9 - Salir\n");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1: cargarSeries(series, TAMSERIE);
                break;
        case 2: cargarClientes(clientes, TAMCLIENTE);
            break;
        case 3: mostrarSeries(series, TAMSERIE);
            break;
        case 4: mostrarClientes(clientes, TAMCLIENTE);
            break;
        case 5: mostrarClienteYSerie(clientes,series,TAMCLIENTE, TAMSERIE);
            break;
        case 6: mostrarSerieYCliente(series,clientes,TAMSERIE,TAMCLIENTE);
            break;
        }
    system("pause");}
    while(opcion !=9);
    return 0;
}
