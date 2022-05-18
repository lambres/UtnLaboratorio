/*
 ============================================================================
 Name        : Funciones_UTN.c
 Author      : Ruben Dario Zevallos Lambrescht
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define QTY_PERSONAS 1000


int main(void) {
	float buffer;
	/*printf("ingrese el signo menos");
	scanf("%c", &buffer);
	if (buffer == 45)
	{
		printf("Correcto");
	}
	else
	{
		printf("Todo mal");
	}*/
	if(!utn_getNumeroFloat(&buffer, "Ingrese un numero flotante:\n", "Error\n", -1000, 1000, 5))
	{
		printf("%.2f\n",buffer);
	}

	/*if (!utn_getCaracter(&buffer, "Ingrese un caracter\n", "Error\n", 'a', 'z', 2))
	{
		printf("Presiono: %c\n", buffer);
	}
	else
	{
		printf("Presiono: %c\n", buffer);
	}
	*/
	return EXIT_SUCCESS;
}
