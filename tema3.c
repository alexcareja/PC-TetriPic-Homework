#include <stdlib.h>
#include <stdio.h>
#include "bmp_header.h"

typedef struct{
		unsigned char B;
		unsigned char G;
		unsigned char R;
}RGB;

void task1();
void piesa(int, int, int, int, int, int, int, int, int, int, int, int, int,
					 char*);
void init_piesa(fileheader *, infoheader *, RGB **);
void create(fileheader *, infoheader *, RGB **, char *);
void basic_data(fileheader *, infoheader *);

int main(){

	task1();
	
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

void piesa(int height, int width,int D1i, int D1f, int D2i, int D2f,
					 int D3i, int D3f, int D4i, int D4f, int R, int G, int B, 
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
	for(i = D1i; i < D1f; i++){
		for(j = D2i; j < D2f; j++){
			rgb_piesa[i][j].B = B;
			rgb_piesa[i][j].G = G;
			rgb_piesa[i][j].R = R;
		}
	}
	for(i = D3i; i < D3f; i++){
		for(j = D4i; j < D4f; j++){
			rgb_piesa[i][j].B = B;
			rgb_piesa[i][j].G = G;
			rgb_piesa[i][j].R = R;
		}
	}
	create(header_piesa, info_piesa, rgb_piesa, file_name);
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

void create(fileheader *header_piesa,
		 infoheader *info_piesa, RGB **rgb_piesa,
		 char *file_name){
	int i, j, padding = 0;
	short two_bytes = 0;
	if(info_piesa->width % 4){
		padding = 1;
	}
	if(padding){
		/* QUICK FIX*/
		info_piesa->biSizeImage += 2 * info_piesa->height;
		header_piesa->bfSize = 54 + info_piesa->biSizeImage;
		//					//
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
	free(file_pointer);
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
