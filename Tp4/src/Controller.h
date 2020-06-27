
#include "../inc/LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "funciones.h"


/** \brief Carga una lista al programa en formato txt
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (1 si cargo - 0 no pudo).
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);


/** \brief agrega un nuevo empleado a la lista
 *
 * \param pArrayListEmployee LinkedList*
 * \return int (1 Si se agrego - 0 no pudo)
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);


/** \brief modifica los datos de un empleado de la lista
 *
 * \param pArrayListEmployee LinkedList*
 * \return int (1 pudo - 0 no pudo o lista vacia)
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);



/** \brief elimina un empleado de la lista
 *
 * \param pArrayListEmployee LinkedList*
 * \return int (1 pudo - 0 no pudo o lista vacia)
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);


/** \brief lista los empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int (1 pudo mostrar - 0 no pudo)
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);


/** \brief ordena la lista de empleados segun el parametro ingresado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int (1 se reordeno la lista - 0 no se reordeno)
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);


/** \brief guarda una lista en un archivo formato txt
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int (1 pudo guardar - 0 no pudo)
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

