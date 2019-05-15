#include "lib.h"

int sumaEnteros(int primerNumero, int segundoNumero, float *resultado)
{
    long resultadoCalculo;
    int retorno = -1;
    resultadoCalculo = primerNumero + segundoNumero;
    if(resultadoCalculo < 32767)
    {
        *resultado = resultadoCalculo;
        retorno = 0;
    }
    return retorno;
}
int restaEnteros(int primerNumero, int segundoNumero, float *resultado)
{
    long resultadoCalculo;
    int retorno = -1;
    resultadoCalculo = primerNumero - segundoNumero;
    if(resultadoCalculo < -32768)
    {
        *resultado = resultadoCalculo;
        retorno = 0;
    }
    return retorno;
}
int multiplicaEnteros(int primerNumero, int segundoNumero, float *resultado)
{
    long resultadoCalculo;
    int retorno = -1;
    resultadoCalculo = primerNumero * segundoNumero;
    if(resultadoCalculo < 32768)
    {
        *resultado = resultadoCalculo;
        retorno = 0;
    }
    return retorno;
}
int divideEnteros(int primerNumero, int segundoNumero, float *resultado)
{
    long resultadoCalculo;
    int retorno = -1;
    if(segundoNumero!=0)
    {
        resultadoCalculo = primerNumero / segundoNumero;
        *resultado = resultadoCalculo;
        retorno = 0;
    }
    return retorno;
}



