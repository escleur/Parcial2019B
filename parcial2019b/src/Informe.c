/*
 * Informe.c
 *
 *  Created on: Oct 11, 2019
 *      Author: gabriel
 */
#include "Informe.h"


/**
 * \brief Cuenta los pedidos de un cliente en estado elegido
 * \param list Pedido*
 * \param len int
 * \param idCliente int
 * \return (-1)si puntero NULL o parametros incorrectos (>= 0) cantidad correspondiente
 */

int pedido_contarPorCliente(Pedido *list,int len, int idCliente, char *estado)
{
	int retorno = -1;
	int i;
	int contador = 0;
	if(list != NULL && len >= 0 && idCliente >= 0){
		for(i=0; i<len; i++){
			if(list[i].isEmpty == FALSE && list[i].idCliente == idCliente && strncmp(list[i].estado,estado,50)==0){
				contador++;
			}
		}
		retorno = contador;
	}

	return retorno;
}

/** \brief Imprime los clientes con cantidad de pendientes.
*
*
* \param list Cliente*
* \param len int
* \param list2 Pedido*
* \param len2 int
* \return int Retorna (-1) si Error [longitud invalida o
*  puntero NULL] - (0) si Ok
*
*/
int cliente_ImprimirArrayConPendientes(Cliente *list, int len, Pedido *list2, int len2)
{
	int i;
	int retorno = -1;
	if(list != NULL && len>0)
	{
		retorno = 0;
		printf("id     Nombre    Cuit    Direccion   Localidad     Cantidad de Pendientes\n");
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE){
				printf("%d -- %s -- %s -- %s -- %s -- %d \n",list[i].id,list[i].nombre,list[i].cuit,list[i].direccion,list[i].localidad,pedido_contarPorCliente(list2, len2, list[i].id,"Pendiente"));
			}

		}
	}
	return retorno;
}


/** \brief Imprime los pedidos pendientes.
*
* \param list Cliente*
* \param len int
* \param list2 Pedido*
* \param len2 int
* \return int Retorna (-1) si Error [longitud invalida o
*  puntero NULL] - (0) si Ok
*
*/
int pedido_ImprimirArrayPendiente(Cliente *list, int len, Pedido *list2, int len2)
{
	int i;
	int retorno = -1;
	Cliente buffer;
	if(list != NULL && len>0)
	{
		retorno = 0;
		printf("Cuit    Direccion    Cantidad \n");
		for(i=0;i<len2;i++)
		{
			if(list2[i].isEmpty == FALSE
					&& strncmp(list2[i].estado,"Pendiente", 50) == 0 ){
				buffer.id = list2[i].idCliente;
				cliente_GetPorId(list, len, &buffer);
				printf("%s -- %s -- %d \n",buffer.cuit,buffer.direccion,list2[i].cantidad);
			}

		}
	}
	return retorno;
}
/** \brief Imprime los pedidos procesados.
*
* \param list Cliente*
* \param len int
* \param list2 Pedido*
* \param len2 int
* \return int Retorna (-1) si Error [longitud invalida o
*  puntero NULL] - (0) si Ok
*
*/
int pedido_ImprimirArrayProcesado(Cliente *list, int len, Pedido *list2, int len2)
{
	int i;
	int retorno = -1;
	Cliente buffer;
	if(list != NULL && len>0)
	{
		retorno = 0;
		printf("Cuit    Direccion    Plastico HDPE     Plastico LDPE     Plastico PP \n");
		for(i=0;i<len2;i++)
		{
			if(list2[i].isEmpty == FALSE
					&& strncmp(list2[i].estado,"Completado", 50) == 0 ){
				buffer.id = list2[i].idCliente;
				cliente_GetPorId(list, len, &buffer);
				printf("%s -- %s -- %d -- %d -- %d \n",buffer.cuit,buffer.direccion,list2[i].claseA,list2[i].claseB,list2[i].claseC);
			}

		}
	}
	return retorno;
}
/*-------------------------------------Informes------------------------------------------*/



