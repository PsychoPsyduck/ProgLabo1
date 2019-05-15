#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "publicacion.h"
#include "informe.h"
#define LEN_CLIENTES 10
#define LEN_AVISOS 20

int main()
{
    Cliente listaClientes[LEN_CLIENTES];
    Aviso listaAvisos[LEN_AVISOS];
    int menu;
    int auxiliarId;
    int auxIndice;
    int auxiliarIndiceAviso;

    cliente_init(listaClientes,LEN_CLIENTES);
    publicacion_init(listaAvisos,LEN_AVISOS);

    cliente_altaForzada(listaClientes,LEN_CLIENTES,"Gatin","Tuca", "27-35654654-6", 5);
    cliente_altaForzada(listaClientes,LEN_CLIENTES,"Nicolas","Sande", "27-37954192-6", 6);
    cliente_altaForzada(listaClientes,LEN_CLIENTES,"Rocio","Giustee", "27-39147115-6", 6);
    publicacion_altaForzada(listaAvisos,LEN_AVISOS, 0 , 1 ,"comida");
    publicacion_altaForzada(listaAvisos,LEN_AVISOS, 1 , 0 ,"varios");
    publicacion_altaForzada(listaAvisos,LEN_AVISOS, 2 , 2 ,"dulces");
    publicacion_altaForzada(listaAvisos,LEN_AVISOS, 1 , 2 ,"chocolate");
    publicacion_altaForzada(listaAvisos,LEN_AVISOS, 0 , 2 ,"caramelo");
    publicacion_altaForzada(listaAvisos,LEN_AVISOS, 1 , 1 ,"snacks");

    do
    {
        getValidInt("\n\n1.Alta cliente\n2.Modificar cliente\n3.Baja cliente\n4.Publicar\n5.Pausar publicacion\n6.Reanudar publicacion\n7.Imprimir clientes\n8.Imprimir publicaciones\n9.a) Imforme: cliente con mas avisos activos\n10.b)Imforme: cliente con mas avisos pausados\n11.c)Imforme: cliente con mas avisos\n12.a)Informe: cantidad de publicaciones de rubro\n13.b)Informe: rubro con mas publicaciones activas\n14.c)Informe: rubro con menos publicaciones activas\n0.Salir\n","\nNo valida\n",&menu,0,35,1);
        switch(menu)
        {
            case 1:
                cliente_alta(listaClientes,LEN_CLIENTES);
                break;
            case 2:
                getValidInt("ID de cliente?","\nID ivalido\n",&auxiliarId,0,200,2);
                cliente_modificacion(listaClientes,LEN_CLIENTES, auxiliarId);
                break;
            case 3:
                getValidInt("ID de cliente?","\nNumero valida\n",&auxiliarId,0,200,2);
                cliente_baja(listaClientes,LEN_CLIENTES, auxiliarId);
                publicacion_baja(listaAvisos,LEN_AVISOS, auxiliarId);
                break;
            case 4:
                if(!getValidInt("\nID cliente? ","\nEso no es un id valido",&auxiliarId,0,999999,2))
                {
                    publicacion_alta(listaAvisos,LEN_AVISOS, auxiliarId);
                    auxIndice =cliente_buscarPorId(listaClientes,LEN_CLIENTES, auxiliarId);
                    listaClientes[auxIndice].avisoActivo++;
                }
                break;
            case 5:
                getValidInt("ID de publicacion?","\nID ivalido\n",&auxiliarId,0,200,2);
                auxiliarIndiceAviso = publicacion_buscarPorId(listaAvisos,LEN_AVISOS,auxiliarId);
                auxIndice = cliente_buscarPorId(listaClientes,LEN_CLIENTES, listaAvisos[auxiliarIndiceAviso].idCliente);
                mostrarCliente(listaClientes,LEN_CLIENTES, listaAvisos[auxIndice].idCliente);
                listaClientes[auxIndice].avisoActivo--;
                publicacion_pausar(listaAvisos,LEN_AVISOS, auxiliarIndiceAviso);
                break;
            case 6:
                getValidInt("ID de publicacion?","\nID ivalido\n",&auxiliarId,0,200,2);
                auxiliarIndiceAviso = publicacion_buscarPorId(listaAvisos,LEN_AVISOS,auxiliarId);
                auxIndice = cliente_buscarPorId(listaClientes,LEN_CLIENTES, listaAvisos[auxiliarIndiceAviso].idCliente);
                mostrarCliente(listaClientes,LEN_CLIENTES, listaAvisos[auxIndice].idCliente);
                listaClientes[auxIndice].avisoActivo++;
                publicacion_reanudar(listaAvisos,LEN_AVISOS, auxiliarIndiceAviso);
                break;
            case 7:
                cliente_mostrarListaClientes(listaClientes,LEN_CLIENTES);
                break;
            case 8:
                publicacion_mostrar(listaAvisos,LEN_AVISOS,listaClientes,LEN_CLIENTES);
                break;
            case 9:
                informe_masAvisosActivos(listaClientes,LEN_CLIENTES, listaAvisos,LEN_AVISOS);
                break;
            case 10:
                informe_masAvisosPausados(listaClientes,LEN_CLIENTES, listaAvisos,LEN_AVISOS);
                break;
            case 11:
                informe_masAvisos(listaClientes,LEN_CLIENTES, listaAvisos,LEN_AVISOS);
                break;
            case 12:
                getValidInt("Numero de rubro?","\nRubro invalido\n",&auxiliarId,0,200,2);
                informe_totalRubro(listaAvisos,LEN_AVISOS, auxiliarId);
                break;
            case 13:
                informe_rubroMasActivas(listaAvisos,LEN_AVISOS);
                break;
            case 14:
                informe_rubroMenosActivas(listaAvisos,LEN_AVISOS);
                break;
            case 33:
                cliente_mostrarDEB(listaClientes,LEN_CLIENTES);
                break;
            case 34:
                publicacion_mostrarDEB(listaAvisos,LEN_CLIENTES);
                break;
        }

    }while(menu != 0);


    return 0;
}
