#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "ArrayEmployees.h"
#define T 5
#define LIBRE 0
#define OCUPADO 1


int main()
{

    int variableControl;
    //int inicializarEnCero;
    //int HayEmpleados;
    float promedioSalario;
    int contadorSalario;
    int generadorId=0;
    int opcion;
    int id;

    Employee listaEmpleados[T]={{1,"maria de los angeles","Apellido",250,7,1},{2,"BART","VERGIL",100,5,1},{3,"Dante","VERGIL",100,2,1}};

    //variableControl = InitEmployees(listaEmpleados,T);
        do
        {
            MenuPrincipal();
            fflush(stdin);
            opcion = getInt("\n\n\t\tElija una opcion: ");
            switch(opcion)
            {
                case 1:
                    generadorId = CargarEmpleado(listaEmpleados,T,generadorId,"\t\tEl empleado se cargo exitosamente","No se pudo cargar al empleado");
                    break;
                case 2:
                    variableControl = SaberSiHayEmpleados(listaEmpleados,T);
                    if (variableControl!=-1)
                    {
                        ModifiyEmployee(listaEmpleados,T);
                    }
                    else
                    {
                        printf("\n\t\tNo hay empleados cargados,presione una tecla para continuar... ");
                        getch();
                        system("cls");
                    }
                    break;
                case 3:
                    variableControl = SaberSiHayEmpleados(listaEmpleados,T);
                    if (variableControl!=-1)
                    {
                        id = getInt("\n\t\tIngrese la ID del empleado que desea eliminar: ");
                        variableControl = RemoveEmployee(listaEmpleados,T,id,"\n\t\tSe elimino al empleado\n","\n\t\tNo se elimino al empleado","\n\t\tNo se encontró la ID\n");
                    }
                    else
                    {

                        printf("\n\t\tNo hay empleados cargados,presione una tecla para continuar... ");
                        getch();
                        system("cls");
                    }
                    break;
                case 4:

                    variableControl = SaberSiHayEmpleados(listaEmpleados,T);
                    if (variableControl==0)
                        {
                        system("cls");
                        printf("\n\t\t\t**LISTA DE EMPLEADOS**\n");
                        HeaderEmpleados("ID","NOMBRE","APELLIDO","SALARIO","SECTOR");
                        OrdenarAscendentemente(listaEmpleados,T);
                        variableControl = PrintEmployees(listaEmpleados,T);
                        promedioSalario = SacarPrommedio (listaEmpleados,T);
                        contadorSalario = SacarEmpleadosMayorAlPromedio(listaEmpleados,T,promedioSalario);
                        if (contadorSalario>0)
                        {
                            printf("\n\tCantidad de empleados que superan el salario promedio: %d",contadorSalario);
                        }
                        else
                        {
                            printf("\n\tNingun empleado supera el salario promedio");
                        }
                    }
                    else
                    {
                        printf("\n\t\tNo hay empleados cargados,presione una tecla para continuar... ");
                        getch();
                        system("cls");
                    }
                    break;
                case 5:
                    break;
                default:
                    printf("\n\t\tIngrese una opcion correcta");
            }
        }while (opcion!=5);

}

