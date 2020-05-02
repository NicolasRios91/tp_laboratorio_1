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




int PrintEmployees(Employee lista[], int tam)
{
    int retorno=-1;
    int i;
    for (i=0;i<tam;i++)
    {
        if(lista[i].isEmpty == OCUPADO)
        {
          PrintEmployee(lista[i]);
          retorno=0;
        }
    }
    return retorno;
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
        lista[indiceEncontrado].id = idAnterior+1;
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


int FindEmployee(Employee lista[],int tam, int id)
{
    int i;
    int retorno=-1;
    for (i=0;i<tam;i++)
    {
        if (lista[i].id == id && lista[i].isEmpty == OCUPADO)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

int RemoveEmployee(Employee lista[],int tam, int id)
{
    int retorno=-1;
    int indice = FindEmployee(lista,tam,id);
    if (indice!=-1)
    {
        printf("se elimino el empleado");
        lista[indice].isEmpty=LIBRE;
        retorno=1;
    }
    else
    {
        printf("No existe id");
    }
    return retorno;
}
