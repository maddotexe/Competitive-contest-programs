#include <iostream>
#include <cstdio>

using namespace std;


void quicksort(int a[], int l, int r) {
	
	if (l >= r) {
		return;
	}
	int i = l, k;
	int j = r;
	int piv = l;
	while (i < j) {
		while (a[i] <= a[piv] && i < r) {
			i++;
		}
		
		while (a[j] > a[piv]) {
			j--;
		}
		if (i < j) {
			k = a[j];
			a[j] = a[i];
			a[i] = k;
		}
	}	
	
	k = a[j];
	a[j] = a[piv];
	a[piv] = k;
	quicksort(a, l, j - 1);
	quicksort(a, j + 1, r);
	 
}


int main()
{
	int n;
	int a[10000];
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	quicksort(a, 0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}
