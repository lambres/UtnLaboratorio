/*
 ============================================================================
 Name        : clase1Ej1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int numero1;
	int numero2;
	int suma;
	int resta;
	int mult;
	float div;

	printf("Ingrese un número");
	scanf("%d",&numero1);
	printf("Ingrese otro número");
	scanf("%d",&numero2);
	suma = numero1 + numero2;
	printf("La suma es:%d\n",suma);

	resta = numero1 - numero2;
	printf("La resta es:%d\n",resta);

	mult = numero1 * numero2;
	printf("La multiplicacion es:%d\n",mult);

	div = (float)numero1 / numero2;
	printf("La división es:%.2f",div);

	return EXIT_SUCCESS;
}
