#include <stdio.h>

union node {
	char c;
	int i;
	float f;
};

int main()
{
	union node u;

	printf("sizeof(union node) = %lu\n\n", sizeof(union node));

	u.c = 'x';
	printf("u.c = %c\n", u.c);
	printf("u.i = %i\n", u.i);
	printf("u.f = %g\n\n", u.f);

	u.i = 100;
	printf("u.c = %c\n", u.c);
	printf("u.i = %i\n", u.i);
	printf("u.f = %g\n\n", u.f);

	u.f = 12.43;
	printf("u.c = %c\n", u.c);
	printf("u.i = %i\n", u.i);
	printf("u.f = %g\n", u.f);

	return 0;
}

