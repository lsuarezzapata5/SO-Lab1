#include <stdio.h>
char nombres[3][10]={"fulano","mengano","perano"};
int main(void){
	char i;
	char *a; //Cuando sume uno va a sumar 1
	char (*b)[10]; //Cuando sume uno va sumar 10 en realidad

	a=(char *)nombres; //Se alamcena en a el contenido de nombre[0]
	printf("El nombre es %s\n",a );
	b=(char (*)[10])nombres[0]; //apuntador a un arreglo de 10 posiciones,
	//es decir, apunta a nombres[0]

	for(i=0; i<3; i++){
		printf("El nombre[%d] es %s \n",i,(char *)(b+i) );
		//b es un apuntador hacia nombres[0],
		//i es la posicion del vector que estamos recorriendo
		//(char *)(b+i) accede al contenido de nombres[i]

	}
	return 0;

}