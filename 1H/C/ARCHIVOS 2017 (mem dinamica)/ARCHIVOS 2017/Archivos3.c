#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int a;
    char b;
} eDato;

int main()
{
    eDato d;
    eDato lista[3];
    FILE* miArchivo;
    int numero=128;
    int otroNumero;
    int cont;
    int i;

    /* miArchivo = fopen("numero.dat", "wb");

     fwrite(&cont, sizeof(int), 1, miArchivo);
     fwrite(lista, sizeof(eDato), cont, miArchivo);

     fclose(miArchivo);*/


    miArchivo = fopen("numero.dat", "rb");
    fread(&cont, sizeof(int), 1, miArchivo);

    fread(lista, sizeof(eDato), cont, miArchivo);

    fclose(miArchivo);
    for(i=0; i<cont; i++)
    {
        printf("%d--%c\n", lista[i].a, lista[i].b);

    }



}

