/*
 Ejercicio 1-2:
Ingresar 5 n�meros. Determinar cu�l es el m�ximo y el m�nimo e indicar en qu� orden fue ingresado.

 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

int main(void) {
	int i;
	int numero;
	int maximo;
	int minimo;
	int posicionMaximo;
	int posicionMinimo;
	int flagMaximo = 0;
	int flagMinimo = 0;
	setbuf(stdout, NULL);

	for (i=0; i<5; i++)
	{
		//fflush(stdin);
		__fpurge(stdin);
		printf("Ingrese un número:");
		scanf("%d", &numero);
		if (flagMaximo == 0 || maximo < numero)
		{
			flagMaximo = 1;
			maximo = numero;
			posicionMaximo = i + 1;
		}
		if (flagMinimo == 0 || minimo > numero)
				{
					flagMinimo = 1;
					minimo = numero;
					posicionMinimo = i + 1;
				}
	}
	printf("El numero mayor es %d y su posición de ingreso es %d \n", maximo, posicionMaximo);
	printf("El numero menor es %d y su posición de ingreso es %d \n", minimo, posicionMinimo);

	return EXIT_SUCCESS;
}
