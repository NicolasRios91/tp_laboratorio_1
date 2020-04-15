#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"


int main()
{
    int numeroUno=4;
    int numeroDos=1;
    int suma;
    int resta;
    float division;
    int multiplicacion;
    int factorialA;
    int factorialB;
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
                numeroDos = IngresarNumero();
                break;
            case 3:
                suma = funcionSuma(numeroUno,numeroDos);
                //system("CLS");
                break;
            case 4:
                resta = funcionResta(numeroUno,numeroDos);
                break;
            case 5:
                division = funcionDivision(numeroUno,numeroDos);
                break;
            case 6:
                multiplicacion= funcionMultiplicacion(numeroUno,numeroDos);
                break;
            case 7:
             factorialA= funcionFactorial(numeroUno);
             factorialB= funcionFactorial(numeroDos);
                break;
            case 8:
            MostrarTodo(numeroUno,numeroDos,suma,resta,division,multiplicacion,factorialA,factorialB,"\nNo se puede dividir por 0","\nNo se puede factorear un numero negativo");
                break;

        }
    }while (respuesta!=9);


    return 0;
}
