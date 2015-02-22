#include <stdio.h>

struct node1 {
	char c1;
	char c2;
	int i;
};

struct node2 {
	char c1;
	int i;
	char c2;
};

int main()
{
	/* 1 + 1 + 2p + 4 */
	printf("sizeof(struct node1) = %lu\n", sizeof(struct node1));

	/* 1 + 3p + 4 + 1 + 3p */
	printf("sizeof(struct node2) = %lu\n", sizeof(struct node2));

	return 0;
}

