/*
 * utn.h
 *
 *  Created on: 8 mar. 2022
 *      Author: dario
 */

#ifndef UTN_H_
#define UTN_H_
static int myGets (char * cadena, int longitud);
static int getInt (int * pResultado);
static int getFloat (float * pResultado);
char getChar(char mensaje[])
static int esNumerica (char * cadena);
int utn_getNumeroInt(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int dividir(float* pResultado ,int operador1 ,int operador2);
int utn_getCaracter(char* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos);
int factorial(int n);
unsigned int verifica(void);
char getNumeroAleatorio(int desde, int hasta, int iniciar);


int utn_getNumeroFlotante(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos);




#endif /* UTN_H_ */
