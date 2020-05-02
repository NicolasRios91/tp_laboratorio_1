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

int SacarMaximoDeUnArrayPorId (Employee lista[],int tam)
{
    int maximo;
    int iDnuevo;
    int i;
    for (i=0;i<tam;i++)
    {
        if (lista[i].id>maximo || i==0)
        {
            maximo = lista[i].id;
        }
    }
    return maximo;
}


int ModifiyEmployee(Employee lista[],int tam)
{
    int retorno;
    int opcion;
    int idEncontrado;
    int id;
    Employee auxiliar;
    char respuesta;

    do
    {
        do
        {
        printf("\nIngrese el ID del empleado que desea modificar");
        scanf("%d",&id);
        idEncontrado = FindEmployee(lista,tam,id);
        if (idEncontrado!=-1)
        {
            printf("\nSe encontró el siguiente empleado:");
            PrintEmployee(lista[idEncontrado]);
            auxiliar = lista[idEncontrado];
            printf("\nQue desea realizar?");
            respuesta='s';
            break;
        }
        else
        {
            printf("\nNo se encontro el empleado, desea buscar otro?");
            fflush(stdin);
            scanf("%c",&respuesta);
        }
        }while(respuesta =='s');

        if (respuesta=='s')

            do
            {
            printf("\n1_Modificar nombre");
            printf("\n2_Modificar apellido");
            printf("\n3_Modificar salario");
            printf("\n4_Modificar sector");
            printf("\n5_Aplicar cambios");
            printf("\n6_Modificar otro empleado");
            printf("\n7_Salir al menu principal");
            printf("\nElija una opcion: ");
            scanf("%d",&opcion);
            if (opcion==7)
            {
                break;
            }
            switch(opcion)
            {
                case 1:
                    strcpy(auxiliar.name,getStr("\nIngrese el nuevo nombre: ","\nIngrese un nombre valido; "));
                    //printf("el nuevo nombre será %s",str);
                    //printf("Confirma el cambio? s/n");
                    //scanf("%c",&respuesta);
                break;
                case 2:
                    strcpy(auxiliar.lastName,getStr("\nIngrese el nuevo apellido: ","\nIngrese un apellido valido: "));
                break;
                case 3:
                    auxiliar.salary = getFloat("Ingrese el nuevo salario","El salario no es valido, ingrese uno correcto: ");
                break;
                case 4:
                    auxiliar.sector = getInt("Ingrese el nuevo sector","El sector ingresado no es valido,ingrese uno correcto: ");
                    break;
                case 5:
                    printf("\nDesea aplicar los cambios? s/n");
                    fflush(stdin);
                    scanf("%c",&respuesta);
                    if (respuesta='s')
                    {
                        lista[idEncontrado] = auxiliar;
                        printf("\nSe realizaron los cambios");
                    }
                    else
                    {
                        printf("\nLos cambios fueron cancelados");
                    }
                    break;
                case 6:
                    break;
                default:
                        printf("\nIngrese una opcion correcta");
                    break;
            }
            }while(opcion!=6);

        //}

    }while(respuesta == 's' && opcion==6);//se hace mientras la respuesta sea por SI Y LA OPCION SEA distinta 7
}
