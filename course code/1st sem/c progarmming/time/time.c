#include <stdio.h>
#include <limits.h>
#include <time.h>

int main()
{
	int i;
	clock_t strt_t;
	clock_t stop_t;

	strt_t = clock();
	for (i=0; i < INT_MAX; i++) {
	}
	stop_t = clock();

 	printf("%7.2fs elapsed\n", (float) (stop_t - strt_t) / CLOCKS_PER_SEC);

	return 0;
}

