#include<stdio.h>
#define SIZE 10

typedef struct Queue {
	int arr[SIZE];
	int front,rear;
}Queue;

void init_Stack(Queue* st) {
	for (int i = 0; i < SIZE; i++) {
		st->arr[SIZE]=0;
	}
	st->front = -1;
	st->rear = -1;
}

void inque(Queue* st, int n) {
	if (st->front<SIZE-1) {
		st->arr[++(st->front)] = n;
	}
}

void deque(Queue* st) {
	if (st->rear < st->front) {
		printf("%d", st->arr[++(st->rear)]);
	}
}

void main() {
	Queue qu;
	init_Stack(&qu);

	for (int i = 0; i < SIZE; i++) {
		inque(&qu, i);
	}
	deque(&qu);
	deque(&qu);
	deque(&qu);
	deque(&qu);
}