

int ValidarDivision (int valor)
{
    int valorDeRetorno=1;
    if (valor==0)
    {
        valorDeRetorno = 0;//Entra al mensaje de error cuando el segundo valor de la division es 0
    }
    return valorDeRetorno;
}

int ValidarFactorial(int valor)
{
    int valorDeRetorno=1;
    if (valor <0)
    {
        valorDeRetorno=0;//igual que el error de la division solo cambia la logica
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


int funcionFactorial (int valor)
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

int IngresarNumero ()
{
    int valorA;
    printf("Ingrese el valor: ");
    scanf ("%d", &valorA);
    return valorA;
}

void MostrarTodo(int valor1,int valor2,int suma, int resta, float division, int multiplicacion, int factorial1,int factorial2,char error1[],char error2[])
{
    int validarFactorial1;
    int validarFactorial2;
    int validarDivision;
    printf("\n\tsuma %d",suma);
    printf("\n\tresta %d",resta);
/////////
    validarDivision = ValidarDivision(valor2);
    validarFactorial1 = ValidarFactorial(valor1);
    validarFactorial2 = ValidarFactorial(valor2);
    if (validarDivision ==0)
    {
        printf("\n\t%s",error1);
    }
    else
    {
        printf("\n\tdivision %.2f",division);
    }
    printf("\n\tMultiplicacion %d",multiplicacion);
//////////

    if (validarFactorial1==1)
    {
        printf("\n\tFactorial %d es %d", valor1,factorial1);

    }
    else
    {
            printf("\n\t%s",error2);
    }
    if (validarFactorial2==1)
    {
        printf("\n\tFactorial %d es %d", valor2,factorial2);

    }
    else
    {
            printf("\n\t%s",error2);
    }

}
