#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n, k, x, sum, r, ans, w;
	
	scanf ("%d%d", &n, &k);
	sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		sum += x;
	}
	w = 99999999;
	ans = -1;
	for (int i = k; i > 1; i--) {
		r = sum % i;
		n = sum / i;
		if (r <= w && n > ans && n <= k) {
			w = r;
			ans = n;
		}
	}
	
	cout << ans << endl;
	return 0;
}
