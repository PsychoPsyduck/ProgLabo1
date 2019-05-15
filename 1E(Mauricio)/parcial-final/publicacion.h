#ifndef PUBLICACION_H_INCLUDED
#define PUBLICACION_H_INCLUDED

typedef struct
{
    int idCliente;
    int numeroRubro;
    char textoAviso[64];
    int estado;
    int idAviso;
    int isEmpty;
}Aviso;

#endif // PUBLICACION_H_INCLUDED

#include "cliente.h"

/** \brief Hace el alta de la listaAvisos vacia
 *
 * \param array Aviso* recibe listaAvisos
 * \param limite int recibe tamano de listaAvisos
 * \return int retorna 0 si funciona
 *
 */
int publicacion_init(Aviso* array,int limite);

/** \brief hace el alta completa de una publicacion
 *
 * \param array Aviso* recibe listaAvisos
 * \param limite int recibe tamano de listaAvisos
 * \param auxIdCliente int recibe el id de cliente
 * \return int retorna 0 si funciona, -2 si no hay lugar, -3 si no se ingresa un rubro valido
 *
 */
int publicacion_alta(Aviso* array,int limite, int auxIdCliente);

/** \brief hace el alta forzada de un aviso
 *
 * \param array Aviso* recibe listaAvisos
 * \param limite int recibe tamano de listaAvisos
 * \param idC int toma el id cliente
 * \param numRubro int toma el rubro
 * \param txtAviso char* toma la descripcion
 * \return int retorna 0 si funciona
 *
 */
int publicacion_altaForzada(Aviso* array,int limite,int idC,int numRubro,char* txtAviso);

/** \brief muestra toda la lista con todos los datos
 *
 * \param array Aviso* recibe listaavisos
 * \param limite int recibe tamano de lista avisos
 * \return int retorna 0 si funciona
 *
 */
int publicacion_mostrarDEB(Aviso* array,int limite);


/** \brief cambia el estado a 0 de una publicacion
 *
 * \param array Aviso* recibe listaAvisos
 * \param limite int recibe tamano de listaAvisos
 * \param id int toma id de publicacion
 * \return int retorna 0 si funciona
 *
 */
int publicacion_pausar(Aviso* array,int limite, int id);


/** \brief busca el indice de una publicacion
 *
 * \param array Aviso* recibe listaAvisos
 * \param limite int recibe tamano de listaAvisos
 * \param id int toma id de publicacion
 * \return int retorna el indice, -2 si no lo encuentra
 *
 */
int publicacion_buscarPorId(Aviso* array,int limite, int id);

/** \brief cambia el estado a 1 de una publicacion
 *
 * \param array Aviso* recibe listaAvisos
 * \param limite int recibe tamano de listaAvisos
 * \param id int toma id de publicacion
 * \return int retorna 0 si funciona
 *
 */
int publicacion_reanudar(Aviso* array,int limite, int id);

/** \brief muestra toda la lista con todos los datos
 *
 * \param array Aviso* recibe listaAvisos
 * \param limite int recibe tamano de listaAvisos
 * \return int retorna 0 si funciona
 *
 */
int publicacion_mostrar(Aviso* arrayA,int limiteA, Cliente* arrayC, int limiteC);

/** \brief da la baja una publiacion
 *
 * \param array Aviso* recibe listaAvisos
 * \param limite int recibe tamano de listaAvisos
 * \param id int toma el id del producto
 * \return int retorna 0 si funciona
 *
 */
int publicacion_baja(Aviso* array,int limite, int id);


/** \brief busca una publiacion por id del cliente
 *
 * \param array Aviso* recibe listaAvisos
 * \param limite int recibe tamano de listaAvisos
 * \param id int toma id de cliente
 * \return int retorna el indice, -2 si esta vacia la lista
 *
 */
int publicacion_buscarPorIdCliente(Aviso* array,int limite, int id);
