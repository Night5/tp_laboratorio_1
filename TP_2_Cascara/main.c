#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define tam 20



int main()
{
    char seguir='s';
    int opcion=0;
    int i;
    int contadorDe18=0,contadorDe19a35=0,contadorMayorDe35=0;
    ePersona persona[tam];

    inicializarPersona(persona,tam);


    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

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
                system("cls");
                break;
            case 4:
                system("cls");
                for(i=0;i<tam;i++)
                {
                    if(persona[i].estado==1)
                        if(persona.edad<19)
                    {
                        contadorDe18++;
                    }
                    else
                    {
                        if(persona[i].edad>18&&persona[i].edad<35)
                        {
                            contadorDe19a35++;
                        }
                        else
                        {
                            contadorMayorDe35++;
                        }
                    }
                }
                graficoPersona(contadorDe18,contadorDe19a35,contadorMayorDe35);
                contadorDe18=0;
                contadorDe19a35=0;
                contadorMayorDe35=0;
                system("cls");
                break;
            case 5:
                seguir = 'n';
                break;
        }

        system("pause");
        system("cls");
    }

    return 0;
}
