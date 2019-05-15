#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "usuario.h"
#include "producto.h"
#define LEN_US 5
#define LEN_PROD 10

int mostrarProdPorIdUs(Producto* array,int limite, int id);


int main()
{
    Usuario listaUsuarios[LEN_US];
    Producto listaProductos[LEN_PROD];
    int menu;
    int auxId;
    int auxIndexUsuario;
    int auxIndexProducto;

    usuario_init(listaUsuarios,LEN_US);
    producto_init(listaProductos,LEN_PROD);

    //informar_consultaFacturacion(contrataciones,LEN_CONT,array,QTY,"20911911915");
    //informar_ListarContrataciones(contrataciones,LEN_CONT,array,QTY);

    do
    {
        getValidInt("1.Alta\n2.Baja\n3.Modificar\n4.Mostrar\n5.Ordenar\n6.Mostrar Debug\n9.Salir\n","\nNo valida\n",&menu,1,9,1);
        switch(menu)
        {
            case 1:
                usuario_alta(listaUsuarios,LEN_US);
                break;
            case 2:
                getValidInt("ID?","\nNumero valida\n",&auxId,0,200,2);
                usuario_modificacion(listaUsuarios,LEN_US, auxId);
                break;
            case 3:
                getValidInt("ID?","\nNumero valida\n",&auxId,0,200,2);
                usuario_baja(listaUsuarios,LEN_US, auxId);
                break;
            case 4:
                producto_alta(listaProductos,LEN_PROD);
                break;
            case 5:
                getValidInt("ID?","\nNumero valida\n",&auxId,0,200,2);
                auxIndexUsuario = usuario_buscarPorId(listaUsuarios,LEN_US,auxId);
                mostrarProdPorIdUs(listaProductos,LEN_PROD, auxIndexUsuario);
                getValidInt("ID?","\nNumero valida\n",&auxId,0,200,2);
                auxIndexProducto = producto_buscarPorId(listaProductos,LEN_PROD,auxId);
                producto_modificacion(listaProductos,LEN_PROD,auxId);
                break;
            case 6:
                break;
        }

    }while(menu != 9);
    return 0;
}



int mostrarProdPorIdUs(Producto* array,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!(array[i].isEmpty) && array[i].idProducto == id)
            {
                printf("\nIdProducto: %d - Nombre: %s - Precio: %d - CantVendida: - Stock: %d", array[i].idProducto, array[i].nombre, array[i].precio, array[i].stock);
            }
        }
    }
    return retorno;
}
