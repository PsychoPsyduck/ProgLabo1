#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "informe.h"
#include "utn.h"

int informe_masAvisos(Cliente* array,int limite)
{
    int maximoAvisos=0;
    int indiceMaximo;
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite-1;i++)
        {
            if(!array[i].isEmpty && array[i].avisoActivo > maximoAvisos)
            {
                maximoAvisos = array[i].avisoActivo;
                indiceMaximo = i;
            }
        }
    }
    printf("%s - %s - %d- Id Cliente: %d - Avisos activos: %d\n",array[indiceMaximo].nombre, array[indiceMaximo].apellido, array[indiceMaximo].cuit, array[indiceMaximo].idCliente, array[indiceMaximo].avisoActivo);

    return retorno;
}


informe_publicacionesPorRubro(Aviso* array,int limite, int rubro)
{
    int i;
    int cantidad;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite-1;i++)
        {
            if(!array[i].isEmpty && array[i].numeroRubro = rubro)
            {
                cantidad++;
            }
        }
    }
    printf("Rubro: %d - Cantidad de avisos: %d \n", rubro )
}
