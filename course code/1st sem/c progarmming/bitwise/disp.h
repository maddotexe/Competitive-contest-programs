#include <limits.h>

void bit_disp(int x)
{
	int y;
	int t_bits = (8 * sizeof(int)) - 1;

	for (y = t_bits; y >= 0; y-- ) {
		if ((1 << y) & x) {
			printf("1");
		} else {
			printf("0");
		}
	}
	printf(" => %d\n", x);
}

