/*
 * Alumno.h
 *
 *  Created on: 22 may. 2022
 *      Author: dario
 */

#ifndef ALUMNO_H_
#define ALUMNO_H_
#include <stdio.h>
#include <string.h>
#define LEN_NOMBRE 50
typedef struct
{
	char nombre[LEN_NOMBRE];
	int id;
	float altura;
}Alumno;
Alumno* Alumno_new(void);
Alumno* Alumno_newParametros(char* nombre, float altura, int id);
void Alumno_delete(Alumno* this);
int Alumno_deleteIndexInArray(Alumno* arrayPunteros[],int limite, int indice);
int Alumno_initArray(Alumno* arrayPunteros[],int limite);
int Alumno_buscarLibreArray(Alumno* arrayPunteros[],int limite);
int Alumno_imprimirArray(Alumno* arrayPunteros[],int limite);
int Alumno_buscarPorIdArray(Alumno* arrayPunteros[],int limite, int id);
int Alumno_agregarAlumnoArray(Alumno* arrayPunteros[],int limite, char* nombre, float altura, int id);
int Alumno_borrarporIdArray(Alumno* arrayPunteros[],int limite,int id);
#endif /* ALUMNO_H_ */
