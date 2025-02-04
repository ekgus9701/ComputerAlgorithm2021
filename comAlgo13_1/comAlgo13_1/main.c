//그래프 구현
#include<stdio.h>
#include<stdlib.h>

#define N 10
typedef struct Vertex {
	int no; //정점번호
	int weight; //가중치값
	struct Vertex* next; //인접정점
}Vertex;

typedef struct {
	int vCount;
	Vertex* v[N];
}Graph;

void init(Graph* G) {
	G->vCount = 0;
	for (int i = 0; i < N; i++)
		G->v[i] = NULL;
}

void makeVertex(Graph* G) {
	G->vCount++;
}

void insertEdge(Graph* G, int w, int v1, int v2) {
	Vertex* p = (Vertex*)malloc(sizeof(Vertex));
	p->weight = w;
	p->no = v1 + 1;
	p->next = G->v[v2];
	G->v[v2] = p;

	Vertex* q = (Vertex*)malloc(sizeof(Vertex));
	q->weight = w;
	q->no = v2 + 1;
	q->next = G->v[v1];
	G->v[v1] = q;
}

void print(Graph* G) {
	for (int i = 0; i < G->vCount; i++) {
		Vertex* v = G->v[i];
		printf("V[%d]: ", i + 1);
		while (v != NULL) {
			printf("[%d (%d)] ", v->no, v->weight);
			v = v->next;
		}
		printf("\n");
	}
}

void process(Graph* G, int num) {
	Vertex* p = G->v[num];
	while (p != NULL) {
		printf("[%d (%d)] ", p->no, p->weight);
		p = p->next;
	}
	printf("\n");
}

void process2(Graph* G, int v1, int v2, int w) {
	Vertex* p = G->v[v1];
	while (p != NULL) {
		if (p->no == v2) {
			p->weight = w;
			return;
		}
		else
			p = p->next;
	}
}
int main() {
	Graph G;
	init(&G);
	for (int i = 0; i < 6; i++)
		makeVertex(&G);

	insertEdge(&G,1,0,1 );//(그래프,가중치,정점,정점) -> 정점 1,2가 가중치 1을 가짐
	insertEdge(&G,1,0,2 );//-> 정점 1,3이 가중치 1을 가짐
	insertEdge(&G, 1,0,3);
	insertEdge(&G, 2,0,5);
	insertEdge(&G, 1,1,2);
	insertEdge(&G, 4,2,4);
	insertEdge(&G, 3,4,5);
	print(&G);


}