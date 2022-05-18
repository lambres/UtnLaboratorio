/*
 ============================================================================
 Name        : Clase07.c
 Author      : Ruben Dario Zevallos Lambrescht
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Inputs.h"

#define CANT_NUM 5

int main(void) {

	int arrayNumeros[CANT_NUM];
	int i;
	for (i = 0 ; i< CANT_NUM; i++)
		{
			printf("Indice %d, valor %d: \n", i,  arrayNumeros[i]);
		}

	for (i = 0 ; i< CANT_NUM; i++)
	{
		getInt("\nIngrese un numero: ", 2, 0, 100, "Numero entre 0 y 100\n", &arrayNumeros[i]);
	}
	printf("\nImprimiendo el array cargado\n\n");
	for (i = 0 ; i< CANT_NUM; i++)
	{
		printf("Indice %d, valor %d: \n", i,  arrayNumeros[i]);
	}
	return EXIT_SUCCESS;
}
