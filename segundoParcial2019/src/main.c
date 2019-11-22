#include <stdio.h>
#include <stdlib.h>

#include "Cachorro.h"
#include "LinkedList.h"
#include "Controller.h"
#include "utn.h"




int main()
{
    int option = 0;


    LinkedList* listaCachorros = ll_newLinkedList();
    do{
    	printf(  "1. Cargar los datos de los cachorros.\n"
    		     "2. Listado.\n"
    		     "3. Guarda menores de 45\n"
    		     "4. filtrar por machos\n"
    		     "5. listado callejeros\n"
    		    "6. Salir\n");
    	getInt(&option,"Ingrese la opcion:\n","Error\n",1,6,3);
        switch(option)
        {
            case 1:
                controller_loadFromText(listaCachorros);
                break;
            case 2:
            	controller_ListCachorro(listaCachorros);

            	break;
            case 3:
            	controller_menosDe45(listaCachorros);
            	break;
            case 4:
            	controller_machos(listaCachorros);
            	break;
            case 5:
            	controller_callejero(listaCachorros);
            	break;
        }
    }while(option != 6);
    return 0;
}

