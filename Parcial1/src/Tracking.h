#ifndef TRACKING_H_
#define TRACKING_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"


#define MAX_CHARS_CADENAS 30
#define LIBRE 0
#define EN_VIAJE 1
#define ENTREGADO -1
#define CANCELADO -2


//*** Tracking
typedef struct {
	int idTracking;
	int isEmpty;			//Todods los estados que crean convenientes
	//AGREGAR RELACION
	int cantidad;			//Cantidad a comprar						//Agregado
	int distanciaKM;		//Distancia p/entrega del producto			//Agregado
	long int horaLlegada;	//Calculo de 20seg cada 10km de distancia	//Agregado
	int FKidUsuarioComprador;//Clave foranea de producto/Usuario		//Agregado
	int FKidUsuarioVendedor; //Clave foranea de producto/Usuario		//Agregado
	int FKidProducto;
} Tracking;
//***

/** INICIO CABECERAS DE FUNCION*/
void Track_Inicializar(Tracking array[], int TAM);
int Track_ObtenerIndexLibre(Tracking array[], int TAM);
int Track_BuscarPorID(Tracking array[], int TAM, int ID);
void Track_MostrarUno(Tracking Track);
int Track_MostrarTodos(Tracking array[], int TAM);
int Track_MostrarDadosDeBaja(Tracking array[], int TAM);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int Track_Sort(Tracking array[], int TAM, int criterio);

//ABM
//Tracking Track_CargarDatos(void);
//Tracking Track_ModificarUno(Tracking Track);
//int Track_Alta(Tracking array[], int TAM);
int Track_Baja(Tracking array[], int TAM, int indexUser);
int Track_Modificacion(Tracking array[], int TAM, int indexUser);
int Track_AltaConDatos(Tracking array[], int TAM, Tracking registro);
int Track_ActualizoEstado(Tracking array[], int TAM);

/** FIN CABECERAS DE FUNCION*/
#endif
