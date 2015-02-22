#include <stdio.h>

struct node {
	int size;
	int arr[10];
};

void get_struct(struct node x)
{
	int i;

	printf("address of x.arr is  %p\n", (void *) x.arr);
	for (i = 0; i < x.size; i++) {
		printf("x.arr[%d] = %d\n", i, x.arr[i]);
		x.arr[i] = 0;
	}
	printf("\n");

	return;
}

int main()
{
	int i;
	struct node s;

	s.size = 4;
	s.arr[0] = 12;
	s.arr[1] = 23;
	s.arr[2] = 35;
	s.arr[3] = 43;

	get_struct(s);

	printf("address of s.arr is  %p\n", (void *) s.arr);
	for (i = 0; i < s.size; i++) {
		printf("s.arr[%d] = %d\n", i, s.arr[i]);
	}

	return 0;
}

