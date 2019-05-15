#include <stdio.h>
#include <stdlib.h>

/** \brief Que hace el programa
 *
 * \param array int*
 * \param cantElementos int
 * \param flagOrden []Menor a mayor []Mayor a menor
 * \return int [-1]Error [0]Ok
 *
 */
int sort_ordenarArrayNumerico(int* array, int cantElementos,int flagOrden)
{
    int retorno=-1;
    if(cantElementos>0)
    {
        retorno=0;
        int swapFlag;
        int i;
        int aux;
        do
        {
            swapFlag=0;
            for(i=0; i<cantElementos-1; i++)
            {
                if(array[i] > array[i+1])
                {
                    aux=array[i];
                    array[i]=array[i+1];
                    array[i+1]=aux;
                    swapFlag=1;
                }
            }
        }while(swapFlag==1);
    }
    return retorno;
}

/** \brief
 *
 * \param array int*
 * \param cantElementos int
 * \return int
 *
 */
int sort_mostrarArrayNumerico(int* array, int cantElementos)
{
    int retorno=-1;
    int i;
    if(cantElementos>0)
    {
        retorno=0;
        for(i=0; i<cantElementos; i++)
        {
            printf("\n %d", array[i]);
        }
    }
    return retorno;
}
