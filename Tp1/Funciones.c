

void ValidarDivision (int valor,float division,char error[])//Recibe el segundo operando, y el valor de retorno de la funcion SacarDivision(si devuelvió),muestra error o el resultado segun correspond
{
    if (valor ==0)
    {
        printf("\n\t%s",error);
    }
    else
    {
        printf("\n\tEl resultado de la division es: %.2f",division);
    }
}
//
void ValidarFactorial(int valor,int factorial,char error[])
{

    if (valor>-1)
    {
        printf("\n\tEl Factorial de %d es: %d", valor,factorial);

    }
    else
    {
            printf("\n\t%s",error);
    }
}

//
int SacarSuma (int valor1,int valor2)
{
    int resultado;
    resultado = valor1 + valor2;
    return resultado;
}

//
int SacarResta (int valor1,int valor2)
{
    int resultado;
    resultado = valor1 - valor2;
    return resultado;
}

//
int SacarMultiplicacion (int valor1,int valor2)
{
    int resultado;
    resultado = valor1 * valor2;
    return resultado;
}

//
float SacarDivision (int valor1,int valor2)
{

    float resultado;
    if(valor2!=0)
    {
        resultado = (float)valor1 /valor2;
        return resultado;
    }

}

//
int SacarFactorial (int valor)
{
    int i;
    int resultado=1;

    if (valor >-1)
    {
        for (i=valor;i>0;i--)
        {
            resultado = resultado*i;
        }
        return resultado;
    }

}

//
int IngresarNumero ()
{
    int valorA;
    printf("  Ingrese el valor: ");
    scanf ("%d", &valorA);
    return valorA;
}

//
void MostrarMenu(int valor_1,int valor_2,int contador)
{
            switch(contador)
            {
                case 1:
                printf("\t\t**CALCULADORA**\n");
                printf("\n  1- Ingresar 1er operando (A=X)");
                printf("\n  2- Ingresar 2do operando (B=Y)");
                printf("\n  3- Calcular todas la operaciones");
                printf("\n\ta- Calcular la suma (A+B)");
                printf("\n\tb- Calcular la resta (A-B)");
                printf("\n\tc- Calcular la division (A/B)");
                printf("\n\td- Calcular la multiplicacion (A*B)");
                printf("\n\te- Calcular el factorial (A!)");
                printf("\n  4- Informar resultados");
                printf("\n  5- Salir\n");
                printf("\n  Elija una opcion (1-5): ");
                break;
                case 2:

                printf("\n  1- Ingresar 1er operando (A=%d)",valor_1);
                printf("\n  2- Ingresar 2do operando (B=Y)");
                printf("\n  3- Calcular todas la operaciones",valor_1);
                printf("\n\ta- Calcular la suma (%d+B)",valor_1);
                printf("\n\tb- Calcular la resta (%d-B)",valor_1);
                printf("\n\tc- Calcular la division (%d/B)",valor_1);
                printf("\n\td- Calcular la multiplicacion (%d*B)",valor_1);
                printf("\n\te- Calcular el factorial (%d!)",valor_1);
                printf("\n  4- Informar resultados");
                printf("\n  5- Salir\n");
                printf("\n  Elija una opcion (1-5): ");
                break;

                default:

                printf("\n  1- Ingresar 1er operando (A=%d)",valor_1);
                printf("\n  2- Ingresar 2do operando (B=%d)",valor_2);
                printf("\n  3- Calcular todas la operaciones");
                printf("\n\ta- Calcular la suma (%d+%d)",valor_1,valor_2);
                printf("\n\tb- Calcular la resta (%d-%d)",valor_1,valor_2);
                printf("\n\tc- Calcular la division (%d/%d)",valor_1,valor_2);
                printf("\n\td- Calcular la multiplicacion (%d*%d)",valor_1,valor_2);
                printf("\n\te- Calcular el factorial (%d!)",valor_1);
                printf("\n  4- Informar resultados");
                printf("\n  5- Salir\n");
                printf("\n  Elija una opcion (1-5): ");
                break;
                }

}

//
void MostrarTodo(int valor_1,int valor_2,int suma, int resta, float division, int multiplicacion, int factorial_1,int factorial_2,char error_1[],char error_2[])
{
    printf("\n\t\tRESULTADOS\n");
    printf("\n\tEl resultado de la suma es: %d",suma);
    printf("\n\tEl resultado de la resta es: %d",resta);
    ValidarDivision (valor_2,division,error_1);
    printf("\n\tEl resultado de la multiplicacion es: %d",multiplicacion);
    ValidarFactorial(valor_1,factorial_1,error_2);
    ValidarFactorial(valor_2,factorial_2,error_2);
    printf("\n\n");

}
