#include <string.h>
#include <stdio.h>
#include "txtfind.h" 
#define LINE 256
#define WORD 30


int Getline(char s[]){
	//takes a string as a argument and returns its length
	int i=strlen(s);
	return i;
}

int getword(char w[]){
	//takes a string as a argument and returns its length
	int i=strlen(w);
	return i;
}

int substring(char *str1, char*str2){
	int a=strlen(str1); //takes the str1 and returns its length
	int b=strlen(str2); //takes the str1 and returns its length
	int c=0;
	int d=0; 
	//loop until the i is equall to the length of str1
	for(int i=0;i<a;i++){
		//if the length of st2 is equal to c so we return 1 
		if(c==b){
			return 1;}
		//if str1 in index i is not null and is not at the end of the sentence (the word in \n or \t and str1 in index i is equall to str2 in index d so we increase c and d +1
		if(str1[i]!=' '&&str1[i]!='\n'&&str1[i]!='\t'&&str1[i]==str2[d]){
			c++;
			d++;}
		//else reset the c and d 	
		else{
			c=0;
			d=0; }
		}
	return 0;
}


int similar(char *s, char *t, int n){
	//the length of the s and t by using the function that we already write 
	//get word is a function that return the length of the string 
	int lenght1=getword(s);
	int lenght2=getword(t);
	int a=0;
	//if lenght of t - the length of s is smaller than 1 or the length of t is bigger that the length of s so return 0; that the two words is not the same 
	if(lenght2<lenght1-n||lenght2>lenght1)
		return 0;
	int i=0;
	int j=0;
	//while the length of s is bigger that 0 
	while(i<lenght1){
		//we check if s in index i is the same as t in index j , if it so we add 1 to j and 1 to i
		if(s[i]==t[j]){
		i++;
		j++; }
	//else we add i and add a to check from onther index 	
	else {
		i++;
		a++; }
	}
	// if a is smaller that the n and j is equall to the lenght of t so we return 1 because they already the same
	if(a<=n&&j==lenght2)
		return 1;
	//else they are not the same	
	else
		return 0;
}


void print_lines(char *str) {
	//LINE already defined
	char line[LINE];
	int i=0;
	//we use fgets to read a line from the specified stream and stores it into the string point to by str.
	//fgets gets char (line) , int (LINE) , FILE (stdin)
	//while itsn't null
	while(fgets(line,LINE,stdin)!=NULL){
		i++;
		//if the i is bigger than 3 so we have to substring by line and str
		if(i>=3) {
			//substring function already wrote 
			if(substring(line,str)==1)
				printf("%s\n",line); 
		}
	}
}

void print_similar_words(char *str){
	//LINE already defined
	char c[LINE];
	int k=0;
	//we use fgets to read a line from the specified stream and stores it into the string point to by str.
	//fgets gets char (line) , int (LINE) , FILE (stdin)
	//while itsn't null
	while(fgets(c,LINE,stdin)!=NULL){
		k++;
		int j;
		//if the i is bigger than 3
		if(k>=3){
			//loop until the length of c
			for(int i=0;i<strlen(c);i++){
				j=0;
				// if theres space between the two words
				char o[WORD]="";
				//while c in index i is not at the end of the sentence (the word in \n or \t and str1 in index i is equall to str2 in index d so we increase j and i +1
				while(c[i]!='\n'&&c[i]!='\t'&&c[i]!=' ') {
					o[j]=c[i];
					j++;
					i++;
				}
				//we here check if they are similar so we print it
				if(similar(o,str,1)==1)
					printf("%s\n",o);
			}
		}
	}
}




