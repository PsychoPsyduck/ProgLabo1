#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    char nombre[50];
    char apellido[50];
    char cuit[15];
    int idCliente;
    int avisoActivo;
    int isEmpty;
}Cliente;

#endif // CLIENTE_H_INCLUDED


/** \brief inicia la listaCientes vacia
 *
 * \param array Cliente* recibe listaClientes
 * \param limite int recibe tamano de listaClientes
 * \return int retorna 0 si funciona
 *
 */
int cliente_init(Cliente* array,int limite);

/** \brief hace el alta completa de un cliente
 *
 * \param array Cliente* recibe listaClientes
 * \param limite int recibe tamano de listaClientes
 * \return int retorna 0 si funciona, -2 si no hay lugar, -3 si no se ingresa un rubro valido
 *
 */
int cliente_alta(Cliente* array,int limite);

/** \brief modifica un cliente
 *
 * \param array Cliente* recibe listaClientes
 * \param limite int recibe tamano de listaClientes
 * \param id recibe el id a modificar
 * \return int 0 si funciona
 *
 */
int cliente_modificacion(Cliente* array,int limite, int id);


/** \brief busnca un cliente por su id
 *
 * \param array Cliente* recibe listaClientes
 * \param limite int recibe tamano de listaClientes
 * \param id int recibe el id
 * \return int devuelve el indice
 *
 */
int cliente_buscarPorId(Cliente* array,int limite, int id);

/** \brief da la baja de un cliente
 *
 * \param array Cliente* recibe listaClientes
 * \param limite int recibe tamano de listaClientes
 * \param id int recibe el id
 * \return int -2 si la lista esta vacia, retorna el indice si esta todo bien
 *
 */
int cliente_baja(Cliente* array,int limite, int id);

/** \brief muestra la lista completa de clietes
 *
 * \param array Cliente* recibe listaClientes
 * \param limite int recibe tamano de listaClientes
 * \return int 0 si funcuiona
 *
 */
int cliente_mostrarDEB(Cliente* array,int limite);


/** \brief hace el alta forzada de un cliente
 *
 * \param array Cliente* recibe listaClientes
 * \param limite int recibe tamano de listaClientes
 * \param nombre char* toma un nombre
 * \param apellido char* toma un apellido
 * \param cuit char* toma su cuit
 * \param avisoActivo int toma la cantidad de avisos activos
 * \return int retorna 0 si esta todo bien
 *
 */
int cliente_altaForzada(Cliente* array,int limite,char* nombre,char* apellido, char* cuit, int avisoActivo);

/** \brief muestra la lista de clietes
 *
 * \param array Cliente* recibe listaClientes
 * \param limite int recibe tamano de listaClientes
 * \return int 0 si funcuiona
 *
 */
int cliente_mostrarListaClientes(Cliente* array,int limite);

/** \brief muestra un cliete
 *
 * \param array Cliente* recibe listaClientes
 * \param limite int recibe tamano de listaClientes
 * \param  id recibe un id a mostrar
 * \return int 0 si funcuiona
 *
 */
int mostrarCliente(Cliente* array,int limite,int id);
