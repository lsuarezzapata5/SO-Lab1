#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int calcPromedio(int *vect, int n);

int main(int arg, char *argv[]){
	int *buff;
	int n=atoi(argv[1]);
	//convierte de String a int


	buff=(int *)malloc(sizeof(int)*n);
	//Como guardo los vectores en ese buff?
	//int vect[n];
	srand(time(NULL)); //Esta funcion da un valor de inicializacion para el random, 
	//en este caso se usa un timer porque se supone que el tiempo de ejecucion es diferente
	int num;
	int i;
	//int *p=&vect[0];
	int *p;
	p=buff;
	for(i=1; i<n; i++){
		num=rand()%n;
		*(p+i)=num;
	}
	int promedio=calcPromedio(p, n);
	printf("El promedio es: %d \n", promedio);
	free(buff);
	return 0;
	
}
int calcPromedio(int *p, int n){
	int suma=0;
	int i;
	for(i=1; i<n; i++){
		suma+=*(p+i);
	}
	return suma/n;
}