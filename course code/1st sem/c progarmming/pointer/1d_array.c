#include <stdio.h>

#define N 4

int main(int argc, char *argv[])
{
	int a[N];
	int i;

	for (i = 0; i < N; i++ ) {
		a[i] = i*i;
	}

	for (i = 0; i < N; i++ ) {
		printf("a[%d] = %d; &a[%d] = %p; ",
			i, a[i], i, (void *)&a[i]);
		printf("*(a + %d) = %d; a+%d = %p\n",
			i, *(a+i), i, (void *)(a+i));
	}

	return 0;
}

