#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nombre[15];
    int telefono;
    char Email[54];
} eContacto;

eContacto* newContacto();
eContacto* newContactoParametros(char*, int, char*);//Constructor parametrizado
void mostrarContacto(eContacto*);

int main()
{
    eContacto* unContacto;

    eContacto* agenda[5];


    char nombre[50];
    char mail[50];
    int telefono;

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(nombre);
    printf("Ingrese telefono");
    scanf("%d", &telefono);
    printf("Ingrese   mail");
    fflush(stdin);
    gets(mail);

    unContacto = newContactoParametros(nombre, telefono, mail);

    *(agenda+1)=unContacto;


    mostrarContacto(*(agenda+1));







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
    printf("%s--%d--%s\n", this->nombre, this->telefono, this->Email);
}
