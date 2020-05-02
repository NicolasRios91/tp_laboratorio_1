//#include "ArrayEmployees.h"
#include <stdio.h>
#include "ArrayEmployees.h"
#define LIBRE 0
#define OCUPADO 1

void ValidarCadena (char str[], char error[])
{
    int largo;
    largo = strlen(str);
    while (largo>51)
    {
        printf("\n%s", error);
        fflush(stdin);
        gets(str);
        largo= strlen(str);
    }
}


char* getStr (char msj[], char error[])
{
    char str[51];
    printf("\n%s",msj);
    fflush(stdin);
    gets(str);
    //ValidarCadena(str,error);
}

float getFloat(char msj[],char error[])
{
    float salary;
    printf("\n%s",msj);
    scanf("%f",&salary);
    while (salary <1)
    {
        printf("\n%s", error);
        scanf("%f",&salary);
    }
    return salary;
}
int getInt (char msj[],char error[])
{
    int valor;
    printf("\n%s",msj);
    scanf("%d",&valor);
    while (valor<1)
    {
        printf("\n%s",error);
        scanf("%d",&valor);
    }
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
