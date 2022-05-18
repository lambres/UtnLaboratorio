/*
Zevallos Lambrescht Ruben Dario
Ejercicio 1-3:
Realizar el algoritmo que permita ingresar los datos de los alumnos de una divisi�n de la UTN FRA,
los datos solicitados son:
Legajo
Tipo cursada(L: "libre" - P: "presencial" � R: "remota")
Cantidad de materias( mas de cero y menos de 8)
Sexo (F: �femenino� � M: �masculino� , O: �no binario�)
Nota promedio (entre 0 y 10)
Edad (validar)
Se debe informar de existir, o informar que no existe , en el caso que corresponda.
a) El Legajo del mejor promedio femenino.
b) El legajo del m�s joven de los alumnos masculinos entre los que dan libre.
c) El promedio de nota por sexo.
d) La edad y legajo del que cursa m�s materias. (Sin importar su g�nero)

 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);
	int legajo;
	char tipoCursada;
	int cantidadMaterias;
	char sexo;
	int notaPromedio;
	int edad;
	char respuesta;
	//Variable respuestas punto a) El Legajo del mejor promedio femenino.
	int valorMejorPromedio;
	int flagMejorPromedioFemenino;
	flagMejorPromedioFemenino = 0;
	int legajoMejorPromedioFemenino;
	//Variables respuestas punt b) El legajo del mas joven de los alumnos masculinos entre los que dan libre.
	int edadMasJovenMasculino;
	int flaglegajoMasJovenMasculinosLibres;
	flaglegajoMasJovenMasculinosLibres = 0;
	int legajoMasJovenMasculinosLibres;
	//Variables punto c) El promedio de nota por sexo.
	//Masculinos
	float acumuladorMasculinos;
	acumuladorMasculinos = 0;
	float promedioMasculinos;
	promedioMasculinos = 0;
	int cantidadMasculinos;
	cantidadMasculinos = 0;
	//Femeninos
	float acumuladorFemeninos;
	acumuladorFemeninos = 0;
	float promedioFemeninos;
	promedioFemeninos = 0;
	int cantidadFemeninos;
	cantidadFemeninos = 0;
	//No Binarios
	float acumuladorNB;
	acumuladorNB = 0;
	float promedioNB;
	promedioNB = 0;
	int cantidadNB;
	cantidadNB = 0;
	//Variables Punto d) La edad y legajo del que cursa más materias. (Sin importar su g�nero)
	int mayorCantidadMaterias;
	mayorCantidadMaterias = 0;
	int flagMayorCantidadMaterias;
	flagMayorCantidadMaterias = 0;
	int edadMayorCantidadMaterias;
	int legajoMayorCantidadMaterias;
	do
	{
		printf("Ingrese Legajo");
		scanf("%d", &legajo);
		//fflush(stdin);
		__fpurge(stdin);
		printf("Ingrese Tipo cursada(L: \"libre\" - P: \"presencial\" - R: \"remota\")");
		scanf("%c", &tipoCursada);
		printf("Ingrese Cantidad de materias( mas de cero y menos de 8)");
		scanf("%d", &cantidadMaterias);
		//fflush(stdin);
		__fpurge(stdin);
		printf("Ingrese Sexo (F: \"femenino\" , M: \"masculino\" , O: \"no binario\")");
		scanf("%c", &sexo);
		//fflush(stdin);
		__fpurge(stdin);
		printf("Ingrese Nota promedio (entre 0 y 10)");
		scanf("%d", &notaPromedio);
		printf("Ingrese Edad");
		scanf("%d", &edad);
		while ( edad < 0 || edad > 100)
		{
			printf("Error Ingrese Edad entre 0 y 100 años");
			scanf("%d", &edad);
		}

		switch (sexo)
		//c) El promedio de nota por sexo.
		{
		case 'M':
			//b) El legajo del m�s joven de los alumnos masculinos entre los que dan libre.
			if (tipoCursada == 'L')
			{
				if (flaglegajoMasJovenMasculinosLibres == 0 || edadMasJovenMasculino > edad)
				{
					flaglegajoMasJovenMasculinosLibres = 1;
					edadMasJovenMasculino = edad;
					legajoMasJovenMasculinosLibres = legajo;
				}
			}
			acumuladorMasculinos = acumuladorMasculinos + notaPromedio;
			cantidadMasculinos++;
			break;
		case 'F':
			// a) El Legajo del mejor promedio femenino.
			if (flagMejorPromedioFemenino == 0 || valorMejorPromedio < notaPromedio)
			{
				flagMejorPromedioFemenino = 1;
				valorMejorPromedio = notaPromedio;
				legajoMejorPromedioFemenino = legajo;
			}
			acumuladorFemeninos = acumuladorFemeninos + notaPromedio;
			cantidadFemeninos++;
			break;
		case 'O':
			acumuladorNB = acumuladorNB + notaPromedio;
			cantidadNB++;
			break;
		}
		//d) La edad y legajo del que cursa m�s materias. (Sin importar su g�nero)
		if (flagMayorCantidadMaterias == 0 || mayorCantidadMaterias < cantidadMaterias)
		{
			edadMayorCantidadMaterias = edad;
			legajoMayorCantidadMaterias = legajo;
			flagMayorCantidadMaterias = 1;
		}

		//fflush(stdin);
		__fpurge(stdin);
		printf("Desea continuar? s/n:");
		scanf("%c", &respuesta);
	}while (respuesta == 's');
	//Muestro resultados
	if (flagMejorPromedioFemenino == 1)
	{
		printf( "a) El Legajo del mejor promedio femenino es %d \n", legajoMejorPromedioFemenino);
	}
	else
	{
		printf ("a) No hay alumnos sexo femenino\n");
	}
	if (flaglegajoMasJovenMasculinosLibres == 1)
	{
		printf("b) El legajo del mas joven de los alumnos masculinos entre los que dan libre es %d \n", legajoMasJovenMasculinosLibres);
	}
	else
	{
		printf("b) no hay alumnos libres masculinos cursando\n");
	}

	if (acumuladorMasculinos > 0)
	{
		promedioMasculinos = (float)acumuladorMasculinos / cantidadMasculinos;
		printf("c) El promedio de nota masculinos es %.2f \n", promedioMasculinos);
	}
	else
	{
		printf("c) no hay alumnos masculinos\n");
	}

	if (acumuladorFemeninos > 0)
	{
		promedioFemeninos = (float)acumuladorFemeninos / cantidadFemeninos;
		printf("c) El promedio de nota femeninos es %.2f \n", promedioFemeninos);
	}
	else
	{
		printf("c) no hay alumnos femeninos\n");
	}

	if (acumuladorNB > 0)
	{
		promedioNB = (float)acumuladorNB / cantidadNB;
		printf("c) El promedio de nota No Binarios es %.2f \n", promedioNB);
	}
	else
	{
		printf("c) no hay alumnos No Binarios\n");
	}

	printf("d) La edad %d y legajo %d del que cursa mas materias. (Sin importar su genero) \n", edadMayorCantidadMaterias, legajoMayorCantidadMaterias);

	return EXIT_SUCCESS;
}
