/*
 ============================================================================
 Name        : promedio5Numeros.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float acumuladorNumeros;
	float numeroIngresado;
	float i;
	float promedio;
	acumuladorNumeros = 0;
	for (i=0;i<5;i++)
	{
		printf("Ingrese un número");
		scanf("%f",&numeroIngresado);
		acumuladorNumeros+=numeroIngresado;
	}
	promedio = acumuladorNumeros / i;
	printf("Valor Acumulador es:%.0f\n" ,acumuladorNumeros );

	printf("El promedio de los 5 numeros ingresados es:%.2f\n" ,promedio );


	return EXIT_SUCCESS;
}
