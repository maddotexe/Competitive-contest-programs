#include <stdio.h>

int main()
{
	unsigned long long int a, b, c, i, n;

	scanf("%lld", &n);

	a = 1;
	b = 1;
	c = 1;

	for (i = 1; i < n; i++) {
		a = a + b;
		b = a + c;
		c = a;
	}

	printf("%lld\n", a + b + c);
	return 0;
}