#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED



#endif // FUNCIONES_H_INCLUDED

/*
Recibe dos valores y retorna el resultado de la suma
*/
int SacarSuma (int valor1,int valor2);
/*
Recibe dos valores y retorna el resultado de la resta
*/
int SacarResta (int valor1,int valor2);
/*
Recibe dos valores y retorna el resultado de la division si el 2do valor es distinto de 0
*/
float SacarDivision (int valor1,int valor2);
/*
Recibe dos valores y retorna el resultado de la multiplicacion
*/
int SacarMultiplicacion (int valor1,int valor2);
/*
Recibe un valor, y si es mayor a -1 devuelve el factorial de dicho valor
*/
int SacarFactorial (int valor);
/*
Pide el numero al usuario y lo devuelve
*/
int IngresarNumero ();
/*
Toma un valor y muestra un msj de error si es 0(toma el 2do valor ingresado), caso contrario, muestra un msj con el valor de la division
*/
void ValidarDivision (int valor,float division,char error[]);
/*
Toma el valor ingresado y si este es >-1  muestra el valor de retorno de la funcion factorial, caso contrario muestra un msj de error.
*/
void ValidarFactorial(int valor,int factorial,char error[]);
/*
Muestra los resultados de las funciones o los msjs de error según corresponda
*/
void MostrarResultados(int valor1,int valor2,int suma, int resta, float division, int multiplicacion, int factorial1,int factorial2,char error1[],char error2[]);
/*
Muestra el menu, en primera instancia sin valores (X,Y), los cuales se van modificando acorde al valor ingresado por el usuario (para eso el contador)
*/
void MostrarMenu(numeroUno,numeroDos,contador);

