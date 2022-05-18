/*
 * utn.h
 *
 *  Created on: 8 mar. 2022
 *      Author: dario
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#ifndef UTN_H_
#define UTN_H_

int obtenerEntero(char mensaje[]);
int utn_getNumeroInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFloat(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos);
int utn_getNumeroAleatorio(int desde, int hasta, int iniciar);
int utn_getCaracter(char* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos);
int dividir(float* pResultado ,int operador1 ,int operador2);
int factorial(int n);
int esSoloLetras(char str[]);
int getStringLetras(char * mensaje, char * input);
int getStringNumeros(char * mensaje, char * input);
char getChar(char mensaje[]);
void getString(char * mensaje, char * input);
void insertion(int data[],int len);
unsigned int verifica(void);

#endif /* UTN_H_ */
