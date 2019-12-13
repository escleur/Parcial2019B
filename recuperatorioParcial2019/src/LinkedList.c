#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this = malloc(sizeof(LinkedList));
    this->pFirstNode = NULL;
    this->size = 0;
    return this;
}

/** \brief Crea un nuevo nodo en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
static Node* ll_newNode(void)
{
    Node* this= NULL;
    this = malloc(sizeof(Node));
    return this;
}


/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode = NULL;
	int i;
	if(this!=NULL && nodeIndex>=0 && nodeIndex<this->size)
	{
		pNode = this->pFirstNode;
		for(i=0;i<nodeIndex;i++)
		{
			pNode = pNode->pNextNode;
		}
	}
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNode;
    Node* pNodeAnterior;
    if(this!=NULL && nodeIndex>=0 && nodeIndex<=this->size)
    {
    	pNode = ll_newNode();
    	if(pNode != NULL)
    	{
    		returnAux = 0;
    		this->size++;
    		pNode->pElement = pElement;
			if(nodeIndex==0)
			{
				pNode->pNextNode = this->pFirstNode;
				this->pFirstNode = pNode;
			}
			else
			{
				pNodeAnterior = getNode(this, nodeIndex-1);
				pNode->pNextNode = pNodeAnterior->pNextNode;
				pNodeAnterior->pNextNode = pNode;
			}

    	}
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = 0;
    	addNode(this, this->size, pElement);
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    if(this != NULL && index>=0 && index<this->size)
    {
    	returnAux = getNode(this, index);
    	if(returnAux!=NULL)
    	{
    		returnAux = ((Node*)returnAux)->pElement;
    	}
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNode;
    if(this != NULL && index>=0 && index<this->size)
    {
    	pNode = getNode(this, index);
    	if(pNode!=NULL)
    	{
    		returnAux = 0;
    		pNode->pElement = pElement;
    	}
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNode;
    Node* pNodeAnterior;
    if(this!=NULL && index>=0 && index<this->size)
    {
    	pNode = getNode(this,index);
    	if(pNode != NULL)
    	{
    		returnAux = 0;
    		this->size--;
			if(index==0)
			{
				this->pFirstNode = pNode->pNextNode;
			}
			else
			{
				pNodeAnterior = getNode(this, index-1);
				pNodeAnterior->pNextNode = pNode->pNextNode;
			}
			//free(pNode);
    	}
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
    	returnAux = 0;
    	while(this->size>0)
    	{
    		ll_remove(this,0);
    	}
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
    	returnAux = 0;
    	if(ll_clear(this)==0)
    		free(this);
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i=0;
    Node* pNode;
    if(this != NULL)
    {
    	pNode=this->pFirstNode;
    	while(pNode!=NULL)
    	{
    		if(pNode->pElement == pElement)
    		{
    			returnAux = i;
    			break;
    		}
    		i++;
    		pNode=pNode->pNextNode;
    	}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
    	if(this->size == 0)
    	{
    		returnAux = 1;
    	}else
    	{
    		returnAux = 0;
    	}
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL && index>=0 && index<=this->size)
    {
    	returnAux = 0;
    	addNode(this,index,pElement);
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    if(this!=NULL && index>=0 && index<=this->size)
    {
    	returnAux = ll_get(this,index);
    	ll_remove(this,index);
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* pNode;
    if(this != NULL)
    {
    	returnAux = 0;
    	pNode=this->pFirstNode;
    	while(pNode!=NULL)
    	{
    		if(pNode->pElement == pElement)
    		{
    			returnAux = 1;
    			break;
    		}
    		pNode=pNode->pNextNode;
    	}
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;
    if(this!=NULL && this2!=NULL)
    {
		returnAux=1;
    	for(i=0;i<this2->size;i++)
    	{
    		if(ll_contains(this,ll_get(this2,i))!=1)
    		{
    			returnAux=0;
    		}
    	}
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    Node* pNode;
    if(this!=NULL && from>=0 && from<=this->size && to>from && to<=this->size)
    {
    	cloneArray = ll_newLinkedList();
    	pNode = this->pFirstNode;
		for(i=0;i<to;i++)
		{
			if(i>=from)
			{
				ll_add(cloneArray,pNode->pElement);
			}
			//if(pNode!=NULL)
				pNode = pNode->pNextNode;
		}
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this!=NULL)
    {
    	cloneArray = ll_subList(this,0,this->size);
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
	int i;
	int j;
	int flagOrdeno;
	void* swap;

	if(this!=NULL && pFunc!=NULL && (order==1||order==0))
	{
		returnAux = 0;
		for(i=1; i<this->size; i++)
		{
			j=i;
			flagOrdeno = 1;
			while(flagOrdeno != 0 && j!=0)
			{
				flagOrdeno = 0;

				if( 	(order && pFunc(ll_get(this,j-1),ll_get(this,j))>0) ||
						(!order && pFunc(ll_get(this,j-1),ll_get(this,j))<0) )
				{
					swap = getNode(this,j-1)->pElement;
					getNode(this, j-1)->pElement = getNode(this, j)->pElement;
					getNode(this, j)->pElement = swap;
					flagOrdeno = 1;
				}
				j--;
			}
		}
	}
    return returnAux;

}

/** \brief Mapea los elementos de la lista utilizando la funcion recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_map(LinkedList* this, int (*pFunc)(void*))
{
    int returnAux =-1;
	int i;
	if(this!=NULL && pFunc!=NULL)
	{
		returnAux = 0;
		for(i=0; i<this->size; i++)
		{
			pFunc(ll_get(this,i));
		}
	}
    return returnAux;

}

/** \brief Crea y retorna una nueva lista con los elementos indicados por el filtro
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* cloneArray = NULL;
    int i;
    Node* pNode;
    if(this!=NULL && pFunc!=NULL)
    {
    	cloneArray = ll_newLinkedList();
    	pNode = this->pFirstNode;
		for(i=0;i<this->size;i++)
		{
			if(pFunc(pNode->pElement))
			{
				ll_add(cloneArray,pNode->pElement);
			}
			//if(pNode!=NULL)
				pNode = pNode->pNextNode;
		}
    }

    return cloneArray;
}


/** \brief Retorna la lista con los elementos indicados por el filtro
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
int ll_reduce(LinkedList* this, int (*pFunc)(void*))
{
	int retorno = -1;
	int i;
    if(this!=NULL && pFunc!=NULL)
    {
    	retorno = 0;
		for(i=this->size-1;i>=0;i--)
		{
			if(!pFunc(ll_get(this, i)))
			{
				ll_remove(this,i);
			}
		}
    }

    return retorno;
}


