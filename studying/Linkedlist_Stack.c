#include<stdio.h>
#include<stdlib.h>

typedef struct _Stack {
	int n;
	struct Stack* next;
}Stack;
/*
typedef struct Stack {
	int n;
	struct Stack* next;
} stack;
*/

void push(Stack* head, int data) {
	Stack* new = malloc(sizeof(Stack));
	new->next = head->next;
	head->next = new;
	new->n = data;
}

void pop(Stack* head) {
	Stack* top = head->next;
	head->next = top->next;
	printf("%d", top->n);
	free(top);
}

void main() {
	Stack *head = malloc(sizeof(Stack));
	head->next = NULL;
	//Å×½ºÆ®
	for (int i = 0; i < 10; i++) {
		push(head, i);
	}
	for (int i = 0; i < 5; i++) {
		pop(head);
	}
	printf("\n");
	for (int i = 0; i < 5; i++) {
		push(head, i);
	}
	for (int i = 0; i < 10; i++) {
		pop(head);
	}
}