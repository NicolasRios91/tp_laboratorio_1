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
    if(this!=NULL && strlen(nombre)!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno = 1;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=0;

    if(this!=NULL)
    {
        strcpy(nombre, this->nombre);
        retorno=1;
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
    int retorno = 0;
    if (this!= NULL && id!=NULL)
    {
        *id = this->id;
        retorno = 1;
    }
    return retorno;
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
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=0;

    if(this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 1;
    }
    return retorno;
}


int employee_CompareByName(void* e1, void* e2)
{
    //verificar nulidad

    Employee* aux1;
    Employee* aux2;
    int ret;
    if(e1 !=NULL && e2!=NULL)
    {
        aux1 = (Employee*)e1;
        aux2 = (Employee*)e2;
        ret = strcmp(aux1->nombre,aux2->nombre);
    }

    return ret;
}

int employee_CompareById(void* e1, void* e2)
{
    Employee* aux1;
    Employee* aux2;
    //int id1;
    //int id2;
    int ret;
    if(e1 !=NULL && e2!=NULL)
    {
        aux1 = (Employee*)e1;
        aux2 = (Employee*)e2;
    }

    //employee_getId(aux1->id,&id1);
    //employee_getId(aux2->id,&id2);

    if(aux1->id > aux2->id)
    {
        ret = 1;
    }
    else
    {
        if(aux1->id < aux2->id)
        {
            ret = -1;
        }
        else
        {
            ret = 0;
        }
    }
    return ret;
}

int employee_CompareBySueldo(void* e1, void* e2)
{
    Employee* aux1;
    Employee* aux2;
    int ret;

    if(e1!=NULL && e2!=NULL)
    {
        aux1 = (Employee*) e1;
        aux2 = (Employee*) e2;

        if(aux1->sueldo > aux2->sueldo)
        {
            ret=1;

        }
        else
        {
            if(aux1->sueldo < aux2->sueldo)
            {
                ret=-1;
            }
            else
            {
                ret = 0;
            }
        }
    }

    return ret;
}

int employee_CompareByHoras(void* e1, void* e2)
{
    Employee* aux1;
    Employee* aux2;
    int ret;
    if(e1 !=NULL && e2!=NULL)
    {
        aux1 = (Employee*)e1;
        aux2 = (Employee*)e2;
    }

    if (aux1->horasTrabajadas > aux2->horasTrabajadas)
    {
        ret =1;
    }
    else
    {
        if (aux1->horasTrabajadas < aux2->horasTrabajadas)
        {
            ret = -1;
        }
        else
        {
            ret =0;
        }
    }
    return ret;
}
