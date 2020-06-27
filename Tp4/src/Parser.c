#include "Parser.h"


int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int ret=0;
    char a[500],b[500],c[500],d[500];
    int r;
    Employee* empleado;
    r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",a,b,c,d);//para no mostrar la primer linea
        while(!feof(pFile))
        {
            if(feof(pFile))
            {
                break;
            }
            r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",a,b,c,d);
            if (r==4)
            {
                empleado = employee_newParametros(a,b,c,d);
                ll_add(pArrayListEmployee,empleado);
                ret =1;
            }
        }
    return ret;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee aux;
    Employee* empleado;
    int len;
    int r;
    int retorno=0;
    char a[500],b[500],c[500],d[500];

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        r = fread(&len, sizeof(int), 1, pFile);//para leer la primer linea
        while(!feof(pFile))
        {
            r = fread(&aux, sizeof(Employee), 1, pFile);
            if(r==1)
            {
                sprintf(a,"%d",aux.id);
                strcpy(b,aux.nombre);
                sprintf(c,"%d",aux.horasTrabajadas);
                sprintf(d,"%d",aux.sueldo);
                empleado = employee_newParametros(a, b, c, d);
                ll_add(pArrayListEmployee, empleado);
                retorno=1;
            }
        }
    }
    return retorno;
}

int employee_getMaxId(LinkedList* pArrayListEmployee,int* idNueva)
{
    int len;
    int i;
    int auxID;
    Employee* aux;
    int ret=0;

    if(pArrayListEmployee!=NULL && idNueva!=NULL)
    {
        len = ll_len(pArrayListEmployee);

        if(len==0)
        {
            *idNueva=1;
        }
        else
        {
            for(i=0; i<len; i++)
            {
                aux = ll_get(pArrayListEmployee, i);
                employee_getId(aux, &auxID);
                if(*idNueva < auxID || i==0)
                {
                    *idNueva = auxID;
                }
            }
        *idNueva+=1;
        ret=1;
        }
    }
    return ret;
}
