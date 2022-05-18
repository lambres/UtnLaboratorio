/*
 ============================================================================
 Name        : Clase4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
int main(void)
{
	int edad;
	char letra;
	int peso;
	int respuesta;

	respuesta = utn_getNumeroInt(&edad,"Edad?\n", "Error la edad debe de ser 0 a 199\n",0,199,2);
	if(respuesta == 0)
	{
		printf("La edad es: %d\n", edad);
	}
	else
	{
		printf("ERROR\n");
	}

	respuesta= utn_getNumeroInt(&peso, "Peso?\n", "Error peso válido entre 0 y 500\n", 0, 500, 3);
	if(respuesta == 0)
	{
		printf("El peso es: %d\n", peso);
	}
	else
	{
		printf("ERROR\n");
	}

	respuesta= utn_getCaracter(&letra, "Letra?\n", "La letra debe ser desde A a J\n", 'A', 'J', 3);
	if(respuesta == 0)
	{
		printf("La letra es: %c\n", letra);
	}
	else
	{
		printf("ERROR\n");
	}

	return EXIT_SUCCESS;
}
