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
		 infoheader *info_piesa, RGB **bit_map,
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
			fwrite(bit_map[i] + j, sizeof(RGB), 1, file_pointer);
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

void drop_pieces(char **map, char **piesa, int height, int width, 
								 date_piesa *Piese, int nr_piese){
	int i, j, k, col, game_over = 0;
	for(i = 0; (i < nr_piese) && (game_over == 0); i++){
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
			default:
				break;
		}
		col = 0;
		while(!col){
			for(j = 0; j < height; j++){
				for(k = 0; k < width; k++){
					if ((piesa[j][k] != '0') && (map[j][k] != '0') && (map[j][k] != '1')){
						col = 1;
						break;
					}
				}
				if(col){
					break;
				}
			}
			if(col){
				break;
			}
			if(drop_one_row(piesa, height, width)){
				break;
			}
		}
		for(j = 0; j < height; j++){
			for(k = 0; k < width; k++){
				if(piesa[j][k] != '0'){
					if(map[j - col][k] == '1'){
					game_over = 1;
					}
					map[j - col][k] = piesa[j][k];
				}
			}
		}
	}
	for(j = 0; j < (height); j++){
		for(k = 0; k < width; k++){
			printf("%c ", map[j][k]);
		}
		printf("\n");
	}
	printf("\n");
	elim_lines(map, height, width);
	for(j = 0; j < (height); j++){
		for(k = 0; k < width; k++){
			printf("%c ", map[j][k]);
		}
		printf("\n");
	}
	print_map(map, height, width);
}

int drop_one_row(char **piesa, int h, int w){
	int i, j, last_row, first_row;
	last_row = -1;
	for(i = h - 1; i >= 0; i--){
		for(j = 0; j < w; j++){
			if(piesa[i][j] != '0'){
				if(i == (h - 1)){ //daca e deja pe ultima linie
					return 1;
				}
				last_row = i;
				break;
			}
		}
		if(last_row != -1){
			break;
		}
	}
	first_row = -1;
	for(i = 0; i < h; i++){
		for(j = 0; j < w; j++){
			if(piesa[i][j] != '0'){
				first_row = i;
				break;
			}
		}
		if(first_row != -1){
			break;
		}
	}
	for(i = last_row; i >= first_row; i--){
		for(j = 0; j < w; j++){
			piesa[i+1][j] = piesa[i][j];
		}
	}
	for(j = 0; j < w; j++){
		piesa[first_row][j] = '0';
	}
	return 0;
}

void elim_lines(char **map, int h, int w){
	int i, j, k, full_line = 1;
	for(i = 4; i < h; i++, full_line = 1){
		for(j = 0; j < w; j++){
			if(map[i][j] == '0'){
				full_line = 0;
				break;
			}
		}
		if(full_line){
			while(i > 4){
				for(k = 0; k < w; k++){
					map[i][k] = map[i-1][k];
				}
				i--;
			}
			for(k = 0; k < w; k++){
				map[i][k] = '0';
			}
		}
	}
}

void print_map(char **map, int h, int w){
	int i;
	fileheader *header_img = (fileheader *) malloc(sizeof(fileheader));
	infoheader *info_img = (infoheader *) malloc(sizeof(infoheader));
	info_img->height = 10 * h;
	info_img->width = 10 * w;
	RGB **bit_map = (RGB **) malloc(info_img->height * sizeof(RGB *));
	for(i = 0; i < info_img->height; i++){
		bit_map[i] = (RGB *) malloc(info_img->width * sizeof(RGB));
	}
	convert_map(map, bit_map, h, w);
	info_img->biSizeImage = info_img->height * info_img->width * 3;
	header_img->bfSize = 54 + info_img->biSizeImage;
  basic_data(header_img, info_img);
	print(header_img, info_img, bit_map, "task3.bmp");
	for(i = 0; i < info_img->height; i++){
		free(bit_map[i]);
	}
	free(bit_map);
	free(header_img);
	free(info_img);
}


void convert_map(char **map, RGB **bit_map, int h, int w){
	int i,j,k,l;
	for(i = 0; i < h; i++){
		for(j = 0; j < w; j++){
			for(k = 10 * i; k < 10 * (i + 1); k++){
				for(l = 10 * j; l < 10 * (j + 1); l++){
					switch(map[i][j]){
						case '1':
							bit_map[k][l].B = 255;
							bit_map[k][l].G = 255;
							bit_map[k][l].R = 255;
							break;
						case '0':
							bit_map[k][l].B = 0;
							bit_map[k][l].G = 0;
							bit_map[k][l].R = 0;
							break;
						case 'O':
							bit_map[k][l].B = 0;
							bit_map[k][l].G = 255;
							bit_map[k][l].R = 255;
							break;
						case 'I':
							bit_map[k][l].B = 255;
							bit_map[k][l].G = 0;
							bit_map[k][l].R = 0;
							break;
						case 'S':
							bit_map[k][l].B = 0;
							bit_map[k][l].G = 0;
							bit_map[k][l].R = 255;
							break;
						case 'Z':
							bit_map[k][l].B = 0;
							bit_map[k][l].G = 255;
							bit_map[k][l].R = 0;
							break;
						case 'L':
							bit_map[k][l].B = 0;
							bit_map[k][l].G = 140;
							bit_map[k][l].R = 255;
							break;
						case 'J':
							bit_map[k][l].B = 255;
							bit_map[k][l].G = 0;
							bit_map[k][l].R = 255;
							break;
						case 'T':
							bit_map[k][l].B = 255;
							bit_map[k][l].G = 0;
							bit_map[k][l].R = 130;
							break;
						default:
							break;
					}
				}
			}
		}
	}
}
