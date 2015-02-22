#include <iostream>
#include <cstdlib>
#include <algorithm>

#define MAX 20

using namespace std;

void prt_arr(int a[], int max)
{
	for (int i = 0; i < max; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void merge(int a[], int left, int mid, int right)
{
	int i;
	int j;
	int k;
	int b[MAX];

	for (i = left; i <= right; i++) {
		b[i] = a[i];
	}

	i = left;
	j = mid + 1;
	k = left;
	while ((i <= mid) && (j <= right)) {
		if (b[i] < b[j]) {
			a[k] = b[i];
			i = i + 1;
		} else {
			a[k] = b[j];
			j = j + 1;
		}
		k = k + 1;
	}

	while (i <= mid) {
		a[k] = b[i];
		i = i + 1;
		k = k + 1;
	}

	while (j <= right) {
		a[k] = b[j];
		j = j + 1;
		k = k + 1;
	}
}

void merge_sort(int a[], int left, int right)
{
	if (left >= right) {
		return;
	}

	int mid = (left + right) / 2;

	merge_sort(a, left, mid);
	merge_sort(a, mid + 1, right);

	merge(a, left, mid, right);
}

int main()
{
	int a[MAX];

	for (int i = 0; i < MAX; i++) {
		a[i] = rand() % 1000;
	}

	prt_arr(a, MAX);

	merge_sort(a, 0, MAX - 1);

	prt_arr(a, MAX);

	getchar();
	getchar();
    return 0;
	
}

