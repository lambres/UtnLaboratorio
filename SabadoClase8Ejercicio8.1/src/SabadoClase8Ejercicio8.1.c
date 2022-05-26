/*
 ============================================================================
 Name        : 8.1
 Author      : Ruben Zevallos
 Version     :
 Copyright   : Your copyright notice
 Description :
Ejercicio 8.1
Realizar una función Suma que reciba como parámetros dos
enteros (los que va a sumar) y un puntero a entero que guardará
el resultado de esta. La función retorna 1 si pudo realizar la suma
y cero en caso de no haberla podido realizar.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
int Suma(int num1, int num2, int* resultado);

int Suma(int num1, int num2, int* resultado)
{
	int retorno = 0;
	if (resultado != NULL)
	{
		*resultado = num1 + num2;
		retorno = 1;
	}
	return retorno;
}

int main(void) {
	int numero1;
	int numero2;
	int pResultado;

	utn_getNumeroInt(&numero1, "Ingrese un numero:", "ERROR! REINGRESE", -1000, 1000, 2);
	utn_getNumeroInt(&numero2, "Ingrese otro numero:", "ERROR! REINGRESE", -1000, 1000, 2);

	if(Suma(numero1,numero2,&pResultado))
	{
		printf("El resultado de la suma de %d y %d es %d\n",numero1, numero2, pResultado);
	}
	else
	{
		printf("No se pudo realizar la suma\n");
	}


	return EXIT_SUCCESS;
}
