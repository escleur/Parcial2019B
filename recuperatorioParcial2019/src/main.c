#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Controller.h"
#include "eComputer.h"
#include "utn.h"




int main()
{
    int option = 0;


    LinkedList* listaComputer = ll_newLinkedList();
    do{
    	printf(  "1. Cargar los datos de las computadoras.\n"
    		     "2. Ordenar.\n"
    		     "3. Listado\n"
    		     "4. mapear\n"
    		     "5. guardar desktop\n"
    		    "7. Salir\n");
    	getInt(&option,"Ingrese la opcion:\n","Error\n",1,6,3);
        switch(option)
        {
            case 1:
                controller_loadFromText(listaComputer);
                break;
            case 2:
            	ll_sort(listaComputer, compararPorTipo, 1);
            	break;
            case 3:
            	controller_ListComputer(listaComputer);
            	break;
            case 4:
            	controller_mapComputer(listaComputer);
            	break;
            case 5:
            	controller_guardar(listaComputer);
            	break;
        }
    }while(option != 7);
    return 0;
}

