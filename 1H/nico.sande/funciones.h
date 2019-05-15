#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct {

    int idDuenio;
    char nombreYapellido[20];
    char direccion[20];
    int nroTarjetaDeCredito;
    int estado;

}eDuenio;

typedef struct {

    char patente[8];
    int marca;
    int idDuenio;
    int horaDeEntrada;
    int estado;

}eAutomovil;

typedef struct {

    int marca;
    char nombre[11];

}eMarca;

void cargarDuenio(eDuenio listaDuenios[], int tamDuenio);
void cargarAutomovil(eAutomovil listaAutos[], int tamAuto);
void ordenarListaAutos(eAutomovil listaAutos[], int tamAuto);
void mostrarAutosYDuenios(eDuenio listaDuenios[], eAutomovil listaAutos[], eMarca listaMarcas[], int tamDuenio, int tamAuto);
int obtenerEspacioLibreDuenios(eDuenio listaDuenios[], int TAMDUENIO);
int obtenerEspacioLibreAutos(eAutomovil listaAutos[], int TAMAUTO);
void cargarDuenioHC(eDuenio listaDuenios[], int tamDuenio);
void cargarAutomovilHC(eAutomovil listaAutos[], int tamAuto );
void modificarTarjeta(eDuenio listaDuenios[], int TAMDUENIO);
void egresoDeAutomovil(eAutomovil listaAutos[], eDuenio listaDuenios[], int TAMAUTO);
void propietariosAudi(eDuenio listaDuenios[], eAutomovil listaAutos[], int TAMDUENIO, int TAMAUTO);


