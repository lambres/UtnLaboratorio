/*
Programa ejemplo clase2
Objetivo:
realizar un programa que solicite cinco numeros e imprima por pantalla el
promedio, el maximo y el minimo.
Aspectos a destacar:
-el uso de bucles para pedir numero tras otro
-el uso de acumiladores, se tiene que guardar la suma para luego hacer el promedio
-el uso de if para preguntar si el numero ingresado es mayor o menor para guardar maximos y minimos
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int maximo;
    int minimo;
    int acumulador;
    int auxiliarInt;
    int i;

    printf("Ingrese un número:\n");
    scanf("%d",&auxiliarInt);
    maximo = auxiliarInt;
    minimo = auxiliarInt;
    acumulador = auxiliarInt;
    for (i = 0 ; i < 4; i++)
    {
        printf("Ingrese un número:\n");
        scanf("%d",&auxiliarInt);
        acumulador = acumulador + auxiliarInt;
        if (maximo < auxiliarInt)
        {
            maximo = auxiliarInt;
        }
        if (minimo > auxiliarInt)
        {
            minimo = auxiliarInt;
        }
    }
    printf("El máximo valor ingresado es: %d\n", maximo);
    printf("El mínimo valor ingresado es: %d\n", minimo);
    printf("El promedio es: %.2f\n", (float)acumulador/5);


    return 0;
}
