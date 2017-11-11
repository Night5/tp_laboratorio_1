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
    int auxDni;

    for(i=0;i<tam;i++)
    {
        if(persona[i].dni==dni && persona[i].estado==1)
        {
            auxDni=i;
        }
    }

    return auxDni;
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



        for(i=0;i<tam;i++)
        {
            if(obtenerEspacioLibre(persona,tam)==i)
            {
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(persona[i].nombre);

            printf("\nIngrese edad: ");
            scanf("%d", &persona[i].edad);

            printf("\nIngrese dni: ");
            scanf("%d",&persona[i].dni);

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
    int paraBorrar, posic;
    int flagAux=0;
    char opcion;
    printf("Ingrese el dni de la persona que desea borrar: ");
    scanf("%d", &paraBorrar);

    posic = buscarPorDni(persona, paraBorrar, tam);


    printf("Esta seguro que desea borrar esta persona? (s/n)\n%d - %s", persona[posic].dni, persona[posic].nombre);
    printf("\n");
    printf("Su respuesta es: ");
    scanf("%s", &opcion);

    if(opcion=='s')
    {
        persona[posic].estado = 0;
        printf("\nBorrado con %cxito.\n", 130);
        flagAux = 1;
        system("pause");
    }
    else
    {
        printf("\nOperacion cancelada!\n");
        flagAux = 1;
        system("pause");
    }


    if(flagAux == 0)
    {
        printf("\nNo se encontr%c el dni solicitado!\n", 162);
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
            printf("%10s\t\t%d\t\t%d\n",persona[i].nombre,persona[i].edad,persona[i].dni);
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
            for(j=i+1;j<tam;j++)
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
   int j;
   int maximo=0;
   int valor[3]={hasta18,de19a35,mayorDe35};

   for(i=0;i<3;i++)
   {
       if(valor[i]>maximo)
       {
           maximo=valor[i];
       }
   }

   printf("\n");

   for(i=maximo;i>0;i--)
   {
       printf("F%d",i);
       for(j=0;j<3;j++)
       {
           if(valor[j]>=i)
           {
               printf("\t  *");
           }
           else
           {
               printf("\t ");
           }
       }

       printf("\n");
   }

   printf("\t<19\t19-35\t >35\n");
   system("pause");
   system("cls");
}





