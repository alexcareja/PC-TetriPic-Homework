#include <stdlib.h>
#include <stdio.h>
#include "func.h"
#include "pieces.h"
#include "bmp_header.h"

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

void drop_pieces(char **map, int height, int width, 
								 date_piesa *Piese, int nr_piese){
	int i, j, k;
	char **piesa = (char **) malloc((height + 1) * sizeof(char *));
	for(i = 0; i < height; i++){
		piesa[i] = (char *) malloc((width + 1) * sizeof(char));
	}
	for(i = 0; i < nr_piese; i++){
		switch(Piese[i].nume_piesa){
			case 'O':
				gen_O(piesa, height, width, Piese[i].coloana, Piese[i].rotatie);
				break;
			case 'I':
				gen_I(piesa, height, width, Piese[i].coloana, Piese[i].rotatie);
				break;
			case 'S':
				gen_S(piesa, height, width, Piese[i].coloana, Piese[i].rotatie);
				break;
			case 'Z':
				gen_Z(piesa, height, width, Piese[i].coloana, Piese[i].rotatie);
				break;
			case 'L':
				gen_L(piesa, height, width, Piese[i].coloana, Piese[i].rotatie);
				break;
			case 'J':
				gen_J(piesa, height, width, Piese[i].coloana, Piese[i].rotatie);
				break;
			case 'T':
				gen_T(piesa, height, width, Piese[i].coloana, Piese[i].rotatie);
				break;

		}
		for(j = 0; j < height; j++){
			for(k = 0; k < width; k++){
				printf("%c ", piesa[j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	for(i = 0; i < height; i++){
		//free(piesa[i]);
	}
	//free(piesa);
}


