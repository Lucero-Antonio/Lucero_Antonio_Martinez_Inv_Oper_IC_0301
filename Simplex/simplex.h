/*-------------------------------------------------------------------------*/
/**
 @file simplex.h
 @brief Prototipo de funciones, declaracion de variables y macros
 @author Lucero Antonio M.
 @date Diciembre 2020
*/
/*--------------------------------------------------------------------------*/

#ifndef SIMPLEX_H
#define SIMPLEX_H

#include<stdio.h>
#include<stdlib.h>

#define MAX 10 //numero maximo de varibles en la funcion
#define RESTRICCION 3 //número máximo de restricciones

double funcion[MAX], restricciones[MAX+1][MAX+RESTRICCION];
double independiente[RESTRICCION];

int rest, var, nt ;
int i,j, k, columna, renglon, count, cuenta;
double maximo, menor, aux, mult, temp;

int leeDatos(int *var);
void CrearTabla();
void iteraciones();

#endif
