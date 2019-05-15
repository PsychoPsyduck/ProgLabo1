#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
typedef struct
{
    int idUsuario;
    char nombre[50];
    float precio;
    int stock;
    int idProducto;
    int isEmpty;
}Producto;

int producto_init(Producto* array,int limite);
int producto_alta(Producto* array,int limite);
int producto_modificacion(Producto* array,int limite, int id);

#endif // PRODUCTO_H_INCLUDED
