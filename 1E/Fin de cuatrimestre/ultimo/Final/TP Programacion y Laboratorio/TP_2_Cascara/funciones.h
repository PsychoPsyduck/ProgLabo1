#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;
}EPersona;

/** \brief
 *
 * \param array EPersona*
 * \param limite int
 * \return int
 *
 */
int initLista(EPersona* array,int limite);

/** \brief
 *
 * \param array EPersona*
 * \param limite int
 * \return int
 *
 */
int agregarPersona(EPersona* array,int limite);

/** \brief
 *
 * \param array EPersona*
 * \param limite int
 * \param dni int
 * \return int
 *
 */
int borrarPersona(EPersona* array,int limite, int dni);

/** \brief
 *
 * \param array EPersona*
 * \param limite int
 * \return int
 *
 */
int mostrarListaPersonas(EPersona* array,int limite);

/** \brief
 *
 * \param array EPersona*
 * \param limite int
 * \param orden int
 * \return int
 *
 */
int ordenarPorDni(EPersona* array,int limite, int orden);

/** \brief
 *
 * \param array EPersona*
 * \param limite int
 * \return void
 *
 */
void grafico(EPersona* array, int limite);

#endif // FUNCIONES_H_INCLUDED
