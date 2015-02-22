#include <stdio.h>

#define N 10

void adds(int x[], int *y, int *z)
{
	int i;

	for (i = 0; i < N; i++) {
		z[i] = x[i] + y[i];
	}

	return;
}

int main()
{
	int m[N];
	int n[N];
	int p[N];
	int i;

	for (i = 0; i < N; i++) {
		m[i] = i;
		n[i] = i * i;
	}

	adds(m, n, p);

	for (i = 0; i < N; i++) {
		printf("%4d + %4d = %4d\n", m[i], n[i], p[i]);
	}

	return 0;
}


