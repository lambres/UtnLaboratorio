#include "Producto.h"

static int Prod_ObtenerID(void);
static int Prod_ObtenerID(void) {
	//ID AUTOINCREMENTAL - PRIVADO / GLOBAL
	//INICIALIZADO UNA UNICA VEZ AL COMIENZO DEL PROGRAMA CON ALCANCE UNICAMENTE EN FUNCION eGen_ObtenerID();
	static int Prod_idIncremental = 0;
	return Prod_idIncremental++;
}

void Prod_Inicializar(Producto array[], int TAM) {
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

int Prod_ObtenerIndexLibre(Producto array[], int TAM) {
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

int Prod_ObtenerIndexOcupado(Producto array[], int TAM)
{
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (array[i].isEmpty == OCUPADO) {
				//OBTENGO EL PRIMER INDEX DEL VECTOR "OCUPADO" Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}
int Prod_BuscarPorID(Producto array[], int TAM, int ID) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].idProducto == ID )//&& array[i].isEmpty == OCUPADO)
			{
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void Prod_MostrarUno(Producto Prod) {
	//PRINTF DE UN SOLO PRODUCTO
	char nombreCategoria[LEN_PRODUCTNAME];
	char estado[10];
	printf("|%-12d", Prod.idProducto);
	switch(Prod.isEmpty)
	{
	case 0:
		strncpy(estado,"LIBRE",10);
		break;
	case 1:
		strncpy(estado,"OCUPADO",10);
		break;
	case -1:
		strncpy(estado,"BAJA",10);
		break;
	}
	printf("|%-11s", estado);
	printf("|%-26s", Prod.nombreProducto);
	printf("|%11.2f", Prod.precio);
	switch(Prod.categoria)
	{
		case 1:
			strncpy(nombreCategoria,"VEHICULOS",LEN_DESCCAT);
			break;
		case 2:
			strncpy(nombreCategoria,"TECNOLOGIA",LEN_DESCCAT);
			break;
		case 3:
			strncpy(nombreCategoria,"ELECTRODOMESTICOS",LEN_DESCCAT);
			break;
		case 4:
			strncpy(nombreCategoria,"HERRAMIENTAS",LEN_DESCCAT);
			break;
		case 5:
			strncpy(nombreCategoria,"CONSTRUCCION",LEN_DESCCAT);
			break;
	}
	printf("|%-21s", nombreCategoria);
	printf("|%-11d", Prod.stock);
	printf("|%-11d|\n", Prod.FKidUsuario);
}

int Prod_MostrarTodos(Producto array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t> LISTADO PRODUCTOS");
	printf("|%-12s", "IDPRODUCTO"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)
	printf("|%-11s", "ESTADO");
	printf("|%-26s", "NOMBRE PRODUCTO");
	printf("|%-11s", "PRECIO");
	printf("|%-21s", "CATEGORIA");
	printf("|%-11s", "STOCK");
	printf("|%-11s|\n", "IDUSUARIO");

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO Gen
				Prod_MostrarUno(array[i]);
				//CONTADOR DE PRODUCTOS
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO PRDUCTOS PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}
int Prod_MostrarFiltroNombre(Producto array[], int TAM, char nombreProd[], int lenNombre)
{
	int i;
	int rtn = 0;
	int cantidad = 0;
	int aux=0;
	//CABECERA
	puts("\n\t> LISTADO PRODUCTOS");
	printf("|%-12s", "IDPRODUCTO"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)
	printf("|%-11s", "ESTADO");
	printf("|%-26s", "NOMBRE PRODUCTO");
	printf("|%-11s", "PRECIO");
	printf("|%-21s", "CATEGORIA");
	printf("|%-11s", "STOCK");
	printf("|%-11s|\n", "IDUSUARIO");

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			aux=strncmp(nombreProd,array[i].nombreProducto,lenNombre);
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO && aux == 0) {
				//MUESTRO UN SOLO Gen
				Prod_MostrarUno(array[i]);
				//CONTADOR DE PRODUCTOS
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO PRDUCTOS PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}
int Prod_MostrarTodosConSaldo(Producto array[], int TAM, int idUser) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t> ESTADO DE VENTAS / VER PRODUCTOS");
	printf("|%-12s", "IDPRODUCTO"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)
	printf("|%-11s", "ESTADO");
	printf("|%-26s", "NOMBRE PRODUCTO");
	printf("|%-11s", "PRECIO");
	printf("|%-21s", "CATEGORIA");
	printf("|%-11s", "STOCK");
	printf("|%-11s|\n", "IDUSUARIO");

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO && array[i].FKidUsuario==idUser) {
				//MUESTRO UN SOLO Gen
				Prod_MostrarUno(array[i]);
				//CONTADOR DE PRODUCTOS
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO PRDUCTOS PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}


int Prod_MostrarDadosDeBaja(Producto array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\t> PRODUCTOS\n");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "BAJA"
			if (array[i].isEmpty == BAJA) {
				//MUESTRO UN SOLO PRODUCTOS
				Prod_MostrarUno(array[i]);
				//CONTADOR DE PRODUCTOS
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO PRODUCTOS PARA MOSTRAR (ARRAY SIN BAJAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

Producto Prod_CargarDatos(void) {
	Producto auxiliar;
	/** CARGAR DATOS NECESARIOS PARA EL ALTA*/
	/** IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL ALTA */
	char auxNombreProducto[LEN_PRODUCTNAME];
	float auxPrecio;
	int auxIntCategoria;
	short int auxCategoria;
	int auxStock;

	utn_getNumeroInt(&auxIntCategoria, "CATEGORIA?\n1 - VEHICULOS\n2 - TECNOLOGIA\n3 - ELECTRODOMESTICOS\n4 - HERRAMIENTAS\n5 - CONSTRUCCION", "VALOR NO VALIDO", 1, 5, 2);
	auxCategoria = (short)auxIntCategoria;
	utn_getTexto(auxNombreProducto, LEN_PRODUCTNAME, "NOMBRE PRODUCTO?:", "ERROR! REINTENTE", 2);
	utn_getNumeroFloat(&auxPrecio, "PRECIO?:", "ERROR! REINTENTE ENTRE 1 y 50000", 1, 50000, 2);
	utn_getNumeroInt(&auxStock, "STOCK?:", "ERROR! VALORES ENTRE 1 y 10000", 1, 10000, 2);
	strncpy(auxiliar.nombreProducto,auxNombreProducto,LEN_PRODUCTNAME);
	auxiliar.precio = auxPrecio;
	auxiliar.categoria=auxCategoria;
	auxiliar.stock=auxStock;
	return auxiliar;
}

Producto Prod_ModificarUno(Producto Prod)
{
	Producto auxiliar = Prod;
	int cantidadAReponer;
	int auxNuevoStock;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	utn_getNumeroInt(&cantidadAReponer, "CANTIDAD A REPONER?", "ERROR! REINGRESE", 1, 2000, 2);
	auxNuevoStock=auxiliar.stock+cantidadAReponer;
	printf("NUEVO STOCK: %d. CONFIRMA?\n", auxNuevoStock);
	if(verifica()=='S')
	{
		auxiliar.stock=auxNuevoStock;
	}
	else
	{
		printf("MODIFICACION ABORTADA!");
	}
	return auxiliar;
}


int Prod_Alta(Producto array[], int TAM, int idusuario)
{
	int rtn = 0;
	Producto auxProductos;

	//BUSCO ESPACIO EN ARRAY
	int index = Prod_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Gen AUXILIAR
		auxProductos = Prod_CargarDatos();
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxProductos.idProducto = Prod_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxProductos.isEmpty = OCUPADO;
		//Asigno el idusuario al campo FKidUsuario
		auxProductos.FKidUsuario = idusuario;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		array[index] = auxProductos;

		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = 1;
	}

	return rtn;
}

int Prod_Baja(Producto array[], int TAM) {
	int rtn = 0;
	int idProd;
	int index;
	int flag = 0;

	//LISTO TODOS LOS PRODUCTOS
	if (Prod_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Gen DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY PRODUCTOS PARA DAR DE BAJA
	if (flag) {
		//PIDO ID A DAR DE BAJA
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		utn_getNumeroInt(&idProd, "ID A ELIMINAR", "ID NO VALIDO", 0, TAM, 2);

		//BUSCO INDEX POR ID EN ARRAY
		while (Prod_BuscarPorID(array, TAM, idProd) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			utn_getNumeroInt(&idProd, "ID A ELIMINAR:", "ID NO VALIDO", 0, TAM, 2);
		}

		//OBTENGO INDEX DEL ARRAY DE PRODUCTOS A DAR DE BAJA
		index = Prod_BuscarPorID(array, TAM, idProd);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		array[index].isEmpty = BAJA;

		//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int Prod_Modificacion(Producto array[], int TAM, int idUser) {
	int rtn = 0;
	int idProd;
	int index;
	int flag = 0;
	Producto auxiliar;

	//LISTO TODOS LOS PRODUCTOS
	if (Prod_MostrarTodosConSaldo(array, TAM,idUser)) {
		//BANDERA EN 1 SI HAY Gen DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Gen PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		utn_getNumeroInt(&idProd, "ID A MODIFICAR:", "ID NO VALIDO", 0, TAM, 2);


		//BUSCO INDEX POR ID EN ARRAY
		while (Prod_BuscarPorID(array, TAM, idProd) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			utn_getNumeroInt(&idProd, "ID A MODIFICAR:", "ID NO VALIDO", 0, TAM, 2);
		}

		//OBTENGO INDEX DEL ARRAY DE Gen A MODIFICAR
		index = Prod_BuscarPorID(array, TAM, idProd);

		//LLAMO A FUNCION QUE MODIFICA Gen
		auxiliar = Prod_ModificarUno(array[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		array[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int Prod_Sort(Producto array[], int TAM, int criterio) {
	int rtn = 0;
	int i;
	int j;
	Producto aux;

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
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (array[i].categoria > array[j].categoria) {
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
						if (array[i].categoria < array[j].categoria) {
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
int Prod_SortName(Producto array[], int TAM, int criterio) {
	int rtn = 0;
	int i;
	int j;
	Producto aux;

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
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (array[i].stock > array[j].stock) {
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
						if (array[i].stock < array[j].stock) {
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
