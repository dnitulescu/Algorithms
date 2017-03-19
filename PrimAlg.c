/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Queue.c"

#define MAX 30
#define MAXINT 30
#define bool int
#define true 1
#define false 0
//typedef enum {false=0, true=1} bool;

FILE *f;
const int sarray[20]={1,56,3,50,60,12,13,49,2,78,44,23,18,89,9,10,71,72,74};

#define MAXV 1000 // maximum number of vertices 
bool processed[MAXV+1]; // which vertices have been processed 
bool discovered[MAXV+1]; // which vertices have been found 
int parent[MAXV+1]; // discovery relation 

struct que{
	int rear;
	int front;
	int que[MAX];
	
};


void init_que(struct que *q ){
	q->front=0;
	q->rear=0;	
}


void enqueue(struct que *q , int element){
	if (q->rear==MAX){
		if(q->front>0){
			q->rear=0;
			q->que[q->rear]=element;
			(q->rear)++;
		}else{
			printf("\n queue ovefload");
		}	
	}else{
		q->que[q->rear]=element;
		(q->rear)++;
	}	
}

int dequeue(struct que * q ){
	if (q->rear==q->front){
		printf("\no gueue empty!!");
		return -1;		
	}else{
		if(q->front==MAX){
			q->front==0;
		}
	int x=q->que[q->front];
	(q->front)++;
	//printf("valoarea este %d",q->que[(q->front)-1]);
	return x;
	}	
}

bool empty_queue(struct que * q){
	if (q->front==q->rear){
		return true;
	}else{
		return false;
	}
	
}


typedef struct {
	int y; // adjacency info 
	int weight; // edge weight, if any 
	struct edgenode *next; // next edge in list 
	} edgenode;
	
typedef struct {
	struct edgenode *edges[MAXV+1]; // adjacency info 
	int degree[MAXV+1]; // outdegree of each vertex 
	int nvertices; // number of vertices in graph 
	int nedges; // number of edges in graph 
	bool directed; // is the graph directed? 
	} graph;

void initialize_graph(graph *g, bool directed)
{
	int i; // counter 
	g -> nvertices = 0;
	g -> nedges = 0;
	g -> directed = directed;
	for (i=1; i<=MAXV; i++) g->degree[i] = 0;
	for (i=1; i<=MAXV; i++) g->edges[i] = NULL;
	}
	
void insert_edge(graph *g, int x, int y, int weight, bool directed)
{
	edgenode *p; // temporary pointer 
	p = malloc(sizeof(edgenode)); // allocate edgenode storage 
	p->weight = weight;
	p->y = y;
	p->next = (g->edges[x]);
	g->edges[x] = p; // insert at head of list 
	g->degree[x] ++;
	//g->nvertices++;
	if (directed == false)
		insert_edge(g,y,x,weight,true);
	else
		g->nedges ++;
}
	
void read_graph(graph *g, bool directed)
{
	int i; // counter 
	int m; // number of edges 
	int x, y; // vertices in edge (x,y) 
	initialize_graph(g, directed);
	scanf("%d %d",&(g->nvertices),&m);
	for (i=1; i<=m; i++) {
		scanf("%d %d",&x,&y);
		insert_edge(g,x,y,0,directed);
		}
	}

void print_graph(graph *g)
{
	int i; // counter 
	edgenode *p;  //temporary pointer 
	for (i=1; i<=g->nvertices; i++) {
		printf("%d: ",i);
		p = g->edges[i];
		while (p != NULL) {
			printf(" %d",p->y);
			p = p->next;
			}
		printf("\n");
		}
}

void initialize_search(graph *g)
{
	int i; // counter 
	for (i=1; i<=g->nvertices; i++) {
		processed[i] = discovered[i] = false;
		parent[i] = -1;
	}
}

process_vertex_late(int v)
{
}
process_vertex_early(graph *g,int v)
{
g->nvertices++;
printf("processed vertex %d\n",v);
}
process_edge(int x, int y)
{
printf("processed edge (%d,%d)\n",x,y);
}
	
void bfs(graph *g, int start)
{
	struct que q;  //queue of vertices to visit 
	int v; // current vertex 
	int y; // successor vertex 
	edgenode *p; // temporary pointer 
	init_que(&q);
	enqueue(&q,start);
	discovered[start] = true;	
	while (empty_queue(&q) == false) {
		v = dequeue(&q);
		process_vertex_early(g,v);
		processed[v] = true;
		p = g->edges[v];
		while (p != NULL) {
			y = p->y;
			if ((processed[y] == false) || g->directed)
				process_edge(v,y);
			if (discovered[y] == false) {
				enqueue(&q,y);
				discovered[y] = true;
				parent[y] = v;
				}
			p = p->next;
			}
		process_vertex_late(v);
	}	
}

void find_path(int start, int end, int parents[])
{
if ((start == end) || (end == -1))
printf("\n%d",start);
else {
find_path(start,parents[end],parents);
printf(" %d",end);
}
}

void prim(graph *g, int start)
{
	int i; // counter
	edgenode *p; // temporary pointer
	bool intree[MAXV+1]; // is the vertex in the tree yet? 
	int distance[MAXV+1]; // cost of adding to tree 
	int v; // current vertex to process 
	int w; // candidate next vertex 
	int weight; // edge weight 
	int dist; // best current distance from start 
	for (i=1; i<=g->nvertices; i++) {
		intree[i] = false;
		distance[i] = MAXINT;
		parent[i] = -1;
		}
	distance[start] = 0;
	v = start;
	while (intree[v] == false) {
		intree[v] = true;
		p = g->edges[v];
		while (p != NULL) {
			w = p->y;
			weight = p->weight;
			if ((distance[w] > weight) && (intree[w] == false)) {
				distance[w] = weight;
				parent[w] = v;
				}
			p = p->next;
			}
		v = 1;
		dist = MAXINT;
		for (i=1; i<=g->nvertices; i++)
			if ((intree[i] == false) && (dist > distance[i])) {
				dist = distance[i];
				v = i;
			}
		}
}
	
int main(int argc, char *argv[]) {		
	// consider the array already split	
	f = fopen("file.txt", "w");
	int array[20];
	memcpy(array ,sarray, sizeof(array));

	graph gh;
	initialize_graph(&gh, true);
	insert_edge(&gh,1,2,5,true);
	insert_edge(&gh,1,3,2,true);
	insert_edge(&gh,2,3,2,true);
	insert_edge(&gh,2,4,3,true);
	insert_edge(&gh,3,4,6,true);
	insert_edge(&gh,3,5,7,true);
	insert_edge(&gh,4,5,1,true);
	print_graph(&gh);
	bfs(&gh,1);
	find_path(1,5,parent);
	printf("\n nvertices are  %d",gh.nvertices);
	
	
	prim(&gh,1);
	
		for(int j=0;j<30;j++){
		printf("\n the values at  %d is %d ", j , parent[j]);
	}
	
	//for(int j=0;j<(sizeof(parent)/sizeof(int));j++){
	//	printf("\n the values at  %d is %d ", j , parent[j]);
	//}

	fclose(f);
	return 0;
}

*/
