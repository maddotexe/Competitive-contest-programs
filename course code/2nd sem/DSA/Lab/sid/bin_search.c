#include <stdio.h>

void bin_srch(int [], int, int, int);
void print(int [], int);
void quick_sort(int *, int, int);

int main()
{
	int i, n, x;

	scanf("%d", &n);
	int arr[n];

	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	print(arr, n);

	quick_sort(arr, 0, n - 1);
	print(arr, n);

	scanf("%d", &x);
	bin_srch(arr, 0,  n, x);

	return 0;
}

void bin_srch(int a[], int n1, int n2, int x) {
	if (n1 > n2) {
		printf("Not Found\n");
		return;
	}
	int m;
	m = (n1 + n2) / 2;
	if (a[m] == x) {
		printf("Found\n");
		return;
	}
	else if (a[m] > x) {
		printf("Moving to left of %d\n", a[m]);
		bin_srch(a, n1, m - 1, x);
	}
	else {
		printf("Moving to right of %d\n", a[m]);
		bin_srch(a, m + 1, n2, x);
	}
}

void print(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void quick_sort(int *a, int n1, int n2)
{
	int pivot;
	int tmp;
	int i;
	int j;

	pivot = *(a + (n1 + n2) / 2);

	i = n1;
	j = n2;

	while (*(a + i) < pivot)
		i++;
	while (*(a + j) > pivot)
		j--;

	if (i <= j) {
		tmp = *(a + i);
		*(a + i) = *(a + j);
		*(a + j) = tmp;
		i++;
		j--;
	}

	if (i <= j) {
		quick_sort(a, i, j);
	}
	
	if (n1 < j)
		quick_sort(a, n1, j);
	if (n2 > i)
		quick_sort(a, i, n2);
}
