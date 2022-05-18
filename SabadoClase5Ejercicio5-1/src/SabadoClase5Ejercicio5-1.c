#include "Hashtag.h"
#include "Posteo.h"
#include "Usuario.h"
#define TAM_Usr 10000
#define TAM_Posteo 10000
#define TAM_Ref 10000

int main(void) {
	setbuf(stdout, NULL);

	int opc;
	int criterioDeOrdenamiento;

	//CREO ARRAY DE ESTRUCTURA
	eUsuario User[TAM_Usr];
	ePosteo Post[TAM_Posteo];
	eHashtag Ref[TAM_Ref];


	//INICIALIAZO ARRAY DE ESTRUCTURA
	eUsuario_hcUsuarios(User, TAM_Usr);
	ePosteo_hcPosteo(Post, TAM_Posteo);
	eHashtag_hcRef(Red, TAM_Ref);

	//BUCLE DE MENU
	do {
		//MENU PRINT
		//Menu();
		printf("INGRESE OPCION: ");
		scanf("%d", &opc);

		//MENU SWITCH
		switch (opc)
		{
		case 0:
			/** PREGUNTAR SI DESEA SALIR */
			opc = 0;
			break;
		case 1:
			//ALTA
			if (eGen_Alta(Gen, TAM_Usr)) {
				puts(" * Gen DADO DE ALTA EXITOSAMENTE");
			} else {
				puts(" * ERROR. SIN ESPACIO PARA ALMACENAR MAS Gen");
			}
			system("pause");
			break;
		case 2:
			//BAJA
			if (eGen_Baja(Gen, TAM_Usr)) {
				puts("\n * BAJA DE Gen EXITOSA");
				eGen_MostrarTodos(Gen, TAM_Usr);
			} else {
				puts("\n * BAJA DE Gen CANCELADA");
			}
			system("pause");
			break;
		case 3:
			//MODIFICACION
			if (eGen_Modificacion(Gen, TAM_Usr)) {
				puts("\n * MODIFICACION DE Gen EXITOSA\n");
				eGen_MostrarTodos(Gen, TAM_Usr);
			} else {
				puts("\n * MODIFICACION DE Gen CANCELADA");
			}
			system("pause");
			break;
		case 4:
			//LISTADO Producto
			if(eGen_MostrarTodos(Gen, TAM_Usr)){
				system("pause");
			}else{
				puts("No hay nada para mostrar pa");
			}

			break;
		case 5:
			//ORDENAR Producto
			criterioDeOrdenamiento = -1; //PEDIR CRITERIO DE ORDENAMIENTO
			eGen_Sort(Gen, TAM_Usr, criterioDeOrdenamiento);
			system("pause");
			break;
		}
	} while (opc != 0);

	puts("\n... FIN PROGRAMA");

	return 0;
}
