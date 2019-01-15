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
	for(i = 0; i < nr_piese; i++){
		fscanf(input_file, "%c %d %d\n", &Piese[i].nume_piesa, &Piese[i].rotatie,
					 &Piese[i].coloana);
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
	drop_pieces(map, piesa, map_height + 4, map_width, Piese, nr_piese, 3);
}

void task4(){
	/*
	citire fisier
	apel functie care baga piese si scrie harta (ca la task 3)
	*/
	int i, j, nr_piese, map_height, map_width;
	date_piesa *Piese = (date_piesa *) malloc(50 * sizeof(date_piesa));
	fileheader *header_harta = (fileheader *) malloc(sizeof(fileheader));
	infoheader *info_harta = (infoheader *) malloc(sizeof(infoheader));
	FILE *input_file = fopen("cerinta4.in","r");
	fscanf(input_file, "%d\n", &nr_piese);
	for(i = 0; i < nr_piese; i++){
		fscanf(input_file, "%c %d %d\n", &Piese[i].nume_piesa, &Piese[i].rotatie,
					 &Piese[i].coloana);
	}
	fclose(input_file);
	FILE *imag_file = fopen("cerinta4.bmp", "rb");

	fread(&header_harta->fileMarker1, sizeof(char), 1, imag_file);
	fread(&header_harta->fileMarker2, sizeof(char), 1, imag_file);
	fread(&header_harta->bfSize, sizeof(int), 1, imag_file);
	fread(&header_harta->unused1, sizeof(short), 1, imag_file);
	fread(&header_harta->unused2, sizeof(short), 1, imag_file);
	fread(&header_harta->imageDataOffset, sizeof(int), 1, imag_file);

	fread(&info_harta->biSize, sizeof(int), 1, imag_file);
	fread(&info_harta->width, sizeof(int), 1, imag_file);
	fread(&info_harta->height, sizeof(int), 1, imag_file);
	fread(&info_harta->planes, sizeof(short), 1, imag_file);
	fread(&info_harta->bitPix, sizeof(short), 1, imag_file);
	fread(&info_harta->biCompression, sizeof(int), 1, imag_file);
	fread(&info_harta->biSizeImage, sizeof(int), 1, imag_file);
	fread(&info_harta->biXPelsPerMeter, sizeof(int), 1, imag_file);
	fread(&info_harta->biYPelsPerMeter, sizeof(int), 1, imag_file);
	fread(&info_harta->biClrUsed, sizeof(int), 1, imag_file);
	fread(&info_harta->biClrImportant, sizeof(int), 1, imag_file);

	RGB **bit_map = (RGB **) malloc(info_harta->height * sizeof(RGB *));
	for(i = 0; i < info_harta->height; i++){
		bit_map[i] = (RGB *) malloc(info_harta->width * sizeof(RGB));
	}
	for(i = 0; i < info_harta->height; i++){
		for(j = 0; j < info_harta->width; j++){
			fread(&bit_map[i][j].B, sizeof(char), 1, imag_file);
			fread(&bit_map[i][j].G, sizeof(char), 1, imag_file);
			fread(&bit_map[i][j].R, sizeof(char), 1, imag_file);
		}
		if(info_harta->width % 4){
			fseek(imag_file, 2, SEEK_CUR);
		}
	}
	fclose(imag_file);
	map_height = info_harta->height / 10;
	map_width = info_harta->width / 10;
	char **map = (char **) malloc((map_height + 1) * sizeof(char *));
	for(i = 0; i < map_height; i++){
		map[i] = (char *) malloc((map_width + 1) * sizeof(char));
	}
	for(i = 0; i < map_height; i++){
		for(j = 0; j < map_width; j++){
			if((bit_map[10*i][10*j].B == 255) && (bit_map[10*i][10*j].G == 255)
				  && (bit_map[10*i][10*j].R == 255)){
				map[map_height - 1 - i][j] = '1';
			}
			if((bit_map[10*i][10*j].B == 0) && (bit_map[10*i][10*j].G == 0)
				  && (bit_map[10*i][10*j].R == 0)){
				map[map_height - 1 - i][j] = '0';
			}
			if((bit_map[10*i][10*j].B == 255) && (bit_map[10*i][10*j].G == 0)
				  && (bit_map[10*i][10*j].R == 0)){
				map[map_height - 1 - i][j] = 'I';
			}
			if((bit_map[10*i][10*j].B == 0) && (bit_map[10*i][10*j].G == 255)
				  && (bit_map[10*i][10*j].R == 255)){
				map[map_height - 1 - i][j] = 'O';
			}
			if((bit_map[10*i][10*j].B == 0) && (bit_map[10*i][10*j].G == 0)
				  && (bit_map[10*i][10*j].R == 255)){
				map[map_height - 1 - i][j] = 'S';
			}
			if((bit_map[10*i][10*j].B == 0) && (bit_map[10*i][10*j].G == 255)
				  && (bit_map[10*i][10*j].R == 0)){
				map[map_height - 1 - i][j] = 'Z';
			}
			if((bit_map[10*i][10*j].B == 0) && (bit_map[10*i][10*j].G == 140)
				  && (bit_map[10*i][10*j].R == 255)){
				map[map_height - 1 - i][j] = 'L';
			}
			if((bit_map[10*i][10*j].B == 255) && (bit_map[10*i][10*j].G == 0)
				  && (bit_map[10*i][10*j].R == 255)){
				map[map_height - 1 - i][j] = 'J';
			}
			if((bit_map[10*i][10*j].B == 255) && (bit_map[10*i][10*j].G == 0)
				  && (bit_map[10*i][10*j].R == 130)){
				map[map_height - 1 - i][j] = 'T';
			}
		}
	}/*
	for(i = 0; i < map_height; i++){
		for(j = 0; j < map_width; j++){
			printf("%c ",map[i][j]);
		}
		printf("\n");
	}*/
	char **piesa = (char **) malloc((map_height + 1) * sizeof(char *));
	for(i = 0; i < map_height + 4; i++){
		piesa[i] = (char *) malloc((map_width + 1) * sizeof(char));
	}
	drop_pieces(map, piesa, map_height , map_width, Piese, nr_piese, 4);
}

void bonus(){
	
}
