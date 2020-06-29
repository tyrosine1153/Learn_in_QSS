#include<stdio.h>
#include<stdlib.h>

struct Node {
	int n;
	struct Node* next;
};

void push_front(struct Node* front, int data) {//5
	struct Node* new = malloc(sizeof(struct Node));//1
	new->next = front->next;//6
	front->next = new;//7
	new->n = data;//3
}

void push_back(struct Node* start, int data) {
	struct Node* rear = start;
	while (rear->next != NULL) {
		rear = rear->next;
	}
	struct Node* new = malloc(sizeof(struct Node));
	new->next = rear->next;
	rear->next = new;
	new->n = data;
}

void Node_insert(struct Node* start, int index, int data) {
	// index��°�� ���� �����Ͻÿ�
	// ������ index�� �ִ� ���� �ڷ� �о��, ���� ��ġ���ؼ� �� �ڸ��� ���ٰ� �����ϼ�
	struct Node* tmp = start;
	struct Node* new = malloc(sizeof(struct Node));

	for (int i = 0; i < index && tmp->next != NULL; i++) {
		tmp = tmp->next;
	}
	new->next = tmp->next;//6
	tmp->next = new;//7
	new->n = data;
}

void Remove(struct Node* target) {//8
	struct Node* removeNode = target->next;//9
	target->next = removeNode->next;
	free(/*Hongkong*/removeNode);
}

void Node_del(struct Node* start, int index) {
	struct Node* tmp = start;
	struct Node* del;

	for (int i = 0; i < index && tmp->next != NULL; i++) {
		tmp = tmp->next;
	}
	del = tmp->next;
	tmp->next = del->next;
	free(del);
}//ù��°, ������, �߰��� �ä����ִ� ���

struct Node* findNode(struct Node* node, int data) {
	if (node == NULL) { return NULL; }
	struct Node* find = node->next;
	while (find != NULL) {
		if (find->n == data) { return find; }
		find = find->next;
	}
	return NULL;
}

void main() {
	struct Node* head = malloc(sizeof(struct Node));//1
	head->next = NULL;//4
	for (int i = 0; i < 10; i++) {
		push_back(head, i);
	}
	Node_del(head, 3);
	struct Node* prt = head->next;
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