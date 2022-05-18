#ifndef EPOSTEO_H_
#define EPOSTEO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS_CADENAS 30
#define ACTIVO 0
#define OCUPADO 1
#define BAJA -1

//*** ePosteo
typedef struct {
	int idPosteo;
	int isEmpty;
	char mensaje;
	int FK_idUsuario;
} ePosteo;
//***

/** INICIO CABECERAS DE FUNCION*/
void ePosteo_Inicializar(ePosteo array[], int TAM);
int ePosteo_ObtenerIndexLibre(ePosteo array[], int TAM);
int ePosteo_BuscarPorID(ePosteo array[], int TAM, int ID);
void ePosteo_MostrarUno(ePosteo Posteo);
int ePosteo_MostrarTodos(ePosteo array[], int TAM);
int ePosteo_MostrarDadosDeBaja(ePosteo array[], int TAM);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int ePosteo_Sort(ePosteo array[], int TAM, int criterio);

//ABM
ePosteo ePosteo_CargarDatos(void);
ePosteo ePosteo_ModificarUno(ePosteo Posteo);
int ePosteo_Alta(ePosteo array[], int TAM);
int ePosteo_Baja(ePosteo array[], int TAM);
int ePosteo_Modificacion(ePosteo array[], int TAM);
int hcPosteos(ePosteo array[], int TAM);

/** FIN CABECERAS DE FUNCION*/
#endif
