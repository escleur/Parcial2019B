#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eComputer.h"
#include "LinkedList.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_ComputerFromText(FILE* pFile , LinkedList* pArrayListComputer)
{
	char id[4096];
	char descripcion[4096];
	char precio[4096];
	char idTipo[4096];
	char oferta[4096];
	EComputer* buffer;
	int leidos;
	if(pFile != NULL && pArrayListComputer != NULL)
	{
		leidos = fscanf(pFile, "%s",descripcion);

		while(!feof(pFile))
		{
			leidos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",id,descripcion,precio,idTipo);
			if(leidos == 4){
				strcpy(oferta,"");
				buffer = ec_newParametros(id,descripcion,precio,idTipo,oferta);

				if(buffer != NULL)
				{
					printf("%d  %s  %d  %d  %s\n",buffer->id,buffer->descripcion,buffer->precio,buffer->idTipo,buffer->oferta);
					ll_add(pArrayListComputer, buffer);

				}
			}
		}
	}
    return 1;
}

