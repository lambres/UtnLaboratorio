/*
 * Producto.h
 *
 *  Created on: 26 abr. 2022
 *      Author: Ruben Dario Zevallos Lambescht 1H
 */
#include <stdio.h>
#include <stdlib.h>

#ifndef PRODUCTO_H_
#define PRODUCTO_H_

typedef struct
{
	int id;
	char nombre[20];
	char descripcion[50];
	float precio;
	int isEmpty;
}Producto;

int inicializarArray(Producto * pArray, long limite, int valor);
int cargarRegistro(Producto * pArray, int nroRegistro);
int imprimirRegistro(Producto * pArray, int nroRegistro);
int buscarVacio(Producto * pArray, long limite);


#endif /* PRODUCTO_H_ */
