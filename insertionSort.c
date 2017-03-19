/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int sarray[10]={1,2,3,50,60,49,13,78,56,12};	
	
int insertionSort(int argc, char *argv[]) {
	
	int array[10];
	memcpy(array ,sarray, sizeof(array));
	
	for(int j=1;j<(sizeof(array)/sizeof(int));j++){
		int key=array[j];
		int i = j-1;
		while( i>=0 & array[i]>key){
			array[i+1]=array[i];
			i=i-1;
			}
		array[i+1]=key;			
	}
	
	
	for(int j=0;j<(sizeof(array)/sizeof(int));j++){
		printf("\n the values at  %d is %d ", j , array[j]);
	}
	
	
	// this is the deacresing order
	
	for(int j=1;j<(sizeof(array)/sizeof(int));j++){
		int key=array[j];
		int i = j-1;
		while( i>=0 & array[i]<key){
			array[i+1]=array[i];
			i=i-1;
			}
		array[i+1]=key;			
	}
	
	
	for(int j=0;j<(sizeof(array)/sizeof(int));j++){
		printf("\n the values at  %d is %d ", j , array[j]);
	}
	

	return 0;
}

*/
