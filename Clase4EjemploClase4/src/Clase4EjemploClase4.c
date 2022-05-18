/*
 ============================================================================
 Name        : Clase4EjemploClase4.c
 Author      : Ruben Dario Zevallos Lambrescht
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
*	Programa: Ejemplo Clase4
*	Onjetivo:
*	A- 	Desarrollar una biblioteca "utn.h" que posea funciones para
*		pedirle al usuario el ingreso de datos
*			-	getInt()
*			-	getFloat()
*			-	getChar()
*
*	B-	Diseñar un programa para juagar a adivinar un numero entre 0 y 100.
*		El juego tiene que dar pistas de si el numero introducido por el
*		jugador esta por encima o por debajo. El juego termina cuando se
*		adivina el numero o se decide terminar de jugar ingresando un numero
*		negativo. Permitir jugar tantas veces como lo desee el juagador y al
*		salir mostrar su mejor puntuacion. Utilizar la biblioteca del punto 1.

 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void) {
	int numeroOculto;
	int numeroIngresado;
	char teclaIngresada;
	int jugar;

	teclaIngresada='s';
	while (teclaIngresada == 's')
	{
		numeroOculto = getNumeroAleatorio(1, 100, 1);
		jugar = 1;
		while(jugar == 1)
		{
			numeroIngresado = obtenerEntero("Ingrese un numero (0 - 99) \n");
			if(numeroIngresado < 0)
			{
				jugar = 0;
			}
			else
			{
				if(numeroIngresado == numeroOculto)
				{
					printf("Felicitaciones Ganaste!!!\n");
					jugar = 0;
				}
				else
				{
					if(numeroIngresado > numeroOculto)
					{
						printf("El numero ingresado es mayor!!! \n");
					}
					else
					{
						printf("El numero ingresado es menor!!! \n");
					}
				}
			}
			teclaIngresada = getChar("Desea Jugar nuevamente? (s/n) \n");
		}
	}

	return EXIT_SUCCESS;
}
