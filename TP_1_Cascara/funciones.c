#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

float sumar(float num1,float num2)
{
    return num1+num2;
}

float restar(float num1,float num2)
{
    return num1-num2;
}
float multiplicacion(float num1,float num2)
{
   return num1*num2;
}

float division(float num1,float num2)
{
    if(num2==0)
    {
        printf("Error. No se puede dividir con 0, reingrese numero.");
        scanf("%f",&num2);
    }
     else
     {
         return num1/num2;
     }
}

int factorial (num1)
{
   int num2;
   int factorial=1;

   for(num2=num1;num2>1;num2--)
   {
    factorial=factorial*num2;
   }

   return factorial;
}
