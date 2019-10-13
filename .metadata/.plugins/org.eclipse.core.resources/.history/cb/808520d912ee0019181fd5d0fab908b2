/*
 * Pantalla.h
 *
 *  Created on: 17 sep. 2019
 *      Author: Sanjurjo Gabriel
 */

#ifndef PEDIDO_H_
#define PEDIDO_H_

#define QTY_PEDIDOS 20
#define QTY_CARACTERES 50

#define FALSE 0
#define TRUE 1

typedef struct
{
	int id;
	int isEmpty;
	//***************
	int cantidad;
	char estado[50];
	int claseA;
	int claseB;
	int claseC;
	int idCliente;
} Pedido;

int pedido_InitLugarLibre(Pedido *list, int len);

int pedido_ImprimirArray(Pedido *list, int len);
int pedido_OrdenarArray(Pedido *list, int len, int orden);

int pedido_BuscarLugarLibre(Pedido *list, int len);
int pedido_BuscarPorId(Pedido *list, int len,int id);
int pedido_AltaPorId(Pedido *list, int len, Pedido item);
int pedido_BajaPorId(Pedido *list, int len,int id);
int pedido_ModificarPorId(Pedido *list, int len,Pedido item);
int pedido_GetPorId(Pedido *list, int len, Pedido *buffer);

#endif /* PEDIDO_H_ */
