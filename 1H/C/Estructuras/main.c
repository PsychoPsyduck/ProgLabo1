#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int legajo;
    int n1, n2;
    float promedio;
    char nombre[30];

}eAlumno;

void mostrarAlumno();

int main()
{
    int i;

    eAlumno alumno[3];//por cada alumno -> unAlumno; //truncado-> ={401, 10, 7, 8.5, "Pedro"};
         //truncado->  strcpy(unAlumno.nombre, "Pedro");

    //eAlumno dosAlumno;
        //dosAlumno = unAlumno;

    for(i=0; i<3; i++)
    {
        printf("Ingrese legajo: ");
        scanf("%d", &alumno[i].legajo); //truncado-> unAlumno.legajo = 401;
        printf("Ingrese nota 1: ");
        scanf("%d", &alumno[i].n1); //truncado-> unAlumno.n1 = 10;
        printf("Ingrese nota 2: ");
        scanf("%d", &alumno[i].n2); //truncado-> unAlumno.n2 = 7;
        alumno[i].promedio = (float)(alumno[i].n1+alumno[i].n2)/2;
        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(alumno[i].nombre);
    }

    mostrarAlumno(alumno[i]);//hacer un for <-
    //printf("%d--%d--%d--%f--%s\n", unAlumno.legajo, unAlumno.n1, unAlumno.n2, unAlumno.promedio, unAlumno.nombre);
    //printf("%d--%d--%d--%f--%s\n", dosAlumno);
    return 0;
}

void mostrarAlumno(eAlumno alumno)
{
    printf("%d--%d--%d--%f--%s\n", alumno.legajo, alumno.n1, alumno.n2, alumno.promedio, alumno.nombre);
}
