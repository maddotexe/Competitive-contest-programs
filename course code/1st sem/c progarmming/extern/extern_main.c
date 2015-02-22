#include <stdio.h>

extern int adds(int x, int y);
/* extern int subs(int x, int y); // wrong */

int main()
{
	printf("%d + %d = %d\n", 5, 7, adds(5, 7));
	/* printf("%d - %d = %d\n", 5, 7, subs(5, 7)); // wrong */

	return 0;
}

