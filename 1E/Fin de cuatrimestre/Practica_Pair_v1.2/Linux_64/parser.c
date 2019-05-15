#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"
#include "utn.h"


int parserEmployee(char* fileName, ArrayList* pArrayListEmployee)
{
    char name[128];
    char email[128];
    FILE* fp=fopen(fileName, "r");
    if(fp != NULL)
    {
        printf("Abri el archivo!\n");
        do
        {
            int parts = fscanf(fp,"%[^,],%[^\n]",name,email);
            if(parts==2)
            {
                printf("%s %s\n",name,email);
                Employee* auxEmpl = employee_new();//hacer
                employee_setName(auxEmpl, name);
                employee_setEmail(auxEmpl, email);
                al_add(pArrayListEmployee, auxEmpl);
            }
        }while(feof(fp)==0);
    }

    return 0;
}
