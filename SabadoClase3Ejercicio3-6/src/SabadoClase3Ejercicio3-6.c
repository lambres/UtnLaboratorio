/*
 ============================================================================
 Name        : SabadoClase3Ejercicio3-6.c
 Author      : Ruben Dario Zevallos Lambrescht 1H
 Ejercicio 3-6 (CADENAS):
 Crear una función que reciba como parámetro una cadena de caracteres.
 Dicha función permitirá reemplazar las vocales de la cadena por asteriscos.
 Retornara la cantidad de reemplazos que se produjeron.

 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int utn_vocalesAsterisco(char * cadena, int longitud);

int main(void) {
	int cantidadCaracteres;
	char cadena[50];
	printf("Ingrese Cadena: \n");
	fpurge(stdin);
	scanf("%[^\n]", cadena);
	cantidadCaracteres = utn_vocalesAsterisco(cadena, strlen(cadena));
	printf("%d", cantidadCaracteres);

	return EXIT_SUCCESS;
}


int utn_vocalesAsterisco(char * cadena, int longitud)
{
	int i = 0;
	int contador = 0;
	char buffer[50];
	strcpy(buffer,cadena);
	for (i = 0 ; i < longitud; i++)
	{
	if (	toupper(buffer[i])== 'A'
			|| toupper(buffer[i])== 'E'
			|| toupper(buffer[i])== 'I'
			|| toupper(buffer[i])== 'O'
			|| toupper(buffer[i])== 'U')
		{
			buffer [i] = 42;
			contador++;
		}
	}
	return contador;
}
