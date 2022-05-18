#ifndef EHASHTAG_H_
#define EHASHTAG_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS_CADENAS 30
#define ACTIVO 0
#define OCUPADO 1
#define BAJA -1

//*** eHashtag
typedef struct {
	int idHashtag;
	int isEmpty;
	char referencia;
	int FK_idPosteo;
} eHashtag;
//***

/** INICIO CABECERAS DE FUNCION*/
void eHashtag_Inicializar(eHashtag array[], int TAM);
int eHashtag_ObtenerIndexLibre(eHashtag array[], int TAM);
int eHashtag_BuscarPorID(eHashtag array[], int TAM, int ID);
void eHashtag_MostrarUno(eHashtag Hashtag);
int eHashtag_MostrarTodos(eHashtag array[], int TAM);
int eHashtag_MostrarDadosDeBaja(eHashtag array[], int TAM);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int eHashtag_Sort(eHashtag array[], int TAM, int criterio);

//ABM
eHashtag eHashtag_CargarDatos(void);
eHashtag eHashtag_ModificarUno(eHashtag Hashtag);
int eHashtag_Alta(eHashtag array[], int TAM);
int eHashtag_Baja(eHashtag array[], int TAM);
int eHashtag_Modificacion(eHashtag array[], int TAM);
int hcHashtag(eHashtag array[], int TAM);
/** FIN CABECERAS DE FUNCION*/
#endif
