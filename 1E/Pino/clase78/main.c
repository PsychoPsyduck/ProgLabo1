#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

typedef struct
{
    int dia;
    char mes[11];
    int anio;
}EFecha;

typedef struct //va en el .h
{
    char nombre[50];
    char apellido[50];
    EFecha fechaNacimiento;
    int legajo;
}EPersona;

int main()
{
    EPersona persona[3];
    int i;
    for(i=0; i<3; i++)
    {
        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(persona[i].nombre);
        printf("Ingrese el apellido: ");
        fflush(stdin);
        gets(persona[i].apellido);
        printf("Ingrese la fecha de nacimiento: ");
        scanf("%d", &persona[i].fechaNacimiento.dia);
        printf("Ingrese el mes: ");
        fflush(stdin);
        gets(persona[i].fechaNacimiento.mes);
        printf("Ingrese el año: ");
        scanf("%d", &persona[i].fechaNacimiento.anio);
        printf("Ingrese el legajo: ");
        scanf("%d", &persona[i].legajo);
        printf("\n");
    }
    for(i=0; i<3; i++)
    {
        printf("\nNombre: %s %s",persona[i].nombre, persona[i].apellido);
        printf("\nFecha de nacimieto: %d %s %d",persona[i].fechaNacimiento.dia, persona[i].fechaNacimiento.mes, persona[i].fechaNacimiento.anio);
        printf("\nLegajo: %d",persona[i].legajo);
        printf("\n");
    }

    return 0;
}
