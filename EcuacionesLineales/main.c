/**
* @file main.c
* @date 29/9/2020
* @author Lucero A.M.
* @brief Programa que grafica ecuaciones lineales dados el valor de las
* constantes y establecido el rango a evaluar
* 
*/

#include <stdio.h>
#include <stdlib.h>
#include "gnuplot_i.h"

int main() {
	/** @param valorM Indica la pendiente.*/
	/** @param valorB Indica el punto de intercepción en el eje Y.*/
	int valorM, valorB;
	/** @param rango1 Indica el rango inicial*/
	/** @param rango2 Indica el rango final*/
	float rangoX1, rangoX2;
	
	printf("Graficacion de ecuaciones lineales");
	printf("\n\nRecuerda la formula y=m*x+b");
	printf("\nIntroduce los valores");
	printf("\nm = ");
	scanf("%d",&valorM);
	printf("b = ");
	scanf("%d",&valorB);
	printf("\nIntroduce el rango");
	printf("\nDe: ");
	scanf("%f",&rangoX1);
	printf("A: ");
	scanf("%f",&rangoX2);
	
	printf("\n\nLa funcion es y=%i*x+%i",valorM,valorB);
	imprimirValores(valorM,valorB,rangoX1,rangoX2);
	graficarValores(valorM,valorB,rangoX1,rangoX2);
	
	return 0;
}

