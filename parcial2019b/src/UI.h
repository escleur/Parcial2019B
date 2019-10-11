/*
 * UI.h
 *
 *  Created on: Oct 5, 2019
 *      Author: Sanjurjo Gabriel
 */

#ifndef UI_H_
#define UI_H_
#include "Cliente.h"
#include "Pedido.h"
int cliente_UIAlta(Cliente *list, int len);
int cliente_UIModificacion(Cliente *list, int len);
int cliente_UIBaja(Cliente *list, int len);
int pedido_UIAlta(Pedido *list, int len, Cliente *list2, int len2);
int pedido_UIModificacion(Pedido *list, int len);

#endif /* UI_H_ */
