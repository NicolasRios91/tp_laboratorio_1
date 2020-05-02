#include "ArrayEmployees.h"
#include "funciones.h"
#include <stdio.h>
#define LIBRE 0
#define OCUPADO 1

void PrintEmployee(Employee lista)
{
    if(lista.isEmpty == OCUPADO)
    {
        printf("\n%8d %8s %8s %4.2f %8d %8d", lista.id,
                                            lista.name,
                                            lista.lastName,
                                            lista.salary,
                                            lista.sector,
                                            lista.isEmpty);
    }
}




void PrintEmployees(Employee lista[], int tam)
{
    int i;
    for (i=0;i<tam;i++)
    {
        PrintEmployee(lista[i]);
    }
    return 0;
}

int InitEmployees (Employee lista[],int tam)
{
    int retorno;
    int i;
    for(i=0;i<tam;i++)
        {
            lista[i].isEmpty = LIBRE;
            retorno = 0;
        }
    return retorno;
}


int BuscarLibre(Employee lista[],int tam)
{
   int indice= -1;
   int i;
   for (i=0;i<tam;i++)
   {
       if (lista[i].isEmpty == LIBRE)
       {
           indice = i;
           break;
       }
   }
   return indice;
}

int GenerarId(Employee lista[],int tam, int idAnterior)
{
   int IdNuevo;
   IdNuevo = SacarMaximoDeUnArrayPorId(lista,tam)+1;
   return IdNuevo;
}

int addEmployee(Employee lista[],int tam,int idAnterior,char name[],char lastName[],float salary,int sector)
{
    int retorno =-1;
    int indiceEncontrado;
    //int idNuevo;
    indiceEncontrado = BuscarLibre(lista,tam);
    if (indiceEncontrado!=-1)
    {

        //idNuevo = GenerarId(lista,tam,idAnterior);
        lista[indiceEncontrado].id = idAnterior++;
        strcpy(lista[indiceEncontrado].name,name);
        strcpy(lista[indiceEncontrado].lastName,lastName);
        lista[indiceEncontrado].salary = salary;
        lista[indiceEncontrado].sector = sector;
        lista[indiceEncontrado].isEmpty = OCUPADO;
        retorno =0;
    }

    return retorno;
}




int CargarEmpleado(Employee lista[],int tam,int idAnterior,char msj[],char error[])
{
    int retorno;
    int idNuevo = idAnterior;
    char name[51];
    char lastName[51];
    float salary;
    int sector;


        fflush(stdin);
        strcpy(name,getStr("\ningrese el nombre","\nel nombre es muy largo"));
        fflush(stdin);
        strcpy(lastName,getStr("\ningrese el apellido","\n mal dato"));
        salary = getFloat("ingrese el salario","Mal dato");
        sector = getInt("Ingrese el sector","Sector invalido");
        retorno = addEmployee(lista,tam,idAnterior,name,lastName,salary,sector);
        if (retorno!=-1)
        {
           idNuevo++;
           printf("\n%s",msj);
        }
        else
        {
            printf("\n%s",error);
        }

        return idNuevo;
}


