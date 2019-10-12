/*
 * Informe.h
 *
 *  Created on: Oct 11, 2019
 *      Author: gabriel
 */

#ifndef INFORME_H_
#define INFORME_H_
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

#include "Cliente.h"
#include "Pedido.h"
#include "utn.h"
#include "UI.h"

int pedido_contarPendientesPorCliente(Pedido *list,int len, int idCliente);
int cliente_ImprimirArrayConPendientes(Cliente *list, int len, Pedido *list2, int len2);
int pedido_ImprimirArrayPendiente(Cliente *list, int len, Pedido *list2, int len2);
int pedido_ImprimirArrayProcesado(Cliente *list, int len, Pedido *list2, int len2);

#endif /* INFORME_H_ */
