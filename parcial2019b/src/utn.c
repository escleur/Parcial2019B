/*
 * utn.c
 *
 *  Created on: 31 ago. 2019
 *      Author: gas
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

//Linux
#define PURGAR __fpurge(stdin);
//Windows
//#define PURGAR fflush(stdin);

/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * 		  informando si la operacion fue exitosa
 * \param pResultado Es el resultado a devolver
 * \param pMensaje Es el mensaje a ser mostrado
 * \param pMensajeError Es el mensaje a ser mostrado cuando se ingreso un valor erroneo
 * \param minimo El minimo valor aceptado por la funcion como valido
 * \param maximo El maximo valor aceptado por la funcion como valido
 * \param reintentos Es la cantidad de reintentos en caso de fallar
 * \return -1 en caso de error y 0 si la operacion fue exitosa
 *
 */
int getChar(char *pResultado, char *pMensaje, char *pMensajeError, char minimo,
		char maximo, int reintentos) {
	int retorno = EXIT_ERROR;
	char buffer;
	if (pResultado != NULL && pMensaje != NULL && pMensajeError != NULL
			&& minimo < maximo && reintentos >= 0) {
		do {
			printf("%s", pMensaje);
			PURGAR
			if (scanf("%c", &buffer) == 1) {
				if (buffer >= minimo && buffer <= maximo) {
					retorno = EXIT_SUCCESS;
					*pResultado = buffer;
					break;
				}
			}
			printf("%s", pMensajeError);
			reintentos--;
		} while (reintentos >= 0);
	}
	return retorno;
}

/**
 * \brief Solicita un entero al usuario y devuelve el resultado
 * 		  informando si la operacion fue exitosa
 * \param pResultado Es el resultado a devolver
 * \param pMensaje Es el mensaje a ser mostrado
 * \param pMensajeError Es el mensaje a ser mostrado cuando se ingreso un valor erroneo
 * \param minimo El minimo valor aceptado por la funcion como valido
 * \param maximo El maximo valor aceptado por la funcion como valido
 * \param reintentos Es la cantidad de reintentos en caso de fallar
 * \return -1 en caso de error y 0 si la operacion fue exitosa
 *
 */
int getInt(int *pResultado, char *pMensaje, char *pMensajeError, int minimo,
		int maximo, int reintentos) {
	int retorno = EXIT_ERROR;
	int buffer;
	if (pResultado != NULL && pMensaje != NULL && pMensajeError != NULL
			&& minimo < maximo && reintentos >= 0) {
		do {
			printf("%s", pMensaje);
			PURGAR
			if (scanf("%d", &buffer) == 1) {
				if (buffer >= minimo && buffer <= maximo) {
					retorno = EXIT_SUCCESS;
					*pResultado = buffer;
					break;
				}
			}
			printf("%s", pMensajeError);
			reintentos--;
		} while (reintentos >= 0);
	}
	return retorno;
}

/**
 * \brief Solicita un flotante al usuario y devuelve el resultado
 * 		  informando si la operacion fue exitosa
 * \param pResultado Es el resultado a devolver
 * \param pMensaje Es el mensaje a ser mostrado
 * \param pMensajeError Es el mensaje a ser mostrado cuando se ingreso un valor erroneo
 * \param minimo El minimo valor aceptado por la funcion como valido
 * \param maximo El maximo valor aceptado por la funcion como valido
 * \param reintentos Es la cantidad de reintentos en caso de fallar
 * \return -1 en caso de error y 0 si la operacion fue exitosa
 *
 */
int getFloat(float *pResultado, char *pMensaje, char *pMensajeError,
		float minimo, float maximo, int reintentos) {
	int retorno = EXIT_ERROR;
	float buffer;
	if (pResultado != NULL && pMensaje != NULL && pMensajeError != NULL
			&& minimo < maximo && reintentos >= 0) {
		do {
			printf("%s", pMensaje);
			PURGAR
			if (scanf("%f", &buffer) == 1) {
				if (buffer >= minimo && buffer <= maximo) {
					retorno = EXIT_SUCCESS;
					*pResultado = buffer;
					break;
				}
			}
			printf("%s", pMensajeError);
			reintentos--;
		} while (reintentos >= 0);
	}
	return retorno;
}

