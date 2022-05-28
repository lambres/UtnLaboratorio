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
	int* pVector;
	pVector=(int*)malloc(sizeof(int)*5);
	for(int i=0;i<5;i++)
	{
		printf("Ingrese un número:\n");
		scanf("%d",(pVector+i));
	}

	for (int i=0;i<5;i++)
	{
		printf("%d\n",*(pVector+i));
	}
	int* pAuxVector;
	pAuxVector = (int*)realloc(pVector, sizeof(int)*10);

	if(pAuxVector!=NULL)
	{
		pVector = pAuxVector;
	}

	for(int i=5;i<10;i++)
	{
		printf("Ingrese un número:\n");
		scanf("%d",(pVector+i));
	}
	printf("Aca van los 10\n");
	for (int i=0;i<10;i++)
	{

		printf("%d\n",*(pVector+i));
	}

	pVector = (int*) realloc(pVector,sizeof(int)*3);
	printf("Aca van los 3\n");
	for (int i=0;i<10;i++)
	{
		printf("%d\n",*(pVector+i));
	}

	return EXIT_SUCCESS;
}

