#include <stdlib.h>
#include "Employee.h"
#include <string.h>

Employee* employee_new()
{
    Employee* miEmpleado;
    miEmpleado = (Employee*) malloc(sizeof(Employee));

    return miEmpleado;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* miEmpleado = employee_new();
    if (miEmpleado !=NULL)
    {
        miEmpleado->id = atoi(idStr);
        strcpy(miEmpleado->nombre,nombreStr);
        miEmpleado->horasTrabajadas = atoi(horasTrabajadasStr);
        miEmpleado->sueldo = atoi(sueldoStr);
    }
    return miEmpleado;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = 0;
    if (this!= NULL)
    {
        strcpy(this->nombre,nombre);
        retorno = 1;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = 0;
    if (this!=NULL && nombre!= NULL)
    {
        strcpy(nombre,this->nombre);
        retorno = 1;
    }
    return retorno;
}


int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = 0;
    if (this!= NULL && sueldo >0)
    {
        this->sueldo = sueldo;
        retorno = 1;
    }
    return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = 0;
    if (this!=NULL && sueldo!=NULL)
    {
        *sueldo = this->sueldo;
        retorno = 1;
    }
    return retorno;
}

int employee_setId(Employee* this,int id)
{
    int retorno = 0;
    if (this!= NULL)
    {
        this->id = id;
        retorno = 1;
    }
    return retorno;
}
int employee_getId(Employee* this,int* id)
{

}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = 0;
    if (this!=NULL && horasTrabajadas>0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 1;
    }
    return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajdas)
{


}


int employee_CompareByName(Employee* e1, Employee* e2)
{
    //verificar nulidad

    return strcmp(e1->nombre, e2->nombre);
}

int employee_CompareById(Employee* e1, Employee* e2)
{
    //verificar nulidad

    if(e1->id > e2->id)
    {
        return 1;
    }
    else
    {
        if(e1->id < e2->id)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }



    return strcmp(e1->nombre, e2->nombre);
}



