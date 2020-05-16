#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

#define LIBRE 0
#define OCUPADO 1
#define ELEMENTOSARRAY 51

#include "funciones.h"
#include "menu.h"
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>


typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}Employee;


/** \brief Muestra la informacion de una variable del tipo Employee
*
* \param lista Employee, variable a mostrar
*
*/
void PrintEmployee(Employee lista);



/** \brief Muestra la informacion de un array del tipo Employee
*
* \param lista Employee[] array de empleados
* \param tam largo del array
* \return int return (-1) si no muestra ninguno, 0 si pudo
*/
int PrintEmployees(Employee lista[], int tam);



/** \brief Pone la bandera isEmpty en LIBRE de todas las posiciones del array
*
* \param lista Employee[] array de empleados
* \param tam int, largo del array
* \return int return (-1) si no hay empleados cargados, 0 si existen
*/
int InitEmployees (Employee lista[],int tam);




/** \brief Busca en el array si hay por lo menos 1 empleado cargado
*
* \param lista Employee[], array de empleados
* \param tam int, largo del array
* \return int return (-1) si no hay empleados cargados, 0 si hay por lo menos uno
*/
int SaberSiHayEmpleados (Employee lista[], int tam);



/** \brief Busca el primer indice libre dentro de un array del tipo de dato Employee
*
* \param lista Employee[] array de empleados
* \param tam int largo del array
* \return int return (-1) si no hay espacio libre, o el indice libre si existe
*/
int BuscarLibre(Employee lista[],int tam);


/** \brief Pide valores y los pasa por parametro a la funcion addEmployee, recibe una id que se autoincrementa al agregar un empleado a la lista
*
* \param lista Employee[] array de empleados
* \param tam largo del array
* \param idAnterior ultimo id cargado, se autoincrementa si se pudo cargar al empleado
* \param msj[] char mensaje afirmativo de carga
* \param error[] char mensaje de error
* \return int return idAnterior con el mismo valor en caso de no poder cargar al empleado, caso contrario devuelve el idAnterior +1
*/
int CargarEmpleado(Employee lista[],int tam,int idAnterior,char msj[],char error[]);


/** \brief Recibe un array del tipo Employe,busca el primer indice libre y le asigna los valores asignados por parametro
*
* \param lista Employee[] array de empleados
* \param tam largo del array
* \param idAnterior int, recibe el id y le suma 1 para el nuevo registro
* \param name[] char
* \param lastname[] char
* \param salary float
* \param sector int
* \return int return (-1) si no hay espacio, 0 si se pudieron asignar los valores
*/
int addEmployee(Employee lista[],int tam,int idAnterior,char name[],char lastName[],float salary,int sector);



/** \brief Recibe un array del tipo Employe y busca el empleado con la id ingresada por parametro
*
* \param lista Employee[] array de empleados
* \param tam int largo del array
* \param id ID buscada en el array
* \return int return (-1) si no existe, o sino devuelve el indice encontrado
*/
int FindEmployee(Employee lista[],int tam, int id);



/** \brief Recibe un array del tipo Employe y realiza la modificacion de un empleado
*
* \param lista Employee[] array de empleados
* \param tam largo del array
*/
void ModifiyEmployee(Employee lista[],int tam);


/** \brief Recibe un array del tipo Employe y busca el empleado con la id ingresada por parametro para borrarlo
*
* \param lista Employee[] array de empleados
* \param tam int largo del array
* \param id int ID buscada en el array
* \param confirma[] char, msj cuando se borro el dato
* \param cancela[] char, msj cuando se cancela la operacion
* \param error[] char,msj cuando no existe la id
* \return int return (-1) si no se borro el dato, 0 si pudo borrarse
*/
int RemoveEmployee(Employee lista[],int tam, int id,char confirma[],char cancela[],char error[]);


/** \brief Recibe un array del tipo Employe y lo ordena segun el parametro ingresado ( 1 ascendente y 0 descendente)
*
* \param lista Employee[] array de empleados
* \param tam int largo del array
* \param id ID buscada en el array
* \return int return (-1) si la opcion ingresada es invalida, 0 si se hizo el ordenamiento
*/
int OrdenarLista(Employee lista[],int tam,int orden);


/** \brief Recibe un array del tipo Employe para sacar el promedio de los salarios
*
* \param lista Employee[] array de empleados
* \param tam int largo del array
* \return float return Valor del promedio de salarios
*/
float SacarPrommedio (Employee lista[],int tam);


/** \brief Recibe un array del tipo Employe y busca la cantidad de empleados que ganan mas del salario promedio
*
* \param lista Employee[] array de empleados
* \param tam largo del array
* \param flot promedio, promedio del salario de los empleados
* \return int return 0 si nadie lo supera
*/
int SacarEmpleadosMayorAlPromedio(Employee lista[], int tam, float promedio);


#endif // ARRAYEMPLOYEES_H_INCLUDED
