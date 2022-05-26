/*
 * Alumno.c
 *
 *  Created on: 22 may. 2022
 *      Author: dario
 */


#include "Alumno.h"

Alumno* Alumno_new(void)
{
	return (Alumno*) malloc(sizeof(Alumno));
}

Alumno* Alumno_newParametros(char* nombre, float altura, int id)
{
	Alumno* punteroAlumno = NULL;
	punteroAlumno = Alumno_new();
	if (punteroAlumno != NULL)
	{
		strncpy(punteroAlumno->nombre,nombre,LEN_NOMBRE);
		punteroAlumno->altura=altura;
		punteroAlumno->id=id;
	}
	return punteroAlumno;
}
/// @fn int Alumno_deleteIndexInArray(Alumno*[], int)
/// @brief Funcion que borra un indice array de punteros
///
/// @pre
/// @post
/// @param arrayPunteros puntero al array a inicializar
/// @param limite tamño del puntero
/// @return devuleve 0 si EXITO y -1 si hay un ERROR
int Alumno_deleteIndexInArray(Alumno* arrayPunteros[],int limite, int indice)
{
	int retorno = -1;
	if(arrayPunteros != NULL && indice >= 0 && arrayPunteros[indice] != NULL)
	{
		retorno = 0;
		Alumno_delete(arrayPunteros[indice]);
		arrayPunteros[indice] = NULL;
	}
	return retorno;
}

void Alumno_delete(Alumno* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

/// @fn int Alumno_initArray(Alumno*[], int)
/// @brief Funcion que inicializa un array de punteros
///
/// @pre
/// @post
/// @param arrayPunteros puntero al array a inicializar
/// @param limite tamño del puntero
/// @return devuleve 0 si EXITO y -1 si hay un ERROR
int Alumno_initArray(Alumno* arrayPunteros[],int limite)
{
	int retorno = -1;
	int i;
	if(arrayPunteros != NULL && limite >= 0 )
	{
		retorno = 0;
		for(i=0;i<limite;i++)
		{
			arrayPunteros[i]=NULL;
		}
	}
	return retorno;
}

/// @fn int Alumno_buscarLibreArray(Alumno*[], int)
/// @brief Funcion que busca una posicion libre en un array de punteros
///
/// @pre
/// @post
/// @param arrayPunteros puntero al array a inicializar
/// @param limite tamño del puntero
/// @return devuleve Indice del lugar libre encontrado si EXITO y -1 si hay un ERROR de
/// parametros recibidos y -2 si no encontró lugar LIBRE
int Alumno_buscarLibreArray(Alumno* arrayPunteros[],int limite)
{
	int retorno = -1;
	int i;
	if(arrayPunteros != NULL && limite > 0 )
	{
		retorno = -2;
		for(i=0;i<limite;i++)
		{
			if (arrayPunteros[i]==NULL)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/// @fn int Alumno_buscarLibreArray(Alumno*[], int)
/// @brief Funcion que busca una posicion libre en un array de punteros
///
/// @pre
/// @post
/// @param arrayPunteros puntero al array a inicializar
/// @param limite tamño del puntero
/// @return devuleve Indice del lugar libre encontrado si EXITO y -1 si hay un ERROR de
/// parametros recibidos y -2 si no encontró lugar LIBRE
int Alumno_imprimirArray(Alumno* arrayPunteros[],int limite)
{
	int retorno = -1;
	int i;
	if(arrayPunteros != NULL && limite > 0 )
	{
		printf("\n------LISTADO Alumno--------\n");
		for(i=0;i<limite;i++)
		{
			if (arrayPunteros[i] != NULL)
			{
				printf("Nombre %s - ID %d - Altura %.2f\n",arrayPunteros[i]->nombre, arrayPunteros[i]->id, arrayPunteros[i]->altura);
			}
			retorno = 0;
		}
	}
	return retorno;
}
/// @fn int Alumno_buscarPorIdArray(Alumno*[], int)
/// @brief Funcion que busca una posicion libre en un array de punteros
///
/// @pre
/// @post
/// @param arrayPunteros puntero al array a inicializar
/// @param limite tamño del puntero
/// @return devuleve Indice del lugar libre encontrado si EXITO y -1 si hay un ERROR de
/// parametros recibidos y -2 si no encontró lugar LIBRE
int Alumno_buscarPorIdArray(Alumno* arrayPunteros[],int limite, int id)
{
	int retorno = -1;
	int i;
	if(arrayPunteros != NULL && limite > 0 && id >= 0)
	{
		retorno = -2;
		for(i=0;i<limite;i++)
		{
			if (arrayPunteros[i] != NULL && arrayPunteros[i]->id == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/// @fn int Alumno_agregarAlumnoArray(Alumno*[], int)
/// @brief Funcion que busca una posicion libre en un array de punteros
/// luego carga los datos recibido como paramateros en un nuevo dato alumno
///
/// @pre
/// @post
/// @param arrayPunteros puntero al array a inicializar
/// @param limite tamño del puntero
/// @param nombre Datos de la estructura Alumno
/// @param altura IDEM
/// @param id IDEM
/// @return devuleve Indice del lugar donde se agrego si EXITO y -1 si hay un ERROR de

int Alumno_agregarAlumnoArray(Alumno* arrayPunteros[],int limite, char* nombre, float altura, int id)
{
	int retorno = -1;
	int indiceLibre;
	if(arrayPunteros != NULL && limite > 0 && nombre != NULL && id >= 0)
	{
		indiceLibre=Alumno_buscarLibreArray(arrayPunteros, limite);
		if(indiceLibre >= 0)
		{
			arrayPunteros[indiceLibre]=Alumno_newParametros(nombre, altura, id);
			retorno = indiceLibre;
		}
	}
	return retorno;
}


int Alumno_borrarporIdArray(Alumno* arrayPunteros[],int limite,int id)
{
	int retorno = -1;
	int indiceBorrar;
	if(arrayPunteros != NULL && limite > 0 && id >= 0)
	{
		indiceBorrar=Alumno_buscarPorIdArray(arrayPunteros, limite, id);
		if(indiceBorrar >= 0)
		{
			if(!Alumno_deleteIndexInArray(arrayPunteros, limite, indiceBorrar))
			{
				retorno = 0;
			}
		}
	}

	return retorno;
}
