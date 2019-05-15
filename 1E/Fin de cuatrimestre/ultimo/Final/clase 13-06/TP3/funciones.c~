#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funciones.h"
#include "utn.h"
static int isValidTitulo(char* titulo);
static int isValidDescripcion(char* descripcion);
static int isValidGenero(char* genero);
static int isValidLink(char* link);
static int isValidDuracionMinutos(int duracion);
static int isValidPuntaje(int puntaje);
//static int proximoId(void);
//static int isValidIsEmpty(int isEmpty);



EMovie* movie_new(void)
{

    EMovie* returnAux = (EMovie*) malloc(sizeof(EMovie));
    return returnAux;
}

void movie_delete(EMovie* this)
{
    if(this != NULL)
        free(this);
}

EMovie* movie_newParametros(char *strtitulo, char *strgenero,char *strdescripcion,char *strlinkImagen,char *strduracion,char *strpuntaje)
{
    int duracion;
    int puntaje;
    EMovie* this;
    this = movie_new();

    duracion = atoi(strduracion); //FALTA VALIDAR
    puntaje = atoi(strpuntaje); //FALTA VALIDAR
    if( !movie_setTitulo(this,strtitulo) &&
        !movie_setGenero(this,strgenero) &&
        !movie_setDescripcion(this,strdescripcion) &&
        !movie_setLink(this,strlinkImagen)&&
        !movie_setDuracion(this,duracion)&&
        !movie_setPuntaje(this,puntaje))
    {

        return this;
    }
    movie_delete(this);
    return NULL;
}

int movie_compareTitulo(EMovie* pEMovieA,EMovie* pEMovieB)
{
    char tituloEMovieA[51];
    char tituloEMovieB[51];
    int retorno = 0;
    if(pEMovieA!=NULL && pEMovieB != NULL)
    {
        movie_getTitulo(pEMovieA,tituloEMovieA);
        movie_getTitulo(pEMovieB,tituloEMovieB);
        retorno = strcmp(tituloEMovieA,tituloEMovieB);
    }
    return retorno ;
}


void movie_printTittle(EMovie* this)
{
    char titulo[51];
    if(this != NULL)
    {
        movie_getTitulo(this,titulo);
        printf(" %s\n",titulo);
    }

}
void movie_print(EMovie* this)
{
    int puntaje;
    char titulo[51];
    char genero[51];
    char descripcion[51];
    char link[51];
    int duracion;
    if(this != NULL)
    {
        movie_getDescripcion(this,descripcion);
        movie_getDuracion(this,&duracion);
        movie_getGenero(this,genero);
        movie_getLink(this,link);
        movie_getPuntaje(this,&puntaje);
        movie_getTitulo(this,titulo);
        printf("Descripcion: %s\nDuracion: %d\nGenero: %s\nLink: %s\nPuntaje: %d\nTitulo: %s\n",descripcion,duracion,genero,link,puntaje,titulo);
    }

}

int movie_setPuntaje(EMovie* this, int puntaje)
{
    int retorno = -1;
    if(this != NULL && isValidPuntaje(puntaje)==0)
    {
        this->puntaje = puntaje;
        retorno = 0;
    }
    return retorno;
}

int movie_getPuntaje(EMovie* this, int *puntaje)
{
    int retorno = -1;
    if((this != NULL) && puntaje!=NULL)
    {
        *puntaje = this->puntaje;
        retorno = 0;
    }
    return retorno;
}



int movie_setTitulo(EMovie* this, char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo != NULL && (isValidTitulo(titulo)==0))
    {
        strcpy(this->titulo,titulo);
        retorno = 0;
    }
    return retorno;
}


int movie_getTitulo(EMovie* this, char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo != NULL)
    {
        strcpy(titulo , this->titulo);
        retorno = 0;
    }
    return retorno;
}


