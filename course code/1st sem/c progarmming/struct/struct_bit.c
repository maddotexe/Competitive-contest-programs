#include <stdio.h>

struct node {
	int a :2;
	int b :6;
	int c :6;
	int d :24;
};

int main()
{
	struct node s;

	s.a = 0;
	s.b = 10;
	s.c = 100;	/* cannot be stored within 4 bits */
	s.d = 1000;

	printf("s.a = %d\n", s.a);
	printf("s.b = %d\n", s.b);
	printf("s.c = %d\n", s.c);
	printf("s.d = %d\n", s.d);

	return 0;
}


