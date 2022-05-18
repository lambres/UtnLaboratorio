/*
 * ordenamiento.c
 *
 *  Created on: 12 abr. 2022
 *      Author: dario
 */

#include <stdio.h>
#include <stdlib.h>
#include "Inputs.h"
#include "ordenamiento.h"

int printArray(int cantidadElementos, int arrayNumeros[])
{
	int retorno = -1;
	int i;
	if(cantidadElementos >0 && arrayNumeros != NULL)
	{
		for (i = 0 ; i< cantidadElementos; i++)
		{
			printf("Indice %d, valor %d: \n", i,  arrayNumeros[i]);
		}

		retorno = 0;
	}
	return retorno;
}

int maximoArray(int arrayNumero[], int tam, int *maximo, int *posicion)
{
	int i;
	int maximoIngresado;
	int posicionAuxiliar;
	int retorno = -1;
	if(arrayNumero != NULL && tam > 0 && maximo != NULL)
	{
		for(i=0;i<tam;i++)
		{
			if(i==0 || arrayNumero[i] > maximoIngresado)
			{
				maximoIngresado = arrayNumero[i];
				posicionAuxiliar=i;
				retorno = 0;
			}
		}
		*maximo = maximoIngresado;
		*posicion = posicionAuxiliar;
	}
	return retorno;
}

int ordenamiento(int arrayOriginal[], int tam)
{
	int retorno = -1;
	int arrayAModificar[tam];
	int i;
	if(arrayOriginal != NULL && tam > 0)
	{


	}

	return retorno;
}

int duplicadoArray(int arrayOriginal[], int arrayACopiar[], int tam)
{
	int retorno = -1;
	int i;
	if(arrayOriginal != NULL && arrayACopiar != NULL && tam > 0)
	{


	}

	return retorno;
}

