#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char* nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Constructor de variable de tipo Employee en memoria dinamica
 *
 * \return Employee*
 *
 */
Employee* employee_new();

/** \brief Constructor por parametros de variable de tipo Employee en memoria dinamica
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee*
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);

/** \brief Ejecuta la funcion free sobre un puntero ingresado por parametro
 *
 * \param Employee*
 * \return void
 *
 */
void employee_delete(Employee*);

/** \brief setea la id del empleado
 *
 * \param this Employee*
 * \param id int
 * \return int (1 si se pudo setear - 0 no se pudo)
 *
 */

int employee_setId(Employee* this,int id);

/** \brief getter del id del empleado
 *
 * \param this Employee*
 * \param id int*
 * \return int (1 si pudo copiarla - 0 no se pudo)
 *
 */
int employee_getId(Employee* this,int* id);


/** \brief setea el nombre del empleado
 *
 * \param this Employee*
 * \param nombre char*
 * \return int (1 si pudo setear - 0 no se pudo)
 *
 */
int employee_setNombre(Employee* this,char* nombre);


/** \brief getter del nombre del empleado
 *
 * \param this Employee*
 * \param nombre char*
 * \return int (1 si lo pudo copiar - 0 no pudo)
 *
 */
int employee_getNombre(Employee* this,char* nombre);


/** \brief setea las horas trabajadas
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return int (1 si pudo setear - 0 no se pudo)
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief getter de las horas trabajadas
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int (1 si lo pudo copiar - 0 no pudo)
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief setea el sueldo del empleado
 *
 * \param this Employee*
 * \param sueldo int
 * \return int (1 si pudo setear - 0 no se pudo)
 *
 */
int employee_setSueldo(Employee* this,int sueldo);

/** \brief getter del sueldo
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int (1 si lo pudo copiar - 0 no pudo)
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief compara las horas de una lista para ordenarlos
 *
 * \param void* e1
 * \param void* e2
 * \return int (1 si e1 mayor e2 , 0 iguales , -1 e1 menor e2)
 *
 */
int employee_CompareByHoras(void* e1, void* e2);

/** \brief compara los sueldos de una lista para ordenarlos
 *
 * \param void* e1
 * \param void* e2
 * \return int (1 si e1 mayor e2 , 0 iguales , -1 si e1 menor e2)
 *
 */
int employee_CompareBySueldo(void* e1, void* e2);

/** \brief compara las ids de una lista para ordenarlos
 *
 * \param void* e1
 * \param void* e2
 * \return int (1 si e1 mayor e2 , 0 iguales , -1 si e1 menor e2)
 *
 */
int employee_CompareById(void* e1, void* e2);

/** \brief compara los nombres de una lista para ordenarlos
 *
 * \param void* e1
 * \param void* e2
 * \return int (1 si e1 mayor e2 , 0 iguales , -1 si e1 menor e2)
 *
 */
int employee_CompareByName(void* e1, void* e2);




#endif // employee_H_INCLUDED
