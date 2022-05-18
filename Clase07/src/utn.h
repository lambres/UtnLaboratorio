/*
 * utn.h
 *
 *  Created on: 8 mar. 2022
 *      Author: dario
 */

#ifndef UTN_H_
#define UTN_H_
char getChar(char mensaje[]);
int obtenerEntero(char mensaje[]);

int utn_getNumeroInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFloat(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos);
int dividir(float* pResultado ,int operador1 ,int operador2);
int utn_getCaracter(char* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos);
int factorial(int n);
unsigned int verifica(void);
char getNumeroAleatorio(int desde, int hasta, int iniciar);
void insertion(int data[],int len);
int esSoloLetras(char str[]);


#endif /* UTN_H_ */
