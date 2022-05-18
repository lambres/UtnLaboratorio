#include <stdio.h>
#include <stdlib.h>
#include "Usuario.h"
#include "Producto.h"
#include "Tracking.h"
#include "utn.h"
#include "Track_Prod.h"
#define TAM_USUARIO 200
#define TAM_PRODUCTO 1000
#define TAM_TRACKING 1000

int main(void) {
	#ifdef _WIN32
		LIMPIAR_SALIDA
	#endif


	int opc;
	int opc2;
	char opc4;
	int indexCurrentUser;
	int indexVendedor;
	int indexProdEncontrado;
	int idProdEncontrado;
	int indexTrackEncontrado;
	int auxCantidad;
	int nuevoStock;
	float auxTotCompra;
	int auxIDVendedor;
	int auxCodPostal;
	char confirmaCompra;
	int auxKm;
	int respuesta;
	char nombreBuscar[LEN_PRODUCTNAME];
	Usuario auxUser;
	Tracking auxTracking;

	Usuario User[TAM_USUARIO]={{0,OCUPADO,ADMIN,"lambres@gmail.com","123","Pichincha 2176",1824},
								{1,OCUPADO,USUARIO,"a@a.a","123","Pichincha 2176",1004},
								{2,OCUPADO,USUARIO,"b@b.b","123","Pichincha 2176",5002}};


	Producto Prod[TAM_PRODUCTO]={{100,OCUPADO,"Tv 32\"",20000,3,10,1},
									{101,OCUPADO,"Batidora Orbital",10000,3,20,1},
									{102,OCUPADO,"Taladro percutor",5000,4,5,2},
									{105,OCUPADO,"Taladro percutor",5000,4,5,2},
									{103,OCUPADO,"Bordeadora Skill",3000,4,10,1},
									{104,OCUPADO,"Bolsa Cemento x 50 Kg",200,5,200,2}};

	Tracking Track[TAM_TRACKING];

	//INICIALIAZO ARRAY DE USUARIO
									// descomentar luego de pruebas
	//User_Inicializar(User, TAM_USUARIO);
	//INICIALIAZO ARRAY DE PRODUCTOS
									// descomentar luego de pruebas
	//Prod_Inicializar(Prod, TAM_PRODUCTO);

	Track_Inicializar(Track, TAM_TRACKING);
	//BUCLE DE MENU
	do {
		//MENU PRINT
		puts("\n****************************");
		puts("** 1er EXAMEN LAB I - 1H ***");
		puts("****************************");
		puts("\n1) INGRESAR");
		puts("2) REGISTRARSE");
		puts("\n0) SALIR");
		printf("INGRESE OPCION: ");

		utn_getNumeroInt(&opc, "INGRESE OPCION", "OPCION NO VALIDA", 0, 2, 2);

		//MENU SWITCH
		switch (opc)
		{
		case 0:
			/** PREGUNTAR SI DESEA SALIR */
			puts("Esta seguro que desea salir? s/n\n");
			if (verifica()=='S')
			{
				opc = 0;
			}
			else
			{
				opc = 1;
			}
			break;
		case 1:
			//INGRESAR: Se ingresara pidiendo usuario y contraseña, validando la existencia del mismo.
			puts("\n****************************");
			puts("******* MENU LOGUEO ********");
			puts("****************************");
			if(utn_getEmail(auxUser.correo, LEN_CORREO, "MAIL:", "ERROR! REINTENTE", 2)==0)
			{
				indexCurrentUser = User_BuscarPorEmail(User,LEN_CORREO,auxUser.correo);
				if(indexCurrentUser!=-1)
				{
					printf("USUARIO ENCONTRADO %s\n", User[indexCurrentUser].correo);
					if(utn_getTexto(auxUser.password, LEN_PWD, "PASSWORD?:", "ERROR! REINTENTE", 0)==0)
					{
						if(strncmp(auxUser.password,User[indexCurrentUser].password,LEN_PWD)==0)
						{
							printf("BIENVENIDO %s\n", User[indexCurrentUser].correo);
							if(User[indexCurrentUser].tipo == ADMIN)
							{
								do
								{
									puts("\n***************************");
									puts("** 1er EXAMEN LAB I - 1H **");
									puts("********** ADMIN **********");
									puts("***************************");
									puts("\n\tGESTION DE INFORMES");
									puts("\n1) LISTAR ESTADO DE TODOS LOS USUARIOS");
									puts("2) LISTAR TODOS LOS PRODUCTOS POR CATEGORIA");
									puts("3) BAJA DE UN PRODUCTO");
									puts("4) BAJA DE UN USUARIO");
									puts("5) VER TRACKING GLOBAL");
									puts("6) FILTRAR POR NOMBRE DE PRODUCTO");
									puts("\n0) SALIR");
									utn_getNumeroInt(&opc2, "INGRESE OPCION", "OPCION NO VALIDA", 0, 6, 2);
									switch(opc2)
									{
									case 0://SALIR
										break;
									case 1://LISTAR ESTADO DE TODOS LOS USUARIOS
										User_Sort(User, TAM_USUARIO, -1);
										User_MostrarTodos(User, TAM_USUARIO);
										break;
									case 2://LISTAR TODOS LOS PRODUCTOS POR CATEGORIA
										if(Prod_Sort(Prod, TAM_PRODUCTO, 1)==1)
										{
											Prod_MostrarTodos(Prod, TAM_PRODUCTO);
										}
										else
										{
											puts("No hay productos cargados");
										}
										break;
									case 3://BAJA DE UN PRODUCTO
										Prod_Sort(Prod, TAM_PRODUCTO, -1);
										Prod_Baja(Prod, TAM_PRODUCTO);
										break;
									case 4://BAJA DE UN USUARIO
										User_Sort(User, TAM_USUARIO, -1);
										User_Baja(User, TAM_USUARIO);
										break;
									case 5://VER TRACKING GLOBAL
										Track_Sort(Track, TAM_TRACKING, -1);
										Track_ActualizoEstado(Track,TAM_TRACKING);
										Track_MostrarTodos(Track, TAM_TRACKING);
										break;
									case 6:
										Track_Sort(Track, TAM_TRACKING, -1);
										utn_getTexto(nombreBuscar, LEN_PRODUCTNAME, "NOMBRE PRODUCTO?:", "ERROR! REINGRESE", 2);
										Prod_MostrarFiltroNombre(Prod, TAM_PRODUCTO, nombreBuscar,LEN_PRODUCTNAME);
										break;
									}
								}while (opc2 != 0);
							}
							else
							{
								do
								{
									puts("\n***************************");
									puts("** 1er EXAMEN LAB I - 1H **");
									puts("********* USUARIO *********");
									puts("***************************");
									puts("\n1) COMPRAR");
									puts("2) VENDER");
									puts("3) ESTADO DE COMPRAS");
									puts("4) ESTADO DE VENTAS");
									puts("\n0) SALIR");
									utn_getNumeroInt(&opc2, "INGRESE OPCION?:", "ERROR!", 0, 4, 2);
									switch (opc2)
									{
									case 0://SALIR"
										break;
									case 1://COMPRAR
										//-----------------------------------------------------------
										//Se listaran todos los productos disponibles para comprar ordenados por categorÃ­a.
											Prod_Sort(Prod,TAM_PRODUCTO,-1);
											if(Prod_MostrarTodos(Prod, TAM_PRODUCTO)==1)
											{
												//Luego se seleccionarÃ¡ el ID del producto a comprar
												utn_getNumeroInt(&idProdEncontrado, "ID?:", "ERROR! REINGRESE", 0, TAM_PRODUCTO, 2);
												indexProdEncontrado=Prod_BuscarPorID(Prod, TAM_PRODUCTO, idProdEncontrado);
												if (indexProdEncontrado!=-1)
												{
													//se le pedirÃ¡ la cantidad a adquirir (se restarÃ¡ del stock)
													if(utn_getNumeroInt(&auxCantidad, "CANTIDAD?:", "ERROR! CANTIDAD INSUFICIENTE REINGRESE", 0, Prod[indexProdEncontrado].stock, 2)==0)
													{
														nuevoStock = Prod[indexProdEncontrado].stock - auxCantidad;
													}
													//se informarÃ¡ al usuario el total de su compra
													auxTotCompra = auxCantidad * Prod[indexProdEncontrado].precio;
													printf("EL IMPORTE DE LA COMPRA ES DE %.2f \n", auxTotCompra);
													printf("CONFIRMA COMPRA?\n");
													confirmaCompra = verifica();
													if (confirmaCompra == 'S')
													{
														auxIDVendedor = Prod[idProdEncontrado].FKidUsuario;
														indexVendedor = User_BuscarPorID(User, TAM_USUARIO, auxIDVendedor);
														auxCodPostal = User[indexVendedor].codPostal;
														if (auxCodPostal < 1001) //20 seg  / 10 km -> 2seg/km
														{
															auxKm = 20;
														}
														else
														{
															if (auxCodPostal<3001)
															{
																auxKm = 30;
															}
															else
															{
																if (auxCodPostal<5001)
																{
																	auxKm = 50;
																}
																else
																{
																	if (auxCodPostal<8001)
																	{
																		auxKm = 80;
																	}
																	else
																	{
																		auxKm = 150;
																	}
																}
															}
														}
														//comprador = usuario
														//vendedor id vendedor del id
														auxTracking.FKidUsuarioComprador=User[indexCurrentUser].idUsuario;
														auxTracking.FKidUsuarioVendedor=User[indexVendedor].idUsuario;
														auxTracking.cantidad = auxCantidad;
														auxTracking.distanciaKM=auxKm;
														auxTracking.horaLlegada=time_Add(2*auxKm);
														auxTracking.FKidProducto=Prod[indexProdEncontrado].idProducto;
														Prod[indexProdEncontrado].stock =nuevoStock;
														if ( nuevoStock == 0)
														{
															Prod[indexProdEncontrado].isEmpty = BAJA;
														}
														Track_AltaConDatos(Track, TAM_TRACKING, auxTracking);
													}
												}
												else
												{
													puts("ID NO ENCONTRADO; VUELVA A INTENTAR.");
												}

											}
										break;
									case 2://VENDER
										//ALTA DE PRODUCTO. Se listarán las categorías al momento de dar de alta.
										utn_getCaracter(&opc4, "A) ALTA DE PRODUCTO\nB) REPONER STOCK\n", "ERROR! REINGRESE", 'A', 'B', 2);
										switch (opc4)
										{
										case 'A':
											Prod_Alta(Prod, TAM_PRODUCTO, User[indexCurrentUser].idUsuario);
											Prod_MostrarTodos(Prod, TAM_PRODUCTO);
											break;
										case 'B':
											Prod_Modificacion(Prod, TAM_PRODUCTO, User[indexCurrentUser].idUsuario);
											break;
										}
										break;
									case 3://ESTADO DE COMPRAS
										//Actualizar el estado de los productos cada vez que se consulte un tracking
										Track_Sort(Track, TAM_TRACKING, -1);
										Track_ActualizoEstado(Track,TAM_TRACKING);
										TU_MostrarTodos(Track, TAM_TRACKING,Prod,TAM_PRODUCTO,indexCurrentUser);
										if(utn_getNumeroInt(&respuesta, "0) SALIR\n1) CANCELAR COMPRA", "ERROR!", 0, 1, 2)==0)
										{
											if(respuesta == 1)
											{
												TU_MostrarEnViaje(Track, TAM_TRACKING,Prod,TAM_PRODUCTO,indexCurrentUser);
												utn_getNumeroInt(&indexTrackEncontrado, "ID?:", "ERROR! REINGRESE", 0, TAM_PRODUCTO, 2);
												indexTrackEncontrado=Track_BuscarPorID(Track, TAM_TRACKING, indexTrackEncontrado);
												Track[indexTrackEncontrado].isEmpty=LIBRE;

												indexProdEncontrado=Prod_BuscarPorID(Prod, TAM_PRODUCTO, Track[indexTrackEncontrado].FKidProducto);
												Prod[indexProdEncontrado].stock=Prod[indexProdEncontrado].stock+Track[indexTrackEncontrado].cantidad;
											}
										}
										break;
									case 4://ESTADO DE VENTAS
										// Actualizar el estado de los productos cada vez que se
										//consulte el tracking
										Track_Sort(Track, TAM_TRACKING, -1);
										Track_ActualizoEstado(Track,TAM_TRACKING);
										// En este listado estar�n todas las ventas para el usuario logueado que hayan
										//finalizado. Estados ENTREGADO - CANCELADO.
										utn_getCaracter(&opc4, "A) LISTADO DE VENTAS FINALIZADAS\nB) VER PRODUCTOS\n", "ERROR! REINGRESE", 'A', 'B', 2);
										if(opc4=='A')
										{
											TU_MostrarVentasFinalizadas(Track, TAM_TRACKING, Prod, TAM_PRODUCTO, indexCurrentUser);
										}
										else
										{
											//Se listar�n todos los productos que el usuario logueado a�n tenga STOCK con
											//toda su informaci�n (Si es que tiene productos en venta)
											Prod_MostrarTodosConSaldo(Prod, TAM_PRODUCTO, User[indexCurrentUser].idUsuario);
										}
										break;
									}
								}while (opc2 != 0);
							}
						}
						else
						{
							printf("Intente Nuevavente\n");
						}
					}
				}
				else
				{
					printf("Usuario No Encontado\n");
				}
			}
			break;
		case 2:
			//REGISTRARSE: ALTA DE USUARIO.	VALIDANDO EL FORMATO DE TODOS SUS CAMPOS.
			if (User_Alta(User, TAM_USUARIO))
			{
				puts(" * User DADO DE ALTA EXITOSAMENTE");
			}
			else
			{
				puts(" * ERROR. SIN ESPACIO PARA ALMACENAR MAS User");
			}

			break;
		}
	} while (opc != 0);

	puts("\n... Gracias por usar el programa");

	return 0;
}

