#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bmp_header.h"

typedef struct{
		unsigned char B;
		unsigned char G;
		unsigned char R;
}RGB;

typedef struct {
		char nume_piesa;
		int coloana;
		int rotatie;
}date_piesa;

void task1();
void task2();
void task3();
void task4();
void piesa(int, int, int, int, int, int, int, int, int, int, int, int, int,
					 char*);
void init_piesa(fileheader *, infoheader *, RGB **);
void print(fileheader *, infoheader *, RGB **, char *);
void basic_data(fileheader *, infoheader *);

int main(int argc, char *argv[]){
	if(strcmp(argv[1], "1") == 0){
		task1();
	}
	if(strcmp(argv[1], "2") == 0){
		task2();
	}
	if(strcmp(argv[1], "3") == 0){
		task3();
	}
	if(strcmp(argv[1], "4") == 0){
		task4();
	}
	if(strcmp(argv[1], "bonus") == 0){
		//bonus();
	}
	return 0;
}

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
	-1 - ALB
	O, I, S, Z, L, J, T - patrat din piesa (mai incolo)
	apel functie care baga piese si scrie harta
	*/
	int i, j, nr_piese, map_height, map_width;
	date_piesa *Piese = (date_piesa *) malloc(50 * sizeof(date_piesa));
	FILE *input_file = fopen("cerinta3.in","r");
	fscanf(input_file, "%d %d %d\n", &nr_piese, &map_height, &map_width);
	printf("%d %d %d\n", nr_piese, map_height, map_width);
	for(i = 0; i < nr_piese; i++){
		fscanf(input_file, "%c %d %d\n", &Piese[i].nume_piesa, &Piese[i].coloana,
					 &Piese[i].rotatie);
		printf("%c %d %d\n", Piese[i].nume_piesa, Piese[i].coloana, Piese[i].rotatie);
	}
	fclose(input_file);
	char **map = (char **) malloc(map_height * sizeof(char *));
	for (i = 0; i < map_height + 4; i++){
		map[i] = (char *) malloc(map_width * sizeof(char ));
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
	for(j = 0; j < map_width; j++){printf("%c ", map[i][j]);}printf("\n");
	}
	
}

void task4(){
	/*
	citire fisier
	apel functie care baga piese si scrie harta (ca la task 3)
	*/
}

void piesa(int height, int width,int H1i, int H1f, int W1i, int W1f,
					 int H2i, int H2f, int W2i, int W2f, int R, int G, int B, 
					 char *file_name){
	int i,j;
	fileheader *header_piesa = (fileheader *) malloc(sizeof(fileheader));
	infoheader *info_piesa = (infoheader *) malloc(sizeof(infoheader));
	info_piesa->height = height;
	info_piesa->width = width;
	RGB **rgb_piesa = (RGB **) malloc(info_piesa->height * sizeof(RGB *));
	for(i = 0; i < info_piesa->height; i++){
		rgb_piesa[i] = (RGB *) malloc(info_piesa->width * sizeof(RGB));
	}
	init_piesa(header_piesa, info_piesa, rgb_piesa);
	for(i = H1i; i < H1f; i++){
		for(j = W1i; j < W1f; j++){
			rgb_piesa[i][j].B = B;
			rgb_piesa[i][j].G = G;
			rgb_piesa[i][j].R = R;
		}
	}
	for(i = H2i; i < H2f; i++){
		for(j = W2i; j < W2f; j++){
			rgb_piesa[i][j].B = B;
			rgb_piesa[i][j].G = G;
			rgb_piesa[i][j].R = R;
		}
	}
	print(header_piesa, info_piesa, rgb_piesa, file_name);
	for(i = 0; i < info_piesa->height; i++){
		free(rgb_piesa[i]);
	}
	free(rgb_piesa);
	free(header_piesa);
	free(info_piesa);
}

void init_piesa(fileheader *header_piesa,
		 infoheader *info_piesa, RGB **rgb_piesa){
	int i,j;
	info_piesa->biSizeImage = info_piesa->height * info_piesa->width * 3;
	header_piesa->bfSize = 54 + info_piesa->biSizeImage;
  basic_data(header_piesa, info_piesa);
	for(i = 0; i < info_piesa->height; i++){
		for(j = 0; j < info_piesa->width; j++){
			rgb_piesa[i][j].B=255;
			rgb_piesa[i][j].G=255;
			rgb_piesa[i][j].R=255;
		}
	}
}

void print(fileheader *header_piesa,
		 infoheader *info_piesa, RGB **rgb_piesa,
		 char *file_name){
	int i, j, padding = 0;
	short two_bytes = 0;
	if(info_piesa->width % 4){
		padding = 1;
	}
	if(padding){
		info_piesa->biSizeImage += 2 * info_piesa->height;
		header_piesa->bfSize = 54 + info_piesa->biSizeImage;
	}
	FILE *file_pointer = fopen(file_name,"wb");
	fwrite(header_piesa, sizeof(fileheader), 1, file_pointer);
	fwrite(info_piesa, sizeof(infoheader), 1, file_pointer);
	for (i = info_piesa->height -1; i >= 0; i--){
		for(j = 0; j < info_piesa->width; j++){
			fwrite(rgb_piesa[i] + j, sizeof(RGB), 1, file_pointer);
		}
		if(padding){
			fwrite(&two_bytes, sizeof(short), 1, file_pointer);
		}
	}
	fclose(file_pointer);
}

void basic_data(fileheader *header_piesa, infoheader *info_piesa){
	header_piesa->fileMarker1 = 'B';
	header_piesa->fileMarker2 = 'M';
	header_piesa->unused1 = 0;
	header_piesa->unused2 = 0;
	header_piesa->imageDataOffset = 54;
	info_piesa->biSize = 40;
	info_piesa->planes = 1;
	info_piesa->bitPix = 24;
	info_piesa->biCompression = 0;
	info_piesa->biXPelsPerMeter = 0;
	info_piesa->biYPelsPerMeter = 0;
	info_piesa->biClrUsed = 0;
	info_piesa->biClrImportant = 0;
}
