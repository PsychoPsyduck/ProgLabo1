#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"
#define TAMDUENIO 40
#define TAMAUTO 20
#define TAMMARCA 4

#include "funciones.h"

int main()
{
    int opcion;
    eDuenio listaDuenios[TAMDUENIO];
    eAutomovil listaAutos[TAMAUTO];
    eMarca listaMarcas[TAMMARCA];

//    cargarMarca(listaMarcas, TAMMARCA);

    do
    {
        printf("1.Cargar duenio\n2.Ingresar auto\n3.Ordenar y mostrar datos(5.a)\n8.Salir\nElija una Opcion: ");
        //if (flag) para Nota0
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                cargarDuenio(listaDuenios, TAMDUENIO);
                break;

            case 2:
                cargarAutomovil(listaAutos, TAMAUTO);
                break;

            case 3:
                ordenarListaAutos(listaAutos, TAMAUTO);
                mostrarAutosYDuenios(listaDuenios, listaAutos, listaMarcas, TAMDUENIO, TAMAUTO);
                break;

            case 4:

                break;
        }
    }while(opcion!=8);

    return 0;
}

