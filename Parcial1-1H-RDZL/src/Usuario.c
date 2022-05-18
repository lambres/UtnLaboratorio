#include <stdio.h>
#include <stdlib.h>
#include "Usuario.h"

static int User_ObtenerID(void);
static int User_ObtenerID(void) {
	//ID AUTOINCREMENTAL - PRIVADO / GLOBAL
	//INICIALIZADO UNA UNICA VEZ AL COMIENZO DEL PROGRAMA CON ALCANCE UNICAMENTE EN FUNCION User_ObtenerID();
	static int User_idIncremental = 0;
	return User_idIncremental++;
}

void User_Inicializar(Usuario array[], int TAM) {
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO todo EL ARRAY
		for (i = 0; i < TAM; i++) {
			//SET ESTADO DE "LIBRE"
			array[i].isEmpty = LIBRE;
		}
	}
}

int User_ObtenerIndexLibre(Usuario array[], int TAM) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO todo EL ARRAY
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

int User_BuscarPorEmail(Usuario array[], int TAM, char mail[])
{
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO todo EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL MAIL QUE ESTOY BUSCANDO
			if (strncmp(array[i].correo,mail,LEN_CORREO)==0 && array[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL MAIL
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}
int User_BuscarPorID(Usuario array[], int TAM, int ID) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO todo EL ARRAY
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

void User_MostrarUno(Usuario User) {
	//PRINTF DE UN SOLO Usuario
	char estado[10];
	char tipo[10];
	printf("|%6d", User.idUsuario);
	switch(User.isEmpty)
	{
	case -1:
		strncpy(estado,"BAJA",10);
		break;
	case 0:
		strncpy(estado,"LIBRE",10);
		break;
	case 1:
		strncpy(estado,"OCUPADO",10);
		break;
	}
	printf("|%-12s", estado);
	switch(User.tipo)
	{
	case 0:
		strncpy(tipo,"ADMIN",10);
		break;
	case 1:
		strncpy(tipo,"USUARIO",10);
		break;
	}
	printf("|%-12s",tipo);
	printf("|%-20s", User.correo);
	printf("|%-12s", User.password);
	printf("|%-20s", User.direccion);
	printf("|%6d|\n", User.codPostal);
}

int User_MostrarTodos(Usuario array[], int TAM)
{
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t> LISTADO USUARIOS");
	printf("|%6s", "ID_USR"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)
	printf("|%-12s", "ESTADO");
	printf("|%-12s", "TIPO");
	printf("|%-20s", "EMAIL");
	printf("|%-12s", "PASSWORD");
	printf("|%-20s", "DIRECCION");
	printf("|%6s|\n", "C.P.");
	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO Gen
				User_MostrarUno(array[i]);
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

int User_MostrarDadosDeBaja(Usuario array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\t> Usuario\n");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO todo EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "BAJA"
			if (array[i].isEmpty == BAJA) {
				//MUESTRO UN SOLO Gen
				User_MostrarUno(array[i]);
				//CONTADOR DE Gen
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO Usuarios PARA MOSTRAR (ARRAY SIN BAJAS)
	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

Usuario User_CargarDatos(void) {
	Usuario auxiliar;

	short int auxTipo;
	char auxCorreo[LEN_CORREO];
	char auxPassword[LEN_PWD];
	char auxDireccion[LEN_DIRECCION];
	int auxCodPostal;
	int auxIntTipo;
	/** CARGAR DATOS NECESARIOS PARA EL ALTA*/
	/** IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL ALTA */
	utn_getNumeroInt(&auxIntTipo, "TIPO USUARIO: 0 - ADMIN  1- USUARIO?:","ERROR!: REINTENTE", 0, 1, 2);
	auxTipo = (short)auxIntTipo;
	utn_getEmail(auxCorreo, LEN_CORREO, "MAIL?:", "ERROR! REINTENTE", 2);
	utn_getTexto(auxPassword, LEN_PWD, "PASSWORD?:", "ERROR! REINTENTE", 0);
	utn_getTexto(auxDireccion, LEN_DIRECCION, "DOMICILIO?:", "ERROR! REINTENTE", 2);
	utn_getNumeroInt(&auxCodPostal, "C.P.:", "ERROR, VALORES VALIDOS ENTRE 1 y 9999", 1, 9999, 2);

	auxiliar.tipo = auxTipo;
	strncpy(auxiliar.correo,auxCorreo,LEN_CORREO);
	strncpy(auxiliar.password,auxPassword,LEN_PWD);
	strncpy(auxiliar.direccion,auxDireccion,LEN_DIRECCION);
	auxiliar.codPostal=auxCodPostal;

	return auxiliar;
}

Usuario User_ModificarUno(Usuario User) {
	Usuario auxiliar = User;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	return auxiliar;
}

int User_Alta(Usuario array[], int TAM) {
	int rtn = 0;
	Usuario auxUser;

	//BUSCO ESPACIO EN ARRAY
	int index = User_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Gen AUXILIAR
		auxUser = User_CargarDatos();
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxUser.idUsuario = User_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxUser.isEmpty = OCUPADO;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		array[index] = auxUser;

		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = 1;
	}

	return rtn;
}

int User_Baja(Usuario array[], int TAM) {
	int rtn = 0;
	int idUser;
	int index;
	int flag = 0;

	//LISTO TODOS LOS USUARIOS
	if (User_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY USUARIOS DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY USUARIOS PARA DAR DE BAJA
	if (flag) {
		//PIDO ID A DAR DE BAJA
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		utn_getNumeroInt(&idUser, "ID A ELIMINAR:", "ID NO VALIDO", 0, TAM, 2);

		//BUSCO INDEX POR ID EN ARRAY
		while (User_BuscarPorID(array, TAM, idUser) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			utn_getNumeroInt(&idUser, "ID A ELIMINAR:", "ID NO VALIDO", 0, TAM, 2);
		}

		//OBTENGO INDEX DEL ARRAY DE Gen A DAR DE BAJA
		index = User_BuscarPorID(array, TAM, idUser);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		array[index].isEmpty = BAJA;

		//RETORNO 1 SI SE DIO DE BAJA CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int User_Modificacion(Usuario array[], int TAM) {
	int rtn = 0;
	int idUser;
	int index;
	int flag = 0;
	Usuario auxiliar;

	//LISTO todoS LOS Gen
	if (User_MostrarTodos(array, TAM)) {
		//BANDERA EN 1 SI HAY Gen DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Gen PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		printf("INGRESE ID A DAR DE BAJA: ");
		scanf("%d", &idUser);

		//BUSCO INDEX POR ID EN ARRAY
		while (User_BuscarPorID(array, TAM, idUser) == -1) {
			puts("NO EXISTE ID.");

			/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
			printf("INGRESE ID A DAR DE BAJA: ");
			scanf("%d", &idUser);
		}

		//OBTENGO INDEX DEL ARRAY DE Gen A MODIFICAR
		index = User_BuscarPorID(array, TAM, idUser);

		//LLAMO A FUNCION QUE MODIFICA Gen
		auxiliar = User_ModificarUno(array[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		array[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}

int User_Sort(Usuario array[], int TAM, int criterio) {
	int rtn = 0;
	int i;
	int j;
	Usuario aux;

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


