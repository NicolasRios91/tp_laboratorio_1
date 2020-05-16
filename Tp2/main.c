
#include <stdlib.h>

#include "ArrayEmployees.h"
#define T 1000
#define LIBRE 0
#define OCUPADO 1


int main()
{
    int variableControl;
    float promedioSalario;
    int contadorSalario;
    int generadorId=0;
    int opcion;
    int opcionMenuListas;
    int idIngresado;

    Employee listaEmpleados[T];
    variableControl = InitEmployees(listaEmpleados,T);

    do
    {
        MenuPrincipal();
        fflush(stdin);
        opcion = getInt("\n\n\t\t\tElija una opcion: ");
        switch(opcion)
        {
            case 1:
                generadorId = CargarEmpleado(listaEmpleados,T,generadorId,"\tEl empleado se cargo exitosamente,presione una tecla para continuar",
                                                                            "\tNo se pudo cargar al empleado,presione una tecla para continuar");
                break;
            case 2:
                variableControl = SaberSiHayEmpleados(listaEmpleados,T);
                if (variableControl!=-1)
                {
                    ModifiyEmployee(listaEmpleados,T);
                }
                else
                {
                    PedirCaracter("\n\t\tNo hay empleados cargados,presione una tecla para continuar... ");
                }
                break;
            case 3:
                variableControl = SaberSiHayEmpleados(listaEmpleados,T);
                if (variableControl!=-1)
                {
                    idIngresado = getInt("\n\t\tIngrese la ID del empleado que desea eliminar: ");
                    variableControl = RemoveEmployee(listaEmpleados,T,idIngresado,"\n\t\tSe elimino al empleado,presiona una tecla para continuar",
                                                        "\n\t\tNo se elimino al empleado,presione una tecla para continuar",
                                                        "\n\t\tNo se encontró la ID, presione una tecla pra continuar\n");
                }
                else
                {
                    PedirCaracter("\n\t\tNo hay empleados cargados,presione una tecla para continuar... ");
                }
                break;
            case 4:
                variableControl = SaberSiHayEmpleados(listaEmpleados,T);
                if (variableControl==0)
                {
                    do
                    {
                        MenuListas();
                        opcionMenuListas = getInt("\n\n\t\t\tElija una opcion: ");
                        variableControl = OrdenarLista(listaEmpleados,T,opcionMenuListas);
                        if (variableControl ==-1)
                        {
                            break;
                        }
                        else
                        {
                            system("cls");
                            OrdenarLista(listaEmpleados,T,opcionMenuListas);
                            printf("\n\t\t\t**LISTA DE EMPLEADOS**\n");
                            HeaderEmpleados("ID","NOMBRE","APELLIDO","SALARIO","SECTOR");
                            variableControl = PrintEmployees(listaEmpleados,T);
                            promedioSalario = SacarPrommedio (listaEmpleados,T);
                            contadorSalario = SacarEmpleadosMayorAlPromedio(listaEmpleados,T,promedioSalario);
                            if (contadorSalario>0)
                            {
                                printf("\tCantidad de empleados que superan el salario promedio: %d\n",contadorSalario);
                            }
                            else
                            {
                                printf("\n\tNingun empleado supera el salario promedio\n");
                            }
                        }
                    }while(opcionMenuListas !=2);
                system("cls");
                }
                else
                {
                    PedirCaracter("\n\t\tNo hay empleados cargados,presione una tecla para continuar... ");
                }
                break;
            case 5:
                break;
            default:
                PedirCaracter("\n\t\tIngrese una opcion correcta, presione una tecla para continuar... ");
        }
    }while (opcion!=5);
}

