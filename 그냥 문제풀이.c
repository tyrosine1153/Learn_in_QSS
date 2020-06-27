#pragma warning(disable:4996)
#include<stdio.h>

int main() {
	int arr[10] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
	int i, j, temp, r = 0, t = 0, a;

	for (i = 0; i < 10; i++) {
		scanf("%d", &temp);
		a = temp % 42;
		for (j = 0; j <= r; j++) {
			if (arr[j] != a) {
				t++;
			}
		}
		if (t > r) {
			arr[r] = a;
			r++;
		}
		t = 0;
	}
	printf("%d", r);
}