/*
 * Pantalla.h
 *
 *  Created on: 17 sep. 2019
 *      Author: Sanjurjo Gabriel
 */

#ifndef CLIENTES_H_
#define CLIENTES_H_

#define QTY_CLIENTES 100
#define QTY_CARACTERES 50

#define TRUE 1
#define FALSE 0

typedef struct
{
	int id;
	int isEmpty;
	//***************
	char nombre[50];
	char direccion[50];
	char cuit[50];
	char localidad[50];
} Cliente;

int cliente_InitLugarLibre(Cliente *list, int len);

int cliente_ImprimirArray(Cliente *list, int len);
int cliente_OrdenarArray(Cliente *list, int len, int orden);

int cliente_BuscarLugarLibre(Cliente *list, int len);
int cliente_BuscarPorId(Cliente *list, int len,int id);
int cliente_BuscarPorCuit(Cliente *list, int len,char *cuit);
int cliente_AltaPorId(Cliente *list, int len, Cliente item);
int cliente_BajaPorId(Cliente *list, int len,int id);
int cliente_ModificarPorId(Cliente *list, int len,Cliente item);
int cliente_GetPorId(Cliente *list, int len, Cliente *buffer);

#endif
