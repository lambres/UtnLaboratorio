/*
 ============================================================================
 Name        : ProgramacionClase18.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Alumno.h"
#include "utn.h"

#define QTY_ALUMNOS 100

int main(void) {
	Alumno* arrayPunterosAlumno[QTY_ALUMNOS];

	if(!Alumno_initArray(arrayPunterosAlumno,QTY_ALUMNOS))
	{
		printf("InitOK...\n");
	}

	if(Alumno_agregarAlumnoArray(arrayPunterosAlumno, QTY_ALUMNOS, "Juan", 1.77, 111)>=0)
	{
		printf("Alta OK\n");
	}
	if(Alumno_agregarAlumnoArray(arrayPunterosAlumno, QTY_ALUMNOS, "Ana", 1.65, 112)>=0)
	{
		printf("Alta OK\n");
	}

	Alumno_imprimirArray(arrayPunterosAlumno, QTY_ALUMNOS);

	if(!Alumno_borrarporIdArray(arrayPunterosAlumno, QTY_ALUMNOS, 111))
	{
		printf("\nBorrado ok.\n");
	}

	Alumno_imprimirArray(arrayPunterosAlumno, QTY_ALUMNOS);

	return EXIT_SUCCESS;
}
