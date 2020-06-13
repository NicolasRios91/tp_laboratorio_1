#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.dat (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.dat (modo binario).
    10. Salir
*****************************************************/


int main()
{
    LinkedList* miLista;
    miLista = ll_newLinkedList();
    int control;
    int opcion;
    do
    {
        system("cls");
        printf("    Menu:\n");
        printf(" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
        printf(" 2. Cargar los datos de los empleados desde el archivo data.dat (modo binario).\n");
        printf(" 3. Alta de empleado\n");
        printf(" 4. Modificar datos de empleado\n");
        printf(" 5. Baja de empleado\n");
        printf(" 6. Listar empleados\n");
        printf(" 7. Ordenar empleados\n");
        printf(" 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
        printf(" 9. Guardar los datos de los empleados en el archivo data.dat (modo binario).\n");
        printf("10. Salir\n\n");
        printf("Elija una opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                control = controller_loadFromText("data.csv",miLista);
                if (control ==0)
                {
                    printf("\nNo se cargo la lista\n");
                }
                else
                {
                    printf("\nLa lista fue cargada\n");
                }
                printf("Presione una tecla para continuar...");
                getch();
                break;
            case 2:
                control = controller_loadFromBinary("data.dat",miLista);
                if (control ==1)
                {
                    printf("\nLa lista esta vacia\n");
                }
                else
                {
                    printf("\nLa lista fue cargada\n");
                }
                printf("Presione una tecla para continuar...");
                getch();
                break;
            case 3:
                printf("\nCARGA DE EMPLEADO\n\n");
                control = controller_addEmployee(miLista);
                if (control == 1)
                {
                    printf("\nSe agrego al empleado\n");
                }
                else
                {
                    printf("\nNo se pudo agregar al empleado\n");
                }
                printf("Presione una tecla para continuar...");
                getch();
                break;
            case 4:
                control = controller_editEmployee(miLista);
                if (control!=1)
                {
                    printf("No se hizo ningun cambio o no hay datos para modificar\n");
                    getch();
                }
                break;
            case 5:
                system("cls");
                control = controller_removeEmployee(miLista);
                if (control == 0)
                {
                    printf("\nSe borro el empleado\n");
                }
                else
                {
                    printf("\nNo se borro el empleado o la lista esta vacia\n");
                }
                printf("Presione una tecla para continuar...");
                getch();
                break;
            case 6:
                system("cls");
                control = controller_ListEmployee(miLista);
                if (control == 0)
                {
                    printf("\nLa lista esta vacia\n");
                }
                printf("Presione una tecla para continuar...");
                getch();
                break;
            case 7:
                control = controller_sortEmployee(miLista);
                if (control==0)
                {
                    printf("\nNo se realizo ningun cambio o la lista esta vacia\n");
                    printf("Presione una tecla para continuar...");
                    getch();
                }
                break;
            case 8:
                control = controller_saveAsText("data.csv",miLista);
                if (control==1)
                {
                    printf("Se guardo la lista\n");
                }
                else
                {
                    printf("No se guardo la lista\n");
                }
                printf("Presione una tecla para continuar...");
                getch();
                break;
            case 9:
                control = controller_saveAsBinary("data.dat",miLista);
                if (control==1)
                {
                    printf("Se guardo la lista\n");
                }
                else
                {
                    printf("No se guardo la lista\n");
                }
                printf("Presione una tecla para continuar...");
                getch();
                break;
        }
    }while(opcion !=10);
    return 0;
}

