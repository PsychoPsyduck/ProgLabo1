#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"


int em_trabajaMasDe120Horas(void* item)
{
    int returnAux = -1;
    int horasTrabajadas;

    if(item != NULL);
    {
       empleado_getHorasTrabajadas(item, &horasTrabajadas);
       if(horasTrabajadas > 120)
       {
           returnAux = 1;
       }
       else
       {
           returnAux = 0;
       }
    }
    return returnAux;
}


S_Empleado* empleado_new(void)
{
    S_Empleado* returnAux = (S_Empleado*) malloc(sizeof(S_Empleado));
    return returnAux;
}

int empleado_setId(S_Empleado* this,int id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}

int empleado_getId(S_Empleado* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int empleado_setNombre(S_Empleado* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int empleado_getNombre(S_Empleado* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int empleado_setHorasTrabajadas(S_Empleado* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int empleado_getHorasTrabajadas(S_Empleado* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}
