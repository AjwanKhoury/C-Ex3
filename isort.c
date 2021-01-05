#include <stdio.h>
#include <stdlib.h>
#include "isort.h"
#define size 50

void shift_element(int *arr, int n) {
   int i; 
   int temp = *(arr+n-1);
   //loop n-1 times and swap if the arr in index[min]>index[max];
   for (i = n-1; i > 0 ; i--) {
      *(arr+i) = *(arr+i-1);
   }    
    *arr = temp;
}

// a help function to complete insertion sort
void help(int *arr,int len){
    int j = len;
    int value = *(arr+len);
    //while the len is bigger than zero and arr+j-1 bigger than arr+j (index[min]>index[max] )
    while(j>0&& *(arr+j-1)>=value){
    //so we put the index[min] instead index[max] and reduce the value of j
        *(arr+j) = *(arr+j-1);
        j--;
    }
    *(arr+j) = value;
}

void insertion_sort(int* arr , int len){
    int i;
    //loop over the lenght
	for(i = 1; i < len ; i++)
		//we check if index[max] smaller that index[min] so we use a help function to solve this.
		if(*(arr+i) < *(arr+i-1))
		help(arr, i);
}


