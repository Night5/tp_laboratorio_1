#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"

#define A 3

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[200];
    int puntaje;
    char linkImagen[50];
    int estado;
    int idPelicula;

}eMovie;

eMovie* nuevaPelicula();
int agregarDatosPelicula(eMovie*);
void mostrarPelicula(eMovie*);
int agregarPelicula(eMovie* pelicula, FILE* archivo);
void borrarPelicula(eMovie*);
void modificarPelicula(eMovie*);

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

eMovie* nuevaPelicula()
{
    eMovie* pelicula = NULL;
    pelicula = malloc(sizeof(eMovie));
    return pelicula;
}

int agregarDatosPelicula(eMovie* pelicula)
{
    int retorno;
    char resp;
    eMovie* auxPeli;
    auxPeli=nuevaPelicula();

    printf("Ingrese ID de la pelicula: ");
    scanf("%d",&auxPeli->idPelicula);

    printf("Ingrese titulo de la pelicula: ");
    fflush(stdin);
    gets(auxPeli->titulo);
    while(strlen(auxPeli->titulo)>20)
    {
        printf("Error, titulo demasiado largo, supera los 20 caracteres,reingrese titulo");
        fflush(stdin);
        gets(auxPeli->titulo);
    }

    printf("Ingrese genero de la pelicula: ");
    fflush(stdin);
    gets(auxPeli->genero);
    while(strlen(auxPeli->genero)>20)
    {
        printf("Error, genero demasiado largo, supera los 20 caracteres,reingese genero");
        fflush(stdin);
        gets(auxPeli->genero);
    }

    printf("Ingrese duracion de la pelicula: ");
    scanf("%d",&auxPeli->duracion);

    printf("Ingrese descripcion de la pelicula: ");
    fflush(stdin);
    gets(auxPeli->descripcion);
    while(strlen(auxPeli->descripcion)>200)
    {
        printf("Error, descripcion demasiado larga, supera los 200 caracteres,reingrese descripcion");
        fflush(stdin);
        gets(auxPeli->descripcion);
    }

    printf("Ingrese puntaje de la pelicula: ");
    scanf("%d",&auxPeli->puntaje);
    while(auxPeli->puntaje <0 || auxPeli->puntaje >10)
    {
        printf("Error, el puntaje debe de ser entre 0 o 10,reingrese puntaje: ");
        scanf("%d",&auxPeli->puntaje);
        break;
    }

    printf("Ingrese link de la imagen de la pelicula: ");
    fflush(stdin);
    gets(auxPeli->linkImagen);
    while(strlen(auxPeli->linkImagen)>50)
    {
        printf("Error, link demasiado largo,supera los 50 caracteres,reingrese link");
        fflush(stdin);
        gets(auxPeli->linkImagen);
    }

    printf("\n\nEsta seguro que desea agregar esta pelicula? s/n\n\n");

    mostrarPelicula(auxPeli);
    printf("\n\nSu respuesta es: ");
    scanf("%c",&resp);
    if(resp=='s')
    {
        *pelicula=*auxPeli;
        free(auxPeli);
        retorno=1;
        printf("\nSe ha ingresado correctamente!\n\n");
    }
    else
    {
        printf("\n\nSe ha cancelado la operacion!!\n\n");
        retorno=0;
    }

    return retorno;

}

void mostrarPelicula(eMovie* pelicula)
{
    printf("\nTitulo: %s\nGenero: %s\nDuracion: %d\nDescripcion: %s\nPuntaje: %d\nLink de imagen: %s\n",pelicula->titulo,pelicula->genero,pelicula->duracion,pelicula->descripcion,pelicula->puntaje,pelicula->linkImagen);

}

int agregarPelicula(eMovie* pelicula, FILE* archivo)
{
    int estado=0;

    archivo=fopen("peliculas.dat","wb");

    if(archivo!=NULL)
    {
        estado=fwrite(pelicula, sizeof(eMovie),1,archivo);
        if(estado==1)
        {
            estado=1;
        }
        else
        {
            estado=0;
        }
    }

    fclose(archivo);

    return estado;
}


