#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include "ArrayEmployees.h"
#include "funciones.h"
#define T 5


int main()
{

    int r;
    int r2;
    float promedioSalario;
    int contadorSalario;
    int generadorId=0;
    int opcion;
    int id;
    int altas=0;
    Employee empleados[T]={{1,"radamantis","Apellido",100,7,1},{2,"BART","VERGIL",100,5,1},{3,"Dante","VERGIL",100,2,1}};

    r2 = InitEmployees(empleados,T);
/*
        fflush(stdin);
        strcpy(name,getStr("ingrese el nombre","ponga el apellido"));
        fflush(stdin);
        strcpy(lastName,getStr("ingrese el apellido"," mal dato"));
        salary = getFloat("ingrese el salario","Mal dato");
        sector = getInt("Ingrese el sector","Sector invalido");
        addEmployee(empleados,T,id,name,lastName,salary,sector);
        */

        do
        {
            printf("\n1_Cargar un empleado");
            printf("\n2_Buscar");
            printf("\n3_Eliminar");
            printf("\n4_Mostrar Empleados");
            printf("\n5_Modificar");
            printf("\n6_Ordenar alfabeticamente");
            printf("\n7_Ordenar por sector");
            printf("\n8_Salario Total y promedio");
            printf("\n9_Salir");
            printf("\n\tElija una opcion");
            scanf("%d",&opcion);
            switch(opcion)
            {
                case 1:
                generadorId = CargarEmpleado(empleados,T,generadorId,"El empleado se cargo exitosamente","No se pudo cargar al empleado");
                break;
                altas++;
                case 2:
                printf("\nIngrese la ID del empleado que busca");
                scanf("%d",&id);
                r = FindEmployee(empleados,T,id);
                if (r!=-1)//pasar a funcion ?!
                {
                    printf("\nSe encontro");
                    PrintEmployee(empleados[r]);
                }
                else
                {
                    printf("\nNo se encontro");
                }
                break;
                case 3:
                printf("\nIngrese la ID del empleado que desea eliminar");
                scanf("%d",&id);
                r = RemoveEmployee(empleados,T,id);
                break;
                case 4:
                r = PrintEmployees(empleados,T);
                if (r ==-1)
                {
                    printf("No hay empleados cargados");
                }
                break;
                case 5:
                    ModifiyEmployee(empleados,T);
                    break;
                case 6:
                    OrdenarAscendentemente(empleados,T);
                    break;
                case 7:
                    OrdenarPorSector(empleados,T);
                    break;
                case 8:
                    promedioSalario = SacarPrommedio (empleados,T);
                    contadorSalario = SacarEmpleadosMayorAlPromedio(empleados,T,promedioSalario);
                    if (contadorSalario>0)
                    {
                        printf("\nCantidad de empleados que superan el salario promedio: %d",contadorSalario);
                    }
                    else
                    {
                        printf("\nNingun empleado supera el salario promedio");
                    }
            }
        }while (opcion!=9);





















    //Employee empleado= {01,"Dante","Milazzo",5000,2};


    /*
    r2 = InitEmployees(empleados,T);


    //PrintEmployee(empleado);
    r = PrintEmployees(empleados,T);

    indiceLibre= BuscarLibre(empleados,T);
    AddEmployee(empleados,T,indiceLibre);
    r = PrintEmployees(empleados,T);
*/
}

