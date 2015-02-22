#include <stdio.h>

int main(int argc, char *argv[])
{
	float f;
	int i;

	f = 2E7; // This does not work
	f = 1.5E7; // This works

	i = 0;
	while ( f > 0 ) {
		f--;
		if (i % 100000 == 0) {
			printf("i = %d; f = %f\n", i, f);
		}
		i++;
	}

	return 0;
}

