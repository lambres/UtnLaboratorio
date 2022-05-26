/*
 ============================================================================
 Name        : Ruben Dario Zevallos lambrescht Division H
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description :
Ejercicio 8.4
Escriba una función que reciba dos números enteros y los devuelva ordenados.
Es decir que en el primer parámetro debe devolver el menor valor y en el 2do. el mayor.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void ordenarDos(int * num1, int * num2);
int main(void) {
	int numero1=50;
	int numero2=30;
	ordenarDos(&numero1,&numero2);
	printf("Los numeros ordenados son %d , %d.\n", numero1,numero2);
	return EXIT_SUCCESS;
}

void ordenarDos(int * num1, int * num2)
{
	int a,b,aux;
	a=*num1;
	b=*num2;
	if (a>b)
	{
		aux=a;
		*num1=b;
		*num2=aux;
	}
}
