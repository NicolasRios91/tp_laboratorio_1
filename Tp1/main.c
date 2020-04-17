#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"


int main()
{
    int numeroUno;
    int numeroDos;
    int suma;
    int resta;
    float division;
    int multiplicacion;
    int factorial_1;
    int factorial_2;
    int respuesta;
    int contador=0;

do
    {
        contador++;//Dependiendo el valor muestra un menu "distinto"(por ejemplo con X reemplazado por un valor ingresado).
        MostrarMenu(numeroUno,numeroDos,contador);
        scanf("%d",&respuesta);

        switch(respuesta)
        {
            case 1://Se ingresa el primer operando y lo guarda en la variable numeroUno
                numeroUno = IngresarNumero();
                system("cls");
                break;
            case 2://igual case 1,salvo por la variable asignada
                numeroDos = IngresarNumero();
                system("cls");
                break;
            case 3://Calcula todos los resultados y los guarda en una variable
                suma = SacarSuma(numeroUno,numeroDos);
                resta = SacarResta(numeroUno,numeroDos);
                division = SacarDivision(numeroUno,numeroDos);
                multiplicacion= SacarMultiplicacion(numeroUno,numeroDos);
                factorial_1= SacarFactorial(numeroUno);
                factorial_2= SacarFactorial(numeroDos);
                system("cls");
                printf("\n\t\tSe calcularon todas las operaciones\n");
                break;
            case 4://Muestra los resultados o msj de error segun corresponda
            MostrarResultados(numeroUno,numeroDos,suma,resta,division,multiplicacion,factorial_1,factorial_2,"No se puede dividir por 0","No se puede factorear un numero negativo");
            contador = 0;//se resetea el contador para volver a mostrar el menu con'X' e 'Y' en vez de los valores asignados anteriormente.
            system("pause");
            system("cls");
            break;
        }

    }while (respuesta!=5);


    return 0;
}
