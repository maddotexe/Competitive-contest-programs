#include <stdio.h>

extern adds(int x, int y);

int main(int argc, char *argv[])
{
	printf("adds(%d, %d) = %d\n", 10, 20, adds(10, 20));

	return 0;
}

