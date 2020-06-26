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
1. 노드에 메모리 할당->생성.
  ex) struct Node *head = malloc(sizeof(struct Node));
2. next멤버에 다음 노드의 메모리 주소 저장.
  ex)head->next = 어쩌구; 
3. n 멤버에 데이터 저장.
  ex)어쩌구->n = 20;
4. 마지막 노드라면 next멤버에 NULL저장. 
  ex) 어쩌구->next = NULL;
5. 매개 변수로 새 노드 앞에 연결할 노드와 넣을 값을 받음.
6. 새로운 노드 new의 next멤버에 앞에 연결할 노드의 원래 next주소 저장.
7. 앞에 연결할 노드의 next멤버에 new주소 저장.
8. 매개 변수로 삭제할 노드의 앞 순서에 있는 노드를 받음
9. node자료형 포인터인 removeNode에 매개변수노드의 next멤버(삭제할 노드의 앞노드의 뒷노드, 본인)를 가리킴.
*/