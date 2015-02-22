#include <stdio.h>

int main()
{
	char *ptr_c;

	ptr_c="Hello World";

	printf("ptr_s as string = %s\n", ptr_c);
	printf("ptr_s as pointer = %p\n", (void *) ptr_c);
	printf("&ptr_s = %p\n", (void *) &ptr_c);

	return 0;
}

