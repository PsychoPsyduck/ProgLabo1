#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 20

void cargarPersona(ePersona listaPersonas[])
{
    char continuar;
    int contador=0;
    int i;

    do
    {
        i=obtenerEspacioLibre(listaPersonas);

        if(i!=-1)
        {

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(listaPersonas[i].nombre);

            printf("Ingrese edad: ");
            scanf("%d", &listaPersonas[i].edad);

            printf("Ingrese dni: ");
            scanf("%d", &listaPersonas[i].dni);

            listaPersonas[i].estado=1;

            contador++;

            if(contador<TAM)
            {
                printf("continuar? s/n ");
                fflush(stdin);
                gets(&continuar);
            }
            else
            {
                break;
            }
        }
        else
        {
            printf("No hay espacio libre.\n");
        }

    }
    while(continuar=='s');
}

int obtenerEspacioLibre(ePersona listaPersonas[])
{
    int i=-1;
    int auxIndice;

    for(i=0; i<TAM; i++)
    {
        if(listaPersonas[i].estado!=1)
        {
            auxIndice=i;
            break;
        }
    }
    return(auxIndice);
}


int buscarPorDni(ePersona listaPersonas[], int dni)
{
    int i;
    int auxI=-1;

    for(i=0; i<TAM; i++)
    {
        if(listaPersonas[i].dni == dni)
        {
            auxI=i;
            break;
        }
    }

    return(auxI);
}

void borrarPersona(ePersona listaPersonas[])
{
    int indice;
    char eliminar;
    int auxDNI;

    printf("Ingrese el dni buscado: ");
    scanf("%d", &auxDNI);
    indice=buscarPorDni(listaPersonas, auxDNI);

    if(indice!=-1)
    {
        printf("Seguro que desea eliminar? s/n \n");
        fflush(stdin);
        gets(&eliminar);


        listaPersonas[indice].estado=0;

    }
    else
    {
        printf("No se encontro el dni buscado.\n");
    }
}

void mostrarListaPorNombre(ePersona listaPersonas[])
{

    int i,j;
    ePersona auxListaPersonas;

    for(i=0; i<1; i++)
    {
        for(j=i+1; j<TAM; j++)
        {
            if(strcmp(listaPersonas[i].nombre, listaPersonas[j].nombre)>0)
            {
                auxListaPersonas=listaPersonas[i];
                listaPersonas[i]=listaPersonas[j];
                listaPersonas[j]=auxListaPersonas;

            }
        }
    }

    mostrarTodaLaLista(listaPersonas);
}

void mostrarTodaLaLista(ePersona listaPersonas[])
{
    int i;
    for(i=0; i<TAM; i++)
    {
        if(listaPersonas[i].estado==1)
        {
            mostrarPersona(listaPersonas[i]);
        }
    }
}

void mostrarPersona(ePersona listaPersonas)
{
    printf("%s--%d--%d\n", listaPersonas.nombre, listaPersonas.edad, listaPersonas.dni);
}

void grafico(ePersona listaPersonas[])
{
    int i;
    int menor=0;
    int adulto=0;
    int mayor=0;
    int maximo;
    int flag;

    for(i=0; i<TAM; i++)
    {
        if(listaPersonas[i].edad<18)
        {
            menor++;
        }
        else if(listaPersonas[i].edad>=18 && listaPersonas[i].edad<35)
        {
            adulto++;
        }
        else
        {
            mayor++;
        }
    }

    if(menor >= adulto && menor >= mayor)
    {
        maximo = menor;
    }
    else if(adulto >= menor && adulto >= mayor)
    {
        maximo = adulto;
    }
    else
    {
        maximo = mayor;
    }

    for(i=maximo; i>0; i--)
    {
        if(i<10)
        {
            printf("\n%02d|",i);
        }
        else
        {
            printf("\n%02d|",i);
        }
        if(i<= menor)
        {
            printf("*");
        }
        if(i<= adulto)
        {
            flag=1;
            printf("\t*");
        }
        if(i<=mayor)
        {
            if(flag==0)
            {
                printf("\t\t*");
            }
            if(flag==1)
            {
                printf("\t*");
            }

        }
    }
    printf("\n--|-----------------");
    printf("\n  |-18\t19-35\t+35");
    printf("\n   %d\t%d\t%d\n", menor, adulto, mayor);

}

