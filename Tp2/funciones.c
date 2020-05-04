//#include "ArrayEmployees.h"
#include <stdio.h>
#include <string.h>
//#include "ArrayEmployees.h"
#define LIBRE 0
#define OCUPADO 1







int ValidarCadena (char str[],int size)// si es menor (valido) devuelve 0
{
    int retorno=0;
    if (strlen(str)>size)
    {
        retorno=-1;
    }
    return retorno;
}

void ConvertirPrimerCaracterStrMayus(char lista[])
{
    int i;
    int largo;
    strlwr(lista);
    largo = strlen(lista);
    for(i=-1;i<largo;i++)
    {
        if (lista[i] == ' ' || i==-1)
        {
            lista[i+1]=toupper(lista[i+1]);
        }
    }
}


int getStr (char msj[],char error[],char dato[], int size)
{
    int retorno;
    int largo=0;
    char str[100];
    printf("%s",msj);

    fflush(stdin);
    fgets(str,100,stdin);
    largo= strlen(str);
    str[strlen(str)-1]='\0';
    printf("%d",largo);

    retorno = ValidarCadena (str,size);
    if (retorno!=-1)
        {
            strcpy(dato,str);
        }
        else
        {
            printf("%s",error);
        }
    return retorno;
//ValidarCadena(str,error);
}



float getFloat(char msj[])
{
    float salary;
    printf("\n%s",msj);
    scanf("%f",&salary);
    return salary;
}
int ValidarSalario(float valor,int parametro)
{
    int retorno=0;
    if (valor <parametro)
    {
        retorno=-1;
    }
    return retorno;
}
int getInt (char msj[])
{
    int valor;
    printf("\n%s",msj);
    scanf("%d",&valor);
    return valor;
}


int SacarMaximo(int valor1,int control)
{
    int maximo;
    if (valor1>maximo ||control ==0)
    {
        maximo=valor1;
    }
    return maximo;
}


/*
void validarTodo(char msj[],char msjError[],char confirma[],char str[])
{
    int retorno;
    char respuesta;
    do
    {
    //fflush(stdin);
    strcpy(str,getStr(msj));
    retorno = ValidarCadena(str,msjError);
    if (retorno==0)
    {
        break;
    }
    else
    {
        respuesta=getChar(confirma);
    }
    }while(retorno==-1 && respuesta=='s');
}*/
