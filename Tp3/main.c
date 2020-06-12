#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
  ;
                break;
            case 2:
                break;
            case 3:
                controller_addEmployee(miLista);

                break;
            case 4:

                break;
            case 5:
                break;
            case 6:
                controller_ListEmployee(miLista);

                break;
            case 7:
                break;
            case 8:
                controller_saveAsText("data.csv",miLista);

                break;
        }
    }while(opcion !=10);
    return 0;
}

