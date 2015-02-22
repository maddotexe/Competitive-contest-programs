#include <stdio.h>
#include "disp.h"

int main()
{
	int i;
	int j;
	int k;

	i = 212;
	j = 123;

	k = i | j;

	bit_disp(i);
	bit_disp(j);
	bit_disp(k);

	return 0;
}

