#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include "parser.h"

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
    int i;

    FILE* pFile;
    pFile = fopen("data.csv","r");
    parserEmployee(pFile,listaEmpleados);

    auxiliarEmpleado = employee_newParametro("1","Juan","Carlos","true");
    al_add(listaEmpleados,auxiliarEmpleado);
    auxiliarEmpleado = employee_newParametro("2","Juan","Carlos","true");
    al_add(listaEmpleados,auxiliarEmpleado);


    for(i=0 ;i<al_len(listaEmpleados);i++)
    {
        auxiliarEmpleado = al_get (listaEmpleados,i);
        employee_print(auxiliarEmpleado);
        // O, la otra forma
        // employee_print(al_get (listaEmpleados,i));
    }

    char seguir='s';
    int opcion=0;

     while(seguir == 's')
    {
        printf("\n1- Parse del archivo data.csv\n");
        printf("2- Listar Empleados\n");
        printf("3- Ordenar por nombre\n");
        printf("4- Agregar un elemento\n");
        printf("5- Elimina un elemento\n");
        printf("6- Listar Empleados (Desde/Hasta)\n");
        printf("7- Salir\n\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            case 6:

                break;
            case 7:
                seguir = 'n';
                break;
        }
    }


    return 0;
}
