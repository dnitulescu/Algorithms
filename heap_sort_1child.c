/* hash with only one child minimum 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int sarray[20]={1,56,3,50,60,12,13,49,2,78,44,23,18,89,9,10,71,72,74};

const int PQ_SIZE=20;
FILE *f;


typedef struct {
	int q[21];  //body of queue 
	int n;  //number of queue elements 
} priority_queue;

int pq_parent(int n)
{
	if (n == 1) return(-1);
	else return((int) n/2); // implicitly take floor(n/2) 
}

int pq_young_child(int n)
{
	return(2*n);
}

void pq_swap(priority_queue *q,int child,int parent){	
	int x = q->	q[parent];
	q->	q[parent] = q->	q[child];
	q->	q[child] = x	;
}


void bubble_up(priority_queue *q, int p)
{  		
fprintf(f,"\n \n   ");
for(int j=0;j<(sizeof(q->q)/sizeof(int));j++){
fprintf(f,"\n the values at  %d is %d ", j , q->q[j]);
}
	if (pq_parent(p) == -1) return; // at root of heap, no parent 
	if (q->q[pq_parent(p)] > q->q[p]) {
  		pq_swap(q,p,pq_parent(p));
		bubble_up(q, pq_parent(p));
		}
}


void pq_insert(priority_queue *q, int x)
{
	if (q->n >= PQ_SIZE)
		fprintf(f,"Warning: priority queue overflow insert x=%d\n",x);
	else {
		q->n = (q->n) + 1;
		q->q[ q->n ] = x;
		bubble_up(q, q->n);
		}
}


void pq_init(priority_queue *q)
{
	q->n = 0;
	for(int j=0;j<(sizeof(q->q)/sizeof(int));j++){
		q->q[j]=0;
		fprintf(f,"fuck");
	}
	
}

void make_heap(priority_queue *q, const int s[], int n)
{
	int i; // counter 
	pq_init(q);
	for (i=0; i<n; i++)
		pq_insert(q, s[i]);
}


int main(int argc, char *argv[]) {		
	// consider the array already split	
	f = fopen("file.txt", "w");
	
	priority_queue priority_q; 
	make_heap(&priority_q,sarray,20);

	for(int j=0;j<(sizeof(priority_q.q)/sizeof(int));j++){
		fprintf(f,"\n the values at  %d is %d ", j , priority_q.q[j]);
	}
	fclose(f);
	return 0;
}

*/
