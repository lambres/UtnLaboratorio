/*
 * Producto.c
 *
 *  Created on: 26 abr. 2022
 *      Author: Ruben Dario Zevallos Lambescht 1H
 */

#include "Producto.h"
#include <string.h>
#include "utn.h"

//1) Definir un tipo de dato que represente un producto. El producto tiene un nombre, una descripcion y un precio

int inicializarArray(Producto * pArray, long limite, int valor)
{

	int i;
	int retorno = -1;
	if(pArray != NULL && limite > 0)
	{
		for (i=0; i<limite; i++)
		{
			pArray[i].isEmpty=valor;
		}
		retorno = 0;
	}
	return retorno;
}

//3) Realizar una funcion que reciba el array, un indice, y le permita al usuario cargar los datos
//en el item de la posicion especificada por el indice.
int cargarRegistro(Producto * pArray, int nroRegistro)
{

	Producto auxiliarProducto;

	int retorno = -1;

	printf("Nombre Producto:\n");
	scanf("%s", auxiliarProducto.nombre);
	printf("Descripcion:\n");
	scanf("%s", auxiliarProducto.descripcion);

	utn_getNumeroFloat(&auxiliarProducto.precio, "Precio\n", "Valor erroneo\n", 0, 50000, 2);
	pArray[nroRegistro]=auxiliarProducto;
	pArray[nroRegistro].isEmpty=-1;

	return retorno;
}

//4) Realizar una funcion que reciba el array y un indice e imprima los datos del item de la
//posicion especificada por el indice.
int imprimirRegistro(Producto * pArray, int nroRegistro)
{
	printf("Nombre:\t\tDescripcion:\t\tPrecio:\n");
	printf("%s\t\t%s\t\t%.2f\n",pArray[nroRegistro].nombre,pArray[nroRegistro].descripcion,pArray[nroRegistro].precio);
	return 0;
}

//5) Realizar una funcion que me devuelva el indice de un item vacio (sin cargar).
int buscarVacio(Producto * pArray, long limite)
{
	int retorno = -1;
	int i=0;
	for (i = 0; i<limite; i++)
	{
		if(!(pArray[i].isEmpty))
		{
			retorno = i;
			break;
		}
	}
	return retorno;
}
