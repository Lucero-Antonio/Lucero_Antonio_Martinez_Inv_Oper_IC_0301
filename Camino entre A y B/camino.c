#include "camino.h"

/********************************************//**
*  @file  	camino.c
*  @brief 	Implementacion de las funciones
*  @author 	Lucero Antonio M.
*  @date 	octubre 2020
*  
************************************************/

/********************************************//**
*  @brief	Crea la tabla inicial (Matriz)
************************************************/
void tablaInicial(){
	
	for (i=0;i<=r;++i){
		for (j=0;j<=r;++j){
			adya[0][j]=j;
			adya[i][0]=i;
			adya[i+1][j+1]=0;
		}
	}
	printf("\n");
	for (i= 0;i<=r;++i){
		for (j=0;j<=r;++j){
			printf("%i\t",adya[i][j]);
		}
		printf("\n");
	}
}

/********************************************//**
*  @brief 	Pide la posicion de las adyacencias
************************************************/
void pedirAdyacencias(){
	adyacen=0;
	while(adyacen<c){
		printf("\nAdyacencia #%i",adyacen+1);
		printf("\nx: ");
		scanf("%i",&x);
		fflush(stdin);
		printf("y: ");
		scanf("%i",&y);
		fflush(stdin);
		for (i=0;i<=r;++i){
			for (j=0;j<=r;++j){			
				adya[y][x]=1;
				printf("\n");
				for (i= 0;i<=r;++i){
					for (j=0;j<=r;++j){
						printf("%i\t",adya[i][j]);
					}
					printf("\n");
				}
			}
		}
		adyacen++;
	}
}

/********************************************//**
*  @brief 	Busca si existe un camino entre a y b
* 
************************************************/
void encontrarCamino(){
	do{	
		printf("\nEncontrar si exite camino:");
		printf("\nx: ");
		scanf("%i",&x);
		fflush(stdin);
		printf("y: ");
		scanf("%i",&y);			
		fflush(stdin);
		if(adya[y][x]==1){
			printf("\n-->Existe un camino entre los vertices<--\n");
		} else {
			printf("\n-->No existe un camino entre los vertices<--\n");
		}
		printf("\n¿Desea buscar otro camino? [y/n]");
		scanf("%c",&opcion);
	}
	while(opcion=='y');
}
