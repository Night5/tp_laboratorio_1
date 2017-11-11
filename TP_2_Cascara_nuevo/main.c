#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define tam 4



int main()
{
    char seguir='s';
    int opcion=0;
    int i;
    int hasta18=0,de19a35=0,mayorDe35=0;

    ePersona persona[tam];

    inicializarPersona(persona,tam);


    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n\n");

        printf("Su opcion es: ");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                altaPersona(persona,tam);
                system("cls");
                break;
            case 2:
                system("cls");
                borrarPersona(persona,tam);
                system("cls");
                break;
            case 3:
                system("cls");
                mostrarPersona(persona,tam);
                system("pause");
                system("cls");
                break;
            case 4:
                system("cls");
                for(i=0;i<tam;i++)
                {
                    if(persona[i].estado=1)
                    {
                        if(persona[i].edad<19)
                        {
                            hasta18++;
                        }
                        else
                        {
                            if(persona[i].edad>18 && persona[i].edad<35)
                            {
                                de19a35++;
                            }
                            else
                            {
                                mayorDe35++;
                            }
                        }
                    }
                }

                graficoPersona(hasta18,de19a35,mayorDe35);

                hasta18=0;
                de19a35=0;
                mayorDe35=0;

                system("cls");

                break;
            case 5:
                seguir = 'n';
                break;
            default:
                system("cls");
                printf("Esta opcion no existe. Por favor, reingrese su opcion");
                system("pause");
                system("cls");
                break;

        }


    }

    return 0;
}
