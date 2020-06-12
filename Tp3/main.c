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
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    FILE* ID;
    ID = fopen("ID.csv","w");
    fprintf(ID,"%d",1);
    fclose(ID);
    FILE* fp;
    LinkedList* miLista = ll_newLinkedList();
    int size;
    int control;
    Employee* aux;
    int i;
    int opcion;

    int len;
    do
    {
        system("cls");
        printf("    Menu:\n");
        printf(" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
        printf(" 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
        printf(" 3. Alta de empleado\n");
        printf(" 4. Modificar datos de empleado\n");
        printf(" 5. Baja de empleado\n");
        printf(" 6. Listar empleados\n");
        printf(" 7. Ordenar empleados\n");
        printf(" 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
        printf(" 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
        printf("10. Salir\n");
        printf("Elija una opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                control = controller_loadFromText("data.csv",miLista);
                if (control ==1)
                {
                    printf("La lista esta vacia\n");
                }
                else
                {
                    printf("La lista fue cargada\n");
                }
                getch();
                break;
            case 2:
                break;
            case 3:
                system("cls");
                control = controller_addEmployee(miLista);
                if (control == 1)
                {
                    printf("Se agrego al empleado\n");
                }
                else
                {
                    printf("No se pudo agregar al empleado\n");
                }
                getch();
                break;
            case 4:
                system("cls");
                control = controller_editEmployee(miLista);
                break;
            case 5:
                system("cls");
                control = controller_removeEmployee(miLista);
                if (control == 0)
                {
                    printf("Se borro el empleado\n");
                }
                else
                {
                    printf("No se borro el empleado o la lista esta vacia\n");
                }
                getch();
                break;
            case 6:
                system("cls");
                control = controller_ListEmployee(miLista);
                if (control == 0)
                {
                    printf("La lista esta vacia\n");
                }
                getch();
                break;
            case 7:
                system("cls");
                getch();
                break;
            case 8:
                system("cls");
                controller_saveAsText("data.csv",miLista);
                getch();
                break;
        }
    }while(opcion !=10);
    return 0;
}

