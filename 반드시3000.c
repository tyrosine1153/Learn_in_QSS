#pragma warning(disable:4996)
#include<stdio.h>

void main() {
	int i, j;
	char al;

	scanf("%c", &al);
	for (i = al; i >= 'A'; i--) {
		for (j = 'A'; j < i; j++) {
			printf("%c", j);
		}
		printf("\n");
	}
}
/*
�Է¿���
D //�빮�� ���ĺ�

��¿���
ABCD
ABC
AB
A
*/
