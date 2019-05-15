#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"
#define TAMDUENIO 40
#define TAMAUTO 20
#define TAMMARCA 4


int main()
{
    int opcion;
    eDuenio listaDuenios[TAMDUENIO];
    eAutomovil listaAutos[TAMAUTO];
    eMarca listaMarcas[TAMMARCA];

//    cargarMarca(listaMarcas, TAMMARCA);

    do
    {
        printf("1.Cargar duenio\n2.Ingresar auto\n3.Ordenar y mostrar datos(5.a)\n4.Cambio de tarjeta\n5.Egreso de Automovil\n6.Propietarios con Audi\n8.Salir\nElija una Opcion: ");

        //if (flag) para Nota0
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                //cargarDuenio(listaDuenios, TAMDUENIO);
                cargarDuenioHC(listaDuenios, TAMDUENIO);
                break;

            case 2:
                //cargarAutomovil(listaAutos, TAMAUTO);
                cargarAutomovilHC(listaAutos, TAMAUTO);
                break;

            case 3:
                ordenarListaAutos(listaAutos, TAMAUTO);
                mostrarAutosYDuenios(listaDuenios, listaAutos, listaMarcas, TAMDUENIO, TAMAUTO);
                break;

            case 4:
                modificarTarjeta(listaDuenios, TAMDUENIO);
                break;

            case 5:
                egresoDeAutomovil(listaAutos, listaDuenios, TAMAUTO);
                break;

            case 6:
                propietariosAudi(listaDuenios, listaAutos, TAMDUENIO, TAMAUTO);
                break;
        }
    }while(opcion!=8);

    return 0;
}

