/*
 ============================================================================
 Name        : 3.c
 Author      : Ruben Zevallos Div H
 Version     :
 Copyright   : Your copyright notice
 Description :
Ejercicio 8.3
Realizar una función que reciba como parámetros un array de enteros,
el tamaño del array y un entero por referencia. La función calculara el máximo
valor de ese array y utilizará el valor por referencia para retornar ese valor.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAMANIO 10

void ejercicio83(int* parray, int TAM, int * resultado);
int main(void) {
	int array[TAMANIO]={34,60,75,2,100,1,25,33,77,85};
	int valorResultado;
	ejercicio83(array,TAMANIO,&valorResultado);
	printf("El valor maximo dentro del array es %d: \n", valorResultado);
	return EXIT_SUCCESS;
}


void ejercicio83(int* parray, int TAM, int * resultado)
{
	int encontreMaximo=0;
	int maximo=0;
	int i;
	if(resultado!=NULL)
	{
		for (i=0; i<TAM; i++)
		{
			if (encontreMaximo == 0 || resultado[i]>maximo )
			{
				maximo = resultado[i];
				encontreMaximo=1;
			}
		}
	*resultado=maximo;
	}
}
