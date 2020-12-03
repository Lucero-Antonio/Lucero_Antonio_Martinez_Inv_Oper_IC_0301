#ifndef __CAMINO_H
#define __CAMINO_H
#include <stdio.h>

/********************************************//**
*  @file  	camino.h
*  @brief 	Declaracion de las variables
			globales y funciones
*  @author 	Lucero Antonio M.
*  @date 	octubre 2020
************************************************/

#define MAX 10

int funcion[MAX], adya[MAX+1][MAX+1];
int r,c,x,y,adyacen;
int i,j;
char opcion;

void tablaInicial();
void pedirAdyacencias();
void encontrarCamino();


#endif

