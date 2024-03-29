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

int pedido_contarPorCliente(Pedido *list,int len, int idCliente, char *estado);
int cliente_ImprimirArrayConPendientes(Cliente *list, int len, Pedido *list2, int len2);
int pedido_ImprimirArrayPendiente(Cliente *list, int len, Pedido *list2, int len2);
int pedido_ImprimirArrayProcesado(Cliente *list, int len, Pedido *list2, int len2);
int cliente_ConMasPedidosPendientes(Cliente *list, int len, Pedido *list2, int len2);
int cliente_ConMasPedidosCompletados(Cliente *list, int len, Pedido *list2, int len2);
int cliente_ConMasPedidos(Cliente *list, int len, Pedido *list2, int len2);
int pedido_contarRecicladoPorCliente(Pedido *list,int len, int idCliente);
int cliente_ConMasReciclado(Cliente *list, int len, Pedido *list2, int len2);
int cliente_ConMenosReciclado(Cliente *list, int len, Pedido *list2, int len2);
int cliente_ConMasDe1000Reciclado(Cliente *list, int len, Pedido *list2, int len2);
int cliente_ConMenosDe100Reciclado(Cliente *list, int len, Pedido *list2, int len2);
int pedido_CompletadosConPorcentajeReciclado(Cliente *list, int len, Pedido *list2, int len2);
int pedido_PendientesPorLocalidad(Cliente *list, int len, Pedido *list2, int len2);
int cliente_PPPromedio(Cliente *list, int len, Pedido *list2, int len2);
int pedido_PlasticoPorCliente(Pedido *list,int len, int idCliente, int clase);
int cliente_CantidadDePlasticoReciclado(Cliente *list, int len, Pedido *list2, int len2);
#endif /* INFORME_H_ */
