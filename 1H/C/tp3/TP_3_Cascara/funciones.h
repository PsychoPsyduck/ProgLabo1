#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


typedef struct
{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
    int estado;
} eMovie;


/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna si pudo eliminar la pelicula o no
 */
int borrarPelicula(eMovie*);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void crearPagina(eMovie*, int);

/**
 * crea una nueva pelicula
 * \param recibe un dato vacio
 * \return una pelicula para ser ingresada en un catalogo
 */
eMovie* nuevaPelicula();

/**
 * recibe datos de una pelicula y los carga a un
 * \param recibe datos de la peli
 * \return los retorna a una array
 *
 */
eMovie* newPelicula(char*, char*, int, char*, int, char*);


/**
 * crea una nueva pelicula vacia lista para cargar datos (sin basura)
 * \param un array de pelicula
 * \return el array sin basura
 *
 */
eMovie* newPeliVacia();

/**
 *  elimina una pelicula dejando su estado en 0
 * \param toma las peliculas de un catalogo
 * \return el catalogo con la pelicula en estado 0
 */
void borrarPelicula(eMovie*);

/**
 * crea un archivo de texto
 * \param toma los datos de catalogo
 * \return los retorna en un archivo de texto
 */
void crearTxt(eMovie*);

/**
 * crea un archivo index
 * \param toma los datos de catalogo
 * \return los retorna en formato html
 *
 */

void crearPagina(eMovie* , int);

int buscarLibre(eMovie*);

#endif // FUNCIONES_H_INCLUDED
