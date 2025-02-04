#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 100

typedef struct {
	int heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

void init(HeapType *h) {
	h->heap_size = 0;
}
void upHeap(HeapType* h) {
	int i = h->heap_size;
	int key = h->heap[i];

	//루트가 아니고 부모노드보다 삽입하려는 값이 작으면
	while ((i != 1) && (key < h->heap[i / 2])) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = key;
}

void insertItem(HeapType* h, int key) {
	h->heap_size+=1;
	h->heap[h->heap_size] = key;
	upHeap(h);
}


void printHeap(HeapType* h) {
	for (int i = 1; i <= h->heap_size; i++) {
		printf("[%d] ", h->heap[i]);
	}
	printf("\n");
}
void main() {
	HeapType heap;
	init(&heap);  
	insertItem(&heap, 5);
	insertItem(&heap, 3);
	insertItem(&heap, 7);
	insertItem(&heap, 4);
	insertItem(&heap, 1);
	insertItem(&heap, 4);
	insertItem(&heap, 8);
	insertItem(&heap, 2);
	printHeap(&heap);

}