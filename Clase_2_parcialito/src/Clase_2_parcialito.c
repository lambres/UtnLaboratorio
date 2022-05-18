/*
 ============================================================================
 Name        : Clase_2_parcialito.c
 Author      : Ruben Zevallos
 Version     : Solicitar al usuario que ingrese una serie de numeros la cual finaliza al ingresar 999
 (el 999 no debe ser tenido en cuenta para dicho calculo). Una vez
 finalizado el ingreso de numeros el programa debera mostrar el promedio de
 dichos numeros en pantalla
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#define TRUE 1
#define FALSE 0
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int acumulador=0;//a
	int numero;//b
	int contador=0;//c
	float promedio;//d

	while(1)//e
	{
		printf("Ingrese un numero:");
		scanf("%d", &numero);//f
		if(numero != 999)//g
		{
			acumulador = acumulador + numero;//h
			contador++;
		}
		else
		{
			break;//i
		}
	}
	promedio = (float)acumulador/contador;//j
	printf("\n El promedio es: %f", promedio);

	return EXIT_SUCCESS;
}
