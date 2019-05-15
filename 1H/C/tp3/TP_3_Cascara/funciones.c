#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>


eMovie* nuevaPelicula()
{

    eMovie* unaPelicula;


    char tituloa[50];
    char generoa[50];
    int duraciona;
    char descripciona[50];
    int puntajea;
    char linkImagena[50];

    printf("Titulo: ");
    fflush(stdin);
    gets(tituloa);

    printf("Genero: ");
    fflush(stdin);
    gets(generoa);

    printf("Duracion: ");
    scanf(&duraciona);

    printf("Descripcion: ");
    fflush(stdin);
    gets(descripciona);

    printf("Puntaje: ");
    scanf(&puntajea);

    printf("Link de imagen: ");
    fflush(stdin);
    gets(linkImagena);

    unaPelicula = newPelicula(tituloa, generoa, duraciona, descripciona, puntajea, linkImagena);

    return unaPelicula;
}


eMovie* newPelicula(char* titulo, char* genero, int duracion, char* descripcion, int puntaje, char* linkImagen)
{
    eMovie* peli;

    peli = newPeliVacia();

    if(peli!=NULL)
    {
        strcpy(peli->titulo, titulo);
        strcpy(peli->genero, genero);
        peli->duracion=duracion;
        strcpy(peli->descripcion, descripcion);
        peli->puntaje=puntaje;
        strcpy(peli->linkImagen, linkImagen);
        peli->estado=0;
    }

    return peli;
}


eMovie* newPeliVacia()
{
    eMovie* unaPelicula;

    unaPelicula =(eMovie*) malloc(sizeof(eMovie));
    if(unaPelicula!=NULL)
    {

        strcpy(unaPelicula->titulo, "");
        strcpy(unaPelicula->genero, "");
        unaPelicula->duracion=0;
        strcpy(unaPelicula->descripcion, "");
        unaPelicula->puntaje=0;
        strcpy(unaPelicula->linkImagen, "");
        unaPelicula->estado=0;
    }

    return unaPelicula;
}




void borrarPelicula(eMovie* catalogo)
{
    int flag=0,i;
    char titulo[50];
    char opcion;

    printf("Ingrese titulo a borrar: ");
    fflush(stdin);
    gets(titulo);

    for(i=0; i<50; i++)
    {
        if(strcmp(titulo, *(catalogo+i)->titulo)==0) //probar *(catalogo+i).titulo
        {

            printf("\nTitulo encontrado. Seguro desea borrar? s/n");
            opcion=getche();
            if(opcion=='s')
            {
                *(catalogo+i)->titulo=""; //probar *(catalogo+i).titulo. Tambien usar funcion que devuelva todo 0
                printf("Titulo eliminado");
            }
            else
            {
                printf("El titulo no fue eliminado");
            }
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("Titulo inexistente");
        getch();
    }
}



void crearTxt(eMovie* catalogo)
{
    int i;
    FILE *f;
    f=fopen("Lista de peliculas.txt", "w");

    if(f != NULL)
    {
        fprintf(f,"Listado de peliculas\n\n");
        fprintf(f,"Titulo    Genero     Duracion    Descripcion    Puntaje    Link de imagen \n");

        for(i=0; i<50; i++)
        {
            if(*(catalogo+i)->estado == '1')
            {
                fprintf(f, "%s  %s  %d  %s  %d  %s\n", catalogo[i].titulo, catalogo[i].genero, catalogo[i].duracion, catalogo[i].descripcion, catalogo[i].puntaje, catalogo[i].linkImagen);
            }
        }
    }
    else
    {

        printf("No se pudo abrir el archivo\n");
    }

    fclose(f);

    printf("Listado creado con exito\n");
    system("pause");
}

void crearPagina(eMovie* catalogo, int i)
{
    FILE *archivo;


    char imagen[50]=*(catalogo+i).linkImagen;
    char tituloa[50]=*(catalogo+i).titulo;
    char generoa[50]=*(catalogo+i).genero;
    int duraciona=*(catalogo+i).duracion;
    char descripciona[50]=*(catalogo+i).descripcion;
    int puntajea=*(catalogo+i).puntaje;

    char buffer[1080]= {};

    strcat(buffer,"<article class='col-md-4 article-intro'> <a href='#'> <img class='img-responsive img-rounded' src='");
    strcat(buffer,imagena);
    strcat(buffer,"' alt=''> </a> <h3> <a href='#'>");
    strcat(buffer,tituloa);
    strcat(buffer,"e</a> </h3> <ul> <li>Género:");
    strcat(buffer,generoa);
    strcat(buffer,"</li> <li>Duracion:");
    strcat(buffer,duraciona);
    strcat(buffer,"</li> <li>Puntaje:");
    strcat(buffer,puntajea);
    strcat(buffer,"</li> </ul> <p>");
    strcat(buffer,descripciona);
    strcat(buffer,"</p> </article>");


    fprintf(archivo,buffer);

    fclose(archivo);
}

int buscarLibre(eMovie* catalogo)
{
	int index=-1;
	int i;
	for( i=0; i < A; i++)
	   if(*(catalogo+i)->estado == 0){
		index=i;
		break;
	   }
	return index;
}
