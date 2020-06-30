#include<stdio.h>
#include<stdlib.h>

struct Queue{
	int n;
	struct Queue* next;
};

void inque(struct Queue* head, int data) {
	struct Queue* rear = head;
	while (rear->next != NULL) {
		rear = rear->next;
	}
	struct Queue* new = malloc(sizeof(struct Queue));
	new->next = rear->next;
	rear->next = new;
	new->n = data;
}

void deque(struct Queue* head) {
	struct Queue* front = head->next;//9
	head->next = front->next;
	printf("%d", front->n);
	free(front);
}

void main() {
	struct Queue* head = malloc(sizeof(struct Queue));
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