#include <stdio.h>
#include "disp.h"

int main()
{
	int i;
	
	bit_disp(INT_MIN);
	for (i = -4; i < 5; i++) {
		bit_disp(i);
	}
	bit_disp(INT_MAX);

	return 0;
}

