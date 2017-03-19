/*#define MAX 30
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct que{
	int rear;
	int front;
	int que[MAX];
	
}q;


void init_que(struct que *q ){
	q->front=0;
	q->rear=0;	
}


void enqueue(struct que *q , int element){
	if (q->rear==MAX){
		if(q->front>0 && (q->rear)<(q->front)){
			q->rear=0;
			q->que[q->rear]=element;
			(q->rear)++;
		}else{
			printf("queue ovefload");
		}	
	}else{
		q->que[q->rear]=element;
		(q->rear)++;
	}	
}

int dequeue(struct que * q ){
	if (q->rear==q->front){
		printf("\no gueue empty!!");		
	}else{
		if(q->front==MAX){
			q->front==0;
		}
		(q->front)++;
		return q->que[q->front];
	}	
}*/

