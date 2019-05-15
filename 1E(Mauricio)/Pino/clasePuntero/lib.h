#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

typedef struct
{
    int edad;
    char nombre[];
    int idPersona;
}Persona

#endif // LIB_H_INCLUDED

Persona* persona_new();
void persona_delete(Persona* this);
int persona_setEdad(Persona* this,int edad);
int validarEdad(int edad);
int persona_getEdad(Persona* this, int* edad);
int persona_getNombre(Persona* this, char* nombre);

