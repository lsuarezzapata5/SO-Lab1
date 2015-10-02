#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(){
	int x=20;
	int *ptr=&x;
	printf("El dato: %d \nLa direccion: %p \n", *ptr,ptr);
	

	float *ptr2=malloc(sizeof(float));
	*ptr2=40.5;
	printf("El dato: %f \nLa direccion: %p \n", *ptr2,ptr2);
	return 0;
}