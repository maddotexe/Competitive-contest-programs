#include <stdio.h>

static int subs(int x, int y)
{
	return (x - y);
}

int adds(int x, int y)
{
	printf("%d - %d = %d\n", x, y, subs(x, y));

	return (x + y);
}

