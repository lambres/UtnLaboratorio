/*
 ============================================================================
 Name        : Punteros.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int auxInt = 10;
	int *a;
	int num = 10;
	char auxChar = 'a';
	auxInt = (int) &auxChar;
	printf("%d\n",auxInt);
	printf("Direccion de a antes de incrementar %d\n", a);
	printf("El tamaño de num es %d\n",(num*sizeof(num)));
	a = a + num;
	printf("Direccion de a despues de incrementar %d\n", a);
	return EXIT_SUCCESS;
}
