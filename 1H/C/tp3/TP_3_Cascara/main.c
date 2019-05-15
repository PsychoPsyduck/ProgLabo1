
#include "funciones.h"


int main()
{
    char seguir='s';
    int opcion=0;
    int i;

    eMovie* catalogo[50];

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Salir\n");

        scanf("%d",&opcion);


        if(opcion > 0 && opcion < 5)
        {
            switch(opcion)
            {
            case 1:

                  *(catalogo+(buscarLibre(catalogo))=nuevaPelicula();
                  crearTxt(*catalogo);
                  break;

              case 2:
                      //levantar archivo
                      borrarPelicula(catalogo);
                      crearTxt(catalogo); //hacer que tome el archivo y lo modifique. Este solo crea uno nuevo
                      break;

                  case 3:
                          for(i=0; i<50; i++)
                    {
                        if(*(catalogo+i)->estado == '1')
                            {
                                crearPagina(catalogo, i);
                            }

                        }
                break;

            case 4:
                    seguir = 'n';
                             break;
                }
        }
        else
        {
            printf("Codigo de operacion invalido. Reingrese codigo. \n");
        }
    }

    return 0;
}

