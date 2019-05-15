#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "parser.h"
#include "utn.h"
#include "ArrayList.h"
void AddMovieToFile(char * path,char*link,char*tittle,char*genero,char*puntaje,char*duracion,char*descripcion);
void movie_CargarPelicula(char *strtitulo, char *strgenero,char *strdescripcion,char *strlinkImagen,char *strduracion,char *strpuntaje);

void cargarPelicula(EMovie* lista,ArrayList* arrayList);
int main()
{
    char seguir='s';
    int opcion=0;
    int i;

    EMovie* pArrayEmovie;
    ArrayList* plistaPeliculas = al_newArrayList();
    parserEMovie("data.txt",plistaPeliculas);
    EMovie * auxiliar;


    al_add(plistaPeliculas,movie_newParametros("PELICULA","CUALQUIERA","EXTRANNNASSDA","AGSTADEBAS","2","5"));

    for(i=0;i<al_len(plistaPeliculas);i++)
    {
    movie_print(al_get(plistaPeliculas,i));
    printf("------------------\n");
    }

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                cargarPelicula(pArrayEmovie,plistaPeliculas);
                break;
            case 2:
                printf("Cual pelicula?\n");

                for(i = 0; i < al_len(plistaPeliculas); i++){
                    printf("%d - %s\n", i + 1, al_get(plistaPeliculas, i));
                }

                scanf("%d",&i);
                al_remove(plistaPeliculas,i-1);


                for(i = 0; i < al_len(plistaPeliculas); i++)
                {
                    pArrayEmovie=al_get(plistaPeliculas,i);
                }

                break;
            case 3:
                auxiliar= plistaPeliculas->get(plistaPeliculas,1);
                if(auxiliar!=NULL)
                {
                    system("clear");
                    movie_printTittle(auxiliar);
                }
               break;
            case 4:// Generar página web


                seguir = 'n';
                break;
        }
    }

    return 0;
}

void AddMovieToFile(char * path,char*link,char*tittle,char*genero,char*puntaje,char*duracion,char*descripcion)
{
    FILE* pFile;
    pFile = fopen(path,"a");

    char buffer[1080]="<article class='col-md-4 article-intro'> <a href='#'> <img class='img-responsive img-rounded' src='";
    strcat(buffer,link);
    strcat(buffer,"' alt=''></a><h3><a href='#'>");
    strcat(buffer,tittle);
    strcat(buffer,"</a></h3><ul><li>Género:");
    strcat(buffer,genero);
    strcat(buffer,"</li><li>Puntaje:");
    strcat(buffer,puntaje);
    strcat(buffer,"</li><li>Duración:");
    strcat(buffer,duracion);
    strcat(buffer,"</li></ul><p>");
    strcat(buffer,descripcion);
    strcat(buffer,"</p></article>");

    fprintf(pFile,buffer);

    fclose(pFile);
}

void cargarArchivo(ArrayList* lista)
{
    FILE*pFile;
    pFile=fopen("data.txt","w");
    fwrite(lista,sizeof(ArrayList),1,pFile);
    fclose(pFile);

}
void cargarPelicula(EMovie* lista,ArrayList* arrayList)
{
    char titulo[20];
    char genero[20];
    char descripcion[50];
    char linkImagen[50];
    char duracion[50];
    char puntaje[50];

    EMovie* auxLista;
    if(!getValidString("ingrese el Titulo de la pelicula: \n","ERROR, Titulo no valido\n","ERROR, Titulo muy largo\n",titulo,25,2))
        {
        if(!getValidString("ingrese el Genero de la pelicula:\n","ERROR, Genero no valido\n","muy largo\n",genero,25,2))
            {
            if(!getValidString("ingrese la Descripcion de la pelicula:","ERROR, Descripcion no valida","ERROR, Muy largo",descripcion,25,2))
                {
                getString("ingrese el Link de la imagen para la Pelicula :",linkImagen);
                    {
                    if(getStringNumeros("Ingrese la duracion de la pelicula en Minutos?",duracion)==1)
                    {
                        if(getStringNumeros("Puntaje del [1-5]?",puntaje)==1)
                       {
                        auxLista=movie_newParametros(titulo,genero,descripcion,linkImagen,duracion,puntaje);
                        al_add(arrayList,auxLista);
                       }
                    }
                }
            }
        }
    }
    else
        printf("datos ingresados no valido");
    }