/*
int movie_setId(EMovie* this, int id)
{
    static int ultimoId = -1;
    int retorno = -1;
    if(this != NULL && id == -1)
    {
        retorno = 0;
        ultimoId++;
        this->id = ultimoId;
    }
    else if(this != NULL && id > ultimoId)
    {
        retorno = 0;
        ultimoId = id;
        this->id = ultimoId;
    }
    return retorno;
}

int movie_getId(EMovie* this, int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        retorno = 0;
        *id = this->id;
    }
    return retorno;
}
*/
int movie_setLink(EMovie* this, char* link)
{
    int retorno = -1;
    if(this != NULL && link != NULL && (isValidLink(link)==0))
    {
        strcpy(this->linkImagen,link);
        retorno = 0;
    }
    return retorno;
}

int movie_getLink(EMovie* this, char* link)
{
    int retorno = -1;
    if(this != NULL && link != NULL)
    {
        strcpy(link , this->linkImagen);
        retorno = 0;
    }
    return retorno;
}

int movie_setDescripcion(EMovie* this, char* descripcion)
{
    int retorno = -1;
    if(this != NULL && descripcion != NULL && (isValidDescripcion(descripcion)==0))
    {
        strcpy(this->descripcion,descripcion);
        retorno = 0;
    }
    return retorno;
}

int movie_getDescripcion(EMovie* this, char* descripcion)
{
    int retorno = -1;
    if(this != NULL && descripcion != NULL)
    {
        strcpy(descripcion , this->descripcion);
        retorno = 0;
    }
    return retorno;
}

int movie_setGenero(EMovie* this, char* genero)
{
    int retorno = -1;
    if(this != NULL && genero != NULL && (isValidGenero(genero)==0))
    {
        strcpy(this->genero,genero);
        retorno = 0;
    }
    return retorno;
}

int movie_getGenero(EMovie* this, char* genero)
{
    int retorno = -1;
    if(this != NULL && genero != NULL)
    {
        strcpy(genero , this->genero);
        retorno = 0;
    }
    return retorno;
}


int movie_setDuracion(EMovie* this, int duracion)
{
    int retorno = -1;

    if(this != NULL && isValidDuracionMinutos(duracion)==0)
    {
        this->duracion = duracion;
        retorno = 0;
    }
    return retorno;
}

int movie_getDuracion(EMovie* this, int* duracion)
{
    *duracion=55;
    int retorno = -1;
    if((this != NULL) &&duracion!=NULL)//validar duracion
    {

        *duracion = this->duracion;
        retorno = 0;
    }
    return retorno;
}

/*
int movie_getIsEmpty(EMovie* this, int* isEmpty)
{
    int retorno = -1;
    if(this != NULL && isEmpty != NULL)
    {
        retorno = 0;
        *isEmpty = this->isEmpty;
    }
    return retorno;
}

int movie_setIsEmpty(EMovie* this, int isEmpty)
{
    int retorno = -1;
    if(this != NULL && isValidIsEmpty(isEmpty))
    {
        retorno = 0;
        this->isEmpty = isEmpty ;
    }
    return retorno;
}
*/
//-------------------------------------------------------------
//-------------------------------------------------------------
//-------------------------------------------------------------
/*static int isValidIsEmpty(int isEmpty)
{
    return 1;
}*/
static int isValidGenero(char* genero)
{
    int retorno=-1;
    if(esSoloLetras(genero)==1)
    {
        retorno=0;
    }

    return retorno;
}
static int isValidLink(char* link)
{
    int retorno=0;//ver despues que validar ya que lleva todo tipo de caracteres.

    return retorno;
}
static int isValidDescripcion(char* descripcion)
{
    int retorno=-1;
    if(esAlfaNumerico(descripcion)==1)
    {
        retorno=0;
    }

    return retorno;
}

static int isValidDuracionMinutos(int duracion)
{
    int retorno=-1;
    if(duracion>1&&duracion<=255)
    {
        retorno=0;
    }
    return retorno;
}

static int isValidTitulo(char* titulo)
{
    int retorno=-1;
    if(esAlfaNumerico(titulo)==1)
    {
        retorno=0;
    }

    return retorno;
}


static int isValidPuntaje(int puntaje)
{
    int retorno=-1;
    if(puntaje>0&&puntaje<=5)
    {
        retorno=0;
    }
    return retorno;
}

/*
static int proximoId(void)
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}
*/
