#ifndef USUARIO_H_
#define USUARIO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#define ADMIN 0
#define USUARIO 1
#define MAX_CHARS_CADENAS 30
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1
#define LEN_CORREO 25
#define LEN_PWD 10
#define LEN_DIRECCION 50

//*** Usuario
typedef struct {
	int idUsuario;
	short int isEmpty; //Todos los estados que crean convenientes
	//AGREGAR RELACION
	short int tipo; //ADMIN - USUARIO 							//Agregado
	char correo[LEN_CORREO]; //Validado 						//Agregado
	char password[LEN_PWD]; //Minimo 4 | Alfanumerico sin signo //Agregado
	char direccion[LEN_DIRECCION]; //Domicilio 					//Agregado
	int codPostal; 												//Agregado
} Usuario;
//***

/** INICIO CABECERAS DE FUNCION*/
void User_Inicializar(Usuario array[], int TAM);
int User_ObtenerIndexLibre(Usuario array[], int TAM);
int User_BuscarPorID(Usuario array[], int TAM, int ID);
int User_BuscarPorEmail(Usuario array[], int TAM, char mail[]);
void User_MostrarUno(Usuario User);
int User_MostrarTodos(Usuario array[], int TAM) ;
int User_MostrarDadosDeBaja(Usuario array[], int TAM);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int User_Sort(Usuario array[], int TAM, int criterio);

//ABM
Usuario User_CargarDatos(void);
Usuario User_ModificarUno(Usuario User);
int User_Alta(Usuario array[], int TAM);
int User_Baja(Usuario array[], int TAM);
int User_Modificacion(Usuario array[], int TAM);
/** FIN CABECERAS DE FUNCION*/
#endif
