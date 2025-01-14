//개방주소법 구현
#include<stdio.h>
#include<stdlib.h>

#define M 13

typedef struct {
	int key;
	int probeCount;
}Bucket;

typedef struct {
	Bucket A[M];
}HashType;

void initHash(HashType* HT) {
	for (int i = 0; i < M; i++) {
		HT-> A[i].key = 0;
		HT->A[i].probeCount = 0;
	}
}

int h(int key) {
	return key % M;
}

int h2(int key) {
	return 11 - (key % 11);
}

int getNextBucketLinear(int v, int i) {
	return (v + i) % M;
}
int getNextBucketQuadratic(int v, int i) {
	return (v + i*i) % M;
}
int getNextBucketDouble(int v, int i,int key) {
	return (v + i*h2(key)) % M;
}

int isEmpty(HashType* HT, int b) {
	return HT->A[b].key == 0;
}

void insertItem(HashType* HT, int key) {
	int v = h(key);
	int i = 0;
	int count = 0;
	while (i < M) {
		count++;
		int b = getNextBucketLinear(v, i);
		if (isEmpty(HT, b)) {
			HT->A[b].key = key;
			HT->A[b].probeCount = count;
			return;
		}
		else
			i++;
	}
}


int findElement(HashType* HT, int key) {
	int v = h(key);
	int i = 0;
	
	while (i < M) {
		
		int b = getNextBucketLinear(v, i);
		if (isEmpty(HT, b)) {
			return 0;
		}
		else if (HT->A[b].key == key)
			return key;
		else
			i++;
	}
	return 0;
}
int removeElement(HashType* HT, int key) {
	int v = h(key);
	int i = 0;

	while (i < M) {

		int b = getNextBucketLinear(v, i);
		if (isEmpty(HT, b)) {
			return 0;
		}
		else if (HT->A[b].key == key) {
			HT->A[b].key = 0;
			HT->A[b].probeCount = 0;
			return key;
		}
		else
			i++;
	}
	return 0;
}

void printHashTable(HashType* HT) {
	printf("Bucket  Key Probe\n");
	printf("===================\n");

	for (int i = 0; i < M; i++) {
		printf("HT[%0.2d] : %2d   %d\n", i, HT->A[i].key, HT->A[i].probeCount);
	}
}

int main() {
	HashType HT;
	initHash(&HT);

	insertItem(&HT, 25);
	insertItem(&HT, 13);
	insertItem(&HT, 16);
	insertItem(&HT, 15);
	insertItem(&HT, 7);
	insertItem(&HT,28 );
	insertItem(&HT, 31);
	insertItem(&HT, 20);
	insertItem(&HT, 1);
	insertItem(&HT, 38);
	printHashTable(&HT);

	int key;
	printf("탐색할 키: ");
	scanf_s("%d", &key);
	if (findElement(&HT, key))
		printf("\n키 캆 %d가(이) 존재합니다.\n", key);
	else {
		printf("\n키 캆 %d가(이) 없습니다.\n", key);
	}

	printf("삭제할 키: ");
	scanf_s("%d", &key);
	if (removeElement(&HT, key))
		printf("\n키 캆 %d가(이) 삭제됩니다.\n", key);
	else {
		printf("\n키 캆 %d가(이) 없습니다.\n", key);
	}
	printf("\n");
	printHashTable(&HT);
	return 0;
}