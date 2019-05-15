#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "ArrayList.h"
int parserEMovie(char* path , ArrayList* pArrayListEMovie)
{
    FILE* pFile;
    pFile=fopen(path,"r");

    int retorno = -1;
    char bTitulo[4096];
    char bGenero[4096];
    char bDescripcion[4096];
    char bLinkImagen[4096];
    char bDuracion[4096];
    char bPuntaje[4096];
    EMovie* auxiliarPelicula;

    if(pFile != NULL)
    {
        retorno = 0;
       do
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
                   bTitulo,bGenero,bDescripcion,bLinkImagen,bDuracion,bPuntaje);

            auxiliarPelicula = movie_newParametros(bTitulo,bGenero,bDescripcion,bLinkImagen,bDuracion,bPuntaje);
            al_add(pArrayListEMovie,auxiliarPelicula);

        }while(!feof(pFile));
    }
    else
        printf("no se pudo encontrar el archivo");

    return retorno;
}




