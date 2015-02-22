#include <stdio.h>
#include <limits.h>

int main(int argc, char *argv[])
{
	int *ptr;
	int a1[1];
	int a2[2];
	int a3[1024];
	int a4[2000];

	printf("sizeof ptr  = %lu\n\n", sizeof(ptr));
	printf("sizeof a1[] = %lu\n", sizeof(a1));
	printf("sizeof a2[] = %lu\n", sizeof(a2));
	printf("sizeof a3[] = %lu\n", sizeof(a3));
	printf("sizeof a4[] = %lu\n", sizeof(a4));

	return 0;
}