/** \brief Imprime el cliente con mas cantidad de pedidos pendientes.
*
* \param list Cliente*
* \param len int
* \param list2 Pedido*
* \param len2 int
* \return int Retorna (-1) si Error [longitud invalida o
*  puntero NULL] - (0) si Ok
*
*/
int cliente_ConMasPedidosPendientes(Cliente *list, int len, Pedido *list2, int len2)
{
	int i;
	int retorno = -1;
	int flagPrimero = 1;
	int cantidadPedidos;
	int maximoPedidos=0;
	Cliente clienteMaximo;
	if(list != NULL && len>0 && list2 != NULL && len2 > 0)
	{
		retorno = 0;
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE){
				cantidadPedidos = pedido_contarPorCliente(list2, len2, list[i].id,"Pendiente");
				if(flagPrimero){
					maximoPedidos = cantidadPedidos;
					clienteMaximo = list[i];
					flagPrimero = 0;
				}else if(maximoPedidos < cantidadPedidos){
					maximoPedidos = cantidadPedidos;
					clienteMaximo = list[i];
				}

			}

		}
		printf("id     Nombre    Cuit    Direccion   Localidad     Cantidad de Pendientes\n");
		printf("%d -- %s -- %s -- %s -- %s -- %d \n",clienteMaximo.id,clienteMaximo.nombre,clienteMaximo.cuit,clienteMaximo.direccion,clienteMaximo.localidad,maximoPedidos);
	}
	return retorno;
}


/** \brief Imprime el cliente con mas cantidad de pedidos completados.
*
* \param list Cliente*
* \param len int
* \param list2 Pedido*
* \param len2 int
* \return int Retorna (-1) si Error [longitud invalida o
*  puntero NULL] - (0) si Ok
*
*/
int cliente_ConMasPedidosCompletados(Cliente *list, int len, Pedido *list2, int len2)
{
	int i;
	int retorno = -1;
	int flagPrimero = 1;
	int cantidadPedidos;
	int maximoPedidos=0;
	Cliente clienteMaximo;
	if(list != NULL && len>0 && list2 != NULL && len2 > 0)
	{
		retorno = 0;
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE){
				cantidadPedidos = pedido_contarPorCliente(list2, len2, list[i].id,"Completado");
				if(flagPrimero){
					maximoPedidos = cantidadPedidos;
					clienteMaximo = list[i];
					flagPrimero = 0;
				}else if(maximoPedidos < cantidadPedidos){
					maximoPedidos = cantidadPedidos;
					clienteMaximo = list[i];
				}

			}

		}
		printf("id     Nombre    Cuit    Direccion   Localidad     Cantidad de Pedidos completados\n");
		printf("%d -- %s -- %s -- %s -- %s -- %d \n",clienteMaximo.id,clienteMaximo.nombre,clienteMaximo.cuit,clienteMaximo.direccion,clienteMaximo.localidad,maximoPedidos);
	}
	return retorno;
}

/** \brief Imprime el cliente con mas cantidad de pedidos completados.
*
* \param list Cliente*
* \param len int
* \param list2 Pedido*
* \param len2 int
* \return int Retorna (-1) si Error [longitud invalida o
*  puntero NULL] - (0) si Ok
*
*/
int cliente_ConMasPedidos(Cliente *list, int len, Pedido *list2, int len2)
{
	int i;
	int retorno = -1;
	int flagPrimero = 1;
	int cantidadPedidos;
	int maximoPedidos=0;
	Cliente clienteMaximo;
	if(list != NULL && len>0 && list2 != NULL && len2 > 0)
	{
		retorno = 0;
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE){
				cantidadPedidos = pedido_contarPorCliente(list2, len2, list[i].id,"Completado") + pedido_contarPorCliente(list2, len2, list[i].id,"Pendiente");
				if(flagPrimero){
					maximoPedidos = cantidadPedidos;
					clienteMaximo = list[i];
					flagPrimero = 0;
				}else if(maximoPedidos < cantidadPedidos){
					maximoPedidos = cantidadPedidos;
					clienteMaximo = list[i];
				}

			}

		}
		printf("id     Nombre    Cuit    Direccion   Localidad     Cantidad de Pedidos\n");
		printf("%d -- %s -- %s -- %s -- %s -- %d \n",clienteMaximo.id,clienteMaximo.nombre,clienteMaximo.cuit,clienteMaximo.direccion,clienteMaximo.localidad,maximoPedidos);
	}
	return retorno;
}
/**
 * \brief Cuenta cantidad de reciclado de un cliente en estado elegido
 * \param list Pedido*
 * \param len int
 * \param idCliente int
 * \return (-1)si puntero NULL o parametros incorrectos (>= 0) cantidad correspondiente
 */

