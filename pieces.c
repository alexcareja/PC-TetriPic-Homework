#include <stdio.h>
#include <stdlib.h>
#include "pieces.h"

void gen_O(char **piesa, int h, int w, int col, int rot){
	int i, j;
	for(i = 0; i < h; i++){
		for(j = 0; j < w; j++){
			piesa[i][j] = '0';
		}
	}
	for(i = 0; i < 2; i++){
		for(j = col; j < (col + 2); j++){
			piesa[i][j] = 'O';
		}
	}
}

void gen_I(char **piesa, int h, int w, int col, int rot){
	int i, j;
	for(i = 0; i < h; i++){
		for(j = 0; j < w; j++){
			piesa[i][j] = '0';
		}
	}
	if (rot % 180){
		for(i = 0; i < 4; i++){
			piesa[0][col + i] = 'I';
		}
	}
	else{
		for(i = 0; i < 4; i++){
			piesa[i][col] = 'I';
		}
	}
}

void gen_S(char **piesa, int h, int w, int col, int rot){
	int i, j;
	for(i = 0; i < h; i++){
		for(j = 0; j < w; j++){
			piesa[i][j] = '0';
		}
	}
	if(rot % 180){
		piesa[0][col] = 'S';
		piesa[1][col] = 'S';
		piesa[1][col + 1] = 'S';
		piesa[2][col + 1] = 'S';
	}
	else{
		piesa[0][col + 1] = 'S';
		piesa[0][col + 2] = 'S';
		piesa[1][col] = 'S';
		piesa[1][col + 1] = 'S';
	}
}

void gen_Z(char **piesa, int h, int w, int col, int rot){
	int i, j;
	for(i = 0; i < h; i++){
		for(j = 0; j < w; j++){
			piesa[i][j] = '0';
		}
	}
	if(rot % 180){
		piesa[0][col + 1] = 'Z';
		piesa[1][col + 1] = 'Z';
		piesa[1][col] = 'Z';
		piesa[2][col] = 'Z';
	}
	else{
		piesa[0][col] = 'Z';
		piesa[0][col + 1] = 'Z';
		piesa[1][col + 1] = 'Z';
		piesa[1][col + 2] = 'Z';
	}
}

void gen_L(char **piesa, int h, int w, int col, int rot){
	int i, j;
	for(i = 0; i < h; i++){
		for(j = 0; j < w; j++){
			piesa[i][j] = '0';
		}
	}
	if(rot == 0){
		piesa[0][col] = 'L';
		piesa[1][col] = 'L';
		piesa[2][col] = 'L';
		piesa[2][col + 1] = 'L';
	}
	else{
		if(rot == 90){
			piesa[0][col] = 'L';
			piesa[1][col] = 'L';
			piesa[0][col + 1] = 'L';
			piesa[0][col + 2] = 'L';
		}
		else{
			if(rot == 180){
				piesa[0][col] = 'L';
				piesa[0][col + 1] = 'L';
				piesa[1][col + 1] = 'L';
				piesa[2][col + 1] = 'L';
			}
			else{
				piesa[0][col + 2] = 'L';
				piesa[1][col] = 'L';
				piesa[1][col + 1] = 'L';
				piesa[1][col + 2] = 'L';
				
			}
		}
	}
}

void gen_J(char **piesa, int h, int w, int col, int rot){
	int i, j;
	for(i = 0; i < h; i++){
		for(j = 0; j < w; j++){
			piesa[i][j] = '0';
		}
	}
	if(rot == 0){
		piesa[0][col + 1] = 'J';
		piesa[1][col + 1] = 'J';
		piesa[2][col + 1] = 'J';
		piesa[2][col] = 'J';
	}
	else{
		if(rot == 90){
			piesa[0][col] = 'J';
			piesa[1][col] = 'J';
			piesa[1][col + 1] = 'J';
			piesa[1][col + 2] = 'J';
		}
		else{
			if(rot == 180){
				piesa[0][col] = 'J';
				piesa[0][col + 1] = 'J';
				piesa[1][col] = 'J';
				piesa[2][col] = 'J';
			}
			else{
				piesa[0][col] = 'J';
				piesa[0][col + 1] = 'J';
				piesa[0][col + 2] = 'J';
				piesa[1][col + 2] = 'J';
				
			}
		}
	}
}

void gen_T(char **piesa, int h, int w, int col, int rot){
	int i, j;
	for(i = 0; i < h; i++){
		for(j = 0; j < w; j++){
			piesa[i][j] = '0';
		}
	}
	if(rot == 0){
		piesa[0][col] = 'T';
		piesa[0][col + 1] = 'T';
		piesa[0][col + 2] = 'T';
		piesa[1][col + 1] = 'T';
	}
	else{
		if(rot == 90){
			piesa[1][col] = 'T';
			piesa[0][col + 1] = 'T';
			piesa[1][col + 1] = 'T';
			piesa[2][col + 1] = 'T';
		}
		else{
			if(rot == 180){
				piesa[0][col + 1] = 'T';
				piesa[1][col] = 'T';
				piesa[1][col + 1] = 'T';
				piesa[1][col + 2] = 'T';
			}
			else{
				piesa[0][col] = 'T';
				piesa[1][col] = 'T';
				piesa[2][col] = 'T';
				piesa[1][col + 1] = 'T';
				
			}
		}
	}
}
