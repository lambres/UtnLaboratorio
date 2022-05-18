/*
 Biblioteca funciones
 */
//setbuf(stdout,NULL); para compilador windows
#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
static int esNumerica(char* cadena, int limite);
static int esNumeroDecimal(char* cadena, int limite);
static int getInt(int* pResultado);
static int myGets (char * cadena, int longitud);
static int getFloat (float * pResultado);


/**
* \	brief	Lee ​ de​ ​ stdin​ ​ hasta​ ​ que​ ​ encuentra​ ​ un​ '\n' o ​ hasta​ ​ que​ ​ haya​ ​ copiado​ ​ en​ ​ cadena
* \			un​ máximo​ ​ de​ '​ longitud​ - 1' ​ caracteres​ .
* \​ param​	pResultado ​ Puntero​ ​ al​ ​ espacio​ ​ de​ ​ memoria​ ​ donde​ ​ se​ ​ copiara​ ​ la​ ​ cadena​ ​ obtenida
* \​ param​	longitud​ Define el ​ tamaño​ ​ de​ ​ cadena
* \ return	Retorna​ 0 (EXITO) ​ si​ ​ se​ ​ obtiene​ ​ una​ ​ cadena​ y -1 (ERROR) ​ si​ no
*/


static int myGets(char* cadena, int longitud)
//int myGets(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[4096];//arreglar en clases posteriores

	if(cadena != NULL && longitud >0)
	{
		fpurge(stdin);
		//__fpurge(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno = 0;
			}
		}
	}
	return retorno;
}

/**
* \brief	Obtiene un numero entero
* \​param​ 	pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
* \return ​	Retorna​ 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
*/

static int getInt(int * pResultado)
{
	int retorno=-1;
	char buffer[4096];

	if(	pResultado != NULL &&
		!myGets(buffer, sizeof(buffer)) &&
		esNumerica(buffer,sizeof(buffer)))
		{
			*pResultado = atoi(buffer);
			retorno = 0;
		}
	return retorno;
}


/**
* \brief ​Verifica​ ​si​ ​la​ ​cadena​ ​ingresada​ ​es​ ​numerica flotante
* \​param​ pResultado ​Puntero​ ​al​ ​espacio​ ​de​ ​memoria​ ​donde​ ​se​ ​dejara​ el ​resultado​ ​de​ ​la​ ​funcion
* \return ​Retorna​ 0 (EXITO) ​si​ ​se​ ​obtiene​ ​un​ ​numero​ ​flotante y -1 (ERROR) ​si​ no
**/

