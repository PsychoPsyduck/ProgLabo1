#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
typedef struct{
    char titulo[20];
    char genero[20];
    char descripcion[50];
    char linkImagen[50];
    int duracion;
    int puntaje;
}EMovie;


#endif // FUNCIONES_H_INCLUDED


void movie_printTittle(EMovie* this);
void movie_delete(EMovie* this);
EMovie* movie_newParametros(char *strtitulo, char *strgenero,char *strdescripcion,char *strlinkImagen,char *strduracion,char *strpuntaje);

int movie_setId(EMovie* this, int id);
int movie_getId(EMovie* this, int* id);
void movie_print(EMovie* this);
//-------------------------------
int movie_setTitulo(EMovie* this, char* titulo);
int movie_getTitulo(EMovie* this, char* titulo);

int movie_setPuntaje(EMovie* this, int puntaje);
int movie_getPuntaje(EMovie* this, int *puntaje);

int movie_setLink(EMovie* this, char* link);
int movie_getLink(EMovie* this, char* link);

int movie_setDescripcion(EMovie* this, char* descripcion);
int movie_getDescripcion(EMovie* this, char* descripcion);

int movie_setGenero(EMovie* this, char* genero);
int movie_getGenero(EMovie* this, char* genero);

int movie_setDuracion(EMovie* this, int duracion);
int movie_getDuracion(EMovie* this, int* duracion);

int movie_setIsEmpty(EMovie* this, int isEmpty);
int movie_getIsEmpty(EMovie* this, int* isEmpty);


