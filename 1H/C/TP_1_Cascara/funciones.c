#include "funciones.h"

float primerIngreso()
{
    float x;

    printf("Ingrese el primer valor\n");
    scanf("%f", &x);

    return(x);
}

float segundoIngreso()
{
    float y;

    printf("Ingrese el segundo valor\n");
    scanf("%f", &y);

    return(y);
}

void suma(float val1, float val2)
{
    float resultado;

    resultado=val1 + val2;

    printf("El resultado de la suma es: %f", resultado);
}

void resta(float val1, float val2)
{
    float resultado;

    resultado = val1-val2;

    printf("El resultado de la resta es: %f", resultado);
}

void division(float val1, float val2)
{
    float resultado;

    if(val2 == 0)
    {
        printf("No puede ser posible la operacion. El divisor es 0\n");
    }
    else
    {
        resultado = val1/val2;

        printf("El resultado de la division es: %f", resultado);
    }
}

void multi(float val1, float val2)
{
    double resultado;

    resultado = val1*val2;

    printf("El resultado de la multiplicacion es: %f", resultado);
}

void factorial(float val1, float val2)
{
    float result1;
    float result2;

    result1 = calcularFactorial(val1);
    result2 = calcularFactorial(val2);

    printf("El resultado de la primer factorial es: %f \n", result1);
    printf("El resultado de la segunda factorial es: %f \n", result2);
    if(val1>=14 || val2>=14)
    {
        printf("Recuerde que la calculadora no factorea correctamente nros mayores a 12. \n");
    }
}

float calcularFactorial(float f)
{
    float num=f;
    float acum=1;
    float i;

    for(i = num; i>0; i--)
    {
        acum = acum*i;
    }

    return(acum);
}

