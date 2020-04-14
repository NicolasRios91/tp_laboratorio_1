#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"


int main()
{
    int numeroUno=-2;
    int numeroDos=10;
    int suma;
    int resta;
    float division;
    int multiplicacion;
    int factorial;
    int respuesta;


do
    {
        printf("\n1- Ingresar 1er operando (A=%d)\n",numeroUno);
        printf("2- Ingresar 2do operando (B=%d)\n",numeroDos);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");
        printf("\nElija una opcion: ");
        scanf("%d", &respuesta);


        switch(respuesta)
        {
            case 1:
                numeroUno = IngresarNumero();
                break;
            case 2:
                numeroDos = IngresarNumero ();
                break;
            case 3:
                suma = funcionSuma(numeroUno,numeroDos);
                //system("CLS");
                break;
            case 4:
                funcionResta(numeroUno,numeroDos);
                break;
            case 5:
                division = funcionDivision(numeroUno,numeroDos,"No se puede dividir por 0 ");
                break;
            case 6:
                multiplicacion = funcionMultiplicacion(numeroUno,numeroDos);
                break;
            case 7:
                //system("CLS");
                funcionFactorial(numeroUno,"\nNo se puede factorear un numero negativo\n");
                break;
            case 8:
                CalcularTodo (numeroUno,numeroDos,"\nno se pudo realizar la operacion");





        }
    }while (respuesta!=9);


    return 0;
}
