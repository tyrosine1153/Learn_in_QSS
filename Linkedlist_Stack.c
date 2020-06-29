#include<stdio.h>

struct Stack {
	int n;
	struct Stack* next;
};
/*
typedef struct Stack {
	int n;
	struct Stack* next;
} stack;
*/

void push(struct Stack* head, int data) {
	struct Stack* new = malloc(sizeof(struct Stack));
	new->next = head->next;
	head->next = new;
	new->n = data;
}

void pop(struct Stack* head) {
	struct Stack* top = head->next;
	head->next = top->next;
	printf("%d", top->n);
	free(top);
}

void main() {
	struct Stack *head = malloc(sizeof(struct Stack));
	head->next = NULL;
	for (int i = 0; i < 10; i++) {
		push(head, i);
	}
	for (int i = 0; i < 10; i++) {
		pop(head, i);
	}
}