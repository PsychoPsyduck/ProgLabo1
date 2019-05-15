#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
typedef struct
{
    char nombre[50];
    char password[50];
    int idUsuario;
    int isEmpty;
}Usuario;

int usuario_init(Usuario* array,int limite);
int usuario_alta(Usuario* array,int limite);
int usuario_modificacion(Usuario* array,int limite, int id);
int usuario_baja(Usuario* array,int limite, int id);


#endif // USUARIO_H_INCLUDED
