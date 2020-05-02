#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "funciones.h"
#define T 3


int main()
{
    int global=-1;
    int r;
    int r2;
    int generadorId=0;
    int opcion;
    int id;
    int altas=0;
    Employee empleados[T];//={{01,"Dante","Milazzo",0,1,1},{02,"Dante","vargas",250,5,1},{03,"Dante","asdasd",750,2,1}};

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
            printf("\n5_Salir");
            printf("\n\tElija una opcion");
            scanf("%d",&opcion);
            switch(opcion)
            {
                case 1:
                generadorId = CargarEmpleado(empleados,T,generadorId,"El empleado se cargo exitosamente","No se puedo cargar al empleado");
                break;
                altas++;
                case 2:
                printf("\nIngrese la ID del empleado que busca");
                scanf("%d",&id);
                r = FindEmployee(empleados,T,id);
                if (r!=-1)
                {
                    printf("\nSe encontro");
                    PrintEmployee(empleados[id]);
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
            }
        }while (opcion!=5);





















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

