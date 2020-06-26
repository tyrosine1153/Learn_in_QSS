#include<stdio.h>
#include<stdlib.h>

struct Node {
	int n;
	struct Node *next;
};

void add(struct Node *front, int data) {//5
	struct Node* new = malloc(sizeof(struct Node));//1
	new->next = front->next;//6
	front->next = new;//7
	new->n = data;//3
}

void Remove(struct Node* target) {//8
	struct Node* removeNode = target->next;//9
	target->next = removeNode->next;//
	free(/*Hongkong*/removeNode);
}

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

	struct Node* node1 = malloc(sizeof(struct Node));//1
	head->next = node1;//2
	node1->n = 10;//3

	struct Node* node2 = malloc(sizeof(struct Node));
	node1->next = node2;
	node2->n = 20;

	node2->next = NULL;//4

	free(head);
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
*/