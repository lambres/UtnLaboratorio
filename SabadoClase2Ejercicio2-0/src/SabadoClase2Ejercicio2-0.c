/*
 ============================================================================
 Name        : SabadoClase2Ejercicio2-0.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Crear una función que reciba como parámetro dos números enteros, que realice el
 promedio de los números y que retorne dicho valor.
 * Zevallos Lambrescht Ruben Dario 1ºH
 */

#include <stdio.h>
#include <stdlib.h>
float calcular(int numero1, int numero2);

int main(void) {
	float respuesta;
	int valor1;
	int valor2;
	printf("ingrese Numero1:\n");
	fpurge(stdin);
	scanf("%d", &valor1);
	printf("ingrese Numero2:\n");
	fpurge(stdin);
	scanf("%d", &valor2);
	respuesta = calcular(valor1, valor2);
	printf("El valor devuelto es %.2f:\n", respuesta);
	return EXIT_SUCCESS;
}


float calcular(int numero1, int numero2)
{
	float promedio;
	float buffer;
	buffer = ((float)numero1 + numero2) / 2;
	promedio = buffer;
	return promedio;
}