/**
 * \brief Solicita un string al usuario y devuelve el resultado
 * 		  informando si la operacion fue exitosa
 * \param pResultado Es el resultado a devolver
 * \param pMensaje Es el mensaje a ser mostrado
 * \param pMensajeError Es el mensaje a ser mostrado cuando se ingreso un valor erroneo
 * \param minimo La minima  cantidad de caracteres
 * \param maximo La maxima cantidad de caracteres
 * \param reintentos Es la cantidad de reintentos en caso de fallar
 * \return -1 en caso de error y 0 si la operacion fue exitosa
 *
 */
int getString(char *pResultado, char *pMensaje, char *pMensajeError, int minimo,
		int maximo, int reintentos) {
	int retorno = EXIT_ERROR;
	char buffer[500];
	if (pResultado != NULL && pMensaje != NULL && pMensajeError != NULL
			&& minimo < maximo && reintentos >= 0) {
		do {
			printf("%s", pMensaje);
			PURGAR
			fgets(buffer, sizeof(buffer), stdin);
			buffer[strlen(buffer) - 1] = '\0';
			if (strlen(buffer) >= minimo && strlen(buffer) <= maximo) {
				strncpy(pResultado, buffer, maximo + 1);
				retorno = 0;
				break;
			}
			printf("%s", pMensajeError);
			reintentos--;
		} while (reintentos >= 0);
	}
	return retorno;
}

/**
 * \brief Chequea que la frase contenga solo los caracteres pedidos
 * \param char *frase Texto a chequear
 * \param int esLetra [1] si debe contener letras [0] si no debe contener letras
 * \param int esNumero [1] si debe contener los numeros [0] si no debe contenerlos
 * \param char *letras cadena de caracteres con los caracteres que debe contener
 * \return int 1 si cumple los requisitos 0 si no los cumple
 */
int chequear(char *frase, int esLetra, int esNumero, char *letras) {
	int i;
	int j;
	int flagCumple = 1;
	int flagEncontro;
	if (frase != NULL) {
		for (i = 0; i < strlen(frase); i++) {

			if (esLetra
					&& ((frase[i] >= 'a' && frase[i] <= 'z')
							|| (frase[i] >= 'A' && frase[i] <= 'Z'))) {
				continue;
			}
			if (esNumero
					&& ((frase[i] >= '0' && frase[i] <= '9') )) {
				continue;
			}
			flagEncontro = 0;
			for(j = 0; j<strlen(letras); j++){
				if(frase[i] == letras[j])
				{
					flagEncontro = 1;
					break;
				}
			}
			if(flagEncontro){
				continue;
			}
			flagCumple = 0;
			break;
		}
	}
	return flagCumple;
}

/**
 * \brief Solicita un cuil al usuario y devuelve el resultado
 * 		  informando si la operacion fue exitosa
 * \param pResultado Es el resultado a devolver
 * \param pMensaje Es el mensaje a ser mostrado
 * \param pMensajeError Es el mensaje a ser mostrado cuando se ingreso un valor erroneo
 * \param minimo La minima  cantidad de caracteres
 * \param maximo La maxima cantidad de caracteres
 * \param reintentos Es la cantidad de reintentos en caso de fallar
 * \return -1 en caso de error y 0 si la operacion fue exitosa
 *
 */
int getCuil(char *pResultado, char *pMensaje, char *pMensajeError, int minimo,
		int maximo, int reintentos) {
	int retorno = EXIT_ERROR;
	char buffer[500];
	if (pResultado != NULL && pMensaje != NULL && pMensajeError != NULL
			&& minimo < maximo && reintentos >= 0) {
		do {
			printf("%s", pMensaje);
			PURGAR
			fgets(buffer, sizeof(buffer), stdin);
			buffer[strlen(buffer) - 1] = '\0';
			if (strlen(buffer) >= minimo && strlen(buffer) <= maximo && chequear(buffer, 0, 1, "-")) {
				strncpy(pResultado, buffer, maximo + 1);
				retorno = 0;
				break;
			}
			printf("%s", pMensajeError);
			reintentos--;
		} while (reintentos >= 0);
	}
	return retorno;
}

