#include "camino.h"

/********************************************//**
*  @file  	main.c
*  @brief 	Archivo principal que hace las
			llamadas a las funciones
*  @author 	Lucero Antonio M.
*  @date 	octubre 2020
************************************************/

int main(){
	
	int valorM, valorB;
	float rangoX1, rangoX2;
	
	printf("\nPrograma que indica si existe al menos un camino de un punto A hacia un punto B\n");
	printf("\nNumero de nodos:");
	scanf("%i", &r);
	fflush(stdin);
	printf("\nNumero de adyacencias: ");
	scanf("%i",&c);
	fflush(stdin);
	int adya[r+1][r+1];
	
	/** Llamada a las funciones*/
	tablaInicial();
	pedirAdyacencias();
	encontrarCamino();
}
