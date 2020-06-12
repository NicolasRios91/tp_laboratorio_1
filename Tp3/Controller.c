#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"



int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int ret;
    FILE* archivo;
    archivo = fopen(path,"r");
    ll_clear(pArrayListEmployee);
    parser_EmployeeFromText(archivo,pArrayListEmployee);
    ret = ll_isEmpty(pArrayListEmployee);//0 esta cargada, 1 esta vacia
    fclose(archivo);
return ret;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
return 1;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    char nombre[100];
    int horasTrabajadas;
    int sueldo;
    Employee* aux;
    printf("Ingrese el id: ");
    scanf("%d",&id);
    printf("Ingrese el nombre: ");
    fflush(stdin);
    fgets(nombre,128,stdin);
    nombre[strlen(nombre)-1]='\0';
    printf("Ingrese las horas Trabajadas: ");
    scanf("%d",&horasTrabajadas);
    printf("Ingrese el sueldo");
    scanf("%d",&sueldo);

    aux = employee_new();
    employee_setId(aux,id);
    employee_setNombre(aux,nombre);
    employee_setHorasTrabajadas(aux,horasTrabajadas);
    employee_setSueldo(aux,sueldo);
    ll_add(pArrayListEmployee,aux);

return 1;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
return 1;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
return 1;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int len;
    Employee* aux;
    len = ll_len(pArrayListEmployee);
    for (i=0;i<len;i++)
    {
        aux = ll_get(pArrayListEmployee,i);
        printf("%d %s %d %d\n",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);
    }
return 1;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
return 1;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    Employee* aux = employee_new();
    int len;
    int i;
    FILE* archivo;
    archivo = fopen(path,"w");
    if (archivo!=NULL)
    {
        len = ll_len(pArrayListEmployee);
        for (i=0;i<len;i++)
        {
        aux = ll_get(pArrayListEmployee,i);
        //fwrite(aux,sizeof(Employee),1,archivo);
        fprintf(archivo,"%d,%s,%d,%d\n",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);
        }
    }
    fclose(archivo);

return 1;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
return 1;
}

