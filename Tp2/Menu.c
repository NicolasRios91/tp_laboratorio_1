#include "Menu.h"

void MenuPrincipal()
{
            printf("\n\n\t\t\t*** MENU PRINCIPAL ***\n");
            printf("\n\t\t1_Cargar un empleado");
            printf("\n\t\t2_Modificar");
            printf("\n\t\t3_Eliminar");
            printf("\n\t\t4_Mostrar Empleados");
            printf("\n\t\t5_Salir");
}

void MenuModificar()
{
            printf("\n\t\t1_Modificar nombre");
            printf("\n\t\t2_Modificar apellido");
            printf("\n\t\t3_Modificar salario");
            printf("\n\t\t4_Modificar sector");
            printf("\n\t\t5_Aplicar cambios");
            printf("\n\t\t6_Modificar otro empleado");
            printf("\n\t\t7_Salir al menu principal");
}

void MenuListas()
{
    printf("\n\t\t(0) Mostrar lista descendente");
    printf("\n\t\t(1) Mostrar lista ascendente");
    printf("\n\t\t(*) Cualquier otra tecla para salir");
}

void HeaderEmpleados(char legajo[],char nombre[],char apellido[],char salario[],char sector[])
{
    printf("\n%8s %2s %25s %20s %15s\n",legajo,nombre,apellido,salario,sector);
}
