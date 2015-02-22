#include <stdio.h>
#include "disp.h"

int main()
{
	int i;
	int j;

	i = 5;
	bit_disp(i);
	j = i << 2;
	bit_disp(j);
	printf("\n");

	i = 5;
	bit_disp(i);
	j = i >> 2;
	bit_disp(j);
	printf("\n");

	i = -5;
	bit_disp(i);
	j = i >> 2;
	bit_disp(j);
	printf("\n");

	i = -5;
	bit_disp(i);
	j = i << 2;
	bit_disp(j);

	return 0;
}

