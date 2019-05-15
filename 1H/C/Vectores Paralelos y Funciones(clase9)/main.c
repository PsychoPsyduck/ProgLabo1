#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 3

typedef struct
{
    int legajo;
    int nota1;
    int nota2;
    float promedio;
    char nombre[50];
    int estado;
} eAlumno;

void inicializar(eAlumno[], int);
void mostrarAlumno(eAlumno);
void mostrarTodosLosAlumnos(eAlumno[], int);
void cargarAlumnos(eAlumno[], int);
void ordenarAlumnos(eAlumno[], int);

int main()
{

    int i, j;
    int flag=0;
    char rta;
    int opcion;
    eAlumno listaAlumnos[TAM];
    eAlumno auxAlumno;
    do
    {
        printf("1.Cargar\n2.Mostrar\n3.Ordenar\n4.Modificar\n5. Bajar por legajo\n8.Salir\nElija una Opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            cargarAlumnos(listaAlumnos,TAM);
            //inicializar(listaAlumnos,TAM);

            break;
        case 2:
            mostrarTodosLosAlumnos(listaAlumnos, TAM);

            break;

        case 3:

            ordenarAlumnos(listaAlumnos,TAM);
            break;

        case 4:

        /* printf("Ingrese el legajo: ");
         scanf("%d", &auxInt);

         for(i=0; i<TAM; i++)
         {
             if(leg[i] == auxInt)//Si existe
             {
                 flag=1;
                 printf("%d--%s--%d--%d--%f\n", leg[i], nombre[i], n1[i], n2[i], prom[i]);
                 printf("Ingrese la nueva nota (Nota 1): ");
                 scanf("%d", &auxInt);
                 printf("Esta seguro de modificar la nota? ");
                 rta = getche();
                 if(rta=='s')
                 {
                     n1[i]=auxInt;
                     prom[i] = (float)(n1[i]+n2[i])/2;
                 }
                 else
                 {
                     printf("Accion cancelada por el usuario");
                 }

                 break;
             }

         }
         if(flag==0)
         {

             printf("\nLegajo Inexistente!!!\n");

         }
        */
        case 5:


            break;

        }

    }
    while(opcion!=8);

    return 0;
}

void inicializar(eAlumno lista[], int tam)
{
    int leg[]= {100,101,102}, n1[]= {10,8,9}, n2[]= {4,2,3};
    float prom[]= {7,5,6};
    char nombre[][50]= {"Luis","Maria","Pedro"};
    int i;


    for(i=0; i<tam; i++)
    {
        lista[i].legajo=leg[i];
        lista[i].nota1=n1[i];
        lista[i].nota2=n2[i];
        lista[i].promedio=prom[i];

        strcpy(lista[i].nombre,nombre[i]);
    }

}

void cargarAlumnos(eAlumno lista[], int tam)
{
    int i;
    char continuar;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado!=1)
        {
            printf("Ingrese legajo: ");
            scanf("%d", &lista[i].legajo);
            printf("Ingrese nota 1: ");
            scanf("%d", &lista[i].nota1);

            printf("Ingrese nota 2: ");
            scanf("%d", &lista[i].nota2);

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(lista[i].nombre);

            lista[i].promedio=(float) (lista[i].nota1+lista[i].nota2)/2;

            lista[i].estado=1;


            if(i!=tam-1)
            {
                printf("continuar? s/n ");
                gets(&continuar);
            }

            if(continuar=='n')
            {
                break;
            }
        }


    }
}

void ordenarAlumnos(eAlumno lista[], int tam)
{
    int i,j;
    eAlumno auxAlumno;
    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(lista[i].nombre, lista[j].nombre)<0)
            {
                auxAlumno = lista[i];
                lista[i]=lista[j];
                lista[j]=auxAlumno;

            }
        }
    }

}

void mostrarTodosLosAlumnos(eAlumno lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        mostrarAlumno(lista[i]);
    }
}

void mostrarAlumno(eAlumno alumno)
{
    printf("%d--%d--%d--%f--%s--%d\n", alumno.legajo, alumno.nota1,alumno.nota2,alumno.promedio, alumno.nombre, alumno.estado);
}

void bajarPorLegajo(eAlumno lista[], int tam)
{
    int legajoBuscado;
    int i;
    printf("Ingrese legajo buscado: ");
    scanf("%d", legajoBuscado);

    for(i=0; i<tam-1; i++)
    {
        if(lista[i].legajo=legajoBuscado)
        {
            lista[i].legajo=0;
            lista[i].nota1=0;
            lista[i].nota2=0;
            lista[i].promedio=0;
            lista[i].estado=0;

        }
    }
}

