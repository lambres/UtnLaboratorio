/*
 * Track_Prod.c
 *
 *  Created on: 15 may. 2022
 *      Author: dario
 */

#include "Track_Prod.h"
/// @fn void TU_MostrarUno(Tracking, char*)
/// @brief Funcion encargada de mostrar dato al ser llamada x funcion de listar
///
/// @param Track Puntero a estructura Tracking
/// @param nombre variable conteniendo el nombre del producto
void TU_MostrarUno(Tracking Track, char * nombre)
{
	char estado[10];
	//PRINTF DE UN SOLO Gen
	printf("|%-10d", Track.idTracking);
	switch(Track.isEmpty)
	{
	case -2:
		strncpy(estado,"CANCELADO",10);
		break;
	case -1:
		strncpy(estado,"ENTREGADO",10);
		break;
	case 0:
		strncpy(estado,"LIBRE",10);
		break;
	case 1:
		strncpy(estado,"EN VIAJE",10);
		break;
	}
	printf("|%-11s", estado);
	printf("|%-25s", nombre);
	printf("|%-10d", Track.cantidad);
	printf("|%-10d", Track.distanciaKM);
	printf("|%-10d\n", Track.FKidUsuarioVendedor);
}

/// @fn int TU_MostrarTodos(Tracking[], int, Producto[], int, int)
/// @brief Funcion que lista los encabezados y llama a a la funcion para imprimir
/// los registgros segun criterios
///
/// @param tArray Array de estructura Tracking donde recibo los datos a listar
/// @param tTAM Tamaño del array Tracking
/// @param pArray Array de estructura Producto donde recibo los datos a listar
/// @param pTAM Tamaño del array Producto
/// @param indexUser indice del usuario logueado que llama la funcion
/// @return retorna 1 si encontro datos a listar, sino 0
int TU_MostrarTodos(Tracking tArray[] ,int tTAM ,Producto pArray[] ,int pTAM ,int indexUser)
{
	int i;
	int rtn = 0;
	int cantidad = 0;
	int indexProducto;

	//CABECERA
	puts("\n\t> ESTADO DE COMPRAS");
	printf("|%-10s", "IDTRACKING"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)
	printf("|%-11s", "ESTADO");
	printf("|%-25s", "PRODUCTO");
	printf("|%-10s", "CANTIDAD");
	printf("|%-10s", "DISTANCIA");
	printf("|%-10s\n", "VENDEDOR");
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (tArray != NULL && tTAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < tTAM; i++) {
			//PREGUNTO POR SU ESTADO "DISTINTO DE LIBRE"
			if (tArray[i].isEmpty != LIBRE && tArray[i].FKidUsuarioComprador==indexUser) {
				//MUESTRO UN SOLO Gen
				indexProducto=Prod_BuscarPorID(pArray, pTAM, tArray[i].FKidProducto);
				TU_MostrarUno(tArray[i],pArray[indexProducto].nombreProducto);
				//CONTADOR DE Gen
				cantidad++;
			}
		}
	}
	//SI CANTIDAD == 0 - NO HUBO Gen PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		rtn = 1;
	}
	return rtn;
}

/// @fn int TU_MostrarEnViaje(Tracking tArray[] ,int tTAM ,Producto pArray[] ,int pTAM ,int indexUser)
/// @brief Funcion que lista los encabezados y llama a a la funcion para imprimir
/// los registgros segun criterios  LISTADO DE TRACKING
///
/// @param tArray Array de estructura Tracking donde recibo los datos a listar
/// @param tTAM Tamaño del array Tracking
/// @param pArray Array de estructura Producto donde recibo los datos a listar
/// @param pTAM Tamaño del array Producto
/// @param indexUser indice del usuario logueado que llama la funcion
/// @return retorna 1 si encontro datos a listar, sino 0
int TU_MostrarEnViaje(Tracking tArray[] ,int tTAM ,Producto pArray[] ,int pTAM ,int indexUser)
{
	int i;
	int rtn = 0;
	int cantidad = 0;
	int indexProducto;

	//CABECERA
	puts("\n\t> LISTADO TRACKING");
	printf("|%-10s", "IDTRACKING"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)
	printf("|%-11s", "ESTADO");
	printf("|%-25s", "PRODUCTO");
	printf("|%-10s", "CANTIDAD");
	printf("|%-10s", "DISTANCIA");
	printf("|%-10s\n", "VENDEDOR");
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (tArray != NULL && tTAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < tTAM; i++) {
			//PREGUNTO POR SU ESTADO "DISTINTO DE LIBRE"
			if (tArray[i].isEmpty == EN_VIAJE && tArray[i].FKidUsuarioComprador==indexUser) {
				//MUESTRO UN SOLO Gen
				indexProducto=Prod_BuscarPorID(pArray, pTAM, tArray[i].FKidProducto);
				TU_MostrarUno(tArray[i],pArray[indexProducto].nombreProducto);
				//CONTADOR DE Gen
				cantidad++;
			}
		}
	}
	//SI CANTIDAD == 0 - NO HUBO Gen PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		rtn = 1;
	}
	return rtn;
}

/// @fn int TU_MostrarVentasFinalizadas(Tracking tArray[] ,int tTAM ,Producto pArray[] ,int pTAM ,int indexUser)
/// @brief Funcion que lista los encabezados y llama a a la funcion para imprimir
/// los registgros segun criterios  las Ventas Finalizadas
///
/// @param tArray Array de estructura Tracking donde recibo los datos a listar
/// @param tTAM Tamaño del array Tracking
/// @param pArray Array de estructura Producto donde recibo los datos a listar
/// @param pTAM Tamaño del array Producto
/// @param indexUser indice del usuario logueado que llama la funcion
/// @return retorna 1 si encontro datos a listar, sino 0
int TU_MostrarVentasFinalizadas(Tracking tArray[] ,int tTAM ,Producto pArray[] ,int pTAM ,int indexUser)
{
	int i;
	int rtn = 0;
	int cantidad = 0;
	int indexProducto;

	//CABECERA
	puts("\n\t> LISTADO VENTAS FINALIZADAS");
	printf("|%-10s", "IDTRACKING"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)
	printf("|%-11s", "ESTADO");
	printf("|%-25s", "PRODUCTO");
	printf("|%-10s", "CANTIDAD");
	printf("|%-10s", "DISTANCIA");
	printf("|%-10s\n", "VENDEDOR");
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (tArray != NULL && tTAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < tTAM; i++) {
			//PREGUNTO POR SU ESTADO "DISTINTO DE LIBRE"
			if ((tArray[i].isEmpty == ENTREGADO || tArray[i].isEmpty == CANCELADO)  && tArray[i].FKidUsuarioComprador==indexUser) {
				//MUESTRO UN SOLO Gen
				indexProducto=Prod_BuscarPorID(pArray, pTAM, tArray[i].FKidProducto);
				TU_MostrarUno(tArray[i],pArray[indexProducto].nombreProducto);
				//CONTADOR DE Gen
				cantidad++;
			}
		}
	}
	//SI CANTIDAD == 0 - NO HUBO Gen PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		rtn = 1;
	}
	else
	{
		puts("NO HAY VENTAS FINALIZADAS");
	}
	return rtn;
}

