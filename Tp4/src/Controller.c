#include "Controller.h"


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

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int ret =0;
    int idNuevo;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    int push;
    int control;
    Employee* aux;
    aux = employee_new();
    if (pArrayListEmployee!=NULL)
    {
        employee_getMaxId(pArrayListEmployee,&idNuevo);
        getStr("Ingrese el nombre: ",nombre,128);
        ConvertirPrimerCaracterStrMayus(nombre);

        horasTrabajadas = getInt("Ingrese las horas trabajadas: ");
        while (horasTrabajadas <1)
        {
            horasTrabajadas = getInt("Ingrese una cantidad valida: ");
        }

        sueldo = getInt("Ingrese el sueldo: ");
        while (sueldo <1)
        {
            sueldo = getInt("Ingrese un sueldo valido: ");
        }

        if (aux!=NULL)
        {
            if (employee_setId(aux,idNuevo)==1 && employee_setNombre(aux,nombre)==1 &&
                employee_setHorasTrabajadas(aux,horasTrabajadas)==1 && employee_setSueldo(aux,sueldo)==1)
            {
                printf("\nDonde desea agregar al nuevo empleado?\n\n");
                printf("(1)En un lugar especifico\n");
                printf("(0)Al final de la lista\n\n");
                push = getInt("Opcion: ");
                if (push==1)
                {
                    system("cls");
                    controller_ListEmployee(pArrayListEmployee);
                    printf("\nIndique la posicion: ");
                    scanf("%d",&push);
                    control =ll_push(pArrayListEmployee,push-1,aux);
                    if (control==0)
                    {
                        ret = 1;
                    }
                }
                else
                {
                ll_add(pArrayListEmployee,aux);
                ret = 1;
                }

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


    int i;
    int control;
    int opcion;
    int cambios;

    int auxSueldo;
    int auxHoras;
    char auxNombre[128];


    Employee* aux;
    control = controller_ListEmployee(pArrayListEmployee);
    if (control== 1)
    {
        IDingresado = getInt("\nIngrese la ID del empleado que desea modificar: ");
        for (i=0;i<ll_len(pArrayListEmployee);i++)
        {
            aux = ll_get(pArrayListEmployee,i);
            employee_getId(aux,&IDaux);

            if (IDingresado == IDaux)
            {
                strcpy(auxNombre,aux->nombre);
                auxHoras = aux->horasTrabajadas;
                auxSueldo = aux->sueldo;
                do
                {
                    system("cls");
                    printf("Empleado a modificar\n\n");
                    printf("ID:%d || NOMBRE: %s || HORAS: %d || SUELDO: %d\n\n",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);
                    printf("Datos modificados\n\n");
                    printf("ID:%d || NOMBRE: %s || HORAS: %d || SUELDO: %d\n\n",IDingresado,auxNombre,auxHoras,auxSueldo);
                    printf("(1) NOMBRE\n");
                    printf("(2) SUELDO\n");
                    printf("(3) HORAS TRABAJADAS\n");
                    printf("(4) APLICAR CAMBIOS\n");
                    printf("(5) SALIR\n\n");
                    printf("Elija una opcion : ");
                    fflush(stdin);
                    scanf("%d",&opcion);
                    switch(opcion)
                    {
                        case 1:
                            if (getStr("Ingrese el nuevo nombre: ",auxNombre,128)==0)
                            {
                                 ConvertirPrimerCaracterStrMayus(auxNombre);
                                 printf("El cambio se guardo\n");
                                 cambios = 1;
                            }
                            else
                            {
                                strcpy(auxNombre,aux->nombre);
                            }
                            printf("Presione una tecla para continuar...");
                            getch();
                            break;
                        case 2:
                            auxSueldo = getInt("Ingrese el nuevo sueldo: ");
                            if ((ValidarInt(auxSueldo,1))==0)
                            {
                                cambios = 1;
                                printf("El cambio se guardo\n");
                            }
                            else
                            {
                                auxSueldo = aux->sueldo;
                                printf("No se pudo guardar el sueldo\n");
                            }
                            printf("Presione una tecla para continuar...");
                            getch();

                            break;
                        case 3:
                            auxHoras = getInt("Ingrese las nuevas horas trabajadas: ");
                            if (ValidarInt(auxHoras,1)==0)
                            {
                                cambios = 1;
                                printf("El cambio se guardo\n");
                            }
                            else
                            {
                                auxHoras = aux->horasTrabajadas;
                                printf("No se pudieron guardar las horas\n");
                            }
                            printf("Presione una tecla para continuar...");
                            getch();

                            break;
                        case 4:
                            if (cambios ==1)
                            {
                                Employee* pElement = employee_new();
                                employee_setId(pElement,IDingresado);
                                employee_setSueldo(pElement,auxSueldo);
                                employee_setHorasTrabajadas(pElement,auxHoras);
                                employee_setNombre(pElement,auxNombre);

                                ll_set(pArrayListEmployee,i,pElement);
                                printf("\nSe aplicaron los cambios, puede verlos en la lista de empleados\n\npresione una tecla para continuar...\n");
                                ret = 0;
                            }
                            else
                            {
                                printf("\nNo hay cambios para aplicar,presione una tecla para continuar...\n");
                            }
                            getch();
                            break;
                        default:
                            break;
                    }
                }while(opcion!=5);
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
        printf("\nCantidad de empleados: %d\n\n",len);
        ret = 1;
        printf ("ID      NOMBRE        HORAS TRABAJADAS      SUELDO\n\n");
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
