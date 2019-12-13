#include "eComputer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"

static int isValidDescripcion(char* descripcion);
static int isValidPrecio(int precio);
static int isValidIdTipo(int idTipo);
static int isValidOferta(char* oferta);

/** \brief Crea un nuevo empleado
 *
 * \return Employee*
 *
 */
EComputer* ec_new()
{
	return (EComputer*)malloc(sizeof(EComputer));
}

/** \brief Crea un nuevo empleado con los parametros recibidos
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee*
 *
 */
EComputer* ec_newParametros(char* idStr,char* descripcionStr,char* precioStr,char* idTipoStr,char* ofertaStr)
{
	EComputer* retorno = NULL;
	EComputer* this;
	this = ec_new();
	if(		this!=NULL &&
			ec_setId(this, atoi(idStr))!=-1 &&
			ec_setDescripcion(this, descripcionStr)!=-1 &&
			ec_setPrecio(this, atoi(precioStr))!=-1 &&
			ec_setIdTipo(this, atoi(idTipoStr))!=-1 &&
			ec_setOferta(this, ofertaStr)!=-1
			){
		retorno = this;
	}else{
		printf("fallo");
		printf("%s",idStr);
		printf("%s",descripcionStr);
		printf("%s",precioStr);
		printf("%s",idTipoStr);
		printf("%s",idStr);
		ec_delete(this);
	}
	return retorno;
}

/** \brief Elimina un empleado
 *
 * \param this Employee*
 *
 */
void ec_delete(EComputer* this)
{
	free(this);
}

/** \brief asigna el id, lleva cuenta del id maximo y si se ingresa un numero negativo devuelve maximo+1
 *
 * \param this Employee*
 * \param id int
 * \return retorna -1 si this es null o 0 en caso de exito
 *
 */
int ec_setId(EComputer* this, int id)
{
	int retorno = -1;
	static int maximoId = -1;
	if(this != NULL)
	{
		retorno = 0;
		if(id < 0)
		{
			maximoId++;
			this->id = maximoId;
		}
		else
		{
			if(id > maximoId)
			{
				maximoId = id;
			}
			this->id = id;
		}
	}
	return retorno;
}


/** \brief devuelve el id de un empleado en parametro id
 *
 * \param this Employee*
 * \param id int*
 * \return retorna -1 si this es null o 0 en caso de exito
 *
 */
int ec_getId(EComputer* this,int* id)
{
	int retorno = -1;
	if(this!=NULL && id!=NULL)
	{
		retorno = 0;
		*id = this->id;
	}
	return retorno;
}

/** \brief asigna el nombre de un empleado
 *
 * \param this Employee*
 * \param nombre char*
 * \return retorna -1 si this es null o 0 en caso de exito
 *
 */
int ec_setDescripcion(EComputer* this,char* descripcion)
{
	int retorno = -1;
	if(this!=NULL && isValidDescripcion(descripcion)){
		retorno = 0;
		strncpy(this->descripcion, descripcion,128);
	}
	return retorno;
}

/** \brief devuelve el nombre de un empleado en parametro nombre
 *
 * \param this Employee*
 * \param nombre char*
 * \return retorna -1 si this es null o 0 en caso de exito
 *
 */
int ec_getDescripcion(EComputer* this,char* descripcion)
{
	int retorno = -1;
	if(this!=NULL && descripcion!=NULL)
	{
		retorno = 0;
		strncpy(descripcion, this->descripcion,128);
	}
	return retorno;
}

/** \brief verifica si es un nombre valido
 *
 * \param nombre char*
 * \return retorna 0 si no es nombre valido y 1 si lo es
 *
 */
static int isValidDescripcion(char* nombre)
{
	int retorno = 0;
	if(strlen(nombre)<200)
	{
		retorno = 1;
	}
	return retorno;
}

/** \brief asigna las horas trabajadas de un empleado
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return retorna -1 si this es null o 0 en caso de exito
 *
 */
int ec_setPrecio(EComputer* this,int precio)
{
	int retorno = -1;
	if(this!=NULL && isValidPrecio(precio)){
		this->precio = precio;
		retorno = 0;
	}
	return retorno;
}

/** \brief devuelve las horas trabajadas de un empleado
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return retorna -1 si this es null o 0 en caso de exito
 *
 */
int ec_getPrecio(EComputer* this,int* precio)
{
	int retorno = -1;
	if(this!=NULL && precio!=NULL)
	{
		retorno = 0;
		*precio = this->precio;
	}
	return retorno;
}

/** \brief verifica si horas trabajadas es valido
 *
 * \param horasTrabajadas int
 * \return retorna 0 si no es valido y 1 si lo es
 *
 */
static int isValidPrecio(int precio)
{
	int retorno = 0;
	if(precio >= 0){
		retorno = 1;
	}
	return retorno;
}

/** \brief asigna el nombre de un empleado
 *
 * \param this Employee*
 * \param nombre char*
 * \return retorna -1 si this es null o 0 en caso de exito
 *
 */
int ec_setIdTipo(EComputer* this,int idTipo)
{
	int retorno = -1;
	if(this!=NULL && isValidIdTipo(idTipo)){
		retorno = 0;
		this->idTipo = idTipo;
	}
	return retorno;
}

/** \brief devuelve el nombre de un empleado en parametro nombre
 *
 * \param this Employee*
 * \param nombre char*
 * \return retorna -1 si this es null o 0 en caso de exito
 *
 */
int ec_getIdTipo(EComputer* this,int* idTipo)
{
	int retorno = -1;
	if(this!=NULL && idTipo!=NULL)
	{
		retorno = 0;
		*idTipo= this->idTipo;
	}
	return retorno;
}

/** \brief verifica si es un nombre valido
 *
 * \param nombre char*
 * \return retorna 0 si no es nombre valido y 1 si lo es
 *
 */
static int isValidIdTipo(int idTipo)
{
	int retorno = 0;
	if(idTipo == 1 || idTipo == 2){
		retorno = 1;
	}
	return retorno;
}

int ec_setOferta(EComputer* this,char* oferta)
{
	int retorno = -1;
	if(this!=NULL && isValidOferta(oferta)){
		retorno = 0;
		strncpy(this->oferta, oferta,200);
	}
	return retorno;
}
int ec_getOferta(EComputer* this,char* oferta)
{
	int retorno = -1;
	if(this!=NULL && oferta!=NULL)
	{
		retorno = 0;
		strncpy(oferta, this->oferta,200);
	}
	return retorno;
}

/** \brief verifica si es un nombre valido
 *
 * \param nombre char*
 * \return retorna 0 si no es nombre valido y 1 si lo es
 *
 */
static int isValidOferta(char* oferta)
{
	int retorno = 0;
	if(strlen(oferta)<200)
	{
		retorno = 1;
	}
	return retorno;
}



int compararPorTipo(void* e1, void* e2){
	int retorno;
	EComputer* computer1 = (EComputer*)e1;
	EComputer* computer2 = (EComputer*)e2;

	int tipo1;
	int tipo2;

	ec_getIdTipo(computer1, &tipo1);
	ec_getIdTipo(computer2, &tipo2);
	if(tipo1 > tipo2){
		retorno = 1;
	}else if(tipo1 < tipo2){
		retorno = -1;
	}else{
		retorno = 0;
	}
	return retorno;
}

