#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <string.h>
#define ELEMENTOSARRAY 51
#define LIBRE 0
#define OCUPADO 1


float getFloat(char msj[]);
int ValidarSalario(float valor,int parametro);

int getStr (char msj[],char dato[],int);
int ValidarCadena (char str[],int,char error[] );
void CopiarStrValidado(char cadenaDestino[],char cadenaOrigen[]);

int getInt (char msj[]);
int ValidarSector(int valor, int parametro);

//char getChar(char msj[]);
void validarTodo(char msj[],char msjError[],char confirma[],char str[]);
void ConvertirPrimerCaracterStrMayus(char lista[]);




#endif // FUNCIONES_H_INCLUDED
