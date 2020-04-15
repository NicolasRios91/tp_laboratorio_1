

int Validar (int valor2)
{
    int valorDeRetorno=1;
    if (valor2==0)
    {
        valorDeRetorno = 0;
    }
    return valorDeRetorno;
}
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


float funcionDivision (int valor1,int valor2)
{
    float resultado;
    if(valor2!=0)
    {
        resultado = (float)valor1 /valor2;
        return resultado;
    }

}


int funcionFactorial (int valor1)
{
    int i;
    int resultado=1;
    if (valor1 >-1)
    {
        for (i=valor1;i>0;i--)
        {
            resultado = resultado*i;
        }
    }

    return resultado;

}

int IngresarNumero ()
{
    int valorA;
    printf("Ingrese el valor: ");
    scanf ("%d", &valorA);
    return valorA;
}

void MostrarTodo(int numeroUno,int numeroDos,int suma, int resta, float division, int multiplicacion, int factorialA,int factorialB,char error1[],char error2)
{
    int i=numeroDos;
    printf("\n\tsuma %d",suma);
    printf("\n\tresta %d",resta);
    printf("\n\tdivision %2.f",division);
    printf("\n\tMultiplicacion %d",multiplicacion);
    printf("\n\tFactorial %d es %d", numeroUno,factorialA);
    printf("\n\tFactorial %d es %d", numeroDos,factorialB);

}
