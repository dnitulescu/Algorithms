/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *f;
const int sarray[20]={1,56,3,50,60,12,13,49,2,78,44,23,18,89,9,10,71,72,74};

void swap(int *a,int *b){	
	int x = *a;
	*a = *b;
	*b= x;
}



int partition(int s[], int l, int h)
{
int i; // counter 
int p; // pivot element index  can be improved with randomized function ( select a few values and generates a mid value ) 
int firsthigh; // divider position for pivot element 
p = h;
firsthigh = l;
	for (i=l; i<h; i++)
		if (s[i] < s[p]) {
			swap(&s[i],&s[firsthigh]);
			firsthigh ++;
		}
swap(&s[p],&s[firsthigh]);
return(firsthigh);
}



void quicksort(int s[], int l, int h)
{
int p; // index of partition 
	if ((h-l)>0) {
	p = partition(s,l,h);
	quicksort(s,l,p-1);
	quicksort(s,p+1,h);
	}
}

int main(int argc, char *argv[]) {		
	// consider the array already split	
	f = fopen("file.txt", "w");
	int array[20];
	memcpy(array ,sarray, sizeof(array));
	quicksort(array,0,20);
	
	for(int j=0;j<(sizeof(array)/sizeof(int));j++){
		printf("\n the values at  %d is %d ", j , array[j]);
	}

	fclose(f);
	return 0;
}
*/

