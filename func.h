#ifndef FUNC_H
#define FUNC_H

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

void piesa(int, int, int, int, int, int, int, int, int, int, int, int, int,
					 char*);

void init_piesa(fileheader *, infoheader *, RGB **);

void print(fileheader *, infoheader *, RGB **, char *);

void basic_data(fileheader *, infoheader *);

void drop_pieces(char **, char**, int, int, date_piesa *, int, int);

int drop_one_row(char **, int, int);

void elim_lines(char **, int , int );

void print_map(char **, int, int, int);

void convert_map(char **, RGB **, int, int);

void rgbwrite(RGB **, int, int, char, char, char);

#endif
