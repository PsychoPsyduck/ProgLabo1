#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char calle[20];
    int altuta;
    char localidad[20];
    int cp;
}eDireccion;


typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;


typedef struct
{
    int legajo;
    char nombre[20];
    int dni;
    int telefono;
    eDireccion direccion;
    eFecha fechaNacimiento;
    char nacionalidad[20];
    char sexo;
}eDatosPersonales;

typedef struct
{
    int nota1;
    int nota2;
    int promedio;
}eNota;

typedef struct
{
    eDatosPersonales datosPersonales;
    eFecha fechaIngreso;
    eNota notas;
}eAlumno;

typedef struct
{
    eDatosPersonales datosPersonales;
    eFecha fechaIngreso;
    int salario;
}eProfesor;

void/*creo*/ ingresarFecha();

int main()
{
    eAlumno a;
    a.datosPersonales.legajo=90;
    strcpy(a.datosPersonales.nombre, "Juan");

    eFecha fecha={07, 12, 93};
    a.datosPersonales.fechaNacimiento=fecha;

    a.fechaIngreso= ingresarFecha(char[]);

    return 0;
}

void/*creo*/ ingresarFecha(char[])
{
    printf("Ingrese dia: ");
    scanf("%d", &eFecha.dia);

    printf("Ingrese mes: ");
    scanf("%d", &eFecha.mes);

    printf("Ingrese año: ");
    scanf("%d", &eFecha.anio);
}
