#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int parserEmployee(FILE* pFile , ArrayList* pArrayListEmployee)
{
    //Esto va en el main
    int retorno = -1;
    char bId[4096];
    char bName[4096];
    char bLastName[4096];
    char bIsEmpty[4096];
    Employee* auxiliarEmpleado;


    if(pFile != NULL)
    {
        retorno = 0;
        fscanf(pFile,"[^,],[^,],[^,],[^\n]\n"
                    ,bId,bName,bLastName,bIsEmpty);
        while (!feof(pFile))
        {
            //Asi se lee la primera linea del archivo
            fscanf(pFile,"[^,],[^,],[^,],[^\n]\n"
                        ,bId,bName,bLastName,bIsEmpty);
            auxiliarEmpleado = employee_newParametro(bId,bName,bLastName,bIsEmpty);
            al_add(pArrayListEmployee,auxiliarEmpleado);
            //podria hacerse asi
            //al_add(pArrayListEmployee,employee_newParametro(bId,bName,bLastName,bIsEmpty));
            //arrayList gestiona lugares de memotia
        }
    }
    fclose(pFile);
    //fseek(pFile,(long)(1)*sizeof(),SEEK_CUR)
    return retorno;
}
