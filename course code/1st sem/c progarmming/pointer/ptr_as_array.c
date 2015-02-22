#include <stdio.h>

#define N 10

int main()
{
	int a[N];
	int *pi;
	int i;

	for (i = 0; i < N; i++) {
		a[i] = i * i;
	}

	pi = a;

	for (i = 0; i < N; i++) {
		printf("pi[%d] = %3d\n", i, pi[i]);
	}

	return 0;
}

