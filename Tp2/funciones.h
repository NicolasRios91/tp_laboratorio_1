#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define ELEMENTOSARRAY 51

float getFloat(char msj[]);
int getStr (char msj[],char error[],char dato[], int);
int ValidarCadena (char str[],int );
int getInt (char msj[]);
int SacarMaximoDeUnArrayPorId (Employee lista[],int tam);
//char getChar(char msj[]);
void validarTodo(char msj[],char msjError[],char confirma[],char str[]);
void ConvertirPrimerCaracterStrMayus(char lista[]);
int ValidarFloat(float valor,int parametro);
#endif // FUNCIONES_H_INCLUDED
