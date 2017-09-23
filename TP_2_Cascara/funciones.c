#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"


int obtenerEspacioLibre(ePersona persona[],int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        if(persona[i].estado==0)
        {
            return i;
        }
    }

    return -1;
}


int buscarPorDni(ePersona persona[], int dni,int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        if(persona[i].dni==dni)
        {
            return persona[i].dni;
        }
    }

    return -1;
}

void inicializarPersona(ePersona persona[],int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        persona[i].estado=0;
    }
}

void altaPersona(ePersona persona[], int tam)
{
    int i;
    int personaLibre;

    personaLibre=obtenerEspacioLibre(persona, tam);

    for(i=0;i<tam;i++)
    {
        if(personaLibre=!1)
        {
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(persona[personaLibre].nombre);

            printf("\nIngrese edad: ");
            scanf("%d", &persona[personaLibre].edad);

            printf("\nIngrese dni: ");
            scanf("%d",&persona[personaLibre].dni);

            persona[i].estado=1;

            break;

        }
    }

    if(tam==i && obtenerEspacioLibre(persona,tam)==-1)
    {
        printf("No hay espacio disponible!");
    }

}

void borrarPersona(ePersona persona[],int tam)
{
    int dni,i;
    int lugarBuscar;
    char respuesta;

    printf("Ingrese el DNI de la persona que desea eliminar: ");
    scanf("%d",&dni);

    if(persona[i].estado==1&&buscarPorDni(persona,dni,tam)==persona[i].dni)
    {
        printf("Seguro que desea eliminar a: \nNombre:%s\nDNI:%d",persona[lugarBuscar].nombre,persona[lugarBuscar].dni);
        printf("Ingrese: s/n");
        fflush(stdin);
        respuesta=tolower(getche());
        if(respuesta=='s')
        {
            persona[lugarBuscar].estado=0;
            printf("\nSe ha eliminado con existo.\n");
        }
        else if(respuesta=='n')
        {
            printf("Se ha cancelado la operacion.");
        }
        if(buscarPorDni(persona,dni,tam)==-1)
        {
            printf("No se ha encontrado el DNI.\n");
        }

    }
}

void mostrarPersona(ePersona persona[],int tam)
{
    int i;

    ordenarPersona(persona,tam);
    printf("\tNombre\t\tEdad\t\tDNI\n\n");

    for(i=0;i<tam;i++)
    {
        if(persona[i].estado==1)
        {
            printf("%s\t\t%d\t\t%d\t\t",persona[i].nombre,persona[i].edad,persona[i].dni);
        }
    }
}

void ordenarPersona(ePersona persona[],int tam)
{
    int i;
    int j;

    ePersona auxOrdenar;

        for(i=0;i<tam;i++)
        {
            for(j=0;j<tam;j++)
            {
                if(strcmp(persona[i].nombre,persona[j].nombre)==1)
                {
                    auxOrdenar=persona[i];
                    persona[i]=persona[j];
                    persona[j]=auxOrdenar;
                }
            }
        }
}

void graficoPersona(int hasta18,int de19a35,int mayorDe35)
{
    int i;
    int mayor;
    int flag=0;
    int edades[3]={hasta18,de19a35,mayorDe35};

    if(hasta18>=de19a35&&hasta18>=mayorDe35)
    {
        mayor=hasta18;
    }
    else
    {
        if(de19a35>=hasta18&&de19a35>=mayorDe35)
        {
            mayor=de19a35;
        }
        else
        {
            mayor=mayorDe35;
        }
    }
    for(i=mayor;i>0;i--)
    {
        printf("%02d|",i);

        if(i<=hasta18)
        {
            printf("*");
        }
        if(i<=de19a35)
        {
            flag=1;
            printf("\t*");
        }
        if(i<=mayorDe35)
        {
            if(flag==0)
            {
                printf("\t\t*");
            }
            if(flag==1)
            {
                printf("\t*");
            }
        }

        printf("\n");
    }
    printf("-----------------------");
    printf("\n   |<18\t19-35\t>35");
    printf("\n    %d\t%d\t%d",hasta18,de19a35,mayorDe35);

    system("pause");
    system("cls");
}





