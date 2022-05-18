/*
 ============================================================================
 Name        : Clase9.c
 Author      : Ruben Dario Zevallos Lambescht 1H
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
//2) Definir un array de 200 productos, indicar de alguna manera que la info de cada item no esta cargada.
//3) Realizar una funcion que reciba el array, un indice, y le permita al usuario cargar los datos
//en el item de la posicion especificada por el indice.
//4) Realizar una funcion que reciba el array y un indice e imprima los datos del item de la
//posicion especificada por el indice.
//5) Realizar una funcion que me devuelva el indice de un item vacio (sin cargar).

6) Agregar al tipo de dato el campo ID que represente un identificador unico. Modificar el codigo
anterior para que el ID se genere automaticamente. Se debera cargar el ID automaticamente
al cargar un producto, y se debera imprimir al imprimir la lista.

7) Realizar una funcion que reciba el array y un ID, y me devuelva el indice del item con dicho ID.

8) Realizar una funcion que reciba el array, un indice, y le permita al usuario
 modificar los campos nombre y precio del item del array en la posicion especificada por el indice.
 */
#define CANTIDAD_PRODUCTOS 200
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Producto.h"
#include "utn.h"

int main(void) {
	Producto arrayProductos[CANTIDAD_PRODUCTOS];
	inicializarArray(arrayProductos , CANTIDAD_PRODUCTOS, 0);
	int auxPosicion;

	utn_getNumeroInt(&auxPosicion, "Posicion:\n", "Posicion fuera de rango\n", 0, 199, 2);
	cargarRegistro(arrayProductos, auxPosicion);

	utn_getNumeroInt(&auxPosicion, "Ingrese registro a mostrar:\n", "Error entre 0 y 199",0, 199, 2);
	imprimirRegistro(arrayProductos, auxPosicion);

	printf("El primer registro vacio es: %d\n", buscarVacio(arrayProductos, CANTIDAD_PRODUCTOS));


	return EXIT_SUCCESS;
}
