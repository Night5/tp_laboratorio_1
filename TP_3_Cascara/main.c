#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define A 3


int main()
{
    eMovie* peliculas;
    FILE* archivoPeliculas;
    char seguir='s';
    int opcion=0;
    int cargarPelicula=0;
    int flag=0;



    archivoPeliculas=fopen("peliculas.dat","rb");
    if(archivoPeliculas==NULL)
    {
        archivoPeliculas=fopen("peliculas.dat","wb");
    }
    if(archivoPeliculas!=NULL)
    {
        peliculas=nuevaPelicula();
        if(peliculas!=NULL)
        {
            while(!feof(archivoPeliculas))
            {
                fread(peliculas,sizeof(eMovie),1,archivoPeliculas);
            }
        }
    }

    while(seguir=='s')
    {
        printf("------Menu de opciones------\n\n");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n\n");
        printf("La opcion que ha elegido es: ");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                peliculas=nuevaPelicula();
                cargarPelicula=agregarDatosPelicula(peliculas);
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                borrarPelicula(peliculas);
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                modificarPelicula(peliculas);
                system("pause");
                system("cls");
               break;
            case 4:

                break;
            case 5:
                seguir='n';
                break;

        }
    }

    return 0;
}
