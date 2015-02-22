#include <stdio.h>
#include "head1.h"
#include "head2.h"

int main(int argc, char *argv[])
{
	int a;
	int b;

	scanf("%d", &a);
	scanf("%d", &b);

	printf("adds(%d, %d) = %d\n", a, b, adds(a, b));
	printf("subs(%d, %d) = %d\n", a, b, subs(a, b));

	return 0;
}

