#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float num1, num2;
    float resultado;
    int resFactorial;
    int flagOperandoUno=0;
    int flagOperandoDos=0;

    while(seguir=='s')
    {

        if(flagOperandoUno==1)
        {
            printf("1- Ingresar 1er operando (A=x)\n");
            printf("2- Ingresar 2do operando (B=y)\n");

            if(flagOperandoDos==1)
            {
                system("cls");
                printf("1- Ingresar 1er operando (A=%.2f)\n",num1);
                printf("2- Ingresar 2do operando (B=%.2f)\n",num2);
            }

        }

        else
        {
            printf("1- Ingresar 1er operando (A=x)\n",num1);
            printf("2- Ingresar 2do operando (B=y)\n",num2);
        }

        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                printf("Ingrese numero: ");
                scanf("%.2f",&num1);
                system("cls");
                break;
            case 2:
                system("cls");
                printf("Ingrese numero: ");
                scanf("%.2f",&num2);
                system("cls");
                break;
            case 3:
                system("cls");
                resultado = sumar(num1,num2);
                printf("El resultado de la suma es: %.2f\n\n",resultado);
                break;
            case 4:
                system("cls");
                resultado = restar(num1,num2);
                printf("El resultado de la suma es: %.2f\n\n",resultado);
                break;
            case 5:
                system("cls");
                resultado = multiplicacion(num1,num2);
                printf("El resultado de la multiplicacion es: %.2f\n\n",resultado);
                break;
            case 6:
                system("cls");
                resultado = division(num1,num2);
                printf("El resultado de la division es: %.2f\n\n",resultado);
                break;
            case 7:
                system("cls");
                resFactorial= factorial(num1);
                printf("El factorial es: %d\n\n",resFactorial);
                break;
            case 8:
                system("cls");
                resultado = sumar(num1, num2);
                printf("El resultado de la suma es: %.2f\n\n",resultado);

                resultado = restar(num1,num2);
                printf("El resultado de la resta es: %.2f\n\n",resultado);

                resultado = division(num1,num2);
                printf("El resultado de la division es: %.2f\n\n",resultado);

                resultado = multiplicacion(num1,num2);
                printf("El resultado de la multiplicacion es: %.2f\n\n",resultado);

                resFactorial = factorial(num1);
                printf("El resultado de factorial es: %d\n\n",resFactorial);
                break;
            case 9:
                seguir = 'n';
                break;
        }

        system("pause");
        system("cls");

    }

    return 0;
}
