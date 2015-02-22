#include <stdio.h>

int main()
{
	int i;
	int j;
	const int *ptr;

	i = 20;
	j = 50;

	ptr = &i;
	printf("*ptr = %d\n", *ptr);

	ptr = &j;
	printf("*ptr = %d\n", *ptr);

	return 0;
}

