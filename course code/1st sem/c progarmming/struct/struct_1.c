#include <stdio.h>

struct node {
	char c;
	int i;
	float f;
};

int main()
{
	struct node s;

	printf("sizeof(struct node) = %lu\n\n", sizeof(struct node));

	s.c = 'x';
	s.i = 100;
	s.f = 12.43;

	printf("s.c = %c\n", s.c);
	printf("s.i = %i\n", s.i);
	printf("s.f = %g\n", s.f);

	return 0;
}

