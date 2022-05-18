#ifndef PRODUCTO_H_
#define PRODUCTO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#define TAM_PRODUCTO 1000

#define MAX_CHARS_CADENAS 30
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1
#define LEN_PRODUCTNAME 25
#define CAT_VEHICULOS 1
#define CAT_TECNOLOGIA 2
#define CAT_ELECTRODOMESTICOS 3
#define CAT_HERRAMIENTAS 4
#define CAT_CONSTRUCCION 5
#define LEN_DESCCAT 20


//*** eGen
typedef struct {
	int idProducto;
	int isEmpty;				//Todos los estados que crean convenientes
	//AGREGAR RELACION
	char nombreProducto[LEN_PRODUCTNAME];
	float precio;
	short int categoria;		//Ej: Moda/Construccion/Tecnologia/etc
	int stock;					//Cantidad de productos a vender
	int FKidUsuario;
} Producto;
//***

/** INICIO CABECERAS DE FUNCION*/
void Prod_Inicializar(Producto array[], int TAM);
int Prod_ObtenerIndexLibre(Producto array[], int TAM);
int Prod_ObtenerIndexOcupado(Producto array[], int TAM);
int Prod_BuscarPorID(Producto array[], int TAM, int ID);
void Prod_MostrarUno(Producto Prod);
int Prod_MostrarTodos(Producto array[], int TAM);
int Prod_MostrarDadosDeBaja(Producto array[], int TAM);
int Prod_MostrarTodosConSaldo(Producto array[], int TAM, int idUser);
int Prod_MostrarRepoStock(Producto array[], int TAM, int idUser);
int Prod_MostrarFiltroNombre(Producto array[], int TAM, char nombreProd[], int largoNombre);
int Prod_SortName(Producto array[], int TAM, int criterio);
/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int Prod_Sort(Producto array[], int TAM, int criterio);

//ABM
Producto Prod_CargarDatos(void);
Producto Prod_ModificarUno(Producto Prod);
int Prod_Alta(Producto array[], int TAM, int idusuario);
int Prod_Baja(Producto array[], int TAM);
int Prod_Modificacion(Producto array[], int TAM, int idUser);
/** FIN CABECERAS DE FUNCION*/
#endif