int pedido_contarRecicladoPorCliente(Pedido *list,int len, int idCliente)
{
	int retorno = -1;
	int i;
	int acumulador = 0;
	if(list != NULL && len >= 0 && idCliente >= 0){
		for(i=0; i<len; i++){
			if(list[i].isEmpty == FALSE && list[i].idCliente == idCliente && strncmp(list[i].estado,"Completado",50)==0){
				acumulador = list[i].claseA + list[i].claseB + list[i].claseC;
			}
		}
		retorno = acumulador;
	}

	return retorno;
}


/** \brief Imprime el cliente con mas cantidad de reciclado
*
* \param list Cliente*
* \param len int
* \param list2 Pedido*
* \param len2 int
* \return int Retorna (-1) si Error [longitud invalida o
*  puntero NULL] - (0) si Ok
*
*/
int cliente_ConMasReciclado(Cliente *list, int len, Pedido *list2, int len2)
{
	int i;
	int retorno = -1;
	int flagPrimero = 1;
	int cantidadPedidos;
	int maximoPedidos=0;
	Cliente clienteMaximo;
	if(list != NULL && len>0 && list2 != NULL && len2 > 0)
	{
		retorno = 0;
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE){
				cantidadPedidos = pedido_contarRecicladoPorCliente(list2, len2, list[i].id);
				if(flagPrimero){
						maximoPedidos = cantidadPedidos;
						clienteMaximo = list[i];
						flagPrimero = 0;

				}else if(maximoPedidos < cantidadPedidos){
						maximoPedidos = cantidadPedidos;
						clienteMaximo = list[i];
				}
			}

		}
		printf("id     Nombre    Cuit    Direccion   Localidad     Cantidad de kilos reciclados\n");
		printf("%d -- %s -- %s -- %s -- %s -- %d \n",clienteMaximo.id,clienteMaximo.nombre,clienteMaximo.cuit,clienteMaximo.direccion,clienteMaximo.localidad,maximoPedidos);
	}
	return retorno;
}

/** \brief Imprime el cliente con menos cantidad de pedidos completados.
*
* \param list Cliente*
* \param len int
* \param list2 Pedido*
* \param len2 int
* \return int Retorna (-1) si Error [longitud invalida o
*  puntero NULL] - (0) si Ok
*
*/
int cliente_ConMenosReciclado(Cliente *list, int len, Pedido *list2, int len2)
{
	int i;
	int retorno = -1;
	int flagPrimero = 1;
	int cantidadPedidos;
	int minimoPedidos=0;
	Cliente clienteMinimo;
	if(list != NULL && len>0 && list2 != NULL && len2 > 0)
	{
		retorno = 0;
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE){
				cantidadPedidos = pedido_contarRecicladoPorCliente(list2, len2, list[i].id);
				if(flagPrimero){
					if(cantidadPedidos>0){
						minimoPedidos = cantidadPedidos;
						clienteMinimo = list[i];
						flagPrimero = 0;
					}
				}else if(minimoPedidos > cantidadPedidos){
					if(cantidadPedidos>0){
						minimoPedidos = cantidadPedidos;
						clienteMinimo = list[i];
					}
				}

			}

		}
		printf("id     Nombre    Cuit    Direccion   Localidad     Cantidad de kilos reciclados\n");
		printf("%d -- %s -- %s -- %s -- %s -- %d \n",clienteMinimo.id,clienteMinimo.nombre,clienteMinimo.cuit,clienteMinimo.direccion,clienteMinimo.localidad,minimoPedidos);
	}
	return retorno;
}


