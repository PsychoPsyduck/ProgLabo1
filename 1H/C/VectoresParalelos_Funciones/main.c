#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int leg[3], n1[3], n2[3];
    float prom[3];
    char nombre[3];
    float i;
    float j;
    float auxP;
    int auxL;
    int auxN1;
    int auxN2;
    int legAux

    //1. pedir infreso de datos
    for(i=0; i<3; i++)
    {
        printf("ingrese legajo: ");
        scanf("%d", &leg[i]);

        printf("Ingrese su nombre: ");
        fflush(stdin);
        gets(nombre[i]);

        printf("Ingrese primera nota");
        scanf(n1[i]);

        printf("Ingrese segunda nota");
        scanf(n2[i]);

        prom[i] = (float) (n1[i]+n2[i])/2;

    }

    //pedir opciones con dowhile y dentro el switch, tal cual la calculadora

    //3. mostrar datos
    for(i=o; i<3; i++)
    {
        printf("%d--%s--%d--%d--%f\n", leg[i], nombre[i], n1[i], n2[i], prom[i]);
    }

    //2. ordenar datos (ejemplo manitos)
    for(i=0; i<2; i++)
    {
        for(j=i+1; j<3; j++)
        {
            if(strcmp(nombre[i], nombre[j])>0)
            {
                strcpy(auxString, nombre[i]);
                strcpy(nombre[i], nombre[j]);
                strcpy(nombre[j], auxString);

                //hacer lo mismo con los auxiliares de legajo y notas
            }

        }

    }

    //4. a.pedir legajo b. buscarlo c. si existe mostrar y pedir nuevo dat, sino error ingrese otro
    printf("Ingrese el legajo buscado: ");
    scanf("%d", &legAux);

    for(i=0; i<3; i++)
    {
        if(legAux == i){

            printf("%d--%s--%d--%d--%f\n", leg[i], nombre[i], n1[i], n2[i], prom[i]);

            printf("Ingrese nueva nota1: ");
            scanf("&d", n1[i]);

            printf("Ingrese nueva nota2: ");
            scanf("&d", n2[i]);
        }

        else
        {
            printf("Error. No se encontro legajo");
        }
    }


}
