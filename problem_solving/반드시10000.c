#pragma warning(disable:4996)
#include<stdio.h>

void main() {
	int n, i, x = 0, y = 0;

	scanf("%d", &n);
	for (i = 1; i <= n * n; i++) {
		if (x == 0 || x == n - 1 || y == 0 || y == n - 1 || x == y || x + y == n - 1) {
			printf("*");
		}
		else { printf(" "); }
		x++;
		if (i % n == 0) { printf("\n");  y++; x =0; }

	}
}
/* 별 찍기
for, while, 배열 안쓰기
*******
**   **
* * * *
*  *  *
* * * *
**   **
*******
별 자리당 x,y좌표 대입
가로/세로줄이 찍힐 조건: x=0, x=n-1 / y=0, y=n-1
우하향/우상향 대각선이 찍힐 조건: x=y / x+y = n-1
이 조건들에 하나라도 만족한다면 별찍기, 그렇지 않다면 공백
*/
