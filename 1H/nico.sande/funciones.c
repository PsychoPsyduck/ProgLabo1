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

void cargarDuenioHC(eDuenio listaDuenios[], int TAMDUENIO)
{
    int i;
    int idDuenio[] = { 1, 2, 3, 4, 5};
    char nombreYapellido[][25] = { "Juan Perez", "Lucas Gomez", "Romina Gonzalez", "Pepe Sanchez", "Julieta Suarez" };
    char direccion[][25] = { "Azcuenaga", "Lavalle", "9 de julio", "Islas Malvinas", "Alsina" };
    int nroTarjetaDeCredito[] = { 1111, 2222, 3333, 4444, 5555};
    int estado[] = { 1, 1, 1, 1, 1};

    for(i=0; i<TAMDUENIO; i++)
    {
        listaDuenios[i].idDuenio=idDuenio[i];
        strcpy(listaDuenios[i].nombreYapellido,nombreYapellido[i]);
        strcpy(listaDuenios[i].direccion,direccion[i]);
        listaDuenios[i].nroTarjetaDeCredito=nroTarjetaDeCredito[i];
        listaDuenios[i].estado=estado[i];
    }

    printf("\nClientes cargados... \n\n");
}

void cargarAutomovilHC(eAutomovil listaAutos[], int TAMAUTO )
{
    int i;
    char patente[][25] = { "ABC123", "DEF456", "GHI789", "AAA012", "MNO345"};
    int marca[] = { 1, 2, 3, 4, 3};
    int idDuenio[] = { 1, 2, 3, 4, 5};
    int horaDeEntrada[] = { 11, 22, 3, 14, 9};
    int estado[] = { 1, 1, 1, 1, 1};

    for(i=0; i<TAMAUTO; i++)
    {
        strcpy(listaAutos[i].patente,patente[i]);
        listaAutos[i].marca=marca[i];
        listaAutos[i].idDuenio=idDuenio[i];
        listaAutos[i].horaDeEntrada=horaDeEntrada[i];
        listaAutos[i].estado=estado[i];
    }

    printf("\nAutos cargados... \n\n");
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

            if(listaAutos[i].horaDeEntrada < listaAutos[j].horaDeEntrada)//else if pasa esto y es igual a 0 lo anterior
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
    printf("\nDuenio\t\t\tAuto\t\t\tPatente\n\n");


    for(i=0; i<TAMDUENIO; i++)
    {
        for(j=0; j<TAMAUTO; j++)
        {
            if(listaDuenios[i].idDuenio == listaAutos[j].idDuenio)
            {
                //aux =
                switch(listaAutos[j].marca)
                {
                case 1:
                    printf("%s\t\tALPHA ROMEO\t\t%s\n\n",listaDuenios[i].nombreYapellido, listaAutos[j].patente);
                    break;

                case 2:
                    printf("%s\t\tFERRARI\t\t\t%s\n\n",listaDuenios[i].nombreYapellido, listaAutos[j].patente);
                    break;

                case 3:
                    printf("%s\t\tAUDI\t\t\t%s\n\n",listaDuenios[i].nombreYapellido, listaAutos[j].patente);
                    break;

                case 4:
                    printf("%s\t\tOTRO\t\t\t%s\n\n",listaDuenios[i].nombreYapellido, listaAutos[j].patente);
                    break;
                }
            }
        }

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

void modificarTarjeta(eDuenio listaDuenios[], int TAMDUENIO)
{
    int i;
    char aux[50];
    int nuevaTarjeta;
    char continuar;

    printf("Ingrese Nombre y Apellido a modificar: ");
    fflush(stdin);
    gets(aux);

    for(i=0; i<TAMDUENIO; i++)
    {
        if(strcmp(listaDuenios[i].nombreYapellido, aux)==0)
        {
            printf("Numero de tarjeta actual: %d", listaDuenios[i].nroTarjetaDeCredito);
            printf("\n\nIngrese nuevo numero de tarjeta: ");
            scanf("%d", &nuevaTarjeta);
            break;
        }
    }

    printf("Seguro desea hacer el cambio? s/n ");
    fflush(stdin);
    gets(&continuar);

    if(continuar == 's')
    {
        listaDuenios[i].nroTarjetaDeCredito=nuevaTarjeta;
        printf("Cambio realizado \n\n");
    }
    else
    {
        printf("No se realizo el cambio de tarjeta");
    }

}

void egresoDeAutomovil(eAutomovil listaAutos[], eDuenio listaDuenios[], int TAMAUTO)
{
    int i;
    char patente[8];
    int horaActual;
    int auxI;
    int costo;

    printf("Ingrese patente buscada: ");
    fflush(stdin);
    gets(&patente);

    for(i=0; i<TAMAUTO; i++)
    {
        if(strcmp(listaAutos[i].patente, patente)==0)
        {
            printf("Ingrese hora actual: ");
            scanf(&horaActual);

            auxI=i;

            break;
        }
    }

    while(horaActual <= listaAutos[auxI].horaDeEntrada)
    {
        printf("Error, reingrese hora actual: ");

        scanf(&horaActual);
    }


    switch(listaAutos[auxI].marca)
    {
    case 1:
        costo=(horaActual - listaAutos[auxI].horaDeEntrada) *150;
        printf("%s\t\t%s\t\tALPHA ROMEO\t\t%d\n\n",listaDuenios[auxI].nombreYapellido, listaAutos[auxI].patente, costo);
        break;

    case 2:
        costo=(horaActual-listaAutos[auxI].horaDeEntrada) *175;
        printf("%s\t\t%s\t\tFERRARI\t\t%d\n\n",listaDuenios[auxI].nombreYapellido, listaAutos[auxI].patente, costo);
        break;

    case 3:
        costo=(horaActual-listaAutos[auxI].horaDeEntrada) *200;
        printf("%s\t\t%s\t\tAUDI\t\t%d\n\n",listaDuenios[auxI].nombreYapellido, listaAutos[auxI].patente, costo);
        break;

    case 4:
        costo=(horaActual-listaAutos[auxI].horaDeEntrada) *250;
        printf("%s\t\t%s\t\tOTRO\t\t%d\n\n",listaDuenios[auxI].nombreYapellido, listaAutos[auxI].patente, costo);
        break;
    }

}

void propietariosAudi(eDuenio listaDuenios[], eAutomovil listaAutos[], int TAMDUENIO, int TAMAUTO)
{
    int i,j;
    int aux;
    printf("\nDuenio con audi\n\n");


    for(i=0; i<TAMDUENIO; i++)
    {
        for(j=0; j<TAMAUTO; j++)
        {
            if(listaDuenios[i].idDuenio == listaAutos[j].idDuenio)
            {
                if(listaAutos[j].marca == 3)
                {
                    printf("%s", listaDuenios[i].nombreYapellido);
                }
            }

        }

    }
}

void marcasMasEstacionadas(eAutomovil listaAutos[], int TAMAUTO)
{
    int i;
    int aux;
    int cont1=0;
    int cont2=0;
    int cont3=0;
    int cont4=0;

    printf("\nMarca mas estacionada\n\n");




    for(i=0; i<TAMAUTO; i++)
    {

        if(listaAutos[i].marca == 1)
        {
            cont1++;
        }
        else if(listaAutos[i].marca == 2)
        {
            cont2++;
        }
        else if(listaAutos[i].marca == 3)
        {
            cont3++;
        }
        else
        {
            cont4++;
        }

    }

    for(i=0; i<TAMAUTO; i++)
	{

	}

}