/** \brief Imprime el cliente con mas de 1000 de reciclado
*
* \param list Cliente*
* \param len int
* \param list2 Pedido*
* \param len2 int
* \return int Retorna (-1) si Error [longitud invalida o
*  puntero NULL] - (0) si Ok
*
*/
int cliente_ConMasDe1000Reciclado(Cliente *list, int len, Pedido *list2, int len2)
{
	int i;
	int retorno = -1;
	int cantidad;
	int contador = 0;
	if(list != NULL && len>0 && list2 != NULL && len2 > 0)
	{
		retorno = 0;
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE){

				cantidad = pedido_contarRecicladoPorCliente(list2, len2, list[i].id);
				if(cantidad>1000){
					contador++;
				}
			}

		}
		printf(" Cantidad clientes que reciclaron mas de 1000 kilos\n");
		printf("%d \n",contador);
	}
	return retorno;
}

/** \brief Imprime el cliente con mas de 1000 de reciclado
*
* \param list Cliente*
* \param len int
* \param list2 Pedido*
* \param len2 int
* \return int Retorna (-1) si Error [longitud invalida o
*  puntero NULL] - (0) si Ok
*
*/
int cliente_ConMenosDe100Reciclado(Cliente *list, int len, Pedido *list2, int len2)
{
	int i;
	int retorno = -1;
	int cantidad;
	int contador = 0;
	if(list != NULL && len>0 && list2 != NULL && len2 > 0)
	{
		retorno = 0;
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE){

				cantidad = pedido_contarRecicladoPorCliente(list2, len2, list[i].id);
				if(cantidad<100 && cantidad > 0){
					contador++;
				}
			}

		}
		printf(" Cantidad clientes que reciclaron menos de 100 kilos\n");
		printf("%d \n",contador);
	}
	return retorno;
}



/** \brief Imprime los pedidos completados y el porcentaje reciclado
*
* \param list Cliente*
* \param len int
* \param list2 Pedido*
* \param len2 int
* \return int Retorna (-1) si Error [longitud invalida o
*  puntero NULL] - (0) si Ok
*
*/
int pedido_CompletadosConPorcentajeReciclado(Cliente *list, int len, Pedido *list2, int len2)
{
	int i;
	int retorno = -1;
	int porcentaje;
	Cliente buffer;
	if(list != NULL && len>0 && list2 != NULL && len2 > 0)
	{
		retorno = 0;
		printf("id de pedido   cuit de cliente   Porcentaje reciclado\n");
		for(i=0;i<len2;i++)
		{
			if(list2[i].isEmpty == FALSE && strncmp(list2[i].estado,"Completado",50)==0){

				buffer.id =  list2[i].idCliente;
				cliente_GetPorId(list, len, &buffer);
				porcentaje = (list2[i].claseA+list2[i].claseB+list2[i].claseC)*100/list2[i].cantidad;
				printf("%d   %s   %d\n",list2[i].id,buffer.cuit,porcentaje );
			}
		}
	}
	return retorno;
}

