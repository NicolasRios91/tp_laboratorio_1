#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

#include "funciones.h"
#include "menu.h"
#include <stdio.h>


typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}Employee;



void PrintEmployee(Employee lista);
int PrintEmployees(Employee lista[], int tam);

int InitEmployees (Employee lista[],int tam);
int SaberSiHayEmpleados (Employee lista[], int tam);
int BuscarLibre(Employee lista[],int tam);



int addEmployee(Employee lista[],int tam,int idAnterior,char name[],char lastName[],float salary,int sector);


int CargarEmpleado(Employee lista[],int tam,int idAnterior,char msj[],char error[]);

//int GenerarId(Employee lista[],int tam, int idAnterior);
int FindEmployee(Employee lista[],int tam, int id);
void ModifiyEmployee(Employee lista[],int tam);
int RemoveEmployee(Employee lista[],int tam, int id,char confirma[],char cancela[],char error[]);
void OrdenarAscendentemente(Employee lista[],int tam);
void OrdenarPorSector(Employee lista[],int tam);

float SacarPrommedio (Employee lista[],int tam);
int SacarEmpleadosMayorAlPromedio(Employee lista[], int tam, float promedio);
//void ConvertirPrimerCaracterStrMayus(Employee lista,int tam);

#endif // ARRAYEMPLOYEES_H_INCLUDED
