/*-------------------------------------------------------------------------*/
/**
* @file main.h
* @date 22/12/2020
* @author Lucero Antonio Martínez
* @brief Prototipo de funciones y declaración de variables globales
*/
/*-------------------------------------------------------------------------*/

#ifndef __Espera1_H
#define __Espera1_H

#include <stdio.h>
#include <stdlib.h>

#define TAM 20

int hInicio,hFinal,CapacidadU,NoHoras[TAM],NoClientes[TAM],NoCajas[TAM],input[TAM],output[TAM],i;
int CapacidadSalidas[TAM],SalidaClientes[TAM],Espera[TAM],Clientes[TAM],Valor[TAM];

void imprimirHoras(int inicio,int fin);
void imprimir(int Valor[TAM],int inicio,int fin);
void salidasClientes(int NoClientes[TAM],int CapacidadSalidas[TAM],int Inicio,int Final);
void Output(int Clientes[TAM],int Inicio,int Final);
void Input(int SalidaClientes[TAM],int Inicio,int Final);

#endif
