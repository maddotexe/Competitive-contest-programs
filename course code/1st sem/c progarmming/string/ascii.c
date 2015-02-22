#include <stdio.h>

int main(int argc, char *argv[])
{
	int i;

	for ( i = 32; i < 127; i++ ) {
		printf("%3d - %c |", i, i);
		if ( i % 6 == 0 ) {
			printf("\n");
		}
	}

	return 0;
}

