#include <iostream>
#include <cstdio>

using namespace std;

#define m 1000000007

long long int fast(long long int x, long long int n) {
	if (n == 1) {
		return 3;
	} else if (n == 0) {
		return 1;
	} else {
		x = fast(x, n / 2);
		x = ((x) * (x)) % m;
		if (n & 1) {
			x = (x * 3) % m;
		}
		
		return x;
	}
}
		

int main()
{
	long long int n, t, x;
	
	cin >> t;
	while (t--) {
		cin >> n;
		
		if (n == 1) {
			cout << 1 << endl;
			continue;
		}
		if (n % 3 == 0) {
			x = fast(3, n / 3);
		} else if (n % 3 == 1) {
			x = (4 * fast(3, (n - 4) / 3)) % m;
		} else {
			x = (2 * fast(3, (n - 2) / 3)) % m;
		}
		
		cout << x << endl;
		
	}
	return 0;
}
