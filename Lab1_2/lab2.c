/*
Laboratorio 2:
Programa que solicite el primer nombre de un estudiante, 
almacenarlo como una cadena de caracteres
Solicite la nota obtenida y almacenarlo como un flotante
Imprima: 
Nombre: max 5 caracteres, alineado a la izq
Nota: ancho del campo 5, max 2 decimales
Tecla q para terminar
*/

#include <stdio.h>
#include <unistd.h>
char nombre[5];
char quite='a';
int main(){

	while(quite!='q'){
		setbuf(stdin, NULL);
		float nota;
		printf("\n");
		printf("====================Bienvenido=====================\n\n");
		printf("Ingrese el primer nombre del estudiante por favor: ");
		scanf("%s", &nombre[0]);
		printf("Ingrese la nota del estudiante: ");
		scanf("%f", &nota);
		printf("====================Resultado======================\n\n");
		printf("Nombre: %-.5s \nNota: %-5.2f \n", nombre, nota);
		setbuf(stdin, NULL);
		printf("===================================================\n\n");
		printf("Para salir presione q: \n");
		scanf("%c", &quite);
		
	}
	return 0;
}
