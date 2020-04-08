#include<stdio.h>
#include<stdlib.h>
int Max(int a[], int n) {
	int maxSum = 0;
	int proSum = 0;
	for (int i = 0; i < n; i++) {
		if (proSum < 0)
			proSum = a[i];
		else
			proSum = proSum + a[i];
		if (maxSum < proSum)
			maxSum = proSum;
	}
	return maxSum;
}
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