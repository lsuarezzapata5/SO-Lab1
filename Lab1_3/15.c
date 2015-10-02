#include <stdio.h>

int main(void){
	//definimos las variables
	int n;	//numero de materias
	printf("\n*********Bienvenido a mi programa*********\n");
	printf("Ingrese el numero de materias a registrar\n");
	scanf("%d",&n);

	char materias[n][10*n];
	float notas[n];
	int creditos[n];

	int i;
	for(i=0; i<n; i++){
		printf("\n******************************************\n");
		printf("	DATOS DE LA MATERIA: %d\n", i+1);
		printf("Ingrese el nombre de la materia: ");
		scanf("%s", &materias[i]);
		printf("Ingrese la nota obtenida: ");
                scanf("%f", &notas[i]);
                printf("Ingrese el numero de creditos: ");
                scanf("%d", &creditos[i]);
	}
	/*
	//calculo del promedio ponderado
	float promedio = 0;
	int sumaCreditos = 0;
	for (i=0; i<n; i++){
		promedio += notas[i]*creditos[i];
		sumaCreditos += creditos[i];
	}
	printf("\n******************************************\n");
	printf("MATERIA    NOTA    CREDITO\n");
        printf("\n******************************************\n");
	for (i=0; i<n; i++){
		printf("%-11s%-10.2f%d\n", materias[i], notas[i], creditos[i]);
	}
        printf("\n******************************************\n");
	printf("PROMEDIO PONDERADO: %f\n", promedio/sumaCreditos);
	*/
	return 0;
}
