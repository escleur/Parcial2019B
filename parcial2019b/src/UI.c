/*
 * UI.c
 *
 *  Created on: Oct 5, 2019
 *      Author: Sanjurjo Gabriel
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "UI.h"
#include "Cliente.h"
#include "Pedido.h"


int cliente_UIAlta(Cliente *list, int len)
{
	Cliente buffer;
	int step = 0;
	int retorno = -1;
	printf("Alta de clientes\n");
	do
	{
		switch(step){
		case 0:
			if (cliente_BuscarLugarLibre(list, len) == -1)
			{
				printf("Error no hay mas lugar para pantallas\n");
				step = 100;
			}
			else
			{
				step++;
			}
			break;
		case 1:
			if (getNombre(buffer.nombre, "Ingrese el nombre\n", "Error", 1,
					49, 2) == -1) {
				printf("Error en el nombre\n");
				step = 100;
			}
			else
			{
				step++;
			}
			break;
		case 2:
			if (getCuil(buffer.cuit, "Ingrese el cuit\n",
					"Error", 1, 49, 2) == -1) {
				printf("Error en el cuit\n");
				step = 100;
			}
			else
			{
				step++;
			}
			break;
		case 3:
			if (getString(buffer.direccion, "Ingrese la direccion\n",
					"Error", 1, 49, 2) == -1) {
				printf("Error en la direccion\n");
				step = 100;
			}
			else
			{
				step++;
			}
			break;
		case 4:
			if (getString(buffer.localidad, "Ingrese la localidad\n",
					"Error", 1, 49, 2) == -1) {
				printf("Error en la localidad\n");
				step = 100;
			}
			else
			{
				step++;
			}
			break;
		case 5:
			if (cliente_AltaPorId(list, len, buffer) == 0) {
				printf("Alta exitosa\n");
				retorno = 0;
			} else {
				printf("Error al hacer el alta\n");
			}
			step = 100;
			break;
		}
	}while(step!=100);
	return retorno;
}

int cliente_UIModificacion(Cliente *list, int len)
{
	int step = 0;
	int retorno = -1;
	Cliente buffer;
	printf("Modificacion de pantallas\n");
	getInt(&buffer.id,"Ingrese el id para modificar\n","Error\n",0,100000,2);

	if (cliente_GetPorId(list, len, &buffer) == -1) {
		printf("Error el id no existe\n");
	}
	else
	{
		do{
			printf("1. Modificar direccion\n"
					"2. Modificar localidad\n"
					"9. Guardar\n"
					"0. Cancelar\n");
			getInt(&step, "Ingrese la opcion 0 a 9\n", "Error", 0, 9, 2);
			switch(step){
			case 0:
				printf("Cancelado por usuario\n");
				step = 100;
				break;
			case 1:
				if (getString(buffer.direccion, "Ingrese la direccion\n", "Error", 1,
						49, 2) == -1) {
					printf("Error en la direccion\n");
					step = 100;
				}
				break;
			case 2:
				if (getString(buffer.localidad, "Ingrese la localidad\n",
						"Error", 1, 49, 2) == -1) {
					printf("Error en la localidad\n");
					step = 100;
				}
				break;
			case 9:
				if (cliente_ModificarPorId(list, len, buffer) == 0) {
					printf("Modificacion exitosa\n");
					retorno = 0;
				} else {
					printf("Error al hacer la modificacion\n");
				}
				step = 100;
			}
		}while(step!=100);
	}
	return retorno;
}

int cliente_UIBaja(Cliente *list, int len)
{
	int id;
	int retorno = -1;
	char conf;
	printf("Baja\n");
	getInt(&id,"Ingrese el id para dar de baja\n","Error\n",0,100000,2);
	getChar(&conf,"Ingrese s para confirmar la baja\n","Error\n",'a', 'z', 2);
	if(conf=='s'){
		if(cliente_BajaPorId(list,len,id)==0){
			printf("Baja exitosa\n");
			retorno = 0;
		}else{
			printf("Error al dar baja, verifique que el id existe\n");
		}
	}
	return retorno;
}

/************************************************pedido*****************************************/


