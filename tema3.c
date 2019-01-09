#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tasks.h"


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
