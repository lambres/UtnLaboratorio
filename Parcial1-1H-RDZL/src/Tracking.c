#include "Tracking.h"

static int Track_ObtenerID(void);
static int Track_ObtenerID(void) {
	//ID AUTOINCREMENTAL - PRIVADO / GLOBAL
	//INICIALIZADO UNA UNICA VEZ AL COMIENZO DEL PROGRAMA CON ALCANCE UNICAMENTE EN FUNCION eGen_ObtenerID();
	static int Track_idIncremental = 0;
	return Track_idIncremental++;
}

void Track_Inicializar(Tracking array[], int TAM) {
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//SET ESTADO DE "LIBRE"
			array[i].isEmpty = LIBRE;
		}
	}
}

int Track_ObtenerIndexLibre(Tracking array[], int TAM) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (array[i].isEmpty == LIBRE) {
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int Track_BuscarPorID(Tracking array[], int TAM, int ID) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idTracking == ID && array[i].isEmpty != LIBRE) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void Track_MostrarUno(Tracking Track) {
	//PRINTF DE UN SOLO Gen
	char estado[10];
	printf("|%-11d", Track.idTracking);
	switch(Track.isEmpty)
		{
		case -2:
			strncpy(estado,"CANCELADO",10);
			break;
		case -1:
			strncpy(estado,"ENTREGADO",10);
			break;
		case 0:
			strncpy(estado,"LIBRE",10);
			break;
		case 1:
			strncpy(estado,"EN VIAJE",10);
			break;
		}
	printf("|%-11s", estado);
	printf("|%-10d", Track.cantidad);
	printf("|%-10d", Track.distanciaKM);
	printf("|%-10d|\n", Track.FKidUsuarioVendedor);
}

int Track_MostrarTodos(Tracking array[], int TAM)
{
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t> TRACKING GLOBAL");
	printf("|%-11s", "IDTRACKING"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)
	printf("|%-11s", "ESTADO");
	printf("|%-10s", "CANTIDAD");
	printf("|%-10s", "DISTANCIA");
	printf("|%-10s\n", "PRODUCTO");


	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "DISTINTO DE LIBRE"
			if (array[i].isEmpty != LIBRE ) {
				//MUESTRO UN SOLO Gen
				Track_MostrarUno(array[i]);
				//CONTADOR DE Gen
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Gen PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

int Track_MostrarDadosDeBaja(Tracking array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\t> TRACKING\n");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "BAJA"
			if (array[i].isEmpty == ENTREGADO) {
				//MUESTRO UN SOLO Gen
				Track_MostrarUno(array[i]);
				//CONTADOR DE Gen
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Gen PARA MOSTRAR (ARRAY SIN BAJAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

/*Tracking Track_CargarDatos(void) {
	Tracking auxiliar;
	// CARGAR DATOS NECESARIOS PARA EL ALTA/
	// IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL ALTA /

	return auxiliar;
}

Tracking Track_ModificarUno(Tracking Track) {
	Tracking auxiliar = Track;
	// MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" /
	// IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL /
	return auxiliar;
}

int Track_Alta(Tracking array[], int TAM) {
	int rtn = 0;
	Tracking auxTrack;

	//BUSCO ESPACIO EN ARRAY
	int index = Track_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Gen AUXILIAR
		auxTrack = Track_CargarDatos();
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxTrack.idTracking = Track_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxTrack.isEmpty = EN_VIAJE;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		array[index] = auxTrack;

		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = 1;
	}

	return rtn;
}
*/
int Track_Baja(Tracking array[], int TAM, int indexUser) {
	int rtn = 0;
	int idTrack;
	int index;
	int flag = 0;

	//LISTO TODOS LOS Gen
	if (Track_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Gen DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Gen PARA DAR DE BAJA
	if (flag) {
		//PIDO ID A DAR DE BAJA
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idTrack);

		//BUSCO INDEX POR ID EN ARRAY
		while (Track_BuscarPorID(array, TAM, idTrack) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idTrack);
		}

		//OBTENGO INDEX DEL ARRAY DE Gen A DAR DE BAJA
		index = Track_BuscarPorID(array, TAM, idTrack);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		array[index].isEmpty = CANCELADO;

		//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int Track_Modificacion(Tracking array[], int TAM, int indexUser)
{
	int rtn = 0;
	int idTrack;
	int index;
	int flag = 0;
	//Tracking auxiliar;

	//LISTO TODOS LOS Gen
	if (Track_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Gen DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Gen PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idTrack);

		//BUSCO INDEX POR ID EN ARRAY
		while (Track_BuscarPorID(array, TAM, idTrack) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idTrack);
		}

		//OBTENGO INDEX DEL ARRAY DE Gen A MODIFICAR
		index = Track_BuscarPorID(array, TAM, idTrack);

		//LLAMO A FUNCION QUE MODIFICA Gen
		//auxiliar = Track_ModificarUno(array[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		//array[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int Track_Sort(Tracking array[], int TAM, int criterio) {
	int rtn = 0;
	int i;
	int j;
	Tracking aux;

	/** EJEMPLO DE SORT CON ID DE Gen
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
					if (array[i].isEmpty != LIBRE
							&& array[j].isEmpty != LIBRE) {
						//CRITERIO DE ORDENAMIENTO
						if (array[i].idTracking > array[j].idTracking) {
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
					if (array[i].isEmpty != LIBRE
							&& array[j].isEmpty != LIBRE) {
						//CRITERIO DE ORDENAMIENTO
						if (array[i].idTracking < array[j].idTracking) {
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

int Track_AltaConDatos(Tracking array[], int TAM, Tracking registro)
{
	int rtn = 0;
	Tracking auxTrack;

	//BUSCO ESPACIO EN ARRAY
	int index = Track_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1)
	{
		//PIDO DATOS - CARGO Gen AUXILIAR
		auxTrack = registro;
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxTrack.idTracking = Track_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxTrack.isEmpty = EN_VIAJE;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		array[index] = auxTrack;

		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = 1;
	}

	return rtn;
}

int Track_ActualizoEstado(Tracking array[], int TAM)
{
	int retorno = 1;
	int i;
	if(array!=NULL && TAM > 0)
	{
		for (i = 0 ; i<TAM; i++)
		{
			if (array[i].isEmpty == EN_VIAJE && array[i].horaLlegada<time_Current())
			{
				array[i].isEmpty=ENTREGADO;
			}
		}
		retorno = 0;
	}
	return retorno;
}
