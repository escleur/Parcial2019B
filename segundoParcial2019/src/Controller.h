#include "Cachorro.h"


int controller_loadFromText(LinkedList* pArrayListEmployee);
int controller_saveAsText(LinkedList* pArrayListEmployee);
int controller_ListCachorro(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int vaciarLLCachorros(LinkedList* pArrayListEmployee);
int employee_GetPorId(LinkedList* pArrayListEmployee, Cachorro *empleado, int id);
int filtroMenoresDe45(void* p);
int controller_menosDe45(LinkedList* pArrayListCachorros);
int controller_callejero(LinkedList* pArrayListCachorros);
int filtroCallejero(void* p);
int controller_machos(LinkedList* pArrayListCachorros);
int filtroMachos(void* p);





