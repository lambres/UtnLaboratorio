//INCLUDE
#include "Pantallas_Contrataciones.h"

#define CANT_PANTALLAS 100
#define CANT_CONTRATACIONES 1000

int main() {
	setbuf(stdout, NULL);
	int opcion;

	ePantalla arrayPantallas[CANT_PANTALLAS];
	eContrataciones arrayContrataciones[CANT_CONTRATACIONES];

	//INICIALIZO PANTALLAS
	ePantalla_Inicializar(arrayPantallas, CANT_PANTALLAS);
	//INICIALIZO PANTALLAS
	eContrataciones_Inicializar(arrayContrataciones, CANT_CONTRATACIONES);

	do {
		puts("\t*********************");
		puts("\t* MODELO DE PARCIAL *");
		puts("\t*********************");
		puts(""); //SALTO DE LINEA CHILL
		puts(" 1) ALTA DE PANTALLA");
		puts(" 2) MODIFICAR DATOS DE PANTALLA");
		puts(" 3) BAJA DE PANTALLA");
		puts(" 4) CONTRATAR UNA PUBLICIDAD");
		puts(" 5) MODIFICAR CONDICIONES DE PUBLICACION");
		puts(" 6) CANCELAR CONTRATACIONES");
		puts(" 7) CONSULTAR FACTURACION");
		puts(" 8) LISTAR CONTRATACIONES");
		puts(" 9) LISTAR PANTALLAS");
		puts("10) INFORMAR");
		puts(
				"    A) LISTA DE TODOS LOS CLIENTES CON CANTIDAD DE CONTRATACIONES E IMPORTE");
		puts("    B) CLIENTE CON IMPORTE MAS ALTO A FACTURAR");
		puts(""); //SALTO DE LINEA CHILL
		utn_getNumeroInt(&opcion, "OPC:\n", "Error Reingres OPC\n", 0, 10, 2);
		//opcion = Get_IntRange("OPC: ", "Error. Re ingrese.\nOPC:", 0, 10);

		switch (opcion) {
		case 0:

			if (verifica() == 0) {
				opcion = -1;
			} else {
				puts("\n(._. )! ... Saliendo.");
			}
			break;
		case 1:
			//1) ALTA DE PANTALLA
			if (ePantalla_Alta(arrayPantallas, CANT_PANTALLAS)) {
				puts("ALTA REALIZADA");
			} else {
				puts("ERROR EN ALTA");
			}
			break;
		case 2:
			//2) MODIFICAR DATOS DE PANTALLA
			if (ePantalla_Modificacion(arrayPantallas, CANT_PANTALLAS)) {
				puts("MODIFICACION REALIZADA");
			} else {
				puts("ERROR EN MODIFICACION");
			}
			break;
		case 3:
			//3) BAJA DE PANTALLA
			if (ePantalla_Baja(arrayPantallas, CANT_PANTALLAS)) {
				puts("BAJA REALIZADA");
			} else {
				puts("ERROR EN BAJA");
			}
			break;
		case 4:
			//4) CONTRATAR UNA PUBLICIDAD
			if(sapo_AltaDeContratacion(arrayPantallas, CANT_PANTALLAS, arrayContrataciones, CANT_CONTRATACIONES) == 1){
				puts("ALTA DE CONTRATACIONES EXITOSA");
			}else{
				puts("ALGO PASO (._. )?");
			}
			break;
		case 5:
			//5) MODIFICAR UNA CONTRATACION
			IF(eContrataciones_Modificacion(arrayContrataciones, CANT_CONTRATACIONES){

			}
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			break;
		}

	} while (opcion != 0);
	return 0;
}
