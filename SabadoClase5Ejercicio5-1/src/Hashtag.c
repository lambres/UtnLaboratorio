#include "Hashtag.h"

static int eHashtag_ObtenerID(void);
static int eHashtag_ObtenerID(void) {
	//ID AUTOINCREMENTAL - PRIVADO / GLOBAL
	//INICIALIZADO UNA UNICA VEZ AL COMIENZO DEL PROGRAMA CON ALCANCE UNICAMENTE EN FUNCION eHashtag_ObtenerID();
	static int Hashtag_idIncremental = 0;
	return Hashtag_idIncremental++;
}

void eHashtag_Inicializar(eHashtag array[], int TAM) {
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

int eHashtag_ObtenerIndexLibre(eHashtag array[], int TAM) {
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

int eHashtag_BuscarPorID(eHashtag array[], int TAM, int ID) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idHashtag == ID && array[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void eHashtag_MostrarUno(eHashtag Hashtag) {
	//PRINTF DE UN SOLO Hashtag
	printf("%5d\n", Hashtag.idHashtag);
}

int eHashtag_MostrarTodos(eHashtag array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t> LISTADO Hashtag");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO Hashtag
				eHashtag_MostrarUno(array[i]);
				//CONTADOR DE Hashtag
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Hashtag PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

int eHashtag_MostrarDadosDeBaja(eHashtag array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\t> Hashtag\n");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "BAJA"
			if (array[i].isEmpty == BAJA) {
				//MUESTRO UN SOLO Hashtag
				eHashtag_MostrarUno(array[i]);
				//CONTADOR DE Hashtag
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Hashtag PARA MOSTRAR (ARRAY SIN BAJAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

eHashtag eHashtag_CargarDatos(void) {
	eHashtag auxiliar;
	/** CARGAR DATOS NECESARIOS PARA EL ALTA*/
	/** IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL ALTA */
	return auxiliar;
}

eHashtag eHashtag_ModificarUno(eHashtag Hashtag) {
	eHashtag auxiliar = Hashtag;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	return auxiliar;
}

int eHashtag_Alta(eHashtag array[], int TAM) {
	int rtn = 0;
	eHashtag auxHashtag;

	//BUSCO ESPACIO EN ARRAY
	int index = eHashtag_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Hashtag AUXILIAR
		auxHashtag = eHashtag_CargarDatos();
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxHashtag.idHashtag = eHashtag_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxHashtag.isEmpty = OCUPADO;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		array[index] = auxHashtag;

		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = 1;
	}

	return rtn;
}

int eHashtag_Baja(eHashtag array[], int TAM) {
	int rtn = 0;
	int idHashtag;
	int index;
	int flag = 0;

	//LISTO TODOS LOS Hashtag
	if (eHashtag_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Hashtag DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Hashtag PARA DAR DE BAJA
	if (flag) {
		//PIDO ID A DAR DE BAJA
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idHashtag);

		//BUSCO INDEX POR ID EN ARRAY
		while (eHashtag_BuscarPorID(array, TAM, idHashtag) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idHashtag);
		}

		//OBTENGO INDEX DEL ARRAY DE Hashtag A DAR DE BAJA
		index = eHashtag_BuscarPorID(array, TAM, idHashtag);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		array[index].isEmpty = BAJA;

		//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int eHashtag_Modificacion(eHashtag array[], int TAM) {
	int rtn = 0;
	int idHashtag;
	int index;
	int flag = 0;
	eHashtag auxiliar;

	//LISTO TODOS LOS Hashtag
	if (eHashtag_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Hashtag DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Hashtag PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idHashtag);

		//BUSCO INDEX POR ID EN ARRAY
		while (eHashtag_BuscarPorID(array, TAM, idHashtag) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idHashtag);
		}

		//OBTENGO INDEX DEL ARRAY DE Hashtag A MODIFICAR
		index = eHashtag_BuscarPorID(array, TAM, idHashtag);

		//LLAMO A FUNCION QUE MODIFICA Hashtag
		auxiliar = eHashtag_ModificarUno(array[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		array[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int eHashtag_Sort(eHashtag array[], int TAM, int criterio) {
	int rtn = 0;
	int i;
	int j;
	eHashtag aux;

	/** EJEMPLO DE SORT CON ID DE Hashtag
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
						if (array[i].idHashtag > array[j].idHashtag) {
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
						if (array[i].idHashtag < array[j].idHashtag) {
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
int hcHashtag(eHashtag array[], int TAM)
{
	int retorno = -1;
	eHashtag p;
	int i;
	char buffer;
	for (i=0;i<TAM;i++)
	{
		p.FK_idPosteo=i;
		p.idHashtag=i;
		p.isEmpty=OCUPADO;
		buffer = strcat('#', i );
		strcpy(p.referencia, buffer);
	}
}
