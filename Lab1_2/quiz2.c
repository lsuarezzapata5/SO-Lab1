/*
Calcule el area y el perimetro de un triangulo rectangulo dada la base y altura
salida: el area del triangulo de base..cm y altura ..cm es ..cm²

*/


#include <stdio.h>
#include <unistd.h>
#include <math.h> 
float area;
float perimetro;
char quite;
int main(){

	while(quite!='q'){
		setbuf(stdin, NULL);
		float base;
		float altura;
		float hipotenusa;
		printf("\n");
		printf("====================Bienvenido=====================\n\n");
		printf("Ingrese la base del triangulo rectangulo (en cm): ");
		scanf("%f", &base);
		printf("Ingrese la altura del triangulo rectangulo (en cm): ");
		scanf("%f", &altura);
		area= (base*altura)/2;
		float b2;
		float a2;
		b2=base*base;
		a2=altura*altura;
		float ab2;
		ab2=a2+b2;
		hipotenusa=sqrt(ab2);
		perimetro= base+altura+hipotenusa;
		printf("====================Resultado======================\n\n");
		printf("El triangulo de base %f cm y altura %f cm \n Area: %fcm² \n Perimetro: %f \n", base, altura, area,perimetro);
		setbuf(stdin, NULL);
		printf("===================================================\n\n");
		printf("Para salir presione q: \n");
		scanf("%c", &quite);
		
	}
	return 0;
}

