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
입력예시
D //대문자 알파벳

출력예시
ABCD
ABC
AB
A
*/
