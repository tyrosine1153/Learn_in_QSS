#include<stdio.h>
#define SIZE 10

typedef struct Stack {
	int arr[SIZE];
	int top;
}Stack;

void init_Stack(Stack* st) {
	for (int i = 0; i < SIZE; i++) {
		st->arr[i] = 0;
	}
	st->top = -1;
}

void push(Stack* st, int n) {
	if (st->top < SIZE - 1) {
		st->arr[++(st->top)] = n;
	}
}

void pop(Stack* st) {
	if (st->top > -1) {
		printf("%d", st->arr[(st->top)--]);
	}
}

void main() {
	Stack st;
	init_Stack(&st);
	for (int i = 0; i < SIZE; i++) {
		push(&st,i);
	}
	for (int i = 0; i < SIZE; i++) {
		pop(&st);
	}

}