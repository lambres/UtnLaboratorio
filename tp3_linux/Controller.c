#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	if(path != NULL && pArrayListPassenger != NULL)
	{
		if(ll_len(pArrayListPassenger)>0)
		{
			puts("Archivo cargado previamente");
		}
		else
		{
			FILE* pFile=fopen("data.csv","r");
			if(parser_PassengerFromText(pFile, pArrayListPassenger)==1)
			{
				printf("No se pudo cargar el archivo en controller\n");
			}
			retorno = 0;
			fclose(pFile);
		}
	}


    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger, int idNuevo)
{
	int retorno = -1;
	Passenger* aux = Passenger_new();
	int id=-1;
	char nombre[LEN_NOMBRE];
	char apellido[LEN_APELLIDO];
	float precio;
	char codigoVuelo[LEN_CODVUELO];
	int tipoPasajero;
	char estadoVuelo[LEN_ESTADOVUELO];

	if (aux!=NULL && idNuevo >= 0)
	{
		id = idNuevo;
		if(!(utn_getNumeroFloat(&precio, "INGRESE PRECIO DEL VUELO", "ERROR REINTENTE", 0, 99999, 2)))
		{
			if(!(utn_getNumeroInt(&tipoPasajero, "TIPO PASAJERO (0:FirstClass 1:ExecutiveClass "
					"2:EconomyClass): ", "ERROR", 0, 2, 2)))
			{
				if(!(utn_getNombre(nombre, LEN_NOMBRE, "NOMBRE: ", "ERROR",2)))
				{
					if(!(utn_getNombre(apellido, LEN_APELLIDO, "APELLIDO: ", "ERROR", 2)))
					{
						if(!utn_getTexto(codigoVuelo, LEN_CODVUELO, "CODIGO VUELO", "ERROR", 2))
						{
							if(!(utn_getTexto(estadoVuelo, LEN_ESTADOVUELO, "ESTADO VUELO (Aterrizado/En Horario/En Vuelo/Demorado: ", "ERROR", 2)))
							{
								Passenger_setId(aux, id);
								Passenger_setNombre(aux, nombre);
								Passenger_setApellido(aux, apellido);
								Passenger_setCodigoVuelo(aux, codigoVuelo);
								Passenger_setEstadoVuelo(aux, estadoVuelo);
								Passenger_setPrecio(aux, precio);
								Passenger_setTipoPasajero(aux, tipoPasajero);
								ll_add(pArrayListPassenger, aux);
								retorno = 0;
							}
						}
					}
				}
			}
		}
		else
		{
			Passenger_delete(aux);
		}
	}
    return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = 1;
	int i;
	int auxId;
	int opc;
	char nombre[LEN_NOMBRE];
	char apellido[LEN_APELLIDO];
	float precio;
	char codigoVuelo[LEN_CODVUELO];
	char tipoPasajero[LEN_TIPOPASAJERO];
	char estadoVuelo[LEN_ESTADOVUELO];
	Passenger* this = NULL;
	if (pArrayListPassenger != NULL)
	{
		if(!utn_getNumeroInt(&auxId, "INGRESE ID A MODIFICAR", "ERROR", 0, 9999, 2))
		{
			int cantidad = ll_len(pArrayListPassenger);
			for (i=0; i< cantidad; i++)
			{
				this = (Passenger*) ll_get(pArrayListPassenger, i);
				//Passenger_printOne(pPasajero);
				if(auxId==this->id)
				{
					printf("%-10s|%-20s|%-20s|%-11s|%-16s|%-15s|%-15s|\n","Indice","Nombre","Apellido","Precio","Cod. Vuelo","TipoPasajero","Est. Vuelo");
					ll_get(pArrayListPassenger, i);
					Passenger_printOne(this);
					if(!utn_getNumeroInt(&opc, "DATO A MODIF:\n1: NOMBRE\n2: APELLIDO\n3: PRECIO\n4: COD. VUELO\n5: TIPO PASAJERO\n6: EST. VUELO\n", "ERROR", 1, 6, 2))
					{
						switch(opc)
						{
						case 1:
							if(!utn_getNombre(nombre, LEN_NOMBRE, "NUEVO NOMBRE", "ERROR", 2))
							{
								if(Passenger_setNombre(this, nombre)==-1)
								{
									printf("ERROR \nNo se pudo editar el campo\n");
								}
							}
							break;
						case 2:
							if(!utn_getNombre(apellido, LEN_APELLIDO, "NUEVO APELLIDO", "ERROR", 2))
							{
								if(Passenger_setApellido(this, apellido)==-1)
								{
									printf("ERROR \nNo se pudo editar el campo\n");
								}
							}
							break;
						case 3:
							if(!utn_getNumeroFloat(&precio, "NUEVO PRECIO", "ERROR", 0, 99999, 2))
							{
								if(Passenger_setPrecio(this, precio)==-1)
								{
									printf("ERROR \nNo se pudo editar el campo\n");
								}
							}
							break;
						case 4:
							if(!utn_getTexto(codigoVuelo, LEN_CODVUELO, "NUEVO CODIGO", "ERROR", 2))
							{
								if(Passenger_setCodigoVuelo(this, codigoVuelo)==-1)
								{
									printf("ERROR \nNo se pudo editar el campo\n");
								}
							}
							break;
						case 5:
							if(!utn_getTexto(tipoPasajero, LEN_TIPOPASAJERO, "NUEVO TIPO PASAJERO", "ERROR", 2))
							{
								if(Passenger_setTipoPasajeroStr(this, tipoPasajero)==-1)
								{
									printf("ERROR \nNo se pudo editar el campo\n");
								}
							}
							break;
						case 6:
							if(!(utn_getTexto(estadoVuelo, LEN_ESTADOVUELO, "NUEVO ESTADO VUELO (Aterrizado/En Horario/En Vuelo/Demorado: ", "ERROR", 2)))
							{
								if(Passenger_setEstadoVuelo(this, estadoVuelo)==-1)
								{
									printf("ERROR \nNo se pudo editar el campo\n");
								}
							}
							break;
						}
					}
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int retorno = 1;
	int i;
	int auxId;
	//int auxIndex;
	Passenger* this = NULL;
	if (pArrayListPassenger != NULL)
	{
		//controller_ListPassenger(pArrayListPassenger);
		if(!utn_getNumeroInt(&auxId, "INGRESE ID A ELIMINAR", "ERROR", 0, 9999, 2))
		{
			int cantidad = ll_len(pArrayListPassenger);
			for (i=0; i< cantidad; i++)
			{
				this = (Passenger*) ll_get(pArrayListPassenger, i);
				if(auxId==this->id)
				{
					printf("%-10s|%-20s|%-20s|%-11s|%-16s|%-15s|%-15s|\n","Indice","Nombre","Apellido","Precio","Cod. Vuelo","TipoPasajero","Est. Vuelo");
					Passenger_printOne(this);
					if(verifica()=='S')
					{
						//auxIndex=ll_indexOf(pArrayListPassenger, this);
						//if(auxIndex>=0)
						//{
							//printf("Estoy para eliminar index %d\n",auxIndex);
							Passenger_delete(this);
							//ll_remove(pArrayListPassenger, i);
							retorno = 0;
						//}
					}
				}
			}
		}
	}
	return retorno;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = 1;
	int i;
	Passenger* pPasajero = NULL;
	if (pArrayListPassenger != NULL)
	{
		int cantidad = ll_len(pArrayListPassenger);
		printf("%-10s|%-20s|%-20s|%-11s|%-16s|%-15s|%-15s|\n","Indice","Nombre","Apellido","Precio","Cod. Vuelo","TipoPasajero","Est. Vuelo");
		for (i=0; i< cantidad; i++)
		{
			pPasajero = (Passenger*) ll_get(pArrayListPassenger, i);
			Passenger_printOne(pPasajero);
		}
		retorno = 0;
	}
	return retorno;
}



/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* pasajero1;
	Passenger* pasajero2;
	int i;
	int retorno = -1;
	int cantidadElementos;
	if(pArrayListPassenger != NULL)
	{
		cantidadElementos = ll_len(pArrayListPassenger);
		for (i=0;i<cantidadElementos;i++)
		{
			pasajero1=ll_get(pArrayListPassenger, i);
			pasajero2=ll_get(pArrayListPassenger, i+1);
			ll_sort(pArrayListPassenger, Passenger_Criterio((void*)pasajero1,(void*)pasajero2), 0);
		}
		retorno = 0;
	}
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = 1;
	FILE* pArchivo;
	int i;
	Passenger* pPasajero = NULL;
	if (path != NULL && pArrayListPassenger != NULL)
	{
		pArchivo = fopen(path,"w");
		if (pArchivo != NULL)
		{
			int cantidad = ll_len(pArrayListPassenger);
			fprintf(pArchivo,"%s,%s,%s,%s,%s,%s,%s\n","id","name","lastname","price","flycode","typePassenger","statusFlight");
			for (i=0; i< cantidad; i++)
			{
				pPasajero = (Passenger*) ll_get(pArrayListPassenger, i);
				Passenger_printOneFile(pArchivo, pPasajero);
			}
		fclose(pArchivo);
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

