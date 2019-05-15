#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

Persona* persona_new()
{
    return malloc(sizeof(Persona));
}

void persona_delete(Persona* this)
{
    free(this);
}

int persona_setEdad(Persona* this,int edad)
{
    int retorno = -1;
    if(this != NULL && !validarEdad(edad))
    {
        this->edad = edad;
        retorno = 0;
    }
    return retorno;
}

int validarEdad(int edad)
{
    if(edad>0 && edad<200)
        return 0;
    return -1;
}

int persona_getEdad(Persona* this, int* edad)
{
    int retorno = -1;
    if(this != NULL && edad != NULL)
    {
        *edad = this->edad;
        retorno = 0;
    }
    return retorno;
}

int persona_getNombre(Persona* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strcmp(nombre, this->nombre);
        retorno = 0;
    }
    return retorno;
}