void borrarPelicula(eMovie* pelicula)
{
    int auxID;
    int flag=0;
    int i;
    char opcion;

    printf("Ingrese Id de la pelicula a eliminar:");
    scanf("%d",&auxID);
    for(i=0;i<A;i++)
    {
        if(auxID==pelicula[i].idPelicula)
        {
            printf("Pelicula a eliminar:\n");
            mostrarPelicula(pelicula+i);

            printf("\n\nPelicula encontrada. Seguro que desea de dar de baja? s/n\n\n");
            printf("Su respuesta es: ");
            opcion=getche();
            if(opcion=='s')
            {
                pelicula[i].estado=0;
                printf("\n\nPelicula eliminada!\n\n");
            }
            else
            {
                printf("Se ha cancelado la operacion!");
            }
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("Pelicula inexistente");
        getch();
    }
}

void modificarPelicula(eMovie* pelicula)
{
    int i;
    char auxTitle[20];
    char auxGenero[20];
    int auxDuracion;
    char auxDescripcion[50];
    int auxPuntaje;
    char auxLink[50];
    char respuesta;
    int opcion;
    int flag=0;

    eMovie* nuevaPeli = nuevaPelicula();

    printf("Ingrese titulo de la pelicula que desea modificar:\n");
    fflush(stdin);
    gets(auxTitle);

    for(i=0;i<A;i++)
    {
        if(auxTitle==pelicula->titulo)
        {
            printf("Ingrese lo que desea modificar de esta pelicula: ");
            printf("1-Titulo");
            printf("2-Genero");
            printf("3-Duracion");
            printf("4-Descripcion");
            printf("5-Puntaje");
            printf("6-Link de imagen");
            scanf("%d",&opcion);

            switch(opcion)
            {
                case 1:
                    printf("Ingrese nuevo titulo:");
                    fflush(stdin);
                    gets(auxTitle);
                    strcpy(nuevaPeli->titulo,auxTitle);
                    printf("Esta seguro que desea modificar? s/n");
                    mostrarPelicula(nuevaPeli);
                    scanf("%c",&respuesta);
                    if(respuesta=='s')
                    {
                        pelicula=nuevaPeli;
                        printf("\nSe ha realizado la modificacion con exito!\n");
                        flag=1;
                    }
                    else
                    {
                        printf("\nSe ha cancelado la operacion!\n");
                        flag=0;
                    }
                    break;
                case 2:
                    printf("Ingrese nuevo genero de la pelicula:");
                    fflush(stdin);
                    gets(auxGenero);
                    strcpy(nuevaPeli->genero,auxGenero);
                    printf("Esta seguro que desea modificar? s/n");
                    mostrarPelicula(nuevaPeli);
                    scanf("%c",&respuesta);
                    if(respuesta='s')
                    {
                        printf("\nSe ha realizado la modificacion con exito!\n");
                        flag=1;
                    }
                    else
                    {
                        printf("\nSe ha cancelado la operacion!\n");
                        flag=0;
                    }
                    break;
                case 3:
                    printf("Ingrese nueva duracion de la pelicula:");
                    scanf("%d",&auxDuracion);
                    nuevaPeli->duracion=auxDuracion;
                    printf("Esta seguro que desea modificar? s/n");
                    mostrarPelicula(nuevaPeli);
                    scanf("%c",&respuesta);
                    if(respuesta=='s')
                    {
                        printf("\nSe ha realizado la modificacion con exito!\n");
                        flag=1;
                    }
                    else
                    {
                        printf("\nSe ha cancelado la operacion!\n");
                        flag=0;
                    }
                    break;
                case 4:
                    printf("Ingrese nueva descripcion para la pelicula:");
                    fflush(stdin);
                    gets(auxDescripcion);
                    while(strlen(auxDescripcion)>50)
                    {
                        printf("Error, la descripcion es demasiado larga, supera los 50 caracteres, reingrese descripcion");
                        fflush(stdin);
                        gets(auxDescripcion);
                    }
                    strcpy(nuevaPeli->descripcion,auxDescripcion);
                    printf("Esta seguro que desea modificar? s/n");
                    mostrarPelicula(nuevaPeli);
                    scanf("%c",&respuesta);
                    if(respuesta=='s')
                    {
                        printf("Se ha realizado la modificacion con exito!");
                        flag=1;
                    }
                    else
                    {
                        printf("Se ha cancelado la operacion!");
                        flag=0;
                    }
                    break;
                case 5:
                    printf("Ingrese nuevo puntaje de la pelicula");
                    scanf("%d",&auxPuntaje);
                    while(auxPuntaje>10 || auxPuntaje <0)
                    {
                        printf("Error, el puntaje debe de ser entre 0 y 10");
                        scanf("%d",&auxPuntaje);
                        break;
                    }
                    nuevaPeli->puntaje=auxPuntaje;
                    printf("Esta seguro que desea modificar? s/n");
                    mostrarPelicula(nuevaPeli);
                    scanf("%c",&respuesta);
                    if(respuesta=='s')
                    {
                        printf("Se ha realizado la modificacion con exito!");
                        flag=1;
                    }
                    else
                    {
                        printf("Se ha cancelado la operacion!");
                        flag=0;
                    }
                    break;
                case 6:
                    printf("Ingrese nuevo link de imagen");
                    fflush(stdin);
                    gets(auxLink);
                    while(strlen(auxLink)>50)
                    {
                        printf("Error, el nuevo link supera los 50 caracteres, reingrese link de imagen");
                        fflush(stdin);
                        gets(auxLink);
                    }
                    strcpy(nuevaPeli->linkImagen,auxLink);
                    printf("Esta seguro que dedea modificar? s/n");
                    scanf("%c",&respuesta);
                    if(respuesta=='s')
                    {
                        printf("Se ha realizado la modificacion con exito!");
                        flag=1;
                    }
                    else
                    {
                        printf("Se ha cancelado la operacion!");
                        flag=0;
                    }
                    break;

            }
        }
    }


}
