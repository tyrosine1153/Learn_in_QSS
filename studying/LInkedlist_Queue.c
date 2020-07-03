#include<stdio.h>
#include<stdlib.h>

typedef struct _Queue{
	int n;
	struct Queue* next;
}Queue;

void inque(Queue* head, int data) {
	Queue* rear = head;
	while (rear->next != NULL) {
		rear = rear->next;
	}
	Queue* new = malloc(sizeof(Queue));
	new->next = rear->next;
	rear->next = new;
	new->n = data;
}

void deque(Queue* head) {
	Queue* front = head->next;//9
	head->next = front->next;
	printf("%d", front->n);
	free(front);
}

void main() {
	Queue* head = malloc(sizeof(Queue));
	head->next = NULL;
	for (int i = 0; i < 10; i++) {
		inque(head, i);
	}
	for (int i = 0; i < 5; i++) {
		deque(head);
	}
	printf("\n");
	for (int i = 0; i < 5; i++) {
		inque(head, i);
	}
	for (int i = 0; i < 10; i++) {
		deque(head);
	}
}