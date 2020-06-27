#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"

//static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;

    this = (LinkedList*) malloc(sizeof(LinkedList));
    if(this!=NULL)
    {
        this->size = 0;
        this->pFirstNode = NULL;
    }

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
    if(this!=NULL)
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
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{

    Node* pNode = NULL;
    //int len;
    //len = ll_len(this);
    int i;
    if (this !=NULL && nodeIndex >-1 && nodeIndex< ll_len(this))
    {
        pNode = (Node*)malloc(sizeof(Node));
        pNode=this->pFirstNode;
        for (i=0;i<nodeIndex;i++)
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
    Node* prev;
    Node* next;
    Node* nuevoNodo;

    prev = (Node*)malloc(sizeof(Node));
    next = (Node*)malloc(sizeof(Node));

    if (this!=NULL && nodeIndex >-1 && nodeIndex <=ll_len(this))//si verificas que pElement !=NULL da errorfcr
    {
        nuevoNodo = (Node*) malloc(sizeof(Node));
        if (nuevoNodo !=NULL)
        {
            nuevoNodo->pElement = pElement;
            if (nodeIndex == 0 && ll_len(this) == 0) //sin la condicion de nodeindex da todo ok tambien
            {
                this->pFirstNode = nuevoNodo;//si la lista esta vacia
                nuevoNodo->pNextNode= NULL;
                this->size+=1;

                returnAux=0;
            }
            else
            {
                if (nodeIndex >0 && ll_len(this)>0 && nodeIndex<ll_len(this))//con nodeindex >-1 da todo ok tambien
                {
                    prev = getNode(this,nodeIndex-1);
                    next = getNode(this,nodeIndex);
                    prev->pNextNode = nuevoNodo;//El nodo del indice anterior apunta al nuevo
                    nuevoNodo->pNextNode = next;//El nuevo apunta al que estaba antes en esa posicion
                    this->size+=1;
                    returnAux=0;
                }
                else
                {
                    if (nodeIndex == ll_len(this))//si agrego uno mas a lo ultimo, para el ll_add
                    {
                        prev = getNode(this,nodeIndex-1);
                        prev->pNextNode = nuevoNodo;
                        nuevoNodo->pNextNode = NULL;
                        this->size+=1;
                        returnAux=0;
                    }
                }
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

    if (this!=NULL)
    {
            if(addNode(this,this->size,pElement)==0);//Agrega el elemento a lo ultimo
            {
               returnAux = 0;
            }
    }

    return returnAux;
}
//  ******* OJO CORREGIR *******************
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

    Node* aux;

    if (this!=NULL && index>-1 && index < ll_len(this))
    {
        aux = (Node*)malloc(sizeof(Node));
        if (aux!=NULL)
        {
            aux = getNode(this,index);
            returnAux = aux->pElement;
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
    Node* actual;
    //void* aux;
    if (this!=NULL)
    {
        if(index >-1 && index < this->size)
        {
            actual = (Node*)malloc(sizeof(Node));
            actual = getNode(this,index);
            actual->pElement = pElement;
            returnAux = 0;
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
    Node* prev;
    Node* actual;
    Node* next;

    if(this!= NULL && index >-1 && index <ll_len(this))
    {
        prev = (Node*)malloc(sizeof(Node));
        next = (Node*)malloc(sizeof(Node));

        if(index == 0 && ll_len(this)==1)//si hay un solo elemento en la lista
        {
        actual = getNode(this,index);
        this->pFirstNode = NULL;
        this->size= this->size - 1;
        free(actual);
        returnAux = 0;
        }
        else
        {
            if(index == 0 && ll_len(this)>1) //si hay mas de un elemento y el indice es 0
            {
                actual = getNode(this,index);
                next = getNode(this,index+1);
                this->pFirstNode = next;
                free(actual);
                this->size= this->size - 1;
                returnAux = 0;
            }
            else
            {
                if(index == ll_len(this)-1)//El ultimo elemento
                {
                    actual=getNode(this,index);
                    prev = getNode(this,index-1);
                    prev->pNextNode = NULL;
                    free(actual);
                    this->size= this->size - 1;
                    returnAux = 0;
                }
                else
                {
                    if (index > 0 && index < ll_len(this))// si esta en el medio
                    {
                        //prev = (Node*)malloc(sizeof(Node));
                       //actual = (Node*)malloc(sizeof(Node));

                        prev = getNode(this,index-1);
                        actual = getNode(this,index);
                        next = getNode(this,index+1);
                        prev->pNextNode = actual->pNextNode;
                        free(actual);
                        this->size= this->size - 1;

                        returnAux = 0;
                    }
                }
            }
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
    int i;
    if (this!=NULL)
    {
        for (i=0;i<ll_len(this);)//si pongo i++ queda un dato sin borrar, ll_remove ya le resta 1 a la lista
        {
            returnAux = ll_remove(this,i);
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
    if (this!=NULL)
    {
        returnAux = ll_clear(this);
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
    int i;
    Node* nodo;
    if (this!=NULL)
    {
        for (i=0;i<ll_len(this);i++)
        {
            nodo = getNode(this,i);
            if (nodo->pElement == pElement)
            {
                returnAux = i;
                break;
            }
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

    if(this != NULL)
    {
        if(ll_len(this)>0)//si lo dejo solo con la funcion tambien comtempla negativos como true
        {
            returnAux = 0;
        }
        else
        {
            //if (ll_len(this)==0)
            //{
                returnAux = 1;
            //}
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
    if (this!=NULL && index>-1 && index <= this->size)//< this->size da error
    {
        returnAux = addNode(this,index,pElement);
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
    if (this!=NULL && index>-1 && index<ll_len(this))
    {
        returnAux = ll_get(this,index);//puntero pElement
        ll_remove(this,index);//free el nodo
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
    //void* aux = NULL;
    int aux;
    if (this!=NULL)
    {
        /*
        for (i=0;i<ll_len(this);i++)//puedo simplificarlo con la funcion ll_index
        {
            aux = ll_get(this,i);
            if(aux == pElement)
            {
                returnAux = 1;
                break;
            }
        }
        */
        returnAux = 0;
        aux = ll_indexOf(this,pElement);
        if (aux !=-1)
        {
            returnAux = 1;
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
int ll_containsAll(LinkedList* this,LinkedList* this2)//falta 1 para todos los elementos
{
    int returnAux = -1;
    int i;
    void* aux;
    if(this!=NULL && this2!=NULL)
    {
        returnAux = 0;
        for (i=0;i<ll_len(this2);i++)
        {
            aux = ll_get(this2,i);
            returnAux = ll_contains(this,aux);
            if (returnAux==0)//mientras de 1, sigue iterando
            {
                break;
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
    void* pElement;

    if (this!=NULL && from >-1 && from <ll_len(this) && to >from && to <=ll_len(this))
    {

        cloneArray = ll_newLinkedList();
        for (i=from;i<to;i++)
        {
            pElement = ll_get(this,i);
            ll_add(cloneArray,pElement);
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
    if (this!=NULL && ll_len(this)>-1)
    {
        cloneArray = ll_subList(this,0,ll_len(this));
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
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*),int order)
{
    int returnAux =-1;
    int aux;
    int set_1,set_2;

    void* pElement_1=NULL;
    void* pElement_2=NULL;

    int i;
    int j;
    if (this!=NULL && pFunc!=NULL)
    {
        if (order == 1)
        {
            for (i=0;i<ll_len(this)-1;i++)
            {
                for (j=i+1;j<ll_len(this);j++)
                {
                    pElement_1 = ll_get(this,i);//PORQUE i ESTA APUNTANDO A OTRO LUGAR
                    pElement_2 = ll_get(this,j);
                    aux = pFunc(pElement_1,pElement_2);

                    if (aux == 1)
                    {
                        set_1=ll_set(this,i,pElement_2);
                        set_2=ll_set(this,j,pElement_1);
                    }
                }
            }
            returnAux = 0;
        }
        else
        {
            if (order == 0)
            {
                for (i=0;i<ll_len(this)-1;i++)
                {
                    for (j=i+1;j<ll_len(this);j++)
                    {
                        pElement_1 = ll_get(this,i);
                        pElement_2 = ll_get(this,j);

                        aux = pFunc(pElement_1,pElement_2);
                        if (aux == -1)
                        {
                            //pAux = ll_get(this,i);
                            set_1=ll_set(this,i,pElement_2);
                            set_2=ll_set(this,j,pElement_1);

                        }
                    }
                }
                returnAux = 0;
            }
        }
    }
    return returnAux;
}

