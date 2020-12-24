/*-------------------------------------------------------------------------*/
/**
* @file		LineaEspera.c
* @date 	22/12/2020
* @author 	Lucero Antonio Martínez
* @brief  	Contiene la esctructura de las funciones implementadas en la funcion main
*/
/*-------------------------------------------------------------------------*/

#include "LineaEspera.h"

/**
*@brief    imprimirHoras()  imprime el rango de las horas dados el inicio y fin del rango principal
*
*@param     inicio     Parametro de entrada que guarda el valor que marca el inicio del rango
*@param     fin        Parametro de entrada que guarda el valor que marca el fin del rango
*@return   void
*
*/
void imprimirHoras(int inicio,int fin){
	for(i=inicio;i<=fin-1;i++){
		printf("\t%i-%i",i,(i+1));
	}
	printf("\n------------------------------------------------------------------------------------------------");
}

/**
*@brief    imprimirHoras()  imprime el rango de las horas dados el inicio y fin del rango principal
*
*@param     Valor[TAM] Parametro de entrada que guarda los valores a imprimir
*@param     inicio     Parametro de entrada que guarda el valor que marca el inicio del rango
*@param     fin        Parametro de entrada que guarda el valor que marca el fin del rango
*@return   void
*
*/
void imprimir(int Valor[TAM],int inicio,int fin){
	for(i=inicio;i<=fin-1;i++){
		printf("\t %i",Valor[i]);
	}
	printf("\n------------------------------------------------------------------------------------------------");
}

/**
*@brief    imprimirHoras()  imprime el rango de las horas dados el inicio y fin del rango principal
*
*@param     NoClientes[TAM]     	Parametro de entrada que guarda los valores de llegadas de clientes
*@param     CapacidadSalidas[TAM]   Parametro de entrada que guarda la capcidad de salidas segun el numero de cajas abiertas
*@param     Inicio					Parametro de entrada que guarda el valor que marca el inicio del rango
*@param     Final			        Parametro de entrada que guarda el valor que marca el fin del rango
*@param     Espera[TAM]				Guarda el valor acumulado de los clientes en espera
*@param     Clientes[TAM]			Guarda el valor de las llegadas de clientes mas el valor acumalo de los clientes en espera
*@return   void
*
*/
void salidasClientes(int NoClientes[TAM],int CapacidadSalidas[TAM],int Inicio,int Final){
	Espera[Inicio-1]=0;
	for(i=Inicio;i<=Final-1;i++){
		Clientes[i]=NoClientes[i]+Espera[i-1];
		if(CapacidadSalidas[i]<Clientes[i]){
			SalidaClientes[i]=CapacidadSalidas[i];
			Espera[i]=Clientes[i]-CapacidadSalidas[i];
		} else{
			SalidaClientes[i]=CapacidadSalidas[i]-NoClientes[TAM];
			Espera[i]=0;
		}
	}
}

/**
*@brief    Output()  imprime el rango de las horas dados el inicio y fin del rango principal
*
**@param	SalidaClientes[TAM]	Parametro de entrada que guarda los valores del numero de salidas de clientes
*@param     Inicio    			Parametro de entrada que guarda el valor que marca el inicio del rango
*@param     Final     			Parametro de entrada que guarda el valor que marca el fin del rango
*@param     output	  			Guarda el valor acumulado de las salidas de clientes
*@return   void
*
*/
void Output(int SalidaClientes[TAM],int Inicio,int Final){
	output[Inicio-1]=0;
	for(i=Inicio;i<=Final-1;i++){
		output[i]=SalidaClientes[i]+output[i-1];
	}
}

/**
*@brief    Input()  imprime el rango de las horas dados el inicio y fin del rango principal
*
*@param		Clientes[TAM]	Parametro de entrada que guarda el valor del numero de llegadas de clientes
*@param     Inicio     		Parametro de entrada que guarda el valor que marca el inicio del rango
*@param     Final      		Parametro de entrada que guarda el valor que marca el fin del rango
*@param     output	  		Guarda el valor acumulado de las llegadas de clientes
*@return   void
*
*/
void Input(int Clientes[TAM],int Inicio,int Final){
	input[Inicio-1]=0;
	for(i=Inicio;i<=Final-1;i++){
		input[i]=Clientes[i]+input[i-1];
	}
}
