typedef struct
{
    char dni[50];
    int id;
    char nombre[50];
    char apellido[50];
    float altura;
    char cuit[50];
}Cliente;


Cliente* cliente_new();
Cliente* cliente_newNuevo(char* dni,int id, char* nombre, char* apellido, float altura, char* cuit);
Cliente* arrayCliente_getById(Cliente* array[], int cantidadElementos, int idFuncion);

void cliente_delete(Cliente* this);
int  cliente_setEdad(Cliente* this, int edad);
int cliente_getEdad(Cliente* this, int* edad);

int cliente_setAltura(Cliente* this, float alturaFuncion);
int cliente_getAltura(Cliente* this, float* alturaFuncion);
//float isValidAltura(float altura);

int cliente_setCuit(Cliente* this, char* cuitFuncion);
int cliente_getCuit(Cliente* this, char* cuitFuncion);
//int isValidCuit(char* cuitFuncion);

int cliente_setNombre(Cliente* this, char* nombreFuncion);
int cliente_getNombre(Cliente* this, char* nombreFuncion);
//int isValidNombre(char* nombreFuncion);

int cliente_setApellido(Cliente* this, char* apellidoFuncion);
int cliente_getApellido(Cliente* this, char* apellidoFuncion);

int cliente_setDni(Cliente* this, char* dniFuncion);
int cliente_getDni(Cliente* this, char* dniFuncion);

int cliente_setNewId(Cliente* this);
int cliente_getId(Cliente* this, int* idFuncion);
int cliente_setId(Cliente* this,int idFuncion);
