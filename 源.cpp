#include<stdio.h>
#include<stdlib.h>
#include"test.h"
int main() {
	int n;
	int a[100];
	int maxSum;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	maxSum = Max(a, n);
	printf("%d", maxSum);
	system("pause");
	return 0;
}