#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "string.h"
#include "parser.h"
#include "Controller.h"
#include "utn.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(LinkedList* pArrayListComputer)
{
	int retorno = -1;
	char path[128];
	if(pArrayListComputer != NULL)
	{
		getString(path,"Introdusca el nombre del archivo.","Error",0,127,2);
		retorno = 0;
		FILE* pFile = fopen(path, "r");
		if(pFile != NULL){
			vaciarLLComputer(pArrayListComputer);
			parser_ComputerFromText(pFile , pArrayListComputer);
			printf("archivo leido\n");

		}else{
			printf("No encontro el archivo\n");
		}
		fclose(pFile);
	}
	return retorno;
}

/** \brief Elimina los empleados de la linkedList.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int vaciarLLComputer(LinkedList* pArrayListCachorros)
{
	int retorno=-1;
	EComputer* buffer;
	if(pArrayListCachorros != NULL)
	{
		retorno = 0;
		while(!ll_isEmpty(pArrayListCachorros))
		{
			buffer = (EComputer*)ll_pop(pArrayListCachorros, 0);
			ec_delete(buffer);
		}
	}
	return retorno;
}


/** \brief Busca un empleado por id.
 *
 * \param pArrayListEmployee LinkedList*
 * \param empleado Employee* retorno el elemento coincidente
 * \param id int
 * \return int (-1) si la lista es nula o no se encuentra el id (>=0)retorna el indice del elemento que coincide el id
 *
 */
int employee_GetPorId(LinkedList* pArrayListEmployee, EComputer *empleado, int id)
{
	int retorno = -1;
	int i;
	EComputer* buffer;
	int idBuffer;
	if(pArrayListEmployee != NULL){
		for(i=0;i<ll_len(pArrayListEmployee);i++){
			buffer = ll_get(pArrayListEmployee, i);
			ec_getId(buffer, &idBuffer);
			if(id == idBuffer){
				retorno = i;
				*empleado = *buffer;
				break;
			}
		}
	}
	return retorno;
}





/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListComputer(LinkedList* pArrayListComputer)
{
	int i;
	EComputer* buffer;
	int bufferId;
	char bufferDescripcion[200];
	int bufferPrecio;
	int bufferIdTipo;
	char bufferOferta[200];
	if(pArrayListComputer != NULL)
	{
		printf("id      Descripcion      Precio    Tipo     Oferta \n");

		for(i=0;i<ll_len(pArrayListComputer);i++)
		{
			buffer = (EComputer*)ll_get(pArrayListComputer,i);
			ec_getId(buffer, &bufferId);
			ec_getDescripcion(buffer, bufferDescripcion);
			ec_getPrecio(buffer, &bufferPrecio);
			ec_getIdTipo(buffer, &bufferIdTipo);
			ec_getOferta(buffer, bufferOferta);

			printf("%d  --  %s  --  %d  --  ",bufferId,bufferDescripcion,bufferPrecio);
			if(bufferIdTipo == 1){
				printf("DESKTOP  --  ");
			}
			else if(bufferIdTipo== 2){
				printf("LAPTOP  --  ");
			}
			printf("%s\n",bufferOferta);
		}
	}
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
/*int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	ll_sort(pArrayListEmployee, compararPorNombre, 1);
    return 1;
}*/

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText( LinkedList* pArrayListComputer)
{
	int retorno = -1;
	int i;
	char path[128];
	int bufferId;
	char bufferDescripcion[200];
	int bufferPrecio;
	int idTipo;
	char oferta[200];
	EComputer *buffer;
	if( pArrayListComputer != NULL)
	{
		retorno = 0;
		getString(path,"Introdusca el nombre del archivo.","Error",0,127,2);

		FILE* pFile = fopen(path, "w");
		fprintf(pFile,"id,descripcion,precio, idtipo\n");
		if(pFile != NULL){
			for(i=0;i<ll_len(pArrayListComputer);i++){
				buffer = (EComputer*)ll_get(pArrayListComputer, i);
				ec_getId(buffer, &bufferId);
				ec_getDescripcion(buffer, bufferDescripcion);
				ec_getPrecio(buffer, &bufferPrecio);
				ec_getIdTipo(buffer, &idTipo);
				ec_getOferta(buffer, oferta);


				fprintf(pFile,"%d,%s,%d,%d,%s\n",bufferId,bufferDescripcion,bufferPrecio,idTipo,oferta);
			}
			printf("archivo escrito en formato texto\n");

		}else{
			printf("No encontro el archivo\n");
		}
		fclose(pFile);
	}
	return retorno;

}

int controller_mapComputer(LinkedList* pArrayListComputer)
{
	ll_map(pArrayListComputer, mapear);
    return 1;
}



int mapear(void* item){
	EComputer* computer = (EComputer*)item;

	if(computer->idTipo == 2){
		strncpy(computer->oferta,"SIN DATOS",200);
	}
	if(computer->idTipo == 1 && computer->precio >20000){
		strncpy(computer->oferta,"50% DESCUENTO", 200);

	}
	return 1;
}

/*
int filtroMenoresDe45(void* p){
	EComputer* cachorro = (EComputer*)p;
	if(cachorro->dias<45){
		return 1;
	}else{
		return 0;
	}

}

int controller_menosDe45(LinkedList* pArrayListCachorros){
	int ret = -1;
	if(pArrayListCachorros!=NULL){
		LinkedList *lista2;
		ret =0;
		lista2 = ll_filter(pArrayListCachorros, filtroMenoresDe45);
		controller_saveAsText( lista2);
	}
	return ret;
}
*/

int filtro(void* p){
	EComputer* c = (EComputer*)p;
	if(c->idTipo == 1){
		return 1;
	}else{
		return 0;
	}

}

int controller_guardar(LinkedList* pArrayListComputer){
	int ret=-1;
	if(pArrayListComputer!=NULL){
		LinkedList *lista2;
		lista2 = ll_filter(pArrayListComputer, filtro);
		controller_saveAsText( lista2);
		ret=0;
	}
	return ret;
}
/*
int filtroCallejero(void* p){
	EComputer* cachorro = (EComputer*)p;
	if(strcmp(cachorro->raza,"Callejero")==0){
		return 1;
	}else{
		return 0;
	}
}

int controller_callejero(LinkedList* pArrayListCachorros){
	int ret=-1;
	if(pArrayListCachorros!=NULL){
		ret=0;
		LinkedList *lista2;
		lista2 = ll_filter(pArrayListCachorros, filtroCallejero);
		controller_ListCachorro(lista2);

	}
	return ret;
}

*/

