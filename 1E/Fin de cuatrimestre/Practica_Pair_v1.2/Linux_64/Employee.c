#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"
#include "utn.h"

static int isValidName(char* name);
static int isValidEmail(char* name);

int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    return 0;
}

void employee_print(Employee* this)
{
    char name[51];
    char email[51];
    if(this != NULL)
    {
        employee_getName(this,name);
        employee_getEmail(this,email);
        fprintf(stdout,"\nNombre: %s - Email: %s", name,email);
    }

}

Employee* employee_new(void)
{
    Employee* returnAux = (Employee*) malloc(sizeof(Employee));
    return returnAux;
}

void employee_delete(Employee* this)
{


}

//-------------------Set Get-----------------------

int employee_setId(Employee* this, int id)
{

    return 0;

}

int employee_getId(Employee* this)
{

    return 0;

}

int employee_setName(Employee* this, char* name)
{
    int retorno = -1;
    if(this != NULL && name != NULL && isValidName(name))
    {
        retorno = 0;
        strcpy(this->name,name);
    }
    return retorno;
}

int employee_getName(Employee* this, char* name)
{
    int retorno = -1;
    if(this != NULL && name != NULL)
    {
        retorno = 0;
        strcpy(name,this->name);
    }
    return retorno;
}

int employee_setEmail(Employee* this, char* email)
{
    int retorno = -1;
    if(this != NULL && email != NULL && isValidEmail(email))
    {
        retorno = 0;
        strcpy(this->email,email);
    }
    return retorno;
}

int employee_getEmail(Employee* this, char* email)
{
    int retorno = -1;
    if(this != NULL && email != NULL)
    {
        retorno = 0;
        strcpy(email,this->email);
    }
    return retorno;
}

//-------------------IsValid------------------------

static int isValidName(char* name)
{
    return 1;
}

static int isValidEmail(char* email)
{
    return 1;
}