/** \brief Imprime los pedidos pendientes por localidad
*
* \param list Cliente*
* \param len int
* \param list2 Pedido*
* \param len2 int
* \return int Retorna (-1) si Error [longitud invalida o
*  puntero NULL] - (0) si Ok
*
*/
int pedido_PendientesPorLocalidad(Cliente *list, int len, Pedido *list2, int len2)
{
	int i;
	int retorno = -1;
	int acumulador = 0;

	Cliente buffer;
	if(list != NULL && len>0 && list2 != NULL && len2 > 0)
	{
		if (getString(buffer.localidad, "Ingrese la localidad\n",
				"Error", 1, 49, 2) == -1) {
			printf("Error en la localidad\n");
		}else{
			retorno = 0;
			printf("Cantidad de pedidos pendientes en la localidad\n");
			for(i=0;i<len;i++)
			{
				if(list[i].isEmpty == FALSE && strncmp(list[i].localidad,buffer.localidad,50)==0){
					acumulador += pedido_contarPorCliente(list2, len2, list[i].id,"Pendiente");

				}
			}
			printf("%d\n",acumulador );

		}
	}
	return retorno;
}
/** \brief Imprime el promedio de polipropileno por cliente
*
* \param list Cliente*
* \param len int
* \param list2 Pedido*
* \param len2 int
* \return int Retorna (-1) si Error [longitud invalida o
*  puntero NULL] - (0) si Ok
*
*/
int cliente_PPPromedio(Cliente *list, int len, Pedido *list2, int len2)
{
	int i;
	int retorno = -1;
	int acumulador = 0;
	int contador = 0;
	if(list != NULL && len>0 && list2 != NULL && len2 > 0)
	{
		retorno = 0;
		printf("Promedio de polipropileno por cliente\n");
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE){

				acumulador += pedido_PlasticoPorCliente(list2, len2, list[i].id, 3);
				contador++;
			}
		}
		printf("%d\n",acumulador/contador );

	}
	return retorno;
}

/**
 * \brief Cuenta cantidad de reciclado de una de las 3 clases de plastico por cliente
 * \param list Pedido*
 * \param len int
 * \param idCliente int
 * \return (-1)si puntero NULL o parametros incorrectos (>= 0) cantidad correspondiente
 */

int pedido_PlasticoPorCliente(Pedido *list,int len, int idCliente, int clase)
{
	int retorno = -1;
	int i;
	int acumulador = 0;
	if(list != NULL && len >= 0 && idCliente >= 0 && clase >=1 && clase <= 3){
		for(i=0; i<len; i++){
			if(list[i].isEmpty == FALSE && list[i].idCliente == idCliente && strncmp(list[i].estado,"Completado",50)==0){
				switch(clase){
				case 1:
					acumulador += list[i].claseA;
					break;
				case 2:
					acumulador += list[i].claseB;
					break;
				case 3:
					acumulador += list[i].claseC;
				}
			}
		}
		retorno = acumulador;
	}

	return retorno;
}

/** \brief Imprime el promedio de polipropileno por cliente
*
* \param list Cliente*
* \param len int
* \param list2 Pedido*
* \param len2 int
* \return int Retorna (-1) si Error [longitud invalida o
*  puntero NULL] - (0) si Ok
*
*/
int cliente_CantidadDePlasticoReciclado(Cliente *list, int len, Pedido *list2, int len2)
{
	int retorno = -1;
	char cuit[50];
	int clase;
	int index;
	if(list != NULL && len>0 && list2 != NULL && len2 > 0)
	{
		if (getCuil(cuit, "Ingrese el cuit\n",
				"Error", 1, 49, 2) == -1) {
			printf("Error en el cuit\n");
		}else{
			if(cliente_BuscarPorCuit(list, len, cuit)== -1)
			{
				printf("Error el cuit no existe\n");
			}else{
				if(getInt(&clase,"Ingrese el plastico a mostrar 1. HDPE 2. LDPE 3. PP4", "Error",1,3,2)== -1){
					printf("Error al elejir el plastico");
				}else{
					retorno = 0;
					index = cliente_BuscarPorCuit(list, len, cuit);
					printf("Plastico reciclado por cliente\n");
					printf("%dkg\n ",pedido_PlasticoPorCliente(list2, len2, list[index].id, clase));

				}

			}

		}
	}
	return retorno;
}
