#ifndef INFORME_H_INCLUDED
#define INFORME_H_INCLUDED



#endif // INFORME_H_INCLUDED

#include "cliente.h"
#include "publicacion.h"

/** \brief muestra el cliente con mas avisos
 *
 * \param array Cliente* recibe listaClientes
 * \param limite int recibe tamano de listaClientes
 * \param array Aviso* recibe listaAvisos
 * \param limite int recibe tamano de listaAvisos
 * \return int 0 si esta bien
 *
 */
int informe_masAvisos(Cliente* arrayC,int limiteC, Aviso* arrayA, int limiteA);


/** \brief muesta el cliente con mas avisso activos
 *
 * \param array Cliente* recibe listaClientes
 * \param limite int recibe tamano de listaClientes
 * \param array Aviso* recibe listaAvisos
 * \param limite int recibe tamano de listaAvisos
 * \return int 0 si esta bien
 *
 */
int informe_masAvisosActivos(Cliente* arrayC,int limiteC, Aviso* arrayA, int limiteA);


/** \brief muesta el cliente con mas avisos pausados
 *
 * \param array Cliente* recibe listaClientes
 * \param limite int recibe tamano de listaClientes
 * \param array Aviso* recibe listaAvisos
 * \param limite int recibe tamano de listaAvisos
 * \return int 0 si esta bien
 *
 */
int informe_masAvisosPausados(Cliente* arrayC,int limiteC, Aviso* arrayA, int limiteA);


/** \brief muestra la cantidad total de publicaciones de un rubro
 *
 * \param array Aviso* recibe listaAvisos
 * \param limite int recibe tamano de listaAvisos
 * \param rubro int recibe un rubro
 * \return int 0 si esta bien
 *
 */
int informe_totalRubro(Aviso* arrayA, int limiteA, int rubro);

/** \brief rubro con mas activas
 *
 * \param array Aviso* recibe listaAvisos
 * \param limite int recibe tamano de listaAvisos
 * \return int 0 si esta bien
 *
 */
int informe_rubroMasActivas(Aviso* arrayA, int limiteA);

/** \brief rubro con menos activas
 *
 * \param array Aviso* recibe listaAvisos
 * \param limite int recibe tamano de listaAvisos
 * \return int 0 si esta bien
 *
 */
int informe_rubroMenosActivas(Aviso* arrayA, int limiteA);
