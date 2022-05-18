/*
Ejercicio 1-1:
Ingresar n�meros enteros, hasta que el usuario lo decida. Calcular y mostrar:
El promedio de los n�meros positivos.
El promedio de los n�meros negativos.

Zevallos Lambrescht Ruben Dario
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

int main(void) {
	int numero;
	int contadorPos;
	int contadorNeg;
	int acumuladorPos;
	int acumuladorNeg;
	char continuar;
	float promedioPos;
	float promedioNeg;
	contadorPos = 0;
	contadorNeg = 0;
	acumuladorPos = 0;
	acumuladorNeg = 0;
	continuar = 0;
	setbuf(stdout, NULL);
	do
	{
		//fflush(stdin);
		__fpurge(stdin);
		printf("Ingrese un número");
		scanf("%d", &numero);
		if (numero >= 0)
		{
			acumuladorPos = acumuladorPos + numero;
			contadorPos++;
		}
		else
		{
			acumuladorNeg = acumuladorNeg + numero;
			contadorNeg++;
		}
		printf("Desea Continuar? s/n\n");
		__fpurge(stdin);
		//__fflush(stdin);

		scanf("%c", &continuar);
	}while (continuar == 's');
	if (contadorPos > 0)
	{
		promedioPos = (float)acumuladorPos / contadorPos;
		printf("Promedio de numeros positivos: %f\n", promedioPos);
	}
	else
	{
		printf("No hay ingresados numeros positivos\n");
	}

	if (contadorNeg > 0)
	{
		promedioNeg = (float)acumuladorNeg / contadorNeg;
		printf("Promedio de numeros negativos: %f\n", promedioNeg);
	}
	else
	{
		printf("No hay ingresado numeros negativos\n");
	}

	return EXIT_SUCCESS;
}
