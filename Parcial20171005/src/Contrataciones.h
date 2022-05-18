#ifndef Contratacioneserica_H_
#define Contratacioneserica_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define MAX_CHARS_CADENAS 30
#define ACTIVO 0
#define OCUPADO 1
#define BAJA -1


//*** eContrataciones
typedef struct {
	int idContrataciones;
	int isEmpty;

	int FK_idPantalla;

	int cuit;
	int cantidadDias;
	char nombreArchivoVideo[MAX_CHARS_CADENAS];
} eContrataciones;
//***

/** INICIO CABECERAS DE FUNCION*/
void eContrataciones_Inicializar(eContrataciones array[], int TAM);
int eContrataciones_ObtenerIndexLibre(eContrataciones array[], int TAM);
int eContrataciones_BuscarPorID(eContrataciones array[], int TAM, int ID);
void eContrataciones_MostrarUno(eContrataciones Contrataciones);
int eContrataciones_MostrarTodos(eContrataciones array[], int TAM);
int eContrataciones_MostrarDadosDeBaja(eContrataciones array[], int TAM);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int eContrataciones_Sort(eContrataciones array[], int TAM, int criterio);

//ABM
eContrataciones eContrataciones_CargarDatos(void);
eContrataciones eContrataciones_ModificarUno(eContrataciones Contrataciones);
int eContrataciones_Alta(eContrataciones array[], int TAM);
int eContrataciones_Baja(eContrataciones array[], int TAM);
int eContrataciones_Modificacion(eContrataciones array[], int TAM);
/** FIN CABECERAS DE FUNCION*/

#endif
