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
int controller_loadFromText(LinkedList* pArrayListCachorros)
{
	int retorno = -1;
	char path[128];
	if(pArrayListCachorros != NULL)
	{
		getString(path,"Introdusca el nombre del archivo.","Error",0,127,2);
		retorno = 0;
		FILE* pFile = fopen(path, "r");
		if(pFile != NULL){
			vaciarLLCachorros(pArrayListCachorros);
			parser_CachorrosFromText(pFile , pArrayListCachorros);
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
int vaciarLLCachorros(LinkedList* pArrayListCachorros)
{
	int retorno=-1;
	Cachorro* buffer;
	if(pArrayListCachorros != NULL)
	{
		retorno = 0;
		while(!ll_isEmpty(pArrayListCachorros))
		{
			buffer = (Cachorro*)ll_pop(pArrayListCachorros, 0);
			ca_delete(buffer);
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
int employee_GetPorId(LinkedList* pArrayListEmployee, Cachorro *empleado, int id)
{
	int retorno = -1;
	int i;
	Cachorro* buffer;
	int idBuffer;
	if(pArrayListEmployee != NULL){
		for(i=0;i<ll_len(pArrayListEmployee);i++){
			buffer = ll_get(pArrayListEmployee, i);
			ca_getId(buffer, &idBuffer);
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
int controller_ListCachorro(LinkedList* pArrayListCachorro)
{
	int i;
	Cachorro* buffer;
	int bufferId;
	char bufferNombre[128];
	int bufferDias;
	char bufferRaza[128];
	char bufferReservado[128];
	char bufferGenero[128];
	if(pArrayListCachorro != NULL)
	{
		printf("id      Nombre      Dias     Raza      Reservado     Genero\n");

		for(i=0;i<ll_len(pArrayListCachorro);i++)
		{
			buffer = (Cachorro*)ll_get(pArrayListCachorro,i);
			ca_getId(buffer, &bufferId);
			ca_getNombre(buffer, bufferNombre);
			ca_getDias(buffer, &bufferDias);
			ca_getRaza(buffer, bufferRaza);
			ca_getReservado(buffer, bufferReservado);
			ca_getGenero(buffer, bufferGenero);

			printf("%d  --  %s  --  %d  --  %s  --  %s  --  %s\n",bufferId,bufferNombre,bufferDias,bufferRaza,bufferReservado,bufferGenero);
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
int controller_saveAsText( LinkedList* pArrayListCachorros)
{
	int retorno = -1;
	int i;
	char path[128];
	int bufferId;
	char bufferNombre[128];
	int bufferDias;
	char raza[128];
	char reservado[3];
	char genero[2];
	Cachorro *buffer;
	if( pArrayListCachorros != NULL)
	{
		retorno = 0;
		getString(path,"Introdusca el nombre del archivo.","Error",0,127,2);

		FILE* pFile = fopen(path, "w");
		fprintf(pFile,"ID_Cachorro,Nombre,Dias,Raza,Reservado,Genero\n");
		if(pFile != NULL){
			for(i=0;i<ll_len(pArrayListCachorros);i++){
				buffer = (Cachorro*)ll_get(pArrayListCachorros, i);
				ca_getId(buffer, &bufferId);
				ca_getNombre(buffer, bufferNombre);
				ca_getDias(buffer, &bufferDias);
				ca_getRaza(buffer, raza);
				ca_getReservado(buffer, reservado);
				ca_getGenero(buffer, genero);


				fprintf(pFile,"%d,%s,%d,%s,%s,%s\n",bufferId,bufferNombre,bufferDias,raza,reservado,genero);
			}
			printf("archivo escrito en formato texto\n");

		}else{
			printf("No encontro el archivo\n");
		}
		fclose(pFile);
	}
	return retorno;

}


int filtroMenoresDe45(void* p){
	Cachorro* cachorro = (Cachorro*)p;
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


int filtroMachos(void* p){
	Cachorro* cachorro = (Cachorro*)p;
	if(strcmp(cachorro->genero,"M")==0){
		return 1;
	}else{
		return 0;
	}

}

int controller_machos(LinkedList* pArrayListCachorros){
	int ret=-1;
	if(pArrayListCachorros!=NULL){
		LinkedList *lista2;
		lista2 = ll_filter(pArrayListCachorros, filtroMachos);
		controller_saveAsText( lista2);
		ret=0;
	}
	return ret;
}

int filtroCallejero(void* p){
	Cachorro* cachorro = (Cachorro*)p;
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



