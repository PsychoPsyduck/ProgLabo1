#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"

void mostrar(Alumno* array[],int cantidad);
void cargar(Alumno** array,int cantidadMaxima,int* cantidadActual);
void cargarDeArchivo(Alumno** array,int cantidadMaxima,int* cantidadActual);
void guardarTodo(Alumno* array[],int cantidad);

int main()
{

    Alumno* arrayPunteroAlumnos[4000];
    int qtyActualArrayAlumnos = 0;
    int qtyMaximaArrayAlumnos = 4000;

    //cargar(arrayPunteroAlumnos,qtyMaximaArrayAlumnos,&qtyActualArrayAlumnos);
    //mostrar(arrayPunteroAlumnos,qtyActualArrayAlumnos);
    //modificar(arrayPunteroAlumnos,qtyActualArrayAlumnos);
    cargarDeArchivo(arrayPunteroAlumnos,qtyMaximaArrayAlumnos,&qtyActualArrayAlumnos);
    mostrar(arrayPunteroAlumnos,&qtyActualArrayAlumnos);

    printf("\n------------------------------------------------------\n");

    arrayAlumno_add(arrayPunteroAlumnos, qtyMaximaArrayAlumnos, &qtyActualArrayAlumnos,"39147115","Juanito","PerezH","27-37954192-6",5.2,-1);
    mostrar(arrayPunteroAlumnos,qtyActualArrayAlumnos);


    //guardar en disco
    //guardarTodo(arrayPunteroAlumnos,&qtyActualArrayAlumnos);
    return 0;
}


void cargar(Alumno** array,int cantidadMaxima,int* cantidadActual)
{
    int i;
    for(i=0;i<40;i++)
    {
        arrayAlumno_add(array, cantidadMaxima, cantidadActual, "28000555", "JUAN", "PEREZ", "20-28000555-6", i, -1);
    }
}

void cargarDeArchivo(Alumno** array,int cantidadMaxima,int* cantidadActual)
{
    FILE *miArchivo;
    int numero;
    char nombre[20];
    char apellido[20];
    char cuit [20];
    float altura;
    miArchivo = fopen("data.txt","r");

    if(miArchivo!=NULL)
    {
        do
        {
            fscanf(miArchivo,"%d,%[^,],%[^,],%[^,],%f\n",&numero,nombre,apellido,cuit,&altura);
            arrayAlumno_add(array, cantidadMaxima, cantidadActual,"37954192",nombre,apellido,cuit,altura,numero);
            //printf("%d - %s - %s - %s - %.2f\n",numero,nombre,apellido,cuit,altura);
        }while(!feof(miArchivo));
        fclose(miArchivo);
    }
}


void mostrar(Alumno* array[],int cantidad)
{
    int i;
    char cuit[50];
    char nombre[20];
    char apellido[20];
    float altura;
    for(i=0;i<cantidad;i++)
    {
        alumno_getCuit(array[i],cuit);
        alumno_getAltura(array[i],&altura);
        alumno_getNombre(array[i], nombre);
        alumno_getApellido(array[i], apellido);
        printf("\nNombre: %s - Apellido: %s - Cuit: %s - Altura: %.2f",nombre,apellido,cuit,altura);
    }
}

void guardarTodo(Alumno* array[],int cantidad)
{
    FILE *miArchivo;
    int i;
    char cuit[50];
    char nombre[20];
    char apellido[20];
    float altura;
    int numero = 5;

    miArchivo = fopen("data.txt","w");
    if(miArchivo!=NULL)
    {
        for(i=0; i<cantidad; i++)
        {
            numero++;
            alumno_getCuit(array[i],cuit);
            alumno_getAltura(array[i],&altura);
            alumno_getNombre(array[i], nombre);
            alumno_getApellido(array[i], apellido);
            fprintf(miArchivo,"%d,%s,%s,%s,%f\n",numero,nombre,apellido,cuit,altura);
        }
        fclose(miArchivo);
    }
}

void modificar(Alumno* array[],int cantidad)
{
    int i;
    Alumno* auxiliarAlumno;
    for(i=5;i<10;i++)
    {
        auxiliarAlumno = arrayAlumno_getById(array,cantidad,i);
        if(auxiliarAlumno != NULL)
        {
            alumno_setAltura(auxiliarAlumno,88);
        }
    }
}


