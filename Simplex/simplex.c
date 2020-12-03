#include "simplex.h"

/*-------------------------------------------------------------------------*/
/**
 @file simplex.c
 @brief Implementacion de las funciones
 @author Lucero Antonio M.
 @date Diciembre 2020
*/
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/**
*@brief    leerDatos() pide al usuario el valor de los datos
*\details  Esta funcion pide al usuario el numero de varibles y restricciones,
*		   mediante ciclos for delimitados por las varibles de entrada del teclado 
* 		   pide el valor de cada una de las variables y restricciones.
*
*\details   
*@param 	*var 	Puntero de entrada para el seguimiento de las variables
*@param     var     Guarda el numero de variables
*@param     res     Guarda el numero de restricciones
*@param     c       Respresenta el indice de las variables
*@param     i       Respresenta el indice de las restricciones
*@param    funcion  	  Guarda el valor de las varibles de la funcion
*@param    restricciones  Guarda el valor de las restriciones 
*@param    independiente  Guarda el valor inpendiente
*@return   int  rest retorna el numero de restricciones
*
*
*/
/*--------------------------------------------------------------------------*/

int leeDatos(int *var) {
	int rest,c,i;
	printf(" POGRAMA CREADO PARA RESOLVER EL METODO SIMPLEX\n");
	printf("\n RECUERDA: c1.X1+c2.X2+...cn.Xn = b \n");
	printf("\n Numero de Variables: ");
	scanf("%d",var);
	for(c=0;c<*var;c++){
		printf("  c%d: ", c+1);
		scanf("%lf",&funcion[c]);
		fflush(stdin);
	}

	printf("\n Numero de Restricciones: ");
	scanf("%d",&rest);
	fflush(stdin);

	for(i=0;i<rest;i++){
		printf("\n Restriccion %d\n",i+1);
		for(c=0;c<*var;c++)
		{
		printf("  c%d: ",c+1);
		scanf("%lf",&restricciones[i][c]);
		fflush(stdin);
		}
		printf(" Termino independiente: ");
		scanf("%lf", &independiente[i]);
		fflush(stdin);
	}

	return rest;
}

/*--------------------------------------------------------------------------*/
/**
*@brief    crearTabla() crear tabla inicial simplex
*\details  Esta funcion acomoda los valores insertados para posterirormente imprimirlos
* 		   en formato de tabla.
*   
*@param     var     Aloja el numero de variables. 
*@param     res     Aloja el numero de restricciones.
*@param     j       Respresenta el indice
*@param     i       Respresenta el indice
*@param    funcion  	  Aloja el valor de las varibles de la funcion
*@param    restricciones  Aloja el valor de las restriciones 
*@param    independiente  Aloja el valor inpendiente
*@return    void 
*
*
*/
/*--------------------------------------------------------------------------*/

void CrearTabla(){
	for(i=0;i<rest;i++)
	for(j=0; j<rest; j++)
	if (i == j)
	restricciones[i][var+j]=1;
	else
	restricciones[i][var+j]=0;
	for(i=0; i<rest;i++)
	restricciones[i][var+rest] = independiente[i];

	for(j=0; j<var; j++)
	restricciones[rest][j] = funcion[j] * -1;
	for(j=var; j<rest+var; j++)
	restricciones[rest][j] = 0;

	nt=1;
	printf("\n-----------------------------------------------");
	printf("\n TABLA %d",nt);
	printf("\n-----------------------------------------------\n");
	nt++;
	for(i=0; i<=rest; i++) {
	for(j=0; j<=rest+var; j++)
	printf(" %.2f \t", restricciones[i][j]);
	printf("\n");
	}
}

/*--------------------------------------------------------------------------*/
/**
*@brief    interaciones() encuentra el pivote en la tabla, hace las iteraciones
*		   y crea las nuevas tablas y encuentra la solucion optima.
*\details  Esta funcion recorre la tabla inicial hasta encuentrar el pivote de las
*		   restricciones, realiza las operaciones a las demas restricciones para formar
*		   una nueva tabla o en caso de haber encontrado la solucion optima imprimira la
*		   tabla final.
*
*\details   
*@param 	maximo 	Guarda el valor absoluto de las restricciones
*@param     columna Se posiciona en la columna del pivote
*@param     temp    Guarda temporalmente el valor de la restriccion en las posicion de rest y j multiplicada por -1
*@param     count   Guarda un indice hasta ser igual a rest
*@param     aux     Variable auxiliar para encontrar el valor menor de las restricciones,
*					y ayuda a la creacion de la nueva tabla, tomando el valor del pivote,
*					para dividir a las demas restricciones.
*@param     menor   Guarda el valor menor de las restricciones
*@param     cuenta  Sirve como contador de las restricciones mas las variables
*@return    void 
*
*/
/*--------------------------------------------------------------------------*/


void iteraciones(){
	do{
	maximo = abs(restricciones[rest][0]);
	columna = 0;
	for(j=0; j<=rest+var; j++){
		if( restricciones[rest][j] < 0 ){
			temp = -1 * restricciones[rest][j];
			if ( maximo < temp) {
				maximo = temp;
				columna = j;
			}
		}
		else
		continue;
	}

	count = 0;
	aux = 1e20;
	menor = 1e20;
	
	for(i=0; i<rest; i++) {
	if(restricciones[i][columna] > 0)
	aux = restricciones[i][rest+var] / restricciones[i][columna];
	else
	count++;
		if( menor > aux ) {
			menor = aux;
			renglon = i;
		}
	}
	
	if(count == rest) {
		printf("Solucion no acotada");
		exit(1);
	}
	
	printf("\nPivote: %.2lf, renglon %d columna %d",restricciones[renglon][columna], renglon+1, columna+1);
	
	//Crear nueva tabla
	aux = restricciones[renglon][columna];
	for(j=0; j<=(rest+var); j++)
		restricciones[renglon][j] = restricciones[renglon][j] / aux;
	for(i=0; i<=rest; i++) {
		if (i == renglon )
			continue;
		else {
			aux = restricciones[i][columna] * -1;
			for(k=0; k <= rest+var; k++) {
				restricciones[i][k] = (aux * restricciones[renglon][k]) +
				restricciones[i][k];
			}
		}
	}

	printf("\n-----------------------------------------------");
	printf("\n TABLA %d",nt);
	printf("\n-----------------------------------------------\n");
	nt++;
	for(i=0; i<=rest; i++) {
		for(j=0; j<=rest+var; j++)
		printf(" %.2f \t", restricciones[i][j]);
		printf("\n");
	}
	cuenta = 0;
	for(j=0;j<rest+var;j++)
		if(restricciones[rest][j] >= 0)
			cuenta++;
	if (cuenta == rest+var)
	break;
	} while(cuenta);
}
