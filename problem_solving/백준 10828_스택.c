#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

int stack[10000] = { 0 };
int top = -1;

void fpush(int data) {
    stack[++top] = data;
}

void fpop() {
    if (top > -1) {
        printf("%d\n", stack[top--]);
    }
    else { printf("-1\n"); }
}

void fsize() {
    printf("%d\n", top + 1);
}

void fempty() {
    if (top > -1) { printf("0\n"); }
    else { printf("1\n"); }
}

void ftop() {
    if (top > -1) {
        printf("%d\n",stack[top]);
    }
    else { printf("-1\n"); }
}

int main() {
    int n, pushData;
    char input[10];

    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%s", input);
        if (strcmp("push", input) == 0) {
            scanf("%d",&pushData);
            fpush(pushData);
        }
        else if (strcmp("pop", input) == 0) { fpop(); }
        else if (strcmp("size", input) == 0) { fsize(); }
        else if (strcmp("empty", input) == 0) { fempty(); }
        else if (strcmp("top", input) == 0) { ftop(); }
    }
    return 0;
}