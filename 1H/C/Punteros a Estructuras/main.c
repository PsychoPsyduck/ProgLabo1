#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int datoI;
    char datoS[15];
} eDato;

void cargarUnDato(eDato*, int, char*);
void mostrarUnDato(eDato*);

int main()
{
    eDato lista[3];

    int datoI;
    char datoS[15];
    int i;

    for(i=0; i<3; i++)
    {
        printf("Ingrese un entero: ");
        scanf("%d", &datoI);
        printf("Ingrese una cadena: ");
        fflush(stdin);
        gets(datoS);
        cargarUnDato(&lista[i], datoI, datoS);
    }

    for(i=0; i<3; i++)
    {
        mostrarUnDato(&lista[i]);
    }

    return 0;
}
void cargarUnDato(eDato* dato, int i, char* s) // CONSTRUCTOR
{
    dato->datoI=i;
    strcpy(dato->datoS, s);
}

void mostrarUnDato(eDato* dato)
{
    printf("%d--%s\n", dato->datoI, dato->datoS);
}
