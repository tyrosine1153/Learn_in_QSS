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
/* �� ���
for, while, �迭 �Ⱦ���
*******
**   **
* * * *
*  *  *
* * * *
**   **
*******
�� �ڸ��� x,y��ǥ ����
����/�������� ���� ����: x=0, x=n-1 / y=0, y=n-1
������/����� �밢���� ���� ����: x=y / x+y = n-1
�� ���ǵ鿡 �ϳ��� �����Ѵٸ� �����, �׷��� �ʴٸ� ����
*/
