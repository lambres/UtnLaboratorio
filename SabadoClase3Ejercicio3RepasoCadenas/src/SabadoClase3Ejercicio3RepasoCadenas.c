/*
 ============================================================================
 Name        : SabadoClase3Ejercicio3RepasoCadenas.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

int main(void) {

	char cadena[100] = "Sabados";//cantidad de caracteres mas 1 del \0
	char otraCadena[100] = "Los Sabados";
	//int len;
	//printf("%s", cadena);
	/*
	printf("Ingrese una cadena: ");
	fpurge(stdin);
	//scanf("%s", cadena);
	//gets(cadena); para windows
	//para solucion de cualquier so es agregar lo siguiente
	scanf("%[^\n]", cadena);
	//fgets sirve tambien pero es mas especifico para archivos, lo veremos despues
	//fgets(cadena, 100, stdin); //ojo que agrega un \n al final antes del \0
	len = strlen(cadena);

	//printf("%s", cadena);
	printf("%d", len);
	*/

	int comp;
	//comp = strcasecmp("Zapallo", "zapallo"); //en mac y linux reemplaza a stricmp()
	comp = strcmp("Zapallo", "zapallo"); //en mac y linux reemplaza a stricmp()
	printf("%d",comp);

	strcat(cadena, otraCadena);
	printf("%s", cadena);
	return EXIT_SUCCESS;
}