static int getFloat(float* pResultado)
{
	int retorno=-1;
	char buffer[64];

	if(pResultado != NULL)
	{
		if(myGets(buffer,sizeof(buffer))==0 && esNumeroDecimal(buffer,sizeof(buffer)))
		{
			*pResultado = atof(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

/**
* \brief ​Solicita un char al usuario, mostrando el mensaje pasado como argumento
* \​param​ mensaje[] ​Mensaje solicitando al usuario el caracter
* \return ​Retorna​ el caracter (char) ingresado
**/
char getChar(char mensaje[])
{
	char auxiliar;
	printf("%s", mensaje);
	fpurge(stdin);
	//__fpurge(stdin); //__fpurge(stdin) linux fflush(stdin) Win
	scanf("%c", &auxiliar);
	return auxiliar;
}

/**
* \brief ​	Verifica​ ​si​ ​la​ ​cadena​ ​ingresada​ ​es​ ​numerica
* \​param​ ​	cadena​ ​Cadena​ ​de​ ​caracteres​ a ​ser​ ​analizada
* \return ​	Retorna​ 1 (​vardadero​) ​si​ ​la​ ​cadena​ ​es​ ​numerica​ y 0 (​falso​) ​si​ no ​lo​ ​es
* \return	-1 en caso de error de parametros
**/
static int esNumerica(char* cadena, int limite)
{
	int retorno = -1; //ERROR
	int i;
	if(cadena != NULL && limite > 0)
	{
		retorno = 1; //VERDADERO
		for (i=0;i<limite && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i]>'9' || cadena[i]<'0')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
* \brief ​	Verifica​ ​si​ ​la​ ​cadena​ ​ingresada​ ​es​ ​numerica permitiendo punto decimal
* \​param​ ​	cadena​ ​Cadena​ ​de​ ​caracteres​ a ​ser​ ​analizada
* \return ​	Retorna​ 1 (​vardadero​) ​si​ ​la​ ​cadena​ ​es​ ​numerica​ y 0 (​falso​) ​si​ no ​lo​ ​es
* \return	-1 en caso de error de parametros
**/
static int esNumeroDecimal(char* cadena, int limite)
{
	int retorno = -1; //ERROR
	int i;
	int puntoEncontrado=0; //bandera para dejar ingresar solo un punto
	if(cadena != NULL && limite > 0)
	{
		retorno = 1; //VERDADERO
		for (i=0;i<limite && cadena[i] != '\0';i++)
		{
			if (puntoEncontrado == 0 && cadena[i] == '.')
			{
				puntoEncontrado=1;
				continue;
			}
			if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i]>'9' || cadena[i]<'0')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
* \brief ​Solicita​ ​un​ ​numero​ entero ​al​ ​usuario​, ​leuego​ ​de​ ​verificarlo​ ​devuelve​ el ​resultado
* \​param​ pResultado ​Puntero​ ​al​ ​espacio​ ​de​ ​memoria​ ​donde​ ​se​ ​dejara​ el ​resultado​ ​de​ ​la​ ​funcion
* \​param​ ​mensaje​ ​Es​ el ​mensaje​ a ​ser​ ​mostrado
* \​param​ mensajeError ​Es​ el ​mensaje​ ​de​ Error a ​ser​ ​mostrado
* \​param​ ​minimo​ ​Es​ el ​numero​ ​maximo​ a ​ser​ ​aceptado
* \​param​ ​maximo​ ​Es​ el ​minimo​ ​minimo​ a ​ser​ ​aceptado
* \return ​Retorna​ 0 ​si​ ​se​ ​obtuvo​ el ​numero​ y -1 ​si​ no
**/
int utn_getNumeroInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	do
	{
		printf("%s",mensaje);
		if(	getInt(&bufferInt) == 0 &&
			pResultado != NULL &&
			mensaje != NULL &&
			mensajeError != NULL &&
			reintentos >= 0 &&
			bufferInt >= minimo &&
			bufferInt <= maximo)
		{
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		printf("%s",mensajeError);
		reintentos--;
	}while(reintentos>=0);
	/*


	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo < maximo && reintentos >= 0)
	{
		while(reintentos>=0)
		{
			reintentos--;
			printf("%s",mensaje);
			fpurge(stdin);
			if(getInt(&bufferInt) == 0)
			{
				if(bufferInt >= minimo && bufferInt <= maximo)
				{
					*pResultado = bufferInt;
					retorno = 0;
					break;
				}
			}
			printf("%s",mensajeError);
		}
	}*/
	return retorno;
}

/**
* \brief ​Solicita​ ​un​ ​numero​ flotante ​al​ ​usuario​, ​leuego​ ​de​ ​verificarlo​ ​devuelve​ el ​resultado
* \​param​ pResultado ​Puntero​ ​al​ ​espacio​ ​de​ ​memoria​ ​donde​ ​se​ ​dejara​ el ​resultado​ ​de​ ​la​ ​funcion
* \​param​ ​mensaje​ ​Es​ el ​mensaje​ a ​ser​ ​mostrado
* \​param​ mensajeError ​Es​ el ​mensaje​ ​de​ Error a ​ser​ ​mostrado
* \​param​ ​minimo​ ​Es​ el ​numero​ ​maximo​ a ​ser​ ​aceptado
* \​param​ ​maximo​ ​Es​ el ​minimo​ ​minimo​ a ​ser​ ​aceptado
* \return ​Retorna​ 0 ​si​ ​se​ ​obtuvo​ el ​numero​ y -1 ​si​ no
**/
int utn_getNumeroFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	float bufferFloat;
	int retorno = -1;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo < maximo && reintentos >= 0)
	{
		while(reintentos>0)
		{
			reintentos--;
			printf("%s",mensaje);
			if(getFloat(&bufferFloat) == 0)
			{
				if(bufferFloat >= minimo && bufferFloat <= maximo)
				{
					*pResultado = bufferFloat;
					retorno = 0;
					break;
				}
			}
			printf("%s",mensajeError);
		}
	}
	return retorno;
}


/**
*\brief Funcion que divide dos enteros y devuelve un flotante con el resultado,
*\brief validando el denominador que no sea 0
*\param	pResultado es el puntero donde el resultado de la operaciòn va a ser devuelto
*\param	operador1 y operador2 son numerador y denominador respectivamente
*\return	retorna 0 si se logró hacer la división y -1 si no lo pudo realizar
**/


int dividir(float* pResultado ,int operador1 ,int operador2)
{
	float resultado;
	int retorno = -1;
	if(pResultado != NULL && operador2 != 0)
	{
		resultado = (float)operador1 / operador2;
		*pResultado = resultado;
		retorno = 0;
	}
	return retorno;
}

/**
 * @fn int utn_getCaracter(char*, char*, char*, char, char, int)
 * @brief Funcion que solicita un caracter y lo devulve en el puntero pResultado
 *
 * @pre
 * @post
 * @param pResultado Puntero devuleto con el caracter validado
 * @param mensaje texto mostrado al usuario solicitando el caracter
 * @param mensajeError Mensaje para el caso que se haya ingresado un dato erroneo
 * @param minimo Desde que caracter
 * @param maximo Hasta que caracter
 * @param reintentos Cantidad de veces que puede volver a pedir para el caso que tenga algun error
 * @return Devulelve 0 en caso de Exito y -1 en caso de Error
 */
int utn_getCaracter(char* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos)
{
	int retorno = -1;
	char bufferChar;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			fpurge(stdin);
			//__fpurge(stdin); //fpurge(stdin) Mac  fflush(stdin) Windows __fpurge(stdin) Linux
			scanf("%c",&bufferChar);
			if(bufferChar >= minimo && bufferChar <= maximo )
			{
				*pResultado = bufferChar;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}
/**
 * @fn int factorial(int)
 * @brief	Funcion que calcula el factorail del numero pasado como argumento
 *
 * @pre
 * @post
 * @param n numero a calcular el factorial
 * @return retorna el factorial del numero pasado como parametro
 */
int factorial(int n)
{
	int resp;
	if(n==1)
		return 1;
	resp=n* factorial(n-1);
	return (resp);
}


/// @brief Funcion usada para verificar el ingreso de caracteres.Chequea para que
/// solo sean admitidas las letras S o N.
/// Se ingresa void y devuelve un entero sin signo
/// @return 'N' si se ingreso la N
/// 'S' si se ingreso la S

unsigned int verifica(void)
{
	char letra;
	printf("\nIngrese opcion...S/N?");
	fpurge(stdin);
	//__fpurge(stdin);
	letra=toupper(getchar());
	while(!((letra=='S')||(letra=='N')))
	{
		printf("\nHa ingresado opcion no valida...Reintente el ingreso(S/N)... ");
		fpurge(stdin);
		//__fpurge(stdin); //mac fpurge(stdin) windows fflush(stdin)
		letra=toupper(getchar());
	}
	return (letra);//=='S');
}

/**
 * \brief Genera Numero aleatorio
 * \param desde Numero aleatorio minimo
 * \param hasta numero aleatorio maximo
 * \param iniciar Indica si se trata del primer numero solicitado 1 inida que si
 * debemos incluir libreria time.h
 * \return retorna el numero aleatorio generado
 *
 */
char getNumeroAleatorio(int desde, int hasta, int iniciar)
{
	if(iniciar)
		srand(time(NULL));
	return desde + (rand() % (hasta + 1 - desde));
}


void insertion(int data[],int len)
{
	int i,j;
	int temp;
	for(i=1;i<len;i++)
	{
		temp = data[i];
		j=i-1;
		while(j>=0 && temp<data[j]) // temp<data[j] o temp>data[j]
		{
			data[j+1] = data[j];
			j--;
		}
		data[j+1]=temp; // inserción
	}
}

/**
 * \brief	Verifica si el valor recibido contiene solo letras
 * \param	str Array con la cedena a ser analizada
 * \return	1 si contiene solo ' ' y letras y 0 si no lo es
 */

int esSoloLetras(char str[])
{
	int i=0;
	while(str[i] != '\0')
	{
		if((str[i] != ' ') && (str[i]<'a' || str[i] > 'z') && (str[i]<'Z' ||str[i]>'Z'))
			return 0;
		i++;
	}
	return 1;
}

/**
 * \brief	Solicita un numero al usuario y devuelve el resultado
 * \param	mensaje Es el mensaje a ser mostrado
 * \return	El numero ingresado por el usuario
 *
 */
 int obtenerEntero(char mensaje[])
 {
	 int auxiliar;
	 printf("%s", mensaje);
	 fpurge(stdin);
	 //__fpurge(stdin);
	 scanf("%d", &auxiliar);
	 return auxiliar;
 }


