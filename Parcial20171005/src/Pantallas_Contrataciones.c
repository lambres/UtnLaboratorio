#include "Pantallas_Contrataciones.h"

int sapo_AltaDeContratacion(ePantalla arrayPantalla[], int TAM_PANTALLA,
		eContrataciones arrayContrataciones[], int TAM_CONTRATACIONES) {
	int rtn = 0;
	int idBuscar;
	int indexPantalla;
	int indexContratacionesLibre;
	eContrataciones aux;

	if (arrayPantalla != NULL) {
		if (arrayContrataciones != NULL) {
			if (TAM_PANTALLA >= 0 || TAM_CONTRATACIONES >= 0) {

				indexContratacionesLibre = eContrataciones_ObtenerIndexLibre(arrayContrataciones, TAM_CONTRATACIONES);
				//VALIDO QUE MI ARRAY DE CONTRATACIONES TENGA ESPACIO
				if (indexContratacionesLibre != -1) {

					//LISTAR PANTALLAS
					if (ePantalla_MostrarTodos(arrayPantalla, TAM_PANTALLA)) {

						//OBTENER ID - INDEX ARRAY
						utn_getNumeroInt(&idBuscar, "Ingrese ID de pantalla: \n", "Error \n", 0, TAM_PANTALLA, 2);
						//idBuscar = Get_Int("Ingrese ID de pantalla: ", "Error. Reingrese. ");
						indexPantalla = ePantalla_BuscarPorID(arrayPantalla, TAM_PANTALLA, idBuscar);

						//SI LOGRE ENCONTRAR EL INDEX
						if (indexPantalla != -1) {
							//DOY DE ALTA UNA CONTRATACIONES
							aux = eContrataciones_CargarDatos();
							aux.FK_idPantalla = arrayPantalla[indexPantalla].idPantalla; //RELACION DE CONTRATACION A PANTALLA
							aux.isEmpty = OCUPADO;

							//VUELVO AUXILIAR EN ARRAY
							arrayContrataciones[indexContratacionesLibre] = aux;

							rtn = 1;
						}
					}
				}
			} else {
				rtn = -3;
			}
		} else {
			rtn = -2;
		}
	} else {
		rtn = -1;
	}
	return rtn;
}
