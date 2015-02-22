#include <stdio.h>

int main(int argc, char *argv[])
{
	char c;
	char x;

	c = getchar();
	getchar();

	x = getchar();
	getchar();

	printf("c = %c\n", c);
	printf("x = %c\n", x);

	return 0;
}

