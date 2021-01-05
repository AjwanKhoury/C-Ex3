#define LINE 256
#define WORD 30
#include <string.h>
#include <stdio.h>
#include "txtfind.h"

int main( int argc , char **argv){
	char c[WORD]="";
	char o[WORD]="";char d[WORD]="";
	for(int i=0;i<2;i++){
		fscanf(stdin,"%s",c);
		if(i==0)
			strcpy(o,c);
		if(i==1)
			strcpy(d,c);
	}
	if(d[0]=='a'){
		print_lines(o);
	}
	else
		print_similar_words(o);
return 0;
}

