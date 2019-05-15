#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#define LEN_PERSONA 10

int main()
{
    Persona arrayPersonas[LEN_PERSONA]; //array 10 personas
    Persona* arrayPunterosPersona[LEN_PERSONA]; //array 10 punteros a persona
    //Persona** arrayPersona[LEN_PERSONA]; //cada posicion del array es un puntero
    Persona* auxiliarPersona;
    int i;
    int auxEdad;
    for(i=0;i<LEN_PERSONA;i++)//carga
    {
        auxiliarPersona = persona_new();
        persona_setEdad(auxiliarPersona, i*2);
        arrayPunterosPersona[i] = auxiliarPersona;
    }
    for(i=0;i<LEN_PERSONA;i++)//muestra
    {
        persona_getEdad(arrayPunterosPersona[i],&auxEdad);
        printf("Mem: %p - Edad: %d\n",arrayPunterosPersona[i],auxEdad);
    }

    return 0;
}
