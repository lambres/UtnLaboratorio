/*
 * Inputs.h
 *
 *  Created on: 5 abr. 2022
 *      Author: dario
 */

#ifndef INPUTS_H_
#define INPUTS_H_


int getInt(char mensaje[], int reintentos, int minimo, int maximo, char mensajeError[], int* pNumeroIngresado);
int getFloat(char mensaje[], int reintentos, float minimo, float maximo, char mensajeError[], float* pNumeroIngresado);


#endif /* INPUTS_H_ */
