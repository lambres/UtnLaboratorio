#ifndef EUSUARIO_H_
#define EUSUARIO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS_CADENAS 30
#define ACTIVO 0
#define OCUPADO 1
#define BAJA -1

//*** eUsuario
typedef struct {
	int idUsuario;
	int isEmpty;
	char userName;
	char password;
} eUsuario;
//***

/** INICIO CABECERAS DE FUNCION*/
void eUsuario_Inicializar(eUsuario array[], int TAM);
int eUsuario_ObtenerIndexLibre(eUsuario array[], int TAM);
int eUsuario_BuscarPorID(eUsuario array[], int TAM, int ID);
void eUsuario_MostrarUno(eUsuario Usuario);
int eUsuario_MostrarTodos(eUsuario array[], int TAM);
int eUsuario_MostrarDadosDeBaja(eUsuario array[], int TAM);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int eUsuario_Sort(eUsuario array[], int TAM, int criterio);

//ABM
eUsuario eUsuario_CargarDatos(void);
eUsuario eUsuario_ModificarUno(eUsuario Usuario);
int eUsuario_Alta(eUsuario array[], int TAM);
int eUsuario_Baja(eUsuario array[], int TAM);
int eUsuario_Modificacion(eUsuario array[], int TAM);
int hcUsuarios(eUsuario array[], int TAM);
/** FIN CABECERAS DE FUNCION*/
#endif
