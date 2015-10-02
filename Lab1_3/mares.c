#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define numMaxNombre 20
int numeroMaterias;
float calcularPromedio(int n,float *notaObtenida,int *numeroCreditos);
int getNumMat();
void getDatos(int n, char (*nombreMateria)[numMaxNombre], float *notaObtenida, int *numeroCreditos);
void imprimir(int n, float prom, char (*nombreMateria)[numMaxNombre], float *notaObtenida, int *numeroCreditos);
//char (*nombreMateria)[numMaxNombre] tengu un apuntador tipo char a un arreglo

int main(){
	float *notaObtenida;
	int *numeroCreditos;
	char (*nombreMateria)[numMaxNombre];
	float prom=0;
	printf("====================Bienvenido=====================\n\n");
	int n=getNumMat();
	//Creacion de los arreglos con memoria dinamica
	//float notaObtenida[n];
	notaObtenida = (float *) malloc(sizeof(float)*n);
	numeroCreditos = (int *) malloc(sizeof(int)*n);
	nombreMateria = (char(*)[numMaxNombre]) malloc(sizeof(char[numMaxNombre])*n);
	
	printf("tamaño: %d\n", (int)sizeof(char[numMaxNombre])*n);
	
	//Llamado a la funcion para obtener los datos de la materia
	getDatos(n, nombreMateria, notaObtenida, numeroCreditos);
	
	//Llamado a la funcion para clacular el promedio
	prom=calcularPromedio(n,notaObtenida, numeroCreditos);

	//Llamado a la funcion para imprimir
	imprimir(n, prom, nombreMateria, notaObtenida, numeroCreditos);
	free(notaObtenida);
	free(nombreMateria);
	free(numeroCreditos);
	return 0;

}
 int getNumMat(){
 	printf("Ingrese el numero de materias: ");
	scanf("%d", &numeroMaterias);
	int n=numeroMaterias;
	return n;
 }

void getDatos(int n, char (*_nombreMateria)[numMaxNombre], float *notaObtenida, int *numeroCreditos){
int i;
	for (i=0; i<n;i++){
		setbuf(stdin, NULL);
		printf("===Datos de la Materia %d=== \n", i+1);
		printf("Nombre Materia: \n");
		scanf("%s", (char *)(_nombreMateria+i));
		printf("Nota obtenida: \n");
		scanf("%f", notaObtenida+i);
		printf("Creditos Materia: \n");
		scanf("%d", &numeroCreditos[i]);

	}

}
float calcularPromedio(int n,float *notaObtenida,int *numeroCreditos){

	float suma=0;
	int creditosTotal=0;
	float prom=0;
	int i;
	for (i=0; i<n;i++){
		suma=suma+((*(notaObtenida+i))*numeroCreditos[i]);
		creditosTotal=creditosTotal+numeroCreditos[i];
	}
	prom=suma/creditosTotal;
	return prom;
}

void imprimir(int n, float prom, char (*nombreMateria)[numMaxNombre], float *notaObtenida, int *numeroCreditos){
	printf("====================Resultado=====================\n\n");
	printf("El promedio es: %f\n\n",prom );
	printf("MATERIA  | NOTA  |CREDITOS\n");
	int i;
	for (i=0; i<n;i++){
		printf("%-8s | %-6.2f| %d\n", (char *)(nombreMateria+i), *(notaObtenida+i),numeroCreditos[i] );
	}
}