int pedido_UIAlta(Pedido *list, int len, Cliente *list2, int len2)
{
	Pedido buffer;
	int step = 0;
	int retorno = -1;
	printf("Alta de musico\n");
	do
	{
		switch(step){
		case 0:
			if (pedido_BuscarLugarLibre(list, len) == -1)
			{
				printf("Error no hay mas lugar para pedidos\n");
				step = 100;
			}
			else
			{
				step++;
			}
			break;
		case 1:
			cliente_ImprimirArray(list2, len2);
			if (getInt(&buffer.idCliente, "Ingrese el id de cliente\n", "Error",
					0, 10000000, 2) == -1) {
				printf("Error en el id\n");
				step = 100;
			}
			else
			{
				step++;
			}
			break;
		case 2:
			if (cliente_BuscarPorId(list2, len2, buffer.idCliente) == -1) {
				printf("Error id no existe\n");
				step = 100;
			}
			else
			{
				step++;
			}
			break;

		case 3:
			if (getInt(&buffer.cantidad, "Ingrese la cantidad de plastico en kg\n", "Error", 0,
					10000000, 2) == -1) {
				printf("Error en la cantidad\n");
				step = 100;
			}
			else
			{
				step++;
			}
			break;
		case 4:
			strncpy(buffer.estado, "Pendiente", 50);
			buffer.claseA = 0;
			buffer.claseB = 0;
			buffer.claseC = 0;
			step++;
			break;
		case 5:
			if (pedido_AltaPorId(list, len, buffer) == 0) {
				printf("Alta exitosa\n");
				retorno = 0;
			} else {
				printf("Error al hacer el alta\n");
			}
			step = 100;
			break;
		}
	}while(step!=100);
	return retorno;
}


int pedido_UIModificacion(Pedido *list, int len)
{
	int step = 0;
	int retorno = -1;
	Pedido buffer;
	printf("Modificacion de musico\n");
	pedido_ImprimirArray(list, len);
	getInt(&buffer.id,"Ingrese el id para modificar\n","Error\n",0,100000,2);

	if (pedido_GetPorId(list, len, &buffer) == -1) {
		printf("Error el id no existe\n");
	}
	else
	{
		do{
			printf("1. Modificar plastico HDPE\n"
					"2. Modificar plastico LDPE\n"
					"3. Modificar plastico PP\n"
					"9. Guardar\n"
					"0. Cancelar\n");
			getInt(&step, "Ingrese la opcion 0 a 9\n", "Error", 0, 9, 2);
			switch(step){
			case 0:
				printf("Cancelado por usuario\n");
				step = 100;
				break;
			case 1:
				if (getInt(&buffer.claseA, "Ingrese la cantidad de plastico HDPE\n", "Error",
						0, 1000000, 2) == -1) {
					printf("Error en la cantidad\n");
					step = 100;
				}
				break;
			case 2:
				if (getInt(&buffer.claseB, "Ingrese la cantidad de plastico LDPE\n", "Error",
						0, 1000000, 2) == -1) {
					printf("Error en la cantidad\n");
					step = 100;
				}
				break;
			case 3:
				if (getInt(&buffer.claseC, "Ingrese la cantidad de plastico PP\n", "Error",
						0, 1000000, 2) == -1) {
					printf("Error en la cantidad\n");
					step = 100;
				}
				break;
			case 9:
				strncpy(buffer.estado, "Completado",50);
				if (pedido_ModificarPorId(list, len, buffer) == 0) {
					printf("Modificacion exitosa\n");
					retorno = 0;
				} else {
					printf("Error al hacer la modificacion\n");
				}
				step = 100;
			}
		}while(step!=100);
	}
	return retorno;
}

