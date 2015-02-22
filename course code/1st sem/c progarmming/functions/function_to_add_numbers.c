#include <stdio.h>

int adds(int x, int y)
{
	int z;

	z = x + y;

	x = 0;
	y = 0;

	return z;
}

int main()
{
	int i;
	int j;
	int k;

	i = 20;
	j = 30;

	printf("i = %d; j = %d; k = %d\n", i, j, k);
	k = adds(i, j);
	printf("i = %d; j = %d; k = %d\n", i, j, k);

	return 0;
}


