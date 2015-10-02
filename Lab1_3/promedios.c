#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int calcPromedio(int *vect);
int main(){
	int vect[100];
	srand(time(NULL)); //Esta funcion da un valor de inicializacion para el random, 
	//en este caso se usa un timer porque se supone que el tiempo de ejecucion es diferente
	int num;
	int i;
	int *p=&vect[0];
	for(i=1; i<100; i++){
		num=rand()%100;
		*(p+i)=num;
	}
	int promedio=calcPromedio(p);
	printf("El promedio es: %d \n", promedio);
	return 0;
	
}
int calcPromedio(int *p){
	int suma=0;
	int i;
	for(i=1; i<100; i++){
		suma+=*(p+i);
	}
	return suma/100;
}