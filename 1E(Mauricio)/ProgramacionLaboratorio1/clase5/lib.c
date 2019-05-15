#include <stdio.h>
#include <stdlib.h>

int getInt(char* mensaje,
           char* mensajeError,
           int reintentos,
           int minimo,
           int maximo,
           int* resultado)
{
    long auxiliar;
    int retorno = -1;
    do
    {
        reintentos--;
        printf("%s", mensaje);
        scanf("%ld", &auxiliar);

        if(auxiliar >= minimo && auxiliar <= maximo)
        {
            *resultado = (int)auxiliar; //castear int para no usar long y tener exceso de bits
            retorno = 0;
            break;
        }
        printf("%s", mensajeError);
    }while(reintentos >= 0);

    return retorno;
}

int getFloat(char* mensaje,
           char* mensajeError,
           int reintentos,
           float minimo,
           float maximo,
           float* resultado)
{
    float auxiliar;
    int retorno = -1;
    do
    {
        reintentos--;
        printf("%s", mensaje);
        scanf("%f", &auxiliar);

        if(auxiliar >= minimo && auxiliar <= maximo)
        {
            *resultado = auxiliar;
            retorno = 0;
            break;
        }
        printf("%s", mensajeError);
    }while(reintentos >= 0);

    return retorno;
}

int getChar(char* mensaje,
           char* mensajeError,
           int reintentos,
           char minimo,
           char maximo,
           char* resultado)
{
    char auxiliar;
    int retorno = -1;
    do
    {
        reintentos--;
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%c", &auxiliar);

        if(auxiliar >= minimo && auxiliar <= maximo)
        {
            *resultado = (char)auxiliar;
            retorno = 0;
            break;
        }
        printf("%s", mensajeError);
    }while(reintentos >= 0);

    return retorno;
}

float calcularPromedioV1(int valores[], int cantidad)
{
    int i;
    int aux;
    float promedio;
    for(i = 0; i<cantidad; i++)
    {
        if(i == 0)
        {
            aux = valores[i];
        }
        else
        {
            aux = aux + valores[i];
        }
    }
    promedio = (float)aux / i;
    return promedio;
}

float calcularPromedioV2(int valores[], int cantidad, float* resultado)
{
    int i;
    int aux;
    int retorno = 0;
    if(cantidad <= 0 || resultado == NULL) //Resultado no lleva asterisco para verificar que la direccion de memoria existe
    {
        retorno = -1;
    }
    for(i = 0; i<cantidad; i++)
    {
        if(i == 0)
        {
            aux = valores[i];
        }
        else
        {
            aux = aux + valores[i];
        }
    }
    *resultado = (float)aux / i;
    return retorno;
}
