#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"

static int isValidName (char* name);
static int isValidLastName (char* lastName);
static int isValidIsEmpty (int isEmpty);

int employee_compare(void* pEmployeeA,void* pEmployeeB) // puede ser tb Emplyee* pEmployeeA...
{
    int idEmployeeA;
    int idEmployeeB;
    int retorno = 0;
    if (pEmployeeA!=NULL && pEmployeeB!=NULL)
    {
        employee_getId(pEmployeeA,&idEmployeeA);
        employee_getId(pEmployeeB,&idEmployeeB);
        if (idEmployeeA > idEmployeeB)
        {
            retorno = 1;
        }
        else if (idEmployeeA < idEmployeeB)
        {
            retorno = -1;
        }
    }
    return retorno;
}


void employee_print(Employee* this)
{
    int id;
    char name[51];
    char lastName[51];
    int isEmpty;
    if (this!=NULL)
    {
        employee_getId(this,&id);
        employee_getName(this,name);// &name[0]
        employee_getLastName(this,lastName);
        employee_getIsEmpty(this,&isEmpty);
        printf("\nID %d - Nombre: %s - Apellido: %s - isEmpty: %d", id,name,lastName,isEmpty);
    }
}


Employee* employee_new(void)
{

    Employee* returnAux = (Employee*) malloc(sizeof(Employee)); //El Employee entre parentesis es un casting

    return returnAux;

}

Employee* employee_newParametro(char* strId, char* name, char* lastName, char* strIsEmpty)
{
    int id;
    int isEmpty = 0;
    Employee* this;
    //validar que los punteros no sean NULL
    id = atoi (strId); // Falta validar
    if(!strcmp(strIsEmpty, "true")) //Falta validar
        isEmpty = 1;

    this = employee_new();
    if (!employee_setId(this, id)&&
        !employee_setName(this, name)&&
        !employee_setLastName(this,lastName)&&
        !employee_setIsEmpty(this,isEmpty))
    {
        return this;
    }
    employee_delete(this);
    return NULL;
}

void employee_delete(Employee* this)
{
    if (this !=NULL)
        free(this);
}

int employee_setId(Employee* this, int id)
{
    static int ultimoId = -1;
    int retorno = -1;
    if (this !=NULL && id == -1)
    {
        retorno = 0;
        ultimoId++;
        this->id = ultimoId;
            //strcpy(this->id,id);
    }
    else if (this !=NULL && id > ultimoId)
    {
        ultimoId = id;
        this->id = ultimoId;
        retorno = 0;
    }
    return retorno;

}

int employee_getId(Employee* this, int* id)
{
    int retorno = -1;
    if (this !=NULL && id !=NULL)
    {
        retorno = 0;
        *id = this->id;
        //strcpy(id, this->id);
    }
    return retorno;
}

int employee_setName(Employee* this, char* name)
{
    int retorno = -1;
    if (this !=NULL && name !=NULL && isValidName(name))
    {
        strcpy(this->name,name);
        retorno = 0;
    }
    return retorno;

}

int employee_getName(Employee* this, char* name)
{
    int retorno = -1;
    if (this !=NULL && name !=NULL)
    {
        strcpy(name, this->name);
        retorno = 0;
    }
    return retorno;
}

static int isValidName (char* name)
{
    return 1;
}

int employee_setLastName(Employee* this, char* lastName)
{
    int retorno = -1;
    if (this !=NULL && lastName !=NULL && isValidLastName(lastName))
    {
        strcpy(this->lastName,lastName);
        retorno = 0;
    }
    return retorno;

}

int employee_getLastName(Employee* this, char* lastName)
{
    int retorno = -1;
    if (this !=NULL && lastName !=NULL)
    {
        strcpy(lastName, this->lastName);
        retorno = 0;
    }
    return retorno;
}

static int isValidLastName (char* lastName)
{
    return 1;
}

int employee_setIsEmpty(Employee* this, int isEmpty)
{
    int retorno = -1;
    if (this !=NULL && isValidIsEmpty(isEmpty))
    {
        this->isEmpty = isEmpty;
        retorno = 0;
    }
    return retorno;

}

int employee_getIsEmpty(Employee* this, int* isEmpty)
{
    int retorno = -1;
    if (this !=NULL && isEmpty !=NULL)
    {
        retorno = 0;
        *isEmpty = this->isEmpty;
        //strcpy(id, this->id);
    }
    return retorno;
}

static int isValidIsEmpty (int isEmpty)
{
    return 1;
}

