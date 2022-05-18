#include "eUsuario.h"

static int eUsuario_ObtenerID(void);
static int eUsuario_ObtenerID(void) {
	//ID AUTOINCREMENTAL - PRIVADO / GLOBAL
	//INICIALIZADO UNA UNICA VEZ AL COMIENZO DEL PROGRAMA CON ALCANCE UNICAMENTE EN FUNCION eUsuario_ObtenerID();
	static int Usuario_idIncremental = 0;
	return Usuario_idIncremental++;
}

void eUsuario_Inicializar(eUsuario array[], int TAM) {
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

int eUsuario_ObtenerIndexLibre(eUsuario array[], int TAM) {
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

int eUsuario_BuscarPorID(eUsuario array[], int TAM, int ID) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idUsuario == ID && array[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void eUsuario_MostrarUno(eUsuario Usuario) {
	//PRINTF DE UN SOLO Usuario
	printf("%5d\n", Usuario.idUsuario);
}

int eUsuario_MostrarTodos(eUsuario array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t> LISTADO Usuario");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO Usuario
				eUsuario_MostrarUno(array[i]);
				//CONTADOR DE Usuario
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Usuario PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

int eUsuario_MostrarDadosDeBaja(eUsuario array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\t> Usuario\n");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "BAJA"
			if (array[i].isEmpty == BAJA) {
				//MUESTRO UN SOLO Usuario
				eUsuario_MostrarUno(array[i]);
				//CONTADOR DE Usuario
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Usuario PARA MOSTRAR (ARRAY SIN BAJAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

eUsuario eUsuario_CargarDatos(void) {
	eUsuario auxiliar;
	/** CARGAR DATOS NECESARIOS PARA EL ALTA*/
	/** IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL ALTA */
	return auxiliar;
}

eUsuario eUsuario_ModificarUno(eUsuario Usuario) {
	eUsuario auxiliar = Usuario;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	return auxiliar;
}

int eUsuario_Alta(eUsuario array[], int TAM) {
	int rtn = 0;
	eUsuario auxUsuario;

	//BUSCO ESPACIO EN ARRAY
	int index = eUsuario_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Usuario AUXILIAR
		auxUsuario = eUsuario_CargarDatos();
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxUsuario.idUsuario = eUsuario_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxUsuario.isEmpty = OCUPADO;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		array[index] = auxUsuario;

		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = 1;
	}

	return rtn;
}

int eUsuario_Baja(eUsuario array[], int TAM) {
	int rtn = 0;
	int idUsuario;
	int index;
	int flag = 0;

	//LISTO TODOS LOS Usuario
	if (eUsuario_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Usuario DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Usuario PARA DAR DE BAJA
	if (flag) {
		//PIDO ID A DAR DE BAJA
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idUsuario);

		//BUSCO INDEX POR ID EN ARRAY
		while (eUsuario_BuscarPorID(array, TAM, idUsuario) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idUsuario);
		}

		//OBTENGO INDEX DEL ARRAY DE Usuario A DAR DE BAJA
		index = eUsuario_BuscarPorID(array, TAM, idUsuario);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		array[index].isEmpty = BAJA;

		//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int eUsuario_Modificacion(eUsuario array[], int TAM) {
	int rtn = 0;
	int idUsuario;
	int index;
	int flag = 0;
	eUsuario auxiliar;

	//LISTO TODOS LOS Usuario
	if (eUsuario_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Usuario DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Usuario PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idUsuario);

		//BUSCO INDEX POR ID EN ARRAY
		while (eUsuario_BuscarPorID(array, TAM, idUsuario) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idUsuario);
		}

		//OBTENGO INDEX DEL ARRAY DE Usuario A MODIFICAR
		index = eUsuario_BuscarPorID(array, TAM, idUsuario);

		//LLAMO A FUNCION QUE MODIFICA Usuario
		auxiliar = eUsuario_ModificarUno(array[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		array[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int eUsuario_Sort(eUsuario array[], int TAM, int criterio) {
	int rtn = 0;
	int i;
	int j;
	eUsuario aux;

	/** EJEMPLO DE SORT CON ID DE Usuario
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
						if (array[i].idUsuario > array[j].idUsuario) {
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
						if (array[i].idUsuario < array[j].idUsuario) {
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


int hcUsuarios(eUsuario array[], int TAM)
{
	int retorno = -1;
	eUsuario p;
	int i;
	char buffer;
	for (i=0;i<TAM;i++)
	{
		p.idUsuario=i;
		p.isEmpty=OCUPADO;
		strcpy(p.password,'123');
		buffer = strcat('usuario', ' ', i );
		strcpy(p.userName, buffer);
	}
}
