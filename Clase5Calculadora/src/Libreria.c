/*
 * Libreria.c
 *
 *  Created on: 5 abr. 2022
 *      Author: dario
 */
#include <stdio.h>
#include <stdlib.h>

int getInt(char mensaje[], int reintentos, int minimo, int maximo, char mensajeError[], int* pNumeroIngresado)
{
	int retorno;
	int auxiliarInt;
	int retornoScanf;
	retorno = -1;
	if (mensaje != NULL && reintentos >= 0 && minimo < maximo && mensajeError != NULL && pNumeroIngresado != NULL)
	{
		printf("%s", mensaje);
		//fpurge(stdin);
		retornoScanf = scanf("%d", &auxiliarInt);
		//printf("--------Valor ingresado: %d: dentro de la funcion getInt--------\n", auxiliarInt);
		do
		{
			//printf("\tEste es el reintento %d", reintentos);
			if(retornoScanf != 1 || auxiliarInt > maximo || auxiliarInt < minimo)
			{
				printf("%s", mensajeError);
				retornoScanf = scanf("%d", &auxiliarInt);
				reintentos--;
			}
			else
			{
				reintentos = 0;
				*pNumeroIngresado = auxiliarInt;
				retorno = 0;
			}

		}while(reintentos > 0);
	}
	return retorno;
}
int getFloat(char mensaje[], int reintentos, float minimo, float maximo, char mensajeError[], float* pNumeroIngresado)
{
	int retorno;
	float auxiliarFloat;
	float retornoScanf;
	retorno = -1;
	if (mensaje != NULL && reintentos >= 0 && minimo < maximo && mensajeError != NULL && pNumeroIngresado != NULL)
	{
		printf("%s", mensaje);
		retornoScanf = scanf("%f", &auxiliarFloat);
		do
		{
			//printf("\tEste es el reintento %d", reintentos);
			if(retornoScanf != 1 || auxiliarFloat > maximo || auxiliarFloat < minimo)
			{
				printf("%s", mensajeError);
				retornoScanf = scanf("%f", &auxiliarFloat);
				reintentos--;
			}
			else
			{
				reintentos = 0;
				*pNumeroIngresado = auxiliarFloat;
				retorno = 0;
			}

		}while(reintentos > 0);
	}
	return retorno;
}
