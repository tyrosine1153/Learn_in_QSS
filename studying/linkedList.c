#include<stdio.h>
#include<stdlib.h>

typedef struct _Node {
	int n;
	struct Node* next;
}Node;

void push_front(Node* front, int data) {//5
	Node* new = malloc(sizeof(Node));//1
	new->next = front->next;//6
	front->next = new;//7
	new->n = data;//3
}

void push_back(Node* start, int data) {
	Node* rear = start;
	while (rear->next != NULL) {
		rear = rear->next;
	}
	Node* new = malloc(sizeof(Node));
	new->next = rear->next;
	rear->next = new;
	new->n = data;
}

void Node_insert(Node* start, int index, int data) {
	// index��°�� ���� �����Ͻÿ�
	// ������ index�� �ִ� ���� �ڷ� �о��, ���� ��ġ���ؼ� �� �ڸ��� ���ٰ� �����ϼ�
	Node* tmp = start;
	Node* new = malloc(sizeof(Node));

	for (int i = 0; i < index && tmp->next != NULL; i++) {
		tmp = tmp->next;
	}
	new->next = tmp->next;//6
	tmp->next = new;//7
	new->n = data;
}

void Remove(Node* target) {//8
	Node* removeNode = target->next;//9
	target->next = removeNode->next;
	free(/*Hongkong*/removeNode);
}

void Node_del(Node* start, int index) {
	Node* tmp = start;
	Node* del;

	for (int i = 0; i < index && tmp->next != NULL; i++) {
		tmp = tmp->next;
	}
	del = tmp->next;
	tmp->next = del->next;
	free(del);
}//ù��°, ������, �߰��� �ä����ִ� ���

 /*struct Node* findNode(struct Node* node, int data) {
	if (node == NULL) { return NULL; }
	struct Node* find = node->next;
	while (find != NULL) {
		if (find->n == data) { return find; }
		find = find->next;
	}
	return NULL;
}*/

void main() {
	Node* head = malloc(sizeof(Node));//1
	head->next = NULL;//4
	for (int i = 0; i < 10; i++) {
		push_back(head, i);
	}
	Node_del(head, 3);
	Node* prt = head->next;
	for (int i = 0; prt != NULL; i++) {
		printf("%d ", prt->n);
		prt = prt->next;
	}
}

/*
1. ��忡 �޸� �Ҵ�->����.
  ex) struct Node *head = malloc(sizeof(struct Node));
2. next����� ���� ����� �޸� �ּ� ����.
  ex)head->next = ��¼��;
3. n ����� ������ ����.
  ex)��¼��->n = 20;
4. ������ ����� next����� NULL����.
  ex) ��¼��->next = NULL;
5. �Ű� ������ �� ��� �տ� ������ ���� ���� ���� ����.
6. ���ο� ��� new�� next����� �տ� ������ ����� ���� next�ּ� ����.
7. �տ� ������ ����� next����� new�ּ� ����.
8. �Ű� ������ ������ ����� �� ������ �ִ� ��带 ����
9. node�ڷ��� �������� removeNode�� �Ű���������� next���(������ ����� �ճ���� �޳��, ����)�� ����Ŵ.
*/;