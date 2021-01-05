#include <stdio.h>
#include "isort.h"
#define size 50
int scan = 0;
int main(){
 int arr[size];
 int i;   
 //we loop over until the size 
 for(i=0;i<size;i++){
 	//function reads input from the standard input stream stdin
        scanf("%d",&scan);
        //we here save the scan 
        *(arr+i) = scan;
 }
 //we first print the array before sorting it
 printf("The Array Before Sorting:\n");
 	// we loop over until the size-1
    for(i = 0 ;i <size-1;i++){
        printf("%d,", *(arr+i));
    }
    printf("%d\n",*(arr+i));
   int n = sizeof(arr)/sizeof(int);
   //here we use the insertion sort that we bulid in isort so we include it
   insertion_sort(&arr[0],n);
// we here print the array after sorting it
printf("The  Array After Sorting:\n");
   //we loop over the size of arr / size of int this
   for(i = 0 ;i < n; i++ ){
       printf("%d, ",*(arr+i));
   }
   printf("%d\n",*(arr+i));
    return 0;
}



