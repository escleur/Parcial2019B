#include <stdio.h>
#include <stdlib.h>

#include "Cachorro.h"
#include "LinkedList.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_CachorrosFromText(FILE* pFile , LinkedList* pArrayListCachorros)
{
	char id[4096];
	char nombre[4096];
	char dias[4096];
	char raza[4096];
	char reservado[4096];
	char genero[4096];
	Cachorro* buffer;
	int leidos;
	if(pFile != NULL && pArrayListCachorros != NULL)
	{
		leidos = fscanf(pFile, "%s",nombre);

		while(!feof(pFile))
		{
			leidos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,dias,raza,reservado,genero);
			if(leidos == 6){
				buffer = ca_newParametros(id,nombre,dias,raza,reservado,genero);

				if(buffer != NULL)
				{
					printf("%d  %s  %d  %s  %s  %s\n",buffer->id,buffer->nombre,buffer->dias,buffer->raza,buffer->reservado,buffer->genero);
					ll_add(pArrayListCachorros, buffer);

				}
			}
		}
	}
    return 1;
}

