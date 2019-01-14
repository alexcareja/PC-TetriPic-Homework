#include <stdlib.h>
#include <stdio.h>
#include "tasks.h"
#include "func.h"
#include "bmp_header.h"


void task1(){
	piesa(40,40,10,30,10,30,0,0,0,0,255,255,0,"piesa_O.bmp");
	piesa(60,30,10,50,10,20,0,0,0,0,0,0,255,"piesa_I.bmp");
	piesa(40,50,10,20,20,40,20,30,10,30,255,0,0,"piesa_S.bmp");
	piesa(40,50,10,20,10,30,20,30,20,40,0,255,0,"piesa_Z.bmp");
	piesa(50,40,10,40,10,20,30,40,20,30,255,140,0,"piesa_L.bmp");
	piesa(50,40,10,40,20,30,30,40,10,20,255,0,255,"piesa_J.bmp");
	piesa(40,50,10,20,10,40,20,30,20,30,130,0,255,"piesa_T.bmp");

}

void task2(){
	piesa(40,40,10,30,10,30,0,0,0,0,255,255,0,"piesa_O_90.bmp");
	piesa(40,40,10,30,10,30,0,0,0,0,255,255,0,"piesa_O_180.bmp");
	piesa(40,40,10,30,10,30,0,0,0,0,255,255,0,"piesa_O_270.bmp");
	piesa(30,60,10,20,10,50,0,0,0,0,0,0,255,"piesa_I_90.bmp");
	piesa(60,30,10,50,10,20,0,0,0,0,0,0,255,"piesa_I_180.bmp");
	piesa(30,60,10,20,10,50,0,0,0,0,0,0,255,"piesa_I_270.bmp");
	piesa(50,40,10,30,10,20,20,40,20,30,255,0,0,"piesa_S_90.bmp");
	piesa(40,50,10,20,20,40,20,30,10,30,255,0,0,"piesa_S_180.bmp");
	piesa(50,40,10,30,10,20,20,40,20,30,255,0,0,"piesa_S_270.bmp");
	piesa(50,40,10,30,20,30,20,40,10,20,0,255,0,"piesa_Z_90.bmp");
	piesa(40,50,10,20,10,30,20,30,20,40,0,255,0,"piesa_Z_180.bmp");
	piesa(50,40,10,30,20,30,20,40,10,20,0,255,0,"piesa_Z_270.bmp");
	piesa(40,50,10,20,10,40,20,30,10,20,255,140,0,"piesa_L_90.bmp");
	piesa(50,40,10,20,10,30,20,40,20,30,255,140,0,"piesa_L_180.bmp");
	piesa(40,50,10,20,30,40,20,30,10,40,255,140,0,"piesa_L_270.bmp");
	piesa(40,50,10,20,10,20,20,30,10,40,255,0,255,"piesa_J_90.bmp");
	piesa(50,40,10,20,10,30,20,40,10,20,255,0,255,"piesa_J_180.bmp");
	piesa(40,50,10,20,10,40,20,30,30,40,255,0,255,"piesa_J_270.bmp");
	piesa(50,40,10,40,20,30,20,30,10,20,130,0,255,"piesa_T_90.bmp");
	piesa(40,50,10,20,20,30,20,30,10,40,130,0,255,"piesa_T_180.bmp");
	piesa(50,40,10,40,10,20,20,30,20,30,130,0,255,"piesa_T_270.bmp");
}

void task3(){
	/*
	citire fisier
	generare harta neagra + alb deasupra
	0 - spatiu liber (negru)
	1 - ALB
	O, I, S, Z, L, J, T - patrat din piesa (mai incolo)
	apel functie care baga piese si scrie harta
	*/
	int i, j, nr_piese, map_height, map_width;
	date_piesa *Piese = (date_piesa *) malloc(50 * sizeof(date_piesa));
	FILE *input_file = fopen("cerinta3.in","r");
	fscanf(input_file, "%d %d %d\n", &nr_piese, &map_height, &map_width);
	//printf("%d %d %d\n", nr_piese, map_height, map_width);
	for(i = 0; i < nr_piese; i++){
		fscanf(input_file, "%c %d %d\n", &Piese[i].nume_piesa, &Piese[i].rotatie,
					 &Piese[i].coloana);
		//printf("%c %d %d\n", Piese[i].nume_piesa, Piese[i].coloana, Piese[i].rotatie);
	}
	fclose(input_file);
	char **map = (char **) malloc((map_height + 5) * sizeof(char *));
	for (i = 0; i < map_height + 4; i++){
		map[i] = (char *) malloc((map_width + 1) * sizeof(char ));
		if(i < 4){
			for(j = 0; j < map_width; j++){
				map[i][j] = '1';
			}
		}
		else{
			for(j = 0; j < map_width; j++){
				map[i][j] = '0';
			}
		}
	}
	char **piesa = (char **) malloc((map_height + 5) * sizeof(char *));
	for(i = 0; i < map_height + 4; i++){
		piesa[i] = (char *) malloc((map_width + 1) * sizeof(char));
	}
	drop_pieces(map, piesa, map_height + 4, map_width, Piese, nr_piese);
}

void task4(){
	/*
	citire fisier
	apel functie care baga piese si scrie harta (ca la task 3)
	*/
}

void bonus(){
	
}
