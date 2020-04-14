


int funcionSuma (int valor1,int valor2)
{
    int resultado;
    resultado = valor1 + valor2;
    return resultado;
}

int funcionResta (int valor1,int valor2)
{
    int resultado;
    resultado = valor1 - valor2;
    return resultado;
}


int funcionMultiplicacion (int valor1,int valor2)
{
    int resultado;
    resultado = valor1 * valor2;
    return resultado;
}


float funcionDivision (int valor1,int valor2,char error[])
{
    float resultado;
    if (valor2!=0)
    {
        resultado = (float)valor1 /valor2;
        return resultado;
    }
    else
    {
       printf("%s", error);
    }
}


int funcionFactorial (int valor1,char error[])
{
    int i;
    int resultado=1;
    if (valor1 >-1)
    {
        for (i=valor1;i>0;i--)
        {
            resultado = resultado*i;
        }
    return resultado;
    }
    else
    {
        printf("%s",error);
    }

}


int IngresarNumero ()
{
    int valorA;
    printf("Ingrese el valor: ");
    scanf ("%d", &valorA);
    return valorA;
}

void CalcularTodo(int valorA,int valorB,char error[])
{
    int suma = funcionSuma(valorA,valorB);
    printf("suma %d",suma);
    int resta = funcionResta(valorA,valorB);
    printf("\nresta %d", resta);
    float division = funcionDivision (valorA,valorB,error);
    printf("\ndivision %.2f",division);
    int multiplicacion = funcionMultiplicacion (valorA,valorB);
    printf("\nmultiplicacion %d",multiplicacion);
    int factorial = funcionFactorial(valorA,error);
    if (factorial)
    {
        printf("factorial %d",factorial);
    }
    else
    {
        printf("error");
    }
}



