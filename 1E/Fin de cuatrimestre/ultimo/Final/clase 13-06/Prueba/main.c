#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{
    ArrayList* listaEmpleados = al_newArrayList();
    Employee* auxiliarEmpleado;
    FILE* pFile;
    int i;
    int menu;


    auxiliarEmpleado = employee_newParametros("-1","Juan","Perez","true");
    al_add(listaEmpleados,auxiliarEmpleado);
    auxiliarEmpleado = employee_newParametros("-1","Lucas","Lopez","true");
    al_add(listaEmpleados,auxiliarEmpleado);


    do
    {
    printf("1. Parse del archivo data.csv\n2. Listar Empleados\n3. Ordenar por nombre\n4. Agregar un elemento\n5. Elimina un elemento\n6. Listar Empleados (Desde/Hasta)");
    scanf("%d",&menu);
    switch (menu)
    {

        case 1://parse del archivo
        pFile = fopen("data.csv","r");
        parserEmployee(pFile,listaEmpleados);

        break;
        case 2://listar empleados
                for(i=0; i < al_len(listaEmpleados);i++)
                {
                    auxiliarEmpleado = al_get(listaEmpleados,i);
                    employee_print(auxiliarEmpleado);
                }
        break;
        case 3://ordenar por nombre
            al_sort(listaEmpleados,employee_compare,1);
        break;
        case 4://agregar un elemento

        break;
        case 5:

        break;
        case 6:

        break;
    }

}while(menu!=7);
    return 0;
}


