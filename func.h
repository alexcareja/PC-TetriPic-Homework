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

void drop_pieces(char **, int, int, date_piesa *, int);


#endif
