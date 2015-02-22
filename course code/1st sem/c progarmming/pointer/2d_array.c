#include <stdio.h>

#define N 4
#define VP (void *)

int main(int argc, char *argv[])
{
	int i;
	int j;
	int a[N][N];

	for (i = 0; i < N; i++ ) {
		for (j = 0; j < N; j++ ) {
			a[i][j] = i - j;
		}
	}

	printf("a = %p;\n", VP a);
	printf("&a[0] = %p;\n", VP &a);
	printf("&a[0][0] = %p;\n", VP &a[0][0]);
	printf("\n");

	printf("a[0] = %p;\n", VP a[0]);
	printf("a[1] = %p;\n", VP a[1]);
	printf("a+0  = %p;\n", VP (a + 0));
	printf("a+1  = %p;\n", VP (a + 1));
	printf("\n");

	printf("&a[0][0] = %p;\n", VP &a[0][0]);
	printf("&a[0][1] = %p;\n", VP &a[0][1]);
	printf("&a[0][2] = %p;\n", VP &a[0][2]);
	printf("&a[0][3] = %p;\n", VP &a[0][3]);
	printf("&a[1][0] = %p;\n", VP &a[1][0]);
	printf("&a[1][1] = %p;\n", VP &a[1][1]);
	printf("\n");

	printf("a = %p;\n", VP a);

	return 0;
}