/**
 * \brief Solicita un nombre al usuario y devuelve el resultado
 * 		  informando si la operacion fue exitosa
 * \param pResultado Es el resultado a devolver
 * \param pMensaje Es el mensaje a ser mostrado
 * \param pMensajeError Es el mensaje a ser mostrado cuando se ingreso un valor erroneo
 * \param minimo La minima  cantidad de caracteres
 * \param maximo La maxima cantidad de caracteres
 * \param reintentos Es la cantidad de reintentos en caso de fallar
 * \return -1 en caso de error y 0 si la operacion fue exitosa
 *
 */
int getNombre(char *pResultado, char *pMensaje, char *pMensajeError, int minimo,
		int maximo, int reintentos) {
	int retorno = EXIT_ERROR;
	char buffer[500];
	if (pResultado != NULL && pMensaje != NULL && pMensajeError != NULL
			&& minimo < maximo && reintentos >= 0) {
		do {
			printf("%s", pMensaje);
			PURGAR
			fgets(buffer, sizeof(buffer), stdin);
			buffer[strlen(buffer) - 1] = '\0';
			if (strlen(buffer) >= minimo && strlen(buffer) <= maximo && chequear(buffer, 1, 0, " ")) {
				strncpy(pResultado, buffer, maximo + 1);
				retorno = 0;
				break;
			}
			printf("%s", pMensajeError);
			reintentos--;
		} while (reintentos >= 0);
	}
	return retorno;
}

/**
 * \brief Solicita un telefono al usuario y devuelve el resultado
 * 		  informando si la operacion fue exitosa
 * \param pResultado Es el resultado a devolver
 * \param pMensaje Es el mensaje a ser mostrado
 * \param pMensajeError Es el mensaje a ser mostrado cuando se ingreso un valor erroneo
 * \param minimo La minima  cantidad de caracteres
 * \param maximo La maxima cantidad de caracteres
 * \param reintentos Es la cantidad de reintentos en caso de fallar
 * \return -1 en caso de error y 0 si la operacion fue exitosa
 *
 */
int getTelefono(char *pResultado, char *pMensaje, char *pMensajeError, int minimo,
		int maximo, int reintentos) {
	int retorno = EXIT_ERROR;
	char buffer[500];
	if (pResultado != NULL && pMensaje != NULL && pMensajeError != NULL
			&& minimo < maximo && reintentos >= 0) {
		do {
			printf("%s", pMensaje);
			PURGAR
			fgets(buffer, sizeof(buffer), stdin);
			buffer[strlen(buffer) - 1] = '\0';
			if (strlen(buffer) >= minimo && strlen(buffer) <= maximo && chequear(buffer, 0, 1, "(+)- ")) {
				strncpy(pResultado, buffer, maximo + 1);
				retorno = 0;
				break;
			}
			printf("%s", pMensajeError);
			reintentos--;
		} while (reintentos >= 0);
	}
	return retorno;
}



void burbuja(int array[], int limite) {
int i;
int flagOrdeno = 1;
int swap;

while (flagOrdeno == 1) {
	flagOrdeno = 0;
	for (i = 0; i < limite - 1; i++) {
		if (array[i] > array[i + 1]) {
			swap = array[i];
			array[i] = array[i + 1];
			array[i + 1] = swap;
			flagOrdeno = 1;
		}
	}
}
}

void insercion(int array[], int limite) {
int i;
int j;
int flagOrdeno;
int swap;

for (i = 1; i < limite; i++) {
	j = i;
	flagOrdeno = 1;
	while (flagOrdeno != 0 && j != 0) {
		flagOrdeno = 0;

		if (array[j - 1] > array[j]) {
			swap = array[j - 1];
			array[j - 1] = array[j];
			array[j] = swap;
			flagOrdeno = 1;
		}
		j--;
	}
}
}
