
#include "../inc/LinkedList.h"
#include "funciones.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

int employee_getMaxId(LinkedList* pArrayListEmployee,int* idNueva);

