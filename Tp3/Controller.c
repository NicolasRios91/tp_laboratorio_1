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
    int ret =0;
    int id;
    char nombre[100];
    int horasTrabajadas;
    int sueldo;
    Employee* aux;
    aux = employee_new();

    printf("Ingrese el id: ");
    scanf("%d",&id);
    printf("Ingrese el nombre: ");
    fflush(stdin);
    fgets(nombre,100,stdin);
    nombre[strlen(nombre)-1]='\0';
    printf("Ingrese las horas Trabajadas: ");
    scanf("%d",&horasTrabajadas);
    printf("Ingrese el sueldo: ");
    scanf("%d",&sueldo);

    if (aux!=NULL)
    {
        if (employee_setId(aux,id)==1 && employee_setNombre(aux,nombre)==1 &&
            employee_setHorasTrabajadas(aux,horasTrabajadas)==1 && employee_setSueldo(aux,sueldo)==1)
        {
            ll_add(pArrayListEmployee,aux);
            ret = 1;
        }
    }
return ret;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int ret = -1;
    int IDingresado;
    int IDaux;
    int control;
    int i;
    int opcion;
    int indiceEncontrado;

    int auxSueldo;
    int auxHoras;
    char auxNombre[100];
    Employee* aux;
    Employee* aux2 = employee_new();
    control = controller_ListEmployee(pArrayListEmployee);
    if (control== 1)
    {
        printf("Ingrese la ID del empleado que desea modificar: ");
        scanf("%d",&IDingresado);
        for (i=0;i<ll_len(pArrayListEmployee);i++)
        {
            aux = ll_get(pArrayListEmployee,i);
            employee_getId(aux,&IDaux);
            if (IDingresado == IDaux)
            {
                do
                {
                    printf("MENU MODIFICAR\n\n");
                    printf("(1) NOMBRE\n");
                    printf("(2) HORAS TRABAJADAS\n");
                    printf("(3) SUELDO\n");
                    printf("(4) SALIR\n\n");
                    printf("Elija una opcion : ");
                    fflush(stdin);
                    scanf("%d",&opcion);
                    switch(opcion)
                    {
                        case 1:
                            printf("Ingrese el nuevo nombre: ");
                                fflush(stdin);
                                fgets(auxNombre,100,stdin);
                                auxNombre[strlen(auxNombre)-1]='\0';
                            if(employee_setNombre(aux2,auxNombre)==0)
                            {
                                printf("no se pudo guardar el cambio\n");
                            }
                            else
                            {
                                employee_setNombre(aux,auxNombre);
                                printf("El cambio se guardo\n");
                            }
                            free(aux2);
                            break;
                        case 2:
                            printf("Ingrese el nuevo sueldo: ");
                            scanf("%d",auxSueldo);
                            if (employee_setSueldo(aux2,auxSueldo)==0)
                            {
                                printf("No se pudo guardar el sueldo\n");
                            }
                            else
                            {
                                employee_setSueldo(aux,auxSueldo);
                                printf("El cambio se guardo\n");
                            }
                            free(aux2);
                            break;
                        case 3:
                            printf("Ingrese las nuevas horas trabajadas: ");
                            scanf("%d",auxHoras);
                            if (employee_setHorasTrabajadas(aux2,auxHoras)==0)
                            {
                                printf("No se pudieron guardar las horas\n");
                            }
                            else
                            {
                                employee_setHorasTrabajadas(aux,auxHoras);
                                printf("El cambio se guardo\n");
                            }
                            free(aux2);
                            break;
                        case 4:
                            break;
                        default:
                            printf("Ingrese una opcion valida\n");
                            break;
                    }
                }while(opcion!=4);
                break;
            }
        }
    }
return ret;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)//-1 si no pudo, 0 si pudo borrar
{
    int ret=-1;
    int IDingresado;
    int IDaux;
    int control;
    int i;
    int indiceEncontrado;
    Employee* aux;
    control = controller_ListEmployee(pArrayListEmployee);
    if (control !=0)
    {
        printf("Ingrese la ID del empleado que desea eliminar: ");
        scanf("%d",&IDingresado);
        for (i=0;i<ll_len(pArrayListEmployee);i++)
        {
            aux = ll_get(pArrayListEmployee,i);
            employee_getId(aux,&IDaux);
            if(IDingresado == IDaux )
            {
                indiceEncontrado = ll_indexOf(pArrayListEmployee,aux);
                ret = ll_remove(pArrayListEmployee,indiceEncontrado);
                break;
            }
        }
    }
    return ret;
return 1;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)//
{
    int auxID;
    char auxStr[50];
    int auxHoras;
    int auxSueldo;
    int ret=0;
    int i;
    int len;
    int control;
    Employee* aux;
    control = ll_isEmpty(pArrayListEmployee);//0 esta cargada, 1 esta vacia
    if(control ==0)
    {
        len = ll_len(pArrayListEmployee);
        ret = 1;
        printf ("ID      NOMBRE        HORAS TRABAJADAS      SUELDO\n");
        for (i=0;i<len;i++)
        {
            aux = ll_get(pArrayListEmployee,i);
            if(employee_getId(aux,&auxID)==1 && employee_getNombre(aux,auxStr)==1 &&
               employee_getHorasTrabajadas(aux,&auxHoras)==1 && employee_getSueldo(aux,&auxSueldo)==1 )
            {
                printf("%-7d %-20s %-14d %d\n",auxID,auxStr,auxHoras,auxSueldo);
            }
        }
    }

return ret;
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

