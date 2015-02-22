#include <stdio.h>

int main(int argc, char *argv[])
{
	int i;
	int *ptr;

	ptr = &i;

	i = 10;
	printf("i = %d; &i = %p; *p = %d, p = %p; &p = %p\n",
		i, (void *) &i, *ptr, (void *) ptr, (void *) &ptr);
	printf("\n");

	*ptr=20;
	printf("i = %d; &i = %p; *p = %d, p = %p; &p = %p\n",
		i, (void *) &i, *ptr, (void *) ptr, (void *) &ptr);

	return 0;
}

