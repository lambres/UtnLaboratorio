/*
 ============================================================================
 Name        : Clase5Calculadora.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include "Matematicas.h"
#include "Libreria.h"


int main(void) {
	int opcion;
	int numero1;
	int numero2;
	int resultado;
	int respuesta;
	float resultadoFloat;
	do
	{
		printf("----Calculadora-----\n");
		printf("1. Sumar dos numeros\n");
		printf("2. Restar dos números\n");
		printf("3. Multiplicar dos números\n");
		printf("4. Dividir dos numeros\n");
		printf("5. Salir\n");
		printf("Elija opción:\n");
		scanf("%d", &opcion);
		switch(opcion)
		{
		case 1:
			respuesta = getInt("Ingrese primer numero", 3, 0, 100, "Numero entre 0 y 100", &numero1);
			respuesta = getInt("Ingrese segundo numero", 3, 0, 100, "Numero entre 0 y 100", &numero2);
			respuesta = sumar(numero1, numero2, &resultado);
			if (respuesta == 0)
			{
				printf("La suma de los numeros %d y %d es: %d\n", numero1, numero2, resultado);
			}
			break;
		case 2:
			respuesta = getInt("Ingrese primer minuendo", 3, 0, 100, "Numero entre 0 y 100", &numero1);
			respuesta = getInt("Ingrese segundo sustraendo", 3, 0, 100, "Numero entre 0 y 100", &numero2);
			respuesta = restar(numero1, numero2, &resultado);
			if (respuesta == 0)
			{
				printf("La resta de los numeros %d y %d es: %d\n", numero1, numero2, resultado);
			}
			break;
		case 3:
			respuesta = getInt("Ingrese primer numero", 3, 0, 100, "Numero entre 0 y 100", &numero1);
			respuesta = getInt("Ingrese segundo numero", 3, 0, 100, "Numero entre 0 y 100", &numero2);
			respuesta = multiplicar(numero1, numero2, &resultado);
			if (respuesta == 0)
			{
				printf("La multiplicacion de los numeros %d y %d es: %d\n", numero1, numero2, resultado);
			}
			break;
		case 4:
			respuesta = getInt("Ingrese primer numero", 3, 0, 100, "Numero entre 0 y 100", &numero1);
			respuesta = getInt("Ingrese segundo numero", 3, 0, 100, "Numero entre 0 y 100", &numero2);
			respuesta = dividir(numero1, numero2, &resultadoFloat);
			if (respuesta == 0)
			{
				printf("La dividion de los numeros %d y %d es: %.2f\n", numero1, numero2, resultadoFloat);
			}
			else
			{
				printf("No se puede dividir por cero\n");
			}
			break;
			case 5:
			break;
		}
	}while(opcion!=5);
	return EXIT_SUCCESS;
}
