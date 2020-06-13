#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"



int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int ret=0;
    FILE* archivo;
    ll_clear(pArrayListEmployee);
    archivo = fopen(path,"r");
    if (pArrayListEmployee!=NULL && archivo!=NULL)
    {
        parser_EmployeeFromText(archivo,pArrayListEmployee);
        ret=1;
    }
    //ret = ll_isEmpty(pArrayListEmployee);//0 esta cargada, 1 esta vacia
    fclose(archivo);
return ret;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int ret=0;;
    FILE* archivo;
    ll_clear(pArrayListEmployee);
    archivo = fopen(path,"rb");
    if (pArrayListEmployee!=NULL && archivo!=NULL)
    {
        parser_EmployeeFromBinary(archivo,pArrayListEmployee);
        ret=1;
    }
    //ret = ll_isEmpty(pArrayListEmployee);
    fclose(archivo);

return ret;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int ret =0;
    int idNuevo;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

    Employee* aux;
    aux = employee_new();
    if (pArrayListEmployee!=NULL)
    {
        employee_getMaxId(pArrayListEmployee,&idNuevo);
        printf("Ingrese el nombre: ");
        fflush(stdin);
        fgets(nombre,128,stdin);
        nombre[strlen(nombre)-1]='\0';
        printf("Ingrese las horas Trabajadas: ");
        scanf("%d",&horasTrabajadas);
        printf("Ingrese el sueldo: ");
        scanf("%d",&sueldo);

        if (aux!=NULL)
        {
            if (employee_setId(aux,idNuevo)==1 && employee_setNombre(aux,nombre)==1 &&
                employee_setHorasTrabajadas(aux,horasTrabajadas)==1 && employee_setSueldo(aux,sueldo)==1)
            {
                ll_add(pArrayListEmployee,aux);
                ret = 1;
            }
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


    int auxSueldo;
    int auxHoras;
    char auxNombre[128];
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
                    system("cls");
                    printf("Empleado a modificar\n\n");
                    printf("ID:%d || NOMBRE: %s || HORAS: %d || SUELDO: %d\n\n",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);
                    printf("(1) NOMBRE\n");
                    printf("(2) SUELDO\n");
                    printf("(3) HORAS TRABAJADAS\n");
                    printf("(4) SALIR\n\n");
                    printf("Elija una opcion : ");
                    fflush(stdin);
                    scanf("%d",&opcion);
                    switch(opcion)
                    {
                        case 1:
                            printf("Ingrese el nuevo nombre: ");
                                fflush(stdin);
                                fgets(auxNombre,128,stdin);
                                auxNombre[strlen(auxNombre)-1]='\0';
                            if(employee_setNombre(aux2,auxNombre)==0)
                            {
                                printf("no se pudo guardar el cambio\n");
                            }
                            else
                            {
                                employee_setNombre(aux,auxNombre);
                                printf("El cambio se guardo\n");
                                ret =1;
                            }
                            printf("Presione una tecla para continuar...");
                            getch();
                            free(aux2);
                            break;
                        case 2:
                            printf("Ingrese el nuevo sueldo: ");
                            scanf("%d",&auxSueldo);
                            if (employee_setSueldo(aux2,auxSueldo)==0)
                            {
                                printf("No se pudo guardar el sueldo\n");
                            }
                            else
                            {
                                employee_setSueldo(aux,auxSueldo);
                                printf("El cambio se guardo\n");
                                ret =1;
                            }
                            printf("Presione una tecla para continuar...");
                            getch();
                            free(aux2);
                            break;
                        case 3:
                            printf("Ingrese las nuevas horas trabajadas: ");
                            scanf("%d",&auxHoras);
                            if (employee_setHorasTrabajadas(aux2,auxHoras)==0)
                            {
                                printf("No se pudieron guardar las horas\n");
                            }
                            else
                            {
                                employee_setHorasTrabajadas(aux,auxHoras);
                                printf("El cambio se guardo\n");
                                ret =1;
                            }
                            printf("Presione una tecla para continuar...");
                            getch();
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
            if(IDingresado == IDaux)
            {
                indiceEncontrado = ll_indexOf(pArrayListEmployee,aux);
                ret = ll_remove(pArrayListEmployee,indiceEncontrado);
                break;
            }
        }
    }
    return ret;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)//
{
    int auxID;
    char auxStr[128];
    int auxHoras;
    int auxSueldo;
    int ret=0;
    int i;
    int len;
    int control;
    int contador=0;
    Employee* aux;
    control = ll_isEmpty(pArrayListEmployee);//0 esta cargada, 1 esta vacia
    if(control ==0)
    {
        len = ll_len(pArrayListEmployee);
        printf("Cantidad de empleados: %d\n\n",len);
        ret = 1;
        printf ("ID      NOMBRE        HORAS TRABAJADAS      SUELDO\n");
        for (i=0;i<len;i++)
        {
            aux = ll_get(pArrayListEmployee,i);
            employee_getId(aux,&auxID);
            employee_getNombre(aux,auxStr);
            employee_getHorasTrabajadas(aux,&auxHoras);
            employee_getSueldo(aux,&auxSueldo);
            printf("%-7d %-20s %-14d %d\n",auxID,auxStr,auxHoras,auxSueldo);
            contador++;
            if(contador%250==0)
            {
                printf("\nPresione una tecla para seguir viendo la lista...\n");
                getch();
            }
        }
    }

return ret;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{

    int ret =0;
    int opcion;
    int orden;
    if(pArrayListEmployee!=NULL && ll_isEmpty(pArrayListEmployee)==0)
    {
        system("cls");
        printf("Modos de Ordenamiento\n\n");
        printf("1 para ascendente\n0 para descendente\n\n");
        printf("Seleccione el modo: ");
        fflush(stdin);
        scanf("%d",&orden);
        while(orden !=1 && orden!=0)
        {
            printf("Seleccione uno de los valores indicados, 1 o 0 : ");
            fflush(stdin);
            scanf("%d",&orden);
        }
        do
        {
            system("cls");
            if (orden==1)
            {
                printf("Eligio el modo ascendente\n");
            }
            else
            {
                printf("Eligio el modo descendente\n");
            }

            printf("\nLista de criterios\n\n");
            printf("(1)NOMBRE\n(2)SUELDO\n(3)ID\n(4)HORAS TRABAJADAS\n(5)SALIR\n\nElija una opcion: ");
            fflush(stdin);
            scanf("%d",&opcion);
            switch(opcion)
            {
            case 1:
                printf("Espere por favor...\n");
                ll_sort(pArrayListEmployee,employee_CompareByName,orden);
                printf("Se ordeno la lista\n");
                ret=1;
                getch();
                break;
            case 2:
                printf("Espere por favor...\n");
                ll_sort(pArrayListEmployee,employee_CompareBySueldo,orden);
                printf("Se ordeno la lista\n");
                ret=1;
                getch();
                break;
            case 3:
                printf("Espere por favor...\n");
                ll_sort(pArrayListEmployee,employee_CompareById,orden);
                printf("Se ordeno la lista\n");
                ret=1;
                getch();
                break;
            case 4:
                printf("Espere por favor...\n");
                ll_sort(pArrayListEmployee,employee_CompareByHoras,orden);
                printf("Se ordeno la lista\n");
                ret=1;
                getch();
                break;
            case 5:
                break;
            default:
                printf("Ingrese una opcion valida\n");
                break;
            }
        }while(opcion!=5);
    }
return ret;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    Employee* aux = employee_new();
    int len;
    int i;
    int ret=0;
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    FILE* archivo;
    archivo = fopen(path,"w");
    len = ll_len(pArrayListEmployee);
    if (archivo!=NULL && pArrayListEmployee !=NULL)
    {
        fprintf(archivo, "id, nombre, horasTrabajadas, sueldo\n");
        for (i=0;i<len;i++)
        {
        aux = ll_get(pArrayListEmployee,i);

        employee_getId(aux,&id);
        employee_getNombre(aux,nombre);
        employee_getHorasTrabajadas(aux,&horasTrabajadas);
        employee_getSueldo(aux,&sueldo);

        fprintf(archivo,"%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);
        }
        ret =1;
    }
    fclose(archivo);

return ret;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* archivo;
    int ret=0;
    int i;
    int len;
    Employee* auxEmpleado;
    int aux;

    archivo = fopen(path, "wb");
    len = ll_len(pArrayListEmployee);

    if(archivo!=NULL && pArrayListEmployee!=NULL)
    {
        fwrite(&len, sizeof(int), 1, archivo);
        printf("Cantidad de datos: %d\n", len);

        for(i=0; i<len; i++)
        {
            auxEmpleado = ll_get(pArrayListEmployee, i);
            aux = fwrite(auxEmpleado, sizeof(Employee), 1, archivo);

        }
        printf("\nSe guardo la lista\n");
        fclose(archivo);
        ret = 1;
    }
return ret;
}

