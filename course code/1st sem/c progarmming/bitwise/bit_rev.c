#include <stdio.h>
#include "disp.h"

int main()
{
	int i;

	i = 0;
	bit_disp(i);

	i = ~i;
	bit_disp(i);

	i--;
	bit_disp(i);

	i = ~i;
	bit_disp(i);

	return 0;
}

