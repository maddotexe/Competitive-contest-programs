#include <stdio.h>

int main()
{
	int a[2][4];
	int **p;

	a[1][2] = 4;
	p = a;

	printf("a[1][2] = %d\n", a[1][2]);

	printf("a[1][2] = %d\n", *(*(a + 1) + 2));
	printf("a[1][2] = %d\n", *(*(p + 1) + 2));

	return 0;
}

