#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[20];
    int edad;
    int estado;
    int dni;

}ePersona;


/** \brief
 *Inicia la carga de datos de cada persona.
 * \param recibe por otra funcion si hay espacio para cargar una nueva persona
 * \return la persona cargada con sus datos en listaPersonas
 */
 void cargarPersona(ePersona listaPersonas[]);


/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(ePersona listaPersonas[], int dni);


/** \brief
 *Elimmina una persona cargada previamente
 * \param recibe el dni de la persona
 * \return la persona con estado en 0 para que pueda sobreescribirse
 */
void borrarPersona(ePersona listaPersonas[]);


/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(ePersona listaPersonas[]);


 /** \brief
 *Muestra los datos de una lsita de personas ordenados por nombre
 * \param recibe una lista de personas
 * \return  retorna la lista ordenada de A - Z
 */
void mostrarListaPorNombre(ePersona listaPersonas[]);


/** \brief
 *Muestra los datos de todas las personas de la lista solo si estan en estado 1
 * \param recibe los datos de una persona, los envia a mostrarListaPorNombre
 * \return retorna los datos completos de todas las persnas dentro de la lista
 */
void mostrarTodaLaLista(listaPersonas);


 /** \brief
 *Muestra los datos de una persona
 * \param recibe una persona
 * \return  imprime sus datos
 */
void mostrarPersona(ePersona listaPersonas);


/** \brief
 * Imprime en una grafica la cantidad de personas en el rango de edad
 * \param recibe una lista de personas
 * \return retorna el grafico de columna marcando cuantas personas hay de cada rango de edad
 *
 */
void grafico(ePersona listaPersonas[]);



#endif // FUNCIONES_H_INCLUDED
