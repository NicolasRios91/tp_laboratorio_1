#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>

/** \brief Pide un valor y devuelve el float
*
* \param  msj[] char, texto indicativo
* \return float, devuelve el valor ingresado
*/
float getFloat(char msj[]);


/** \brief Recibe un valor y valida el rango
*
* \param parametro int, rango que no puede ser mayor al valor recibido
* \return int return, devuelve 0 si se encuentra dentro del rango, -1 si no cumple
*/
int ValidarSalario(float valor,int parametro);



/** \brief Recibe una variable tipo char[] y le copia una cadena de caracteres si esta dentro del rango
*
* \param dato[] char, variable donde se guardara el array de char.
* \param int, tamaño maximo de la cadena
* \return int return, devuelve 0 se pudo copiar, -1 si no cumple con el rango
*/
int getStr (char msj[],char dato[],int);


/** \brief Recibe una variable tipo char[] y valida que este dentro del rango ingresado
*
* \param str[] str, cadena que se sometera a la validacion
* \param int, tamaño maximo de la cadena
* \param error[] char, cuando no cumpla la condicion
* \return int return, devuelve 0 si cumple, -1 si no cumple con el rango
*/
int ValidarCadena (char str[],int,char error[] );



/** \brief Recibe una variable tipo char[] previamente validada y la copia en otra una cadena
*
* \param cadenaDestino[] char, variable donde se copiara la cadena
* \param char cadenaOrigen[] char, variable de la cual se hara la copia
*/
void CopiarStrValidado(char cadenaDestino[],char cadenaOrigen[]);


/** \brief Pide un valor y devuelve el int
*
* \param msj[] char, texto indicativo
* \return int, devuelve el valor ingresado
*/
int getInt (char msj[]);


/** \brief Recibe un valor y valida el rango
*
* \param parametro int, rango que no puede ser mayor al valor recibido
* \return int, devuelve 0 si se encuentra dentro del rango, -1 si no cumple
*/
int ValidarInt(int valor, int parametro);


/** \brief Recibe una cadena de caracteres y convierte la primera y la letra siguiente a un espacio en mayuscula
*
* \param lista[] char, cadena
*/
void ConvertirPrimerCaracterStrMayus(char lista[]);



#endif // FUNCIONES_H_INCLUDED
