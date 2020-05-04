#include "ArrayEmployees.h"
#include "funciones.h"
#include <stdio.h>
#include <string.h>
#define LIBRE 0
#define OCUPADO 1

void PrintEmployee(Employee lista)
{

    if(lista.isEmpty == OCUPADO)
    {
        printf("\n%8d %4s %4s %4.2f %8d %8d", lista.id,
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
/*
void ConvertirPrimerCaracterStrMayus(Employee lista,int tam)
{
    int i;
    strlwr(lista.name);
    for(i=-1;i<tam;i++)
    {
        if (lista.name[i] = " " || i==-1)
        {
            toupper(lista.name[i+1]);
        }
    }
}
*/
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




int CargarEmpleado(Employee lista[],int tam,int generadorID,char msj[],char error[])
{
    int retorno;
    int idNuevo = generadorID;
    char name[ELEMENTOSARRAY];
    char lastName[ELEMENTOSARRAY];
    float salary;
    int sector;

        do
        {
            retorno = getStr ("\nIngrese el nombre: ","\nERROR: El nombre es muy largo",name,ELEMENTOSARRAY);
        }while (retorno!=0);
        ConvertirPrimerCaracterStrMayus(name);

        do
        {
            retorno = getStr ("Ingrese el apellido: ","ERROR: El apellido es muy largo, ingrese uno valido: ",lastName,ELEMENTOSARRAY);
        }while (retorno!=0);
        ConvertirPrimerCaracterStrMayus(lastName);

        do
        {
            salary = getFloat("ingrese un salario valido: ");
        }while (salary<1);

        do
        {
            sector = getInt("Ingrese un sector valido: ");
        }while (sector <1);

        retorno = addEmployee(lista,tam,idNuevo,name,lastName,salary,sector);
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
    //int iDnuevo;
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
    int auxInt;
    float auxFloat;
    char respuesta;
    char respuestaSwitch;
    //char auxStr[51];
    int cambios;
    do
    {
        do
        {
        cambios=0;
        printf("\nIngrese el ID del empleado que desea modificar: ");
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
            printf("No se encontró ningún empleado, desea buscar otro? s/n: ");
            fflush(stdin);
            respuesta = getchar();
            while(respuesta!='s' && respuesta !='n')
                {
                   printf("\nIngrese  una respuesta valida s/n: ");
                   fflush(stdin);
                   respuesta = getchar();
                }
        }
        }while(respuesta =='s');

        if (respuesta=='s')

            do
            {
            printf("\n  1_Modificar nombre");
            printf("\n  2_Modificar apellido");
            printf("\n  3_Modificar salario");
            printf("\n  4_Modificar sector");
            printf("\n  5_Aplicar cambios");
            printf("\n  6_Modificar otro empleado");
            printf("\n  7_Salir al menu principal");
            printf("\n  Elija una opcion: ");
            scanf("%d",&opcion);
            if (opcion==7)
            {
                break;
            }
            switch(opcion)
            {
                case 1:
                        retorno = getStr("Ingrese el nuevo nombre: ","Error: El nombre ingresado era muy largo ",auxiliar.name,51);
                        if (retorno!=-1)
                        {
                            ConvertirPrimerCaracterStrMayus(auxiliar.name);
                            cambios=cambios+1;
                        }

                   // getStr("Ingrese el nuevo nombre: ",auxiliar.name,ELEMENTOSARRAY);
                    //validarTodo("Ingrese el nuevo nombre","El nombre excede","Desea probar otro nombre?",auxiliar.name);
                    /*
                    do
                    {
                        fflush(stdin);
                        strcpy(auxiliar.name,getStr("\nIngrese el nuevo nombre: "));
                        retorno = ValidarCadena (auxiliar.name,"\nERROR: El nombre excede los caracteres permitidos");
                        if (retorno==0)
                        {
                            break;
                        }
                        else
                        {
                            printf("\nDesea ingresar otro nombre? s/n");
                            fflush(stdin);
                            scanf("%c",&respuestaSwitch);
                        }
                    }while (retorno==-1 && respuestaSwitch=='s');
                    */
                    //ValidarCadena(*auxiliar.name,"\nMal dato: ");
                    //printf("el nuevo nombre será %s",str);
                    //printf("Confirma el cambio? s/n");
                    //scanf("%c",&respuesta);


                break;
                case 2:
                        retorno = getStr("Ingrese el nuevo apellido: ","Error: El apellido ingresado es muy largo",auxiliar.lastName,51);
                        if (retorno!=0)
                        {
                            ConvertirPrimerCaracterStrMayus(auxiliar.lastName);
                            cambios=cambios+1;
                        }

                        //printf("\n%s",auxiliar.lastName);
                        //auxiliar.lastName()
                        /*strcpy(auxStr,"");
                        printf("Ingrese el nuevo apellido: ");
                        fflush(stdin);
                        fgets(auxStr,51,stdin);
                        auxStr[strlen(auxStr)-1]='\0';
                        strcpy(auxiliar.lastName,auxStr);
*/

                break;
                case 3:
                    auxFloat = getFloat("\nIngrese el nuevo salario");//si no declaro auxFloat, guardaria el retorno en auxiliar.salary aunque sea negativo, y despues lo aplica en los cambios
                    if (auxFloat>0)
                    {
                        auxiliar.salary = auxFloat;
                        cambios++;
                    }
                    else
                    {
                        printf("Error: Salario invalido\n");
                    }
                break;
                case 4:
                    auxInt = getInt("\nIngrese el nuevo sector: ");
                    if (auxInt>0)
                    {
                        auxiliar.sector = auxInt;
                        cambios++;
                    }
                    else
                    {
                        printf("\nError: Sector invalido");
                    }
                    break;
                case 5:
                    if (cambios!=0)
                    {
                    PrintEmployee(lista[idEncontrado]);
                    printf("\nCambia a :");
                    PrintEmployee(auxiliar);
                    printf("\nDesea aplicar los cambios? s/n");

                    fflush(stdin);
                    respuestaSwitch = getchar();
                    if (respuestaSwitch=='s')
                    {
                        lista[idEncontrado] = auxiliar;
                        printf("\nSe realizaron los cambios");
                        cambios=0;
                    }
                    else
                    {
                        printf("\nLos cambios fueron cancelados");
                        cambios=0;
                    }
                    }
                    else
                    {
                        printf("No hay cambios para aplicar");
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

    }while(respuesta == 's' && opcion==6);//se hace mientras la respuesta sea por SI  Y LA OPCION SEA modificar otro empleado (6)

}
