#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int swapArrayString(char* primerString, char* segundoString);

/** \brief
 *
 * \param primerString int*
 * \param segundoString int*
 * \return int
 *
 */
int swapArrayString(char* primerString, char* segundoString)
{
    char auxiliar[50];
    strcpy(auxiliar, primerString);
    strcpy(primerString, segundoString);
    strcpy(segundoString, auxiliar);
    return 0;
}

/** \brief
 *
 * \param array[][50] char
 * \param cantidadElementos int
 * \param flagOrden int
 * \return int
 *
 */
int sort_ordenarArrayCadenaCaracteres(char array[][50], int cantidadElementos, int flagOrden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    if(cantidadElementos > 0)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<cantidadElementos-1;i++)
            {
                if((strcmp(array[i], array[i+1])>0 && flagOrden)||(strcmp(array[i], array[i+1])<0 && !flagOrden))
                {
                    swapArrayString(array[i], array[i+1]);
                    flagSwap = 1;
                }
            }
        }while(flagSwap);
    }
    return retorno;
}

int swapInt(int* primerEntero,int* segundoEntero);


/** \brief  Ordena un array de enteros
 *
 * \param array int* Puntero al array
 * \param cantidadElementos int cantidad de elementos del array
 * \param flagOrden int [1] Ordena de mayor a menor [0] Ordena de menor a mayor
 * \return int [-1] Error [0] Ok
 *
 */
int sort_ordenarArrayEnteros(int* array,int cantidadElementos, int flagOrden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    if(cantidadElementos > 0)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<cantidadElementos-1;i++)
            {
                if((array[i] < array[i+1] && flagOrden)||(array[i] > array[i+1] && !flagOrden))
                {
                    swapInt(&array[i],&array[i+1]);
                    flagSwap = 1;
                }
            }
        }while(flagSwap);
    }
    return retorno;
}

/** \brief Intercambia dos enteros
 *
 * \param primerEntero int*
 * \param segundoEntero int*
 * \return int
 *
 */
int swapInt(int* primerEntero,int* segundoEntero)
{
    int auxiliar;
    auxiliar = *primerEntero;
    *primerEntero = *segundoEntero;
    *segundoEntero = auxiliar;
    return 0;
}

/** \brief
 *
 * \param arrayStr[][50] char
 * \param arrayInt[] int
 * \param cantidadElementos int
 * \param flagOrden int
 * \return int
 *
 */
int sort_ordenarArrayStringInt(char arrayStr[][50], int arrayInt[], int cantidadElementos, int flagOrden)
{
    int retorno = -1;
    int flagSwap;
    int i;
    if(cantidadElementos > 0)
    {
        retorno = 0;
        do
        {
            flagSwap = 0;
            for(i=0;i<cantidadElementos-1;i++)
            {
                if((strcmp(arrayStr[i], arrayStr[i+1])>0 && flagOrden)||(strcmp(arrayStr[i], arrayStr[i+1])<0 && !flagOrden))
                {
                    swapArrayString(arrayStr[i], arrayStr[i+1]);
                    swapInt(&arrayInt[i],&arrayInt[i+1]);
                    flagSwap = 1;
                }
            }
        }while(flagSwap);
    }
    return retorno;
}


/** \brief
 *
 * \param array int*
 * \param cantidadElementos int
 * \return int
 *
 */
int sort_mostrarArrayEnteros(int* array, int cantidadElementos)
{
    int retorno = -1;
    int i;
    if(cantidadElementos > 0)
    {
        retorno = 0;
        for(i=0;i<cantidadElementos;i++)
        {
            printf("\n%d",array[i]);
        }
    }
    return retorno;
}


/** \brief
 *
 * \param
 * \param cantidadElementos int
 * \return int
 *
 */
int sort_mostrarArrayCadenaCaracteres(char array[][50], int cantidadElementos)
{
    int retorno = -1;
    int i;
    if(cantidadElementos > 0)
    {
        retorno = 0;
        for(i=0;i<cantidadElementos;i++)
        {
            printf("\n%s",array[i]);
        }
    }
    return retorno;
}

/** \brief
 *
 * \param array[][50] char
 * \param array[] int
 * \param cantidadElementos int
 * \return int
 *
 */
int sort_mostrarArrayStringInt(char arrayStr[][50],int arrayInt[], int cantidadElementos)
{
    int retorno = -1;
    int i;
    if(cantidadElementos > 0)
    {
        retorno = 0;
        for(i=0;i<cantidadElementos;i++)
        {
            printf("\n%s -- %d", arrayStr[i], arrayInt[i]);
        }
    }
    return retorno;
}
