#include <stdio.h>

char* name1()
{
	char n1[] = "Hello World";

	return n1;
}

char* name2()
{
	static char n2[] = "Hello World";

	return n2;
}

int next_val()
{
	static int x = 5;

	return (x++);
}

int main()
{
	int i;

	printf("%s\n", name1());
	printf("%s\n", name2());

	printf("\n");
	for (i = 0; i < 4; i++) {
		printf("next_val = %d\n", next_val());
	}

	return 0;
}

