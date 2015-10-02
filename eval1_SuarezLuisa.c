#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAXCHAR 20
#define NUMEROARTICULOS 100

void newBill(int *codigos,int *valor, char (*descripcion)[MAXCHAR]);
void imprimir(int n, int *cantidad,  int *valor, int total, int *totales, int *codigo, char (*descripcion)[MAXCHAR]);
void buscarItem(int *codigo, int *valor, char (*descripcion)[MAXCHAR]);


int main(){
	
	 int codigo[NUMEROARTICULOS]={101,102,103,104,105,106};
	 char descripcion[NUMEROARTICULOS][MAXCHAR]={ "Articulo#1", "Articulo#2", "Articulo#3","Articulo#4","Articulo#5", "Articulo#6"};
	 int valor[NUMEROARTICULOS]={300,500,250,100,900,600};
	 char opcion;
	 int new;

	 while(opcion!='q'){
	 setbuf(stdin, NULL);
	 printf("\n\n=================================== \nIngrese \n A para una nueva factura \n B para consultar Articulo \n Q para salir \n");
	 scanf("%c", &opcion);


		 if (opcion=='a' || opcion=='A'){
		 	//Llamado a la funcion para crear una nueva funcion
		 	newBill(codigo, valor , descripcion);
		 } else  if(opcion=='b' || opcion=='B'){
		 	//Llamado a la funcion para buscar un articulo
		 	buscarItem(codigo,  valor, (char (*)[MAXCHAR])descripcion);
		 } else  if(opcion=='q' || opcion=='Q'){
		 	return 0;
		 } else{
		 	 printf("No ingreso una opcion valida \n");
		 }
	
	  }

}

void newBill(int *codigos, int *valor, char (*descripcion)[MAXCHAR]){
	int numeroArticulos;
	int codigoArticulo;
	int *f_codigo;
	int *f_cantidad;
	int *f_valor;
	int *f_total;
	char *f_descripcion;
	int n;
	int total=0;
	int a=0;

	printf("Ingrese el numero de articulos a facturar: ");
	scanf("%d", &numeroArticulos);
	n=numeroArticulos;

	f_codigo=malloc(sizeof(int)*n);
	f_cantidad=malloc(sizeof(int)*n);
	f_valor=malloc(sizeof(int)*n);
	f_descripcion=malloc(sizeof(int)*n*MAXCHAR);

	f_total=malloc(sizeof(char)*n);

	int i=0;
	while ( i<n){
		a=0;

		setbuf(stdin, NULL);
		printf("===Datos del articulo %d=== \n", i+1);
		printf("Codigo Articulo: \n");
		scanf("%d", &codigoArticulo);
		//Para validar que el codigo es de un articulo existente
		int j;
		for (j=0; j<NUMEROARTICULOS;j++){
			if(codigoArticulo==codigos[j]){
				f_codigo[i]=codigoArticulo;
				printf("Ingrese la cantidad de Articulos %d a facturar: \n",f_codigo[i] );
				scanf("%d", &f_cantidad[i]);
				f_valor[i]=valor[j];
				f_descripcion=(char *)descripcion+j;
				f_total[i]=(f_valor[i])*(f_cantidad[i]);
				total+=(f_valor[i])*(f_cantidad[i]);
				printf("Valor de Articulo %d - %s : %d Valor total articulo: %d Acumulado:  %d \n",f_codigo[i],(f_descripcion+i),  f_valor[i],f_total[i], total);

				a=1;
				i++;

			}

		
		}
		if(a==0){
			printf("El articulo con codigo %d no se encontró\n", codigoArticulo);
		}
		
	}

	imprimir(n, f_cantidad,  f_valor, total, f_total,f_codigo, descripcion );
	
}

void imprimir(int n, int *cantidad,  int *valor, int total, int *totales, int *codigo, char (*descripcion)[MAXCHAR]){
	printf("\n\n              Factura de Venta\n");
	printf("                   Nombre Empresa \n");
	
	printf("Cantidad  | Descripcion | V. unit | Total\n");
	int i;
	for (i=0; i<n;i++){
		printf("%-8d  | %-5s  |%-10.2d| %d\n", cantidad[i], (char *)(descripcion+i),valor[i],totales[i] );
	}
	printf("Total: %d\n\n",total );
	
}

void buscarItem(int *codigo,  int *valor, char (*descripcion)[MAXCHAR]){
	int a=0;
	int codigoArticulo;
	printf("Codigo Articulo: \n");
	scanf("%d", &codigoArticulo);

	int j;
		for (j=0; j<NUMEROARTICULOS;j++){
			
			if(codigoArticulo==codigo[j]){

				printf("Datos del articulo: \n Codigo: %d \n Descripcion: %s \n Valor: %d \n", codigo[j], (char *)(descripcion+j) , valor[j] );
				a=1;
			}

		
		}
		if(a==0){
			printf("El articulo con codigo %d no se encontró\n", codigoArticulo);
		}
		
		


}
