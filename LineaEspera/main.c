/*-------------------------------------------------------------------------*/
/**
* @file main.h
* @date 22/12/2020
* @author Lucero Antonio Martínez
* @brief Piden los datos al usuario y llama a las funciones
*/
/*-------------------------------------------------------------------------*/
#include "LineaEspera.h"

int main(int argc, char *argv[]) {
	printf("--------------------LINEA DE ESPERA-------------------------\n");
	printf("\nIndique la hora inicial: ");
	scanf("%i",&hInicio);
	fflush(stdin);
	printf("Indique la hora final: ");
	scanf("%i",&hFinal);
	fflush(stdin);
	printf("Capacidad unitaria por hora: ");
	scanf("%i",&CapacidadU);
	fflush(stdin);
	for(i=hInicio;i<=hFinal-1;i++){
		printf("\nHoras: %i - %i ",i,(i+1));
		printf("\nLlegadas Clientes: ");
		scanf("%i",&NoClientes[i]);
		fflush(stdin);
		printf("No. Cajas Abiertas: ");
		scanf("%i",&NoCajas[i]);
		fflush(stdin);
		CapacidadSalidas[i]=CapacidadU*NoCajas[i];
	}
	
	printf("");
	printf("-------------------------------------------------------------------------------------------------");
	printf("\n|Horas\t\t\t|");
	imprimirHoras(hInicio,hFinal);
	printf("\n|Llegadas Clientes\t|");
	imprimir(NoClientes,hInicio,hFinal);
	printf("\n|No. Cajas Abiertas\t|");
	imprimir(NoCajas,hInicio,hFinal);
	printf("\n|Capacidad Salidas\t|");
	salidasClientes(NoClientes,CapacidadSalidas,hInicio,hFinal);
	imprimir(CapacidadSalidas,hInicio,hFinal);
	printf("\n|Salidas de Clientes\t|");
	imprimir(SalidaClientes,hInicio,hFinal);
	printf("\n|Cola de Espera\t\t|");
	imprimir(Espera,hInicio,hFinal);
	printf("\n|INPUT\t\t\t|");
	Input(NoClientes,hInicio,hFinal);
	imprimir(input,hInicio,hFinal);
	printf("\n|OUTPUT\t\t\t|");
	Output(CapacidadSalidas,hInicio,hFinal);
	imprimir(output,hInicio,hFinal);
	return 0;
}

