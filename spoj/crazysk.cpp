#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int t;
	unsigned long long int x, n, k, h, l, g;
	
	cin >> t;
	
	while (t--) {
		scanf("%lld%lld", &x, &n);
		k = x;
		h = x;
		while (k >= n) {
			l = k / n;
			h += l;
			g = k % n;
			k = g + l;
		}
		
		printf("%lld\n", h);
	}
	
	return 0;
}
