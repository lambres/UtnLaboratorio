/*
 Biblioteca funciones
 */
//setbuf(stdout,NULL); para compilador windows
#include "utn.h"

#ifdef __linux__
#define SO "Linux"
#define LIMPIAR_CONSOLA system("clear");
#define LIMPIAR_BUFFER __fpurge(stdin);
#include <stdio_ext.h>
#elif _WIN32
#define SO "Windows"
#define LIMPIAR_CONSOLA system("cls");
#define LIMPIAR_BUFFER fflush(stdin);
#elif __APPLE__
#define SO "OSX"
#define LIMPIAR_CONSOLA system("clear");
#define LIMPIAR_BUFFER fpurge(stdin);
#endif


static int esNumerica(char* cadena, int limite);
static int esNumeroDecimal(char* cadena, int limite);
static int getInt(int* pResultado);
static int myGets (char * cadena, int longitud);
static int getFloat (float * pResultado);

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

static int myGets(char* cadena, int longitud)
//int myGets(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[4096];//arreglar en clases posteriores

	if(cadena != NULL && longitud >0)
	{
		#ifdef __linux__
			LIMPIAR_BUFFER
		#elif _WIN32
			LIMPIAR_BUFFER
		#elif __APPLE__
			LIMPIAR_BUFFER
		#endif
		//fpurge(stdin);
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

int obtenerEntero(char mensaje[])
 {
	 int auxiliar;
	 printf("%s", mensaje);
	 scanf("%d", &auxiliar);
	 return auxiliar;
 }

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
	return retorno;
}

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


int utn_getNumeroAleatorio(int desde, int hasta, int iniciar)
{
	if(iniciar)
		srand(time(NULL));
	return desde + (rand() % (hasta + 1 - desde));
}


int utn_getCaracter(char* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos)
{
	int retorno = -1;
	char bufferChar;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			#ifdef __linux__
				LIMPIAR_BUFFER
			#elif _WIN32
				LIMPIAR_BUFFER
			#elif __APPLE__
				LIMPIAR_BUFFER
			#endif
			//fpurge(stdin);
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

int factorial(int n)
{
	int resp;
	if(n==1)
		return 1;
	resp=n* factorial(n-1);
	return (resp);
}


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

int getStringLetras(char * mensaje, char * input)
{
	int retorno = 0;
	char aux[256];
	getString(mensaje, aux);
	if (esSoloLetras(aux))
	{
		strcpy(input, aux);
		retorno = 1;
	}
	return retorno;

}


int getStringNumeros(char * mensaje, char * input)
{
	int retorno = 0;
	char aux[256];
	getString(mensaje,aux);
	if(esNumerica(aux,256))
	{
		strcpy(input,aux);
		retorno = 0;
	}
	return retorno;
}

char getChar(char mensaje[])
{
	char auxiliar;
	printf("%s", mensaje);
	#ifdef __linux__
		LIMPIAR_BUFFER
	#elif _WIN32
		LIMPIAR_BUFFER
	#elif __APPLE__
		LIMPIAR_BUFFER
	#endif
	//fpurge(stdin);
	//__fpurge(stdin); //__fpurge(stdin) linux fflush(stdin) Win
	scanf("%c", &auxiliar);
	return auxiliar;
}

void getString(char * mensaje, char * input)
{
	printf("%s",mensaje);
	#ifdef __linux__
		LIMPIAR_BUFFER
	#elif _WIN32
		LIMPIAR_BUFFER
	#elif __APPLE__
		LIMPIAR_BUFFER
	#endif
	scanf("%s",input);
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

unsigned int verifica(void)
{
	char letra;
	printf("\nIngrese opcion...S/N?");
	#ifdef __linux__
		LIMPIAR_BUFFER
	#elif _WIN32
		LIMPIAR_BUFFER
	#elif __APPLE__
		LIMPIAR_BUFFER
	#endif
	letra=toupper(getchar());
	while(!((letra=='S')||(letra=='N')))
	{
		printf("\nHa ingresado opcion no valida...Reintente el ingreso(S/N)... ");
		#ifdef __linux__
			LIMPIAR_BUFFER
		#elif _WIN32
			LIMPIAR_BUFFER
		#elif __APPLE__
			LIMPIAR_BUFFER
		#endif
		letra=toupper(getchar());
	}
	return (letra);//=='S');
}
