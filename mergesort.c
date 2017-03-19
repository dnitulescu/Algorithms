/* 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//***************patialy works still need to make some changes ****************


// run this program using the console pauser or add your own getch, system("pause") or input loop 
const int sarray[16]={1,56,3,50,60,12,13,49,2,78,44,23,18,89,9,10};

// funtion merge array separate it by half ; only array that can be divided by 2
void merge_procedure(int *array, int start, int stop ){
 	int len = (stop-start+1)/2 ;
 	int set1[len+1];
    int set2[len+1];
 	memcpy(set1,array+start,len*sizeof(int));
    memcpy(set2,(array+start+len),len*sizeof(int));
	set1[len]=0;
    set2[len]=0;
	int i=0;
	int j=0;
	int k=0;
	for(int x=0;x<=len;x++){
		printf("\n len is %d  start is %d stop is %d",len ,start ,stop);
		printf("\n set1  %d is %d ", x , set1[x]);
		printf("\n set2  %d is %d ", x , set2[x]);
	}
    for(k=0; k<(stop-start); k++){
		if(set1[i]<=set2[j] && set2[j]!=0 && set1[i]!=0){
			array[k+start]=set1[i];
			i=i+1;
		}else{
			array[k+start]=set2[j];
			j=j+1;
		}		
	}
	if(i<j){
		array[k+start]=set1[i];
	}else{
		array[k+start]=set2[j];
	}
 }	
int main(int argc, char *argv[]) {		
	// consider the array already split
	int array[10];
	memcpy(array ,sarray, sizeof(array));
	int array_lenght=sizeof(array)/sizeof(int);
	for(int nr= 2 ; nr<= array_lenght ; nr=nr*2 ){
	   for(int seq=0 ; seq <= array_lenght/nr ; seq++ ){	  
	    	printf("\n the values of nr is %d the value of seq is %d ", nr , seq );
			merge_procedure(array,seq*nr, seq*nr+nr-1);
			for(int j=0;j<(sizeof(array)/sizeof(int));j++){
			printf("\n the values of array  at  %d is %d ", j , array[j]);
			}
	   }
	}

	return 0;
}

*/
