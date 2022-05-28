/*
 ============================================================================
 Name        : SabadoClase9.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	int legajo;
	char nombre[50];
	float nota;
}eAlumno;

eAlumno* cargarAlumno();

int main(void) {
	eAlumno* eAlumno;
	eAlumno = cargarAlumno();
	printf("%d %s %f\n",eAlumno->legajo, eAlumno->nombre, eAlumno->nota);
	printf("%d %s %f\n",eAlumno->legajo, eAlumno->nombre, eAlumno->nota);
	printf("%d %s %f\n",eAlumno->legajo, eAlumno->nombre, eAlumno->nota);
	free(eAlumno);
	printf("%p\n",eAlumno);
	printf("%d %s %f\n",eAlumno->legajo, eAlumno->nombre, eAlumno->nota);
	printf("%d %s %f\n",eAlumno->legajo, eAlumno->nombre, eAlumno->nota);
	return EXIT_SUCCESS;
}

eAlumno* cargarAlumno()
{
	//eAlumno unAlumno = {1000, "Federico", 8.5};
	eAlumno* pAlumno;

	//pAlumno = &unAlumno;
	pAlumno=(eAlumno*)malloc(sizeof(eAlumno));
	if(pAlumno!=NULL)
	{
		pAlumno->legajo=1000;
		strncpy(pAlumno->nombre,"Federico",50);
		pAlumno->nota=8.5;
	}
	return pAlumno;

}
