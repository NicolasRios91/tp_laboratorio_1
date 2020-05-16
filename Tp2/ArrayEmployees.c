#include "ArrayEmployees.h"


void PrintEmployee(Employee lista)
{

    if(lista.isEmpty == OCUPADO)
    {
        printf("\n%8d %-23s %-15s %13.2f %13d", lista.id,
                                            lista.name,
                                            lista.lastName,
                                            lista.salary,
                                            lista.sector);

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
    int retorno=-1;
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

int SaberSiHayEmpleados (Employee lista[], int tam)//-1 si no hay
{
    int i;
    int retorno=-1;
    for (i=0;i<tam;i++)
    {
        if (lista[i].isEmpty == OCUPADO)
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}



int addEmployee(Employee lista[],int tam,int idAnterior,char name[],char lastName[],float salary,int sector)
{
    int retorno =-1;
    int indiceEncontrado;
    indiceEncontrado = BuscarLibre(lista,tam);
    if (indiceEncontrado!=-1)
    {
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
    char name[ELEMENTOSARRAY];
    char lastName[ELEMENTOSARRAY];
    //char auxCadena[ELEMENTOSARRAY];
    float salary;
    int sector;

        retorno = getStr ("\n\n\tIngrese el nombre: ",name,ELEMENTOSARRAY);
        while (retorno!=0)
        {
            retorno = getStr ("\n\n\tIngrese un nombre valido: ",name,ELEMENTOSARRAY);
        }

        retorno = getStr ("\tIngrese el apellido: ",lastName,ELEMENTOSARRAY);
        while (retorno!=0)
        {
            retorno = getStr ("\n\n\tIngrese un apellido valido: ",lastName,ELEMENTOSARRAY);
        }

        salary = getFloat("\tingrese el salario: ");
        retorno = ValidarSalario(salary,1);
        while(retorno !=0 )
        {
            fflush(stdin);
            salary = getFloat("\tIngrese un salario valido: ");
            retorno = ValidarSalario(salary,1);
        }

        sector = getInt("\tIngrese el sector: ");
        retorno = ValidarSector(sector,1);
        while(retorno!=0)
        {
            fflush(stdin);
            sector = getInt("\tIngrese un sector valido: ");
            retorno = ValidarSector(sector,1);
        }

        retorno = addEmployee(lista,tam,generadorID,name,lastName,salary,sector);
        if (retorno!=-1)
        {
           generadorID++;
           PedirCaracter (msj);// se cargo el empleado
        }
        else
        {
            PedirCaracter (error);//no hay espacio
        }

        return generadorID;
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

int RemoveEmployee(Employee lista[],int tam, int id,char confirma[],char cancela[],char error[])
{
    int retorno=-1;
    int indice = FindEmployee(lista,tam,id);
    char respuesta;
    if (indice!=-1)
    {
        system("cls");
        printf("\n\t\tSe encontro el siguiente empleado\n");
        HeaderEmpleados("ID","NOMBRE","APELLIDO","SALARIO","SECTOR");
        PrintEmployee(lista[indice]);
        printf("\n\n\t\tDesea eliminarlo? s/n: ");
        fflush(stdin);
        respuesta = getchar();
        if (respuesta=='s')
        {
            lista[indice].isEmpty=LIBRE;
            PedirCaracter(confirma);
            retorno=0;
        }
        else
        {
            PedirCaracter(cancela);
        }
    }
    else
    {
        PedirCaracter(error);
    }
    return retorno;
}

int SacarMaximoDeUnArrayPorId (Employee lista[],int tam)
{
    int maximo;
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




void ModifiyEmployee(Employee lista[],int tam)
{
    int retorno;
    int opcion;
    int idEncontrado;
    int idIngresada;

    Employee auxiliar;

    int auxInt;
    float auxFloat;
    char respuesta;
    char respuestaSwitch;//para aplicar o no los cambios
    char cambios;//para entrar a la opcion ajustar cambios
    do
    {
        do
        {
            idIngresada = getInt("\n\t\tIngrese el ID del empleado que desea modificar: ");
            idEncontrado = FindEmployee(lista,tam,idIngresada);
            if (idEncontrado!=-1)
            {
                system("cls");
                printf("\n\t\tSe encontro el siguiente empleado\n");
                HeaderEmpleados("ID","NOMBRE","APELLIDO","SALARIO","SECTOR");
                PrintEmployee(lista[idEncontrado]);
                printf("\n");
                auxiliar = lista[idEncontrado];
                break;
            }
            else
            {
                printf("\t\tNo se encontro ningun empleado, desea buscar otro? s/n: ");
                fflush(stdin);
                respuesta = getchar();
                while(respuesta!='s' && respuesta !='n')
                {
                    printf("\n\t\tIngrese  una respuesta valida s/n: ");
                    fflush(stdin);
                    respuesta = getchar();
                }
            }
        }while(respuesta =='s');

        if (idEncontrado!=-1)//si no repito esta condicion entra al menu de modificacion aunque no encuentre la ID, otra opcion era poner una bandera.
        {
            do
            {
                MenuModificar();
                fflush(stdin);
                opcion = getInt("\n\n\t\t\tElija una opcion: ");
                if (opcion==7)
                {
                    system("cls");
                    break;//rompe el bucle para volver al menu principal
                }
                switch(opcion)
                {
                    case 1:
                        fflush(stdin);
                        retorno = getStr("\t\tIngrese el nuevo nombre: ",auxiliar.name,ELEMENTOSARRAY);
                        if (retorno !=-1)
                        {
                            cambios='s';
                            printf("\t\tCambio guardado exitosamente\n");
                        }
                        break;
                    case 2:
                        fflush(stdin);
                        retorno = getStr("\t\tIngrese el nuevo apellido: ",auxiliar.lastName,ELEMENTOSARRAY);
                        if (retorno !=-1)
                        {
                            cambios='s';
                            printf("\t\tCambio guardado exitosamente\n");
                        }
                        break;
                    case 3:
                        auxFloat = getFloat("\n\t\tIngrese el nuevo salario: ");//si no declaro auxFloat, guardaria el retorno en auxiliar.salary aunque sea negativo, y despues lo aplica en los cambios
                        retorno = ValidarSalario(auxFloat,0);
                        if (retorno == 0)
                        {
                            auxiliar.salary = auxFloat;
                            cambios='s';
                            printf("\t\tCambio guardado exitosamente\n");
                        }
                        else
                        {
                            printf("\t\tERROR: Salario invalido\n");
                        }
                        break;
                    case 4:
                        auxInt = getInt("\n\t\tIngrese el nuevo sector: ");
                        retorno = ValidarSector(auxInt,0);
                        if (retorno==0)
                        {
                            auxiliar.sector = auxInt;
                            cambios='s';
                            printf("\t\tCambio guardado exitosamente\n");
                        }
                        else
                        {
                            printf("\t\tError: Sector invalido\n");
                        }
                        break;
                    case 5:
                        if (cambios =='s')
                        {
                            HeaderEmpleados("ID","NOMBRE","APELLIDO","SALARIO","SECTOR");
                            PrintEmployee(lista[idEncontrado]);
                            printf("\n\n\tCambia a :\n");
                            HeaderEmpleados("ID","NOMBRE","APELLIDO","SALARIO","SECTOR");
                            PrintEmployee(auxiliar);
                            printf("\n\n\t\tDesea aplicar los cambios? s/n: ");

                            fflush(stdin);
                            respuestaSwitch = getchar();
                                if (respuestaSwitch=='s')
                                {
                                    lista[idEncontrado] = auxiliar;
                                    system("cls");
                                    printf("\n\t\t\t**Se realizaron los cambios**\n");
                                    cambios='n';
                                }
                                else
                                {
                                    printf("\n\t\tLos cambios no se realizaron");
                                }
                        }
                        else
                        {
                            printf("No hay cambios para aplicar\n");
                        }
                        break;

                    case 6:
                        break;//para evitar el msj default cuando ingrese 7
                    default:
                            printf("\nIngrese una opcion correcta");
                        break;
                }//llavel del switch
            }while(opcion!=6); //bucle del menu modificar
        }
    }while(opcion == 6 && respuesta !='n');//vuelve al principio, a pedir una id de otro empleado

    //Se vuelve a pedir una ID, siempre que: el usuario no responda "n" (cuando se ingresa una ID incorrecta) y la opcion del menu elegida sea la 6
    //Al entrar al menu "respuesta" esta vacio, o es 's' en caso de haber ingresado mal un id
    //y luego haber puesto uno correcto(ya que tuvo que responder 's' si queria ingresar uno nuevo)
    //por eso al poner 7 en el menu (modificar otro usuario), se cumplen las 2 condiciones y se repite el bucle
    system("cls");
}


int OrdenarLista(Employee lista[],int tam,int orden) //0
{
    int retorno=-1;
    int i;
    int j;
    Employee aux;
    if (orden ==1)
    {
        for (i=0;i<tam-1;i++)//ascentente 1
        {
            for (j=i+1;j<tam;j++)
            {
                if (strcmp(lista[i].lastName,lista[j].lastName)>0 || (strcmp(lista[i].lastName,lista[j].lastName)==0 && lista[i].sector > lista[j].sector))//A-Z , Y MENOR A MAYOR
                {
                    aux = lista[i];
                    lista[i]=lista[j];
                    lista[j]=aux;
                }
            }
        }
        retorno=0;
    }
    else
    {
        if (orden ==0) //ascendente 0
        {
            for (i=0;i<tam-1;i++)
            {
                for (j=i+1;j<tam;j++)
                {
                    if (strcmp(lista[i].lastName,lista[j].lastName)<0 || (strcmp(lista[i].lastName,lista[j].lastName)==0 && lista[i].sector < lista[j].sector))//Z-A Y MAYOR A MENOR
                    {
                        aux = lista[i];
                        lista[i]=lista[j];
                        lista[j]=aux;
                    }
                }
            }
            retorno=0;
        }

    }
    return retorno;
}

float SacarPrommedio (Employee lista[],int tam)
{
    float PromedioSalario;
    int i;
    float acumuladorSalario=0;
    int contador=0;
    for (i=0;i<tam;i++)
    {
        if (lista[i].isEmpty == OCUPADO)
        {
            acumuladorSalario+=lista[i].salary;
            contador++;
        }
    }
    PromedioSalario = acumuladorSalario/contador;
    printf("\n\n\tSuma total de los salarios: %.2f",acumuladorSalario);
    printf("\n\tPromedio de salario: %.2f\n",PromedioSalario);
    return PromedioSalario;
}

int SacarEmpleadosMayorAlPromedio(Employee lista[], int tam, float promedio)
{
    int i;
    int cantidad=0;
    for (i=0;i<tam;i++)
    {
        if (lista[i].salary > promedio && lista[i].isEmpty ==OCUPADO)
        {
            cantidad++;
        }
    }
    return cantidad;
}
