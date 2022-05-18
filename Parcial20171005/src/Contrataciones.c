#include "Contrataciones.h"

static int eContrataciones_ObtenerID(void);
static int eContrataciones_ObtenerID(void) {
	//ID AUTOINCREMENTAL - PRIVADO / GLOBAL
	//INICIALIZADO UNA UNICA VEZ AL COMIENZO DEL PROGRAMA CON ALCANCE UNICAMENTE EN FUNCION eContrataciones_ObtenerID();
	static int Contrataciones_idIncremental = 0;
	return Contrataciones_idIncremental++;
}

void eContrataciones_Inicializar(eContrataciones array[], int TAM) {
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//SET ESTADO DE "LIBRE"
			array[i].isEmpty = ACTIVO;
		}
	}
}

int eContrataciones_ObtenerIndexLibre(eContrataciones array[], int TAM) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (array[i].isEmpty == ACTIVO) {
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int eContrataciones_BuscarPorID(eContrataciones array[], int TAM, int ID) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idContrataciones == ID && array[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void eContrataciones_MostrarUno(eContrataciones Contrataciones) {
	//PRINTF DE UN SOLO Contrataciones
	printf("%5d\n", Contrataciones.idContrataciones);
}

int eContrataciones_MostrarTodos(eContrataciones array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t> LISTADO Contrataciones");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO Contrataciones
				eContrataciones_MostrarUno(array[i]);
				//CONTADOR DE Contrataciones
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Contrataciones PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

int eContrataciones_MostrarDadosDeBaja(eContrataciones array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\t> Contrataciones\n");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "BAJA"
			if (array[i].isEmpty == BAJA) {
				//MUESTRO UN SOLO Contrataciones
				eContrataciones_MostrarUno(array[i]);
				//CONTADOR DE Contrataciones
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Contrataciones PARA MOSTRAR (ARRAY SIN BAJAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

eContrataciones eContrataciones_CargarDatos(void) {
	eContrataciones auxiliar;
	int auxDias;
	/** CARGAR DATOS NECESARIOS PARA EL ALTA*/
	/** IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL ALTA */
	auxiliar.idContrataciones = eContrataciones_ObtenerID();
	auxiliar.cantidadDias = utn_getNumeroInt(&auxDias, "Cantidad de dias de publicacion: \n", "Error. Reingrese. \n", 1, 365, 2);
	auxiliar.cuit = utn_getNumeroInt(&auxiliar.cuit, "CUIT:\n", "Error Reingrese CUIT\n", 1, 9999, 2);
	utn_getTexto(auxiliar.nombreArchivoVideo, MAX_CHARS_CADENAS, "Nombre de Archivo de video: \n", "Error. Reingrese. ", 2);

	return auxiliar;
}

eContrataciones eContrataciones_ModificarUno(eContrataciones Contrataciones) {
	eContrataciones auxiliar = Contrataciones;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	return auxiliar;
}

int eContrataciones_Alta(eContrataciones array[], int TAM) {
	int rtn = 0;
	eContrataciones auxContrataciones;

	//BUSCO ESPACIO EN ARRAY
	int index = eContrataciones_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Contrataciones AUXILIAR
		auxContrataciones = eContrataciones_CargarDatos();
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxContrataciones.idContrataciones = eContrataciones_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxContrataciones.isEmpty = OCUPADO;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		array[index] = auxContrataciones;

		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = 1;
	}

	return rtn;
}

int eContrataciones_Baja(eContrataciones array[], int TAM) {
	int rtn = 0;
	int idContrataciones;
	int index;
	int flag = 0;

	//LISTO TODOS LOS Contrataciones
	if (eContrataciones_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Contrataciones DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Contrataciones PARA DAR DE BAJA
	if (flag) {
		//PIDO ID A DAR DE BAJA
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idContrataciones);

		//BUSCO INDEX POR ID EN ARRAY
		while (eContrataciones_BuscarPorID(array, TAM, idContrataciones) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idContrataciones);
		}

		//OBTENGO INDEX DEL ARRAY DE Contrataciones A DAR DE BAJA
		index = eContrataciones_BuscarPorID(array, TAM, idContrataciones);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		array[index].isEmpty = BAJA;

		//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int eContrataciones_Modificacion(eContrataciones array[], int TAM) {
	int rtn = 0;
	int idContrataciones;
	int index;
	int flag = 0;
	eContrataciones auxiliar;

	if(array != NULL && TAM > 0)
	{
		//LISTO TODOS LOS Contrataciones
		if (eContrataciones_MostrarTodos(array, TAM)) {
			//BANDERA EN 1 SI HAY Contrataciones DADOS DE ALTA PARA LISTAR
			flag = 1;
		}

		//SI HAY Contrataciones PARA MODIFICAR
		if (flag) {
			//PIDO ID A MODIFICAR
			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idContrataciones);

			//BUSCO INDEX POR ID EN ARRAY
			while (eContrataciones_BuscarPorID(array, TAM, idContrataciones) == -1) {
				puts("NO EXISTE ID.");

				/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
				printf("INGRESE ID A DAR DE BAJA: ");
				scanf("%d", &idContrataciones);
			}

			//OBTENGO INDEX DEL ARRAY DE Contrataciones A MODIFICAR
			index = eContrataciones_BuscarPorID(array, TAM, idContrataciones);

			//LLAMO A FUNCION QUE MODIFICA Contrataciones
			auxiliar = eContrataciones_ModificarUno(array[index]);

			/**PREGUNTAR SI DESEA CONTINUAR*/
			//MODIFICACION ACEPTADA
			array[index] = auxiliar;

			//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
			rtn = 1;
		}


	}
	else
	{
		rtn = -1;
	}
	return rtn;
}

int eContrataciones_Sort(eContrataciones array[], int TAM, int criterio) {
	int rtn = 0;
	int i;
	int j;
	eContrataciones aux;

	/** EJEMPLO DE SORT CON ID DE Contrataciones
	    MODIFICAR "CRITERIO DE ORDENAMIENTO" PARA OTROS CASOS DE ORDENAMIENTO
	    CASE -1 -> MENOR A MAYOR (ASCENDENTE)
	    CASE  1 -> MAYOR A MENOR (DESCENDENTE)
	    UTILIZAR strcmp(...) PARA COMPARAR CADENAS
	*/

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		switch (criterio) {
		case -1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (array[i].idContrataciones > array[j].idContrataciones) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		case 1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (array[i].idContrataciones < array[j].idContrataciones) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		default:
			//CRITERIO DE ORDENAMIENTO MAL INGRESADO
			rtn = 0;
			break;
		}
	}
	return rtn;
}
