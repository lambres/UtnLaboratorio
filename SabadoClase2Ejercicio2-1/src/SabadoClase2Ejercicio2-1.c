/*
 ============================================================================
 Name        : SabadoClase2Ejercicio2-1.c
 Author      : Ruben Dario Zevallos Lambrescht 1ºH
 Version     : Ejercicio 2-1:
			Crear una función que reciba como parámetro un número entero.
			La función retorna 1 en caso de que sea positivo, -1 en caso
			de que sea negativo y 0 en caso de que sea 0. Realizar la prueba
			lógica de la función en el main.
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int evaluarEntrada(int valor);

int main(void) {
	int numeroIngresado;
	int resultado;
	printf("Ingrese un numero: \n");
	fpurge(stdin);
	scanf("%d", &numeroIngresado);
	resultado = evaluarEntrada(numeroIngresado);
	if (resultado == 0)
	{
		printf("El valor ingresado fue 0\n");
	}
	else
	{
		if(resultado<0)
		{
			printf("El valor ingresado fue negativo\n");
		}
		else
		{
			printf("El valor ingresado fue positivo\n");
		}
	}
	return EXIT_SUCCESS;
}

int evaluarEntrada(int valor)
{
	int retorno;
	retorno = 2;
	if(valor==0)
	{
		retorno = 0;
	}
	else
	{
		if(valor<0)
		{
			retorno = -1;
		}
		else
		{
			retorno = 1;
		}
	}
	return retorno;
}
