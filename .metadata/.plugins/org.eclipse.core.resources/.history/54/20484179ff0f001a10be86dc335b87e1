#include "Cachorro.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"

static int isValidNombre(char* nombre);
static int isValidDias(int dias);
static int isValidRaza(char* raza);
static int isValidReservado(char* reservado);
static int isValidGenero(char* genero);


/** \brief Crea un nuevo empleado
 *
 * \return Employee*
 *
 */
Cachorro* ca_new()
{
	return (Cachorro*)malloc(sizeof(Cachorro));
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
Cachorro* ca_newParametros(char* idStr,char* nombreStr,char* diasStr,char* razaStr,char* reservadoStr,char* generoStr)
{
	Cachorro* retorno = NULL;
	Cachorro* this;
	this = ca_new();
	if(		this!=NULL &&
			ca_setId(this, atoi(idStr))!=-1 &&
			ca_setNombre(this, nombreStr)!=-1 &&
			ca_setDias(this, atoi(diasStr))!=-1 &&
			ca_setRaza(this, razaStr)!=-1 &&
			ca_setReservado(this, reservadoStr)!=-1 &&
			ca_setGenero(this, generoStr)!=-1
			){
		retorno = this;
	}else{
		ca_delete(this);
	}
	return retorno;
}

/** \brief Elimina un empleado
 *
 * \param this Employee*
 *
 */
void ca_delete(Cachorro* this)
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
int ca_setId(Cachorro* this, int id)
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
int ca_getId(Cachorro* this,int* id)
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
int ca_setNombre(Cachorro* this,char* nombre)
{
	int retorno = -1;
	if(this!=NULL && isValidNombre(nombre)){
		retorno = 0;
		strncpy(this->nombre, nombre,128);
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
int ca_getNombre(Cachorro* this,char* nombre)
{
	int retorno = -1;
	if(this!=NULL && nombre!=NULL)
	{
		retorno = 0;
		strncpy(nombre, this->nombre,128);
	}
	return retorno;
}

/** \brief verifica si es un nombre valido
 *
 * \param nombre char*
 * \return retorna 0 si no es nombre valido y 1 si lo es
 *
 */
static int isValidNombre(char* nombre)
{
	int retorno = 0;
	if(chequear(nombre, 1, 0, " ") && strlen(nombre)<127)
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
int ca_setDias(Cachorro* this,int dias)
{
	int retorno = -1;
	if(this!=NULL && isValidDias(dias)){
		this->dias = dias;
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
int ca_getDias(Cachorro* this,int* dias)
{
	int retorno = -1;
	if(this!=NULL && dias!=NULL)
	{
		retorno = 0;
		*dias = this->dias;
	}
	return retorno;
}

/** \brief verifica si horas trabajadas es valido
 *
 * \param horasTrabajadas int
 * \return retorna 0 si no es valido y 1 si lo es
 *
 */
static int isValidDias(int dias)
{
	int retorno = 0;
	if(dias >= 0){
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
int ca_setRaza(Cachorro* this,char* raza)
{
	int retorno = -1;
	if(this!=NULL && isValidRaza(raza)){
		retorno = 0;
		strncpy(this->raza, raza,128);
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
int ca_getRaza(Cachorro* this,char* raza)
{
	int retorno = -1;
	if(this!=NULL && raza!=NULL)
	{
		retorno = 0;
		strncpy(raza, this->raza,128);
	}
	return retorno;
}

/** \brief verifica si es un nombre valido
 *
 * \param nombre char*
 * \return retorna 0 si no es nombre valido y 1 si lo es
 *
 */
static int isValidRaza(char* raza)
{
	int retorno = 0;
	if(chequear(raza, 1, 0, " ") && strlen(raza)<127)
	{
		retorno = 1;
	}
	return retorno;
}

int ca_setReservado(Cachorro* this,char* reservado)
{
	int retorno = -1;
	if(this!=NULL && isValidReservado(reservado)){
		retorno = 0;
		strncpy(this->raza, reservado,3);
	}
	return retorno;
}
int ca_getReservado(Cachorro* this,char* reservado)
{
	int retorno = -1;
	if(this!=NULL && reservado!=NULL)
	{
		retorno = 0;
		strncpy(reservado, this->reservado,3);
	}
	return retorno;
}

/** \brief verifica si es un nombre valido
 *
 * \param nombre char*
 * \return retorna 0 si no es nombre valido y 1 si lo es
 *
 */
static int isValidReservado(char* reservado)
{
	int retorno = 0;
	if(chequear(reservado, 0, 0, "SINO") && strlen(reservado)<3)
	{
		retorno = 1;
	}
	return retorno;
}

int ca_setGenero(Cachorro* this,char* genero)
{
	int retorno = -1;
	if(this!=NULL && isValidGenero(genero)){
		retorno = 0;
		strncpy(this->genero, genero,2);
	}
	return retorno;
}

int ca_getGenero(Cachorro* this,char* genero)
{
	int retorno = -1;
	if(this!=NULL && genero!=NULL)
	{
		retorno = 0;
		strncpy(genero, this->genero,3);
	}
	return retorno;
}

static int isValidGenero(char* genero)
{
	int retorno = 0;
	if(chequear(genero, 0, 0, "MH") && strlen(genero)<3)
	{
		retorno = 1;
	}
	return retorno;
}


int compararPorNombre(void* e1, void* e2){
	int retorno;
	Cachorro* empleado1 = (Cachorro*)e1;
	Cachorro* empleado2 = (Cachorro*)e2;

	char nombre1[128];
	char nombre2[128];

	ca_getNombre(empleado1, nombre1);
	ca_getNombre(empleado2, nombre2);
	if(strncmp(nombre1,nombre2,128)>0){
		retorno = 1;
	}else if(strncmp(nombre1,nombre2,128)<0){
		retorno = -1;
	}else{
		retorno = 0;
	}
	return retorno;
}

