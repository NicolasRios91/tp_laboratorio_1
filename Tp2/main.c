#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "funciones.h"
#define T 3


int main()
{
    int r;
    int r2;
    int generadorId=0;

    Employee empleados[T]={{01,"Dante","Milazzo",0,1,1},{02,"Dante","vargas",250,5,1},{03,"Dante","asdasd",750,2,1}};

   //r2 = InitEmployees(empleados,T);
/*
        fflush(stdin);
        strcpy(name,getStr("ingrese el nombre","ponga el apellido"));
        fflush(stdin);
        strcpy(lastName,getStr("ingrese el apellido"," mal dato"));
        salary = getFloat("ingrese el salario","Mal dato");
        sector = getInt("Ingrese el sector","Sector invalido");
        addEmployee(empleados,T,id,name,lastName,salary,sector);
        */


    for(int i=0;i<T;i++)
    {
        //generadorId=CargarEmpleado(empleados,T,generadorId);;
        generadorId = CargarEmpleado(empleados,T,generadorId,"El empleado se cargo exitosamente","No se puedo cargar al empleado");
        PrintEmployees(empleados,T);

    }



















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

