/*
 ============================================================================
 Name        : SabadoClase3Ejercicio3-4.c
 Author      : Ruben Dario Zevallos Lambrescht
 Version     : 1H Ejercicio 3-4
 Ejercicio 3-4 (CADENAS):
Pedirle al usuario su nombre y apellido (en variables separadas, una para el nombre y otra para el apellido). Ninguna de las dos variables se puede modificar.
Debemos lograr guardar en una tercer variable el apellido y el nombre con el siguiente formato:
Por ejemplo:
Si el nombre es juan ignacio y el apellido es gOmEz, la salida debería ser:
Gomez, Juan Ignacio

 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "utn.h"

int utn_toUpper(char * cadena, int longitud);

int main(void) {
	char nombre[50]="Juan Ignacio";
	char apellido[50]="Gomez";
	char apellidoNombre[100];

	printf("Ingrese Nombre: \n");
	fpurge(stdin);
	scanf("%[^\n]", nombre);

	printf("Ingrese Apellido: \n");
	fpurge(stdin);
	scanf("%[^\n]", apellido);
	snprintf(apellidoNombre,100, "%s, %s" , apellido, nombre);
	if (utn_toUpper(apellidoNombre,sizeof(apellidoNombre)))
		{
			printf("Error en coversion de nombre");
		}
	printf("%s", apellidoNombre);

	return EXIT_SUCCESS;
}


int utn_toUpper(char * cadena, int longitud)
{
	int retorno = -1;
	int i = 0;
	char buffer[longitud];
	strncpy(buffer,cadena,longitud);

	for (i = 0 ; i < longitud; i++)
	{
		if (i == 0)
		{
			if (buffer[i] >= 'a' && buffer[i] <= 'z')
			{
				buffer[i]= buffer[i]-32;
			}
		}
		if (buffer[i]== 32)
		{
			if (buffer[i+1] >= 'a' && buffer[i+1] <= 'z')
			{
				buffer [i+1] = buffer[i+1] - 32;
			}
		}
		retorno = 0;
		strcpy(cadena, buffer);
	}

	return retorno;
}
