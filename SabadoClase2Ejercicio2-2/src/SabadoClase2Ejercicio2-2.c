/*
 ============================================================================
 Name        : SabadoClase2Ejercicio2-2.c
 Author      : Ruben Dario Zevallos Lambrescht
 Version     : Division 1-H
 Ejercicio 2-2:
Realizar un programa que permita el ingreso de 10 números enteros. Determinar
el promedio de los positivos, la cantidad de ceros y del menor de los
negativos la suma de los antecesores.

Nota:
Utilizar la función del punto anterior y desarrollar funciones para resolver
los procesos que están resaltados.

 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void tomar10Valores(float * promedio, int * cantidadCeros, int * sumaAntecesores);
float calcularPromedio(int cantidadElementos, int acumuladorValores);
int evaluarEntrada(int valor);


int main(void) {
	float promedio;
	int cantidadCeros;
	int sumaAntecesores;
	tomar10Valores(&promedio, &cantidadCeros, &sumaAntecesores);
	printf("El promedio de los valores positivos ingresados es %.2f\n", promedio);
	printf("la cantidad de ceros ingresados es %d\n", cantidadCeros);
	printf("la suma de los antecesores negativos ingresados es %d\n", sumaAntecesores);
	return EXIT_SUCCESS;
}

void tomar10Valores(float * promedio, int * cantidadCeros, int * antecesores)
{
	int acumuladorPositivos;
	int contadorPositivos;
	int contadorCeros;
	int numeroMenor;
	int sumaAntecesores;
	acumuladorPositivos=0;
	contadorPositivos=0;
	contadorCeros=0;
	numeroMenor=0;
	sumaAntecesores=0;
	int i;
	int j;
	int valor[10];
	for (i = 0; i<10; i++)
	{
		printf("Ingrese un número:\n");
		fpurge(stdin);
		scanf("%d",&valor[i]);
		if (valor[i]>0)
		{
			acumuladorPositivos+=valor[i];
			contadorPositivos++;
		}
		else
		{
			if(evaluarEntrada(valor[i])==0)
			{
				contadorCeros++;
			}
			else
			{
				if(valor[i]<numeroMenor)
				{
					numeroMenor=valor[i];
				}
			}
		}
	}
	for (j=numeroMenor+1; j<0; j++)
	{
		sumaAntecesores+=j;
	}
	*promedio = calcularPromedio(contadorPositivos, acumuladorPositivos);
	*cantidadCeros = contadorCeros;
	*antecesores = sumaAntecesores;
}

float calcularPromedio(int cantidadElementos, int acumuladorValores)
{
	float promedio;
	float buffer;
	buffer = (float)acumuladorValores / cantidadElementos;
	promedio = buffer;
	return promedio;
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

