/*
 ============================================================================
 Name        : Clase5FuncionesInputs.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Inputs.h"

int main(void) {
	float retornoFuncion;
	float numeroOficial;
	puts("Vamos a probar nuestro codigo"); /* prints !!!Hello World!!! */

	retornoFuncion = getFloat("Ingrese Un Numero: ", 1, 0, 10, "Che te equivoscaste ", &numeroOficial);
	if (retornoFuncion == -1)
	{
		printf("\n\t\t Salio todo mal: %f", retornoFuncion);

	}
	else
	{
		printf("\n\t\t Numero Oficial: %f", numeroOficial);
		printf("\n\t\t Salio todo bien: %F", retornoFuncion);

	}
	return EXIT_SUCCESS;
}
