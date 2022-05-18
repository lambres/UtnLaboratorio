#include "ePosteo.h"

static int ePosteo_ObtenerID(void);
static int ePosteo_ObtenerID(void) {
	//ID AUTOINCREMENTAL - PRIVADO / GLOBAL
	//INICIALIZADO UNA UNICA VEZ AL COMIENZO DEL PROGRAMA CON ALCANCE UNICAMENTE EN FUNCION ePosteo_ObtenerID();
	static int Posteo_idIncremental = 0;
	return Posteo_idIncremental++;
}

void ePosteo_Inicializar(ePosteo array[], int TAM) {
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

int ePosteo_ObtenerIndexLibre(ePosteo array[], int TAM) {
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

int ePosteo_BuscarPorID(ePosteo array[], int TAM, int ID) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idPosteo == ID && array[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void ePosteo_MostrarUno(ePosteo Posteo) {
	//PRINTF DE UN SOLO Posteo
	printf("%5d\n", Posteo.idPosteo);
}

int ePosteo_MostrarTodos(ePosteo array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t> LISTADO Posteo");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO Posteo
				ePosteo_MostrarUno(array[i]);
				//CONTADOR DE Posteo
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Posteo PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

int ePosteo_MostrarDadosDeBaja(ePosteo array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\t> Posteo\n");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "BAJA"
			if (array[i].isEmpty == BAJA) {
				//MUESTRO UN SOLO Posteo
				ePosteo_MostrarUno(array[i]);
				//CONTADOR DE Posteo
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Posteo PARA MOSTRAR (ARRAY SIN BAJAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

ePosteo ePosteo_CargarDatos(void) {
	ePosteo auxiliar;
	/** CARGAR DATOS NECESARIOS PARA EL ALTA*/
	/** IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL ALTA */
	return auxiliar;
}

ePosteo ePosteo_ModificarUno(ePosteo Posteo) {
	ePosteo auxiliar = Posteo;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	return auxiliar;
}

int ePosteo_Alta(ePosteo array[], int TAM) {
	int rtn = 0;
	ePosteo auxPosteo;

	//BUSCO ESPACIO EN ARRAY
	int index = ePosteo_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Posteo AUXILIAR
		auxPosteo = ePosteo_CargarDatos();
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxPosteo.idPosteo = ePosteo_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxPosteo.isEmpty = OCUPADO;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		array[index] = auxPosteo;

		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = 1;
	}

	return rtn;
}

int ePosteo_Baja(ePosteo array[], int TAM) {
	int rtn = 0;
	int idPosteo;
	int index;
	int flag = 0;

	//LISTO TODOS LOS Posteo
	if (ePosteo_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Posteo DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Posteo PARA DAR DE BAJA
	if (flag) {
		//PIDO ID A DAR DE BAJA
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idPosteo);

		//BUSCO INDEX POR ID EN ARRAY
		while (ePosteo_BuscarPorID(array, TAM, idPosteo) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idPosteo);
		}

		//OBTENGO INDEX DEL ARRAY DE Posteo A DAR DE BAJA
		index = ePosteo_BuscarPorID(array, TAM, idPosteo);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		array[index].isEmpty = BAJA;

		//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int ePosteo_Modificacion(ePosteo array[], int TAM) {
	int rtn = 0;
	int idPosteo;
	int index;
	int flag = 0;
	ePosteo auxiliar;

	//LISTO TODOS LOS Posteo
	if (ePosteo_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Posteo DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Posteo PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idPosteo);

		//BUSCO INDEX POR ID EN ARRAY
		while (ePosteo_BuscarPorID(array, TAM, idPosteo) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idPosteo);
		}

		//OBTENGO INDEX DEL ARRAY DE Posteo A MODIFICAR
		index = ePosteo_BuscarPorID(array, TAM, idPosteo);

		//LLAMO A FUNCION QUE MODIFICA Posteo
		auxiliar = ePosteo_ModificarUno(array[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		array[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int ePosteo_Sort(ePosteo array[], int TAM, int criterio) {
	int rtn = 0;
	int i;
	int j;
	ePosteo aux;

	/** EJEMPLO DE SORT CON ID DE Posteo
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
						if (array[i].idPosteo > array[j].idPosteo) {
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
						if (array[i].idPosteo < array[j].idPosteo) {
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
int hcPosteos(ePosteo array[], int TAM)
{
	int retorno = -1;
	ePosteo p;
	int i;
	char buffer;
	for (i=0;i<TAM;i++)
	{
		p.FK_idUsuario=i;
		p.idPosteo=i;
		p.isEmpty=OCUPADO;
		buffer = strcat('mensaje', ' ', i );
		strcpy(p.mensaje, buffer);
	}
}
