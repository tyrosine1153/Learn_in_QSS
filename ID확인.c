#include<stdio.h>
#pragma warning(disable:4996)

int main() {
	char email[100];
	int t,a=0,no=0;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%s", email);
		for (int j = 0; email[j] != NULL; j++) {//틀린 이메일을 탐색하는 for문
			if (email[j] == '@') { a++; }//@의 개수
			if ((email[j] >= 64 && email[j] <= 90) || (email[j] >= 97 && email[j] <= 122) || (email[j] >= 48 && email[j] <= 57) || email[j] == 46 || email[j] == 46) {}
			else { no++; }//조건에 맞지않는 문자의 수
		}
		if (a == 1) {
			if (no == 0) {
				printf("YES");
			}
			else { printf("NO"); }
		}
		else { printf("NO"); }
		a = 0;
		no = 0;
		printf("\n");
	}
	
}
/* 1) @의 개수가 1개인가
2) 이메일 조건에 맞지않는 문자가 있는가*/