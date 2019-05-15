#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
//    pFile = fopen("data.csv","r");

    int seguir;
    int menu;
    int i;

    do
    {
        seguir=1;
        if(!getValidInt("1- Cargar Lista\n2- Cargar ListaNegra \n3- Depurar\n4- Listar\n5- Imprimir\n6- Salir\n","\nNumero no valido\n",&menu,1,6,1))
        {
            switch(menu)
            {
            case 1:
                parserEmployee("data.csv", listaEmpleados);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                for(i=0; i < al_len(listaEmpleados); i++)
                {
                    auxiliarEmpleado = al_get(listaEmpleados,i);
                    employee_print(auxiliarEmpleado);
                }
                break;
            case 6:
                seguir=0;
                break;
            }
        }
    }
    while(seguir);
    return 0;
}
