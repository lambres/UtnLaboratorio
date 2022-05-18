/*
 * Matematicas.c
 *
 *  Created on: 5 abr. 2022
 *      Author: dario
 */

#include <stdio.h>

int sumar(int numero1, int numero2, int* pResultado)
{
	int retorno;
	retorno = -1;
	*pResultado = numero1 + numero2;
	retorno = 0;
	return retorno;
}

int restar(int numero1, int numero2, int* pResultado)
{
	int retorno;
	retorno = -1;
	*pResultado = numero1 - numero2;
	retorno = 0;
	return retorno;
}

int multiplicar(int numero1, int numero2, int* pResultado)
{
	int retorno;
	retorno = -1;
	*pResultado = numero1 * numero2;
	retorno = 0;
	return retorno;
}

int dividir(int numero1, int numero2, float* pResultado)
{
	int retorno;
	retorno = -1;
	float buffer;
	if (pResultado != NULL && numero2 !=0)
	{
		buffer = (float)numero1 / numero2;
		*pResultado = buffer;
		retorno = 0;
	}
	return retorno;
}
