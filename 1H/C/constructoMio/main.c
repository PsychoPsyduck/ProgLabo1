#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5

typedef struct
{
    char nombre[15];
    int telefono;
    char Email[54];
} eContacto;

eContacto* newContacto();
eContacto* newContactoParametros(char*, int, char*);//Constructor parametrizado
void mostrarContacto(eContacto*);
void mostrarAgenda(eContacto*);

int main()
{
    eContacto* unContacto;

    eContacto* agenda[TAM];


    char nombre[50];
    char mail[50];
    int telefono;
    int i;


    for(i=0; i<TAM; i++)
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombre);

        printf("Ingrese telefono: ");
        scanf("%d", &telefono);

        printf("Ingrese mail: ");
        fflush(stdin);
        gets(mail);

        unContacto = newContactoParametros(nombre, telefono, mail);

        *(agenda+i)=unContacto;


    }

    mostrarAgenda(agenda);

    return 0;
}


eContacto* newContacto()//constructor por defecto
{
    eContacto* unContacto;

    unContacto =(eContacto*) malloc(sizeof(eContacto));
    if(unContacto!=NULL)
    {

        strcpy(unContacto->nombre, "");
        unContacto->telefono=0;
        strcpy(unContacto->Email, "");
    }

    return unContacto;
}


eContacto* newContactoParametros(char* nombre, int telefono, char* Email)
{
    eContacto* c;

    c = newContacto();
    if(c!=NULL)
    {

        strcpy(c->nombre, nombre);
        c->telefono=telefono;
        strcpy(c->Email, Email);
    }
    return c;
}


void mostrarContacto(eContacto* this)
{
    printf("\n%s--%d--%s\n", this->nombre, this->telefono, this->Email);
}


void mostrarAgenda(&agenda)
{
    int i;

    for(i=0; i<TAM; i++)
    {
        mostrarContacto(*(agenda+i));
    }
}
