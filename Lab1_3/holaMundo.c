#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	char *buffer;
	char *string1="Hola ";
	buffer=malloc(sizeof(char)*30);
	//Esta definiendo un "buffer" reservandole 
	//en memoria un espacio de tamaño sizeof(char)*30
	strcpy(buffer, string1);
	//Copia la cadena apuntada por String1 (agregandole un byte nulo al final) al buffer
	strcat(buffer, "Mundo. ");
	//Concatena la cadena "Mundo. " al destino agregandole un byte nulo al final
	puts(buffer);
	//Escribe la cadena buffer y le agrega un salto al final
	free(buffer);
	//Libera espacio --> buffer es el tamaño de lo que se va a liberar
	return 0;

}