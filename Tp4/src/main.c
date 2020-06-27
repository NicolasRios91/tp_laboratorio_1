/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "Controller.h"

int main(void)
{
    LinkedList* miLista;
    LinkedList* Copia;
    miLista = ll_newLinkedList();
    int control;
    int opcion;
    int from,to;
    do
    {
        system("cls");
        printf("    Menu:\n");
        printf("0.  Testear las funciones del tp\n");
        printf("1.  Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
        printf("2.  Alta de empleado (con push opcional)\n");
        printf("3.  Modificar datos de empleado\n");
        printf("4.  Baja de empleado\n");
        printf("5.  Listar empleados\n");
        printf("6.  Ordenar empleados\n");
        printf("7.  Copiar lista\n");
        printf("8.  Copiar lista desde una posicion determinada\n");
        printf("9.  Mostrar lista copiada\n");
        printf("10. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
        printf("11. Salir\n\n");
        printf("Elija una opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 0:
                system("cls");
                startTesting(1);  // ll_newLinkedList

                startTesting(2);  // ll_len

                startTesting(3);  // getNode - test_getNode

                startTesting(4);  // addNode - test_addNode

                startTesting(5);  // ll_add

                startTesting(6);  // ll_get

                startTesting(7);  // ll_set

                startTesting(8);  // ll_remove

                startTesting(9);  // ll_clear

                startTesting(10); // ll_deleteLinkedList

                startTesting(11); // ll_indexOf

                startTesting(12); // ll_isEmpty

                startTesting(13); // ll_push

                startTesting(14); // ll_pop

                startTesting(15); // ll_contains

                startTesting(16); // ll_containsAll

                startTesting(17); // ll_subList

                startTesting(18); // ll_clone

                startTesting(19); // ll_sort

                printf("Presione una tecla para continuar...");
                getch();
                break;
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
            case 3:
                system("cls");
                control = controller_editEmployee(miLista);
                if (control!=0)
                {
                    printf("No se hizo ningun cambio o no hay datos para modificar\n");
                    getch();
                }
                break;
            case 4:
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
                printf("\nPresione una tecla para continuar...");
                getch();
                break;
            case 5:
                system("cls");
                control = controller_ListEmployee(miLista);
                if (control == 0)
                {
                    printf("\nLa lista esta vacia\n");
                }
                printf("\nPresione una tecla para continuar...");
                getch();
                break;
            case 6:
                control = controller_sortEmployee(miLista);
                if (control==0)
                {
                    printf("\nNo se realizo ningun cambio o la lista esta vacia\n");
                    printf("\nPresione una tecla para continuar...");
                    getch();
                }
                break;
            case 7:
                Copia = ll_clone(miLista);
                if (Copia!=NULL)
                {
                    printf("Se copio la lista\n");
                }
                else
                {
                    printf("No se pudo copiar la lista o esta vacia\n");
                }
                printf("\nPresione una tecla para continuar...");
                getch();
                break;
            case 8:
                system("cls");
                if (controller_ListEmployee(miLista)!=0)
                {
                    from = getInt("\nIngrese la posicion desde donde desea copiar: ");
                    to = getInt("\nIngrese la posicion hasta donde desea copiar (no incluido), si quiere\ncopiar hasta el final INCLUSIVE coloque la cantidad total+1): ");
                    Copia = ll_subList(miLista,from-1,to-1);
                    if (Copia!=NULL)
                    {
                        printf("La lista fue copiada\n\n");
                    }
                    else
                    {
                        printf("Parametros invalidos\n\n");
                    }
                }
                else
                {
                    printf("No hay lista para copiar o esta vacia\n\n");
                }
                printf("Presione una tecla para continuar...");
                getch();
                break;
            case 9:
                system("cls");
                control = controller_ListEmployee(Copia);
                if (control == 0)
                {
                    printf("No hay lista para mostrar o esta vacia\n");
                }
                printf("\nPresione una tecla para continuar...");
                getch();
                break;
            case 10:
                control = controller_saveAsText("data.csv",miLista);
                if (control==1)
                {
                    printf("Se guardo la lista\n");
                }
                else
                {
                    printf("No se guardo la lista\n");
                }
                printf("\nPresione una tecla para continuar...");
                getch();
                break;
            case 11:
                break;
            default:
                printf("\nOpcion invalida, presione una tecla para continuar...");
                getch();
                break;
        }
    }while(opcion !=11);

    return 0;
}

































