/*
 ============================================================================
 Name        : 2.c
 Author      : Ruben Zevallos
 Version     :
 Copyright   : Your copyright notice
 Description :
Ejercicio 8.2
Realizar una función que reciba un puntero a char y dos char.
La función deberá reemplazar en la cadena cada ocurrencia del primer
carácter recibido, por el segundo. Retornando la cantidad de
reemplazos o -1 en caso de error.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define TAM_TEXTO 20

int reemplazo(char letra1, char letra2, char* cadena1);
int reemplazo(char letra1, char letra2, char* cadena1)
{
	int retorno = -1;
	char auxCadena[TAM_TEXTO];
	strncpy(auxCadena,cadena1,TAM_TEXTO);
	int i=0;
	if (cadena1 != NULL)
	{
		retorno = 0;
		for (i=0; i<TAM_TEXTO; i++)
		{
			if (*(auxCadena+i) == letra1)
			{
				strncpy(&auxCadena[i],&letra2,1);
				retorno ++;
			}
		}
		strncpy(cadena1,auxCadena,TAM_TEXTO);
	}
	return retorno;
}


int main(void) {
	char a, b;
	char cadena[TAM_TEXTO];
	int respuesta;
	fflush(stdin);
	utn_getCaracter(&a, "Ingrese un caracter", "Error!", ' ', '~', 2);
	fflush(stdin);
	utn_getCaracter(&b, "Ingrese otro caracter", "Error!", ' ', '~', 2);
	fflush(stdin);
	utn_getTexto(cadena, TAM_TEXTO, "Ingrese una cadena de texto", "Error!", 2);
	respuesta=reemplazo(a, b, cadena);
	if(respuesta!=-1)
	{
		printf("En la cedena %s se sustituyeron %d veces las letras %c x %c\n", cadena,respuesta,  a , b);
	}
	else
	{
		printf("Algo salio mal");
	}



	return EXIT_SUCCESS;
}
