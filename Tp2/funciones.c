#include "funciones.h"

int ValidarCadena (char str[],int size,char error[])// si es menor (valido) devuelve 0
{
    int retorno=0;
    if (strlen(str)>size)
    {
        retorno=-1;
        printf("%s",error);
    }
    return retorno;
}

int getStr (char msj[],char dato[], int size)
{

    int retorno;
    char str[100];
    printf("%s",msj);

    fflush(stdin);
    fgets(str,100,stdin);
    str[strlen(str)-1]='\0';

    retorno = ValidarCadena (str,size,"ERROR: El nombre es muy largo\n");
    if(retorno!=-1)
    {
        CopiarStrValidado(dato,str);
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


float getFloat(char msj[])
{
    float valor;
    printf("%s",msj);
    scanf("%f",&valor);
    return valor;
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

int ValidarSector(int valor, int parametro)
{
    int retorno=0;
    if (valor<parametro)
    {
        retorno=-1;
    }
    return retorno;
}

int getInt (char msj[])
{
    int valor;
    printf("%s",msj);
    scanf("%d",&valor);
    return valor;
}


void CopiarStrValidado(char cadenaDestino[],char cadenaOrigen[])
{
    strcpy(cadenaDestino,cadenaOrigen);
    ConvertirPrimerCaracterStrMayus(cadenaDestino);
}

void PedirCaracter (char msj[])
{
    printf("%s",msj);
    getch();
    system("cls");
}

