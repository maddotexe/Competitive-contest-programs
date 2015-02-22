#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int n, k, t, sum, p, q;
	
	cin >> t;
	
	while (t--) {
		cin >> n >> k;
		sum = p = q = 0;
		int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		sort (a, a + n);
		
		for (int i = 0; i < k; i++) {
			p += a[i];
		}
		for (int i = n - 1; i >= n - k; i--) {
			q += a[i];
		}
		if (sum - 2 * p > 0) {
			p = sum - 2 * p;
		} else {
			p = 2 * p - sum;
		}
		
		if (sum - 2 * q > 0) {
			q = sum - 2 * q;
		} else {
			q = 2 * q - sum;
		}
		if (q > p) {
			cout << q << endl;
		} else {
			cout << p << endl;
		}
	}
	
	return 0;
}
