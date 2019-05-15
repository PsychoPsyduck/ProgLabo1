typedef struct
{
    char nombre[50];
    char descripcion[50];
    float precio;
    int ID;//que se genere automaticamente al cargar y lo muestre
    int flagLibre;
}EProducto;

int cargarProducto(EProducto listaProductos[], int indice, int cantidad);
int mostrarProducto(EProducto listaProductos[], int indice);
int buscarVacio(EProducto listaProductos[], int cantidad);
