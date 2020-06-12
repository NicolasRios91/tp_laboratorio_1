#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int ret =0;
    char a[500],b[500],c[500],d[500];
    int r;
    //pFile = fopen("data.csv","r");
    Employee* empleado;
    //fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",a,b,c,d);
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
                ret = 1;
            }
        }
    //fclose(pFile);
    return ret;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{

    return 1;
}
