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
            *resultado = (char)auxiliar; //castear float para no usar long y tener exceso de bits
            retorno = 0;
            break;
        }
        printf("%s", mensajeError);
    }while(reintentos >= 0);

    return retorno;
}

int getString(char* mensaje,
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
            *resultado = (char)auxiliar; //castear float para no usar long y tener exceso de bits
            retorno = 0;
            break;
        }
        printf("%s", mensajeError);
    }while(reintentos >= 0);

    return retorno;
}


int factorial(int numero, long* resultado)
{
    long auxiliar = numero;
    while(numero>1)
    {
        numero--;
        printf("%ld", auxiliar);
        auxiliar = auxiliar * numero;
    }
    *resultado = auxiliar;
    return 0;
}

long factorialRecursivo(int numero)
{
    long auxiliar = numero;
    if(numero == 1)
    {
        resultado = 1;
    }
    else
    {
        resultado = numero * factorialRecursivo(int numero-1);
    }
    *resultado = auxiliar;
    return resultado;
}
