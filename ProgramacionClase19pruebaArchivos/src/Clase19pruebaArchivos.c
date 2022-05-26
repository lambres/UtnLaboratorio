/*
 ============================================================================
 Name        : Clase19pruebaArchivos.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Alumno.h"

int main(void) {
	int i;
	FILE* fp;
	Alumno a;
	int listaAlumnos[50];
	//lo abrimos
	fp = fopen("archivo.txt","r");
	if(fp!=NULL)
	{
		//lo usamos
		//MODO TEXTO
		//1 fn para leer y 1 fn para escribir
		//i = 12345678;
		//fprintf(fp,"HOLA\n");
		//fprintf(fp,"HOLA\n");
		//fwrite(&i,sizeof(int),1,fp);
		//a.id=9;
		//a.altura=3.14;
		//sprintf(a.nombre,"Ernesto" );
		//fwrite(&a,sizeof(Alumno),1,fp);

		//fread(&a,sizeof(Alumno),1,fp);
		//printf("id:%d nombre:%s altura:%f\n",a.id,a.nombre,a.altura);

		//lectura binaria con array de punteros
		int fin=1;
		do{
			fin=fread(&a,sizeof(Alumno),1,fp);
			if(fin==1)
			{
				listaAlumnos[i]=Alumno_newParametros(a.nombre,a.altura,a.id);
				//listaalumnos[i]=a;
				i++;
			}
		}
		//while(fin!=0);
		while(feof(fp)==0);


		//lo cerramos
		fclose(fp);
	}
	else
	{
		printf("Error abriendo archivo");
	}
	return EXIT_SUCCESS;
}
