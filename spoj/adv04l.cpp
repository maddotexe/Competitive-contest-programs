#include <iostream>
#include <cstdio>

using namespace std;
long long int a[80];

void pre()
{
	a[0] = 0;
	a[1] = 1;
	
	for (int i = 2; i < 80; i++) {
		a[i] = a[i - 1] + a[i - 2];
	}
}

int main() {
	
	int n;
	
	int t, i;
	pre();
	scanf("%d", &t);
	
	while (t--) {
		scanf("%d", &n);
		long long int c = 0;
		for (i = 77 ; a[i] > n; i--);
		
		while (n != 0) {
			if (a[i] <= n) {
				n -= a[i];
				c += a[i + 1];
			}
			i--;
		}
		printf("%lld\n", c);
		
	}
	return 0;
}
	
