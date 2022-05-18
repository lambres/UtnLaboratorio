/*
 ============================================================================
 Name        : Clase_2_determinarMaximoYMinimo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#define TRUE 1
#define FALSE 0
#include <stdio.h>

int main(void) {
	int minimo;
	int maximo;
	int i;
	int bufferInt;
	int flag;
	flag = TRUE;


	for(i = 0; i < 5; i++)
	{
		printf("Ingrese un numero %d\n", i+1);
		scanf("%d", &bufferInt);
		if (flag == TRUE)
		{
			maximo=bufferInt;
			minimo=bufferInt;
			flag=FALSE;
		}
		else
		{
			if(bufferInt>maximo)
			{
				maximo = bufferInt;
			}
			if (bufferInt<minimo)
			{
				minimo = bufferInt;
			}
		}
	}
	printf("\nEl valor maximo es %d y el valor minimo es %d", maximo, minimo);
	return 0;
}
