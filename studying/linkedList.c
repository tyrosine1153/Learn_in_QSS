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
	// index번째에 값을 삽입하시오
	// 이전에 index에 있던 값은 뒤로 밀어내고, 내가 새치기해서 그 자리로 간다고 생각하셈
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
}//첫번째, 마지막, 중간은 ㅓㅇㅄ애는 경우

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
*/;