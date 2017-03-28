//gcc laberinto.c -o laberinto
//./laberinto

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>

int main(){

	int line = 0;

	FILE *archivo;
 	
 	char caracter[100];
 	char **matriz;
 	int x;
 	int y;

 	int fila = 0;
 	int columna;
 	
 	archivo = fopen("lab.txt","r");
 	
 	if (archivo == NULL)
 		exit(1);
 	
 	while (feof(archivo) == 0)
 	{
 		fgets(caracter,100,archivo);
 		if (line == 0){
   			// strcpy(matriz, caracteres);
   			x = (int)(caracter[1]-'0');
   			y = (int)(caracter[3]-'0'); 									
 			line++;
 			
			matriz = (int **)malloc (x*sizeof(int *));
			int i;
			for (i=0;i<x;i++){
				matriz[i] = (int *) malloc (y*sizeof(int));
 			}
 		}else{
 			for(columna=0; columna < y; columna++){
 				matriz[fila][columna] = caracter[columna];

 				printf("%c",matriz[fila][columna]);
 			}
 			printf("\n");
 			fila++;
 		}	
 	}
 	printf("\n");
 	printf("ll" );
 	printf("%c",matriz[0][1]);
    fclose(archivo);
	return 0;
}