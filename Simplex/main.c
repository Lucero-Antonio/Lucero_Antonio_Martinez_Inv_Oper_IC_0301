#include "simplex.h"

/*-------------------------------------------------------------------------*/
/**
 @file main.c
 @brief Archivo principal que hace las llamadas a las funciones
 @author Lucero Antonio M.
 @date Diciembre 2020
*/
/*--------------------------------------------------------------------------*/

int main(void){
	
	rest = leeDatos( &var);
	CrearTabla();
	iteraciones();
	printf("\n----> SE HA ENCONTRADO LA SOLUCION OPTIMA\n");
	
}
