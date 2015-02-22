#include <iostream>
#include <cstdio>

using namespace std;

long long a[1000010];
long long n;
void update(long long  x, long long val) {
	while (x <= n) {
		a[x] += val;
		x += (x & - x);
	}
}

long long get(long long x) {
	long long sum = 0;
	
	while (x > 0) {
		sum += a[x];
		x -= (x & -x);
	} 
	return sum;
}

int main()
{
	long long q, val, x;
	
	cin >> n >> q;
	char c;
	for (int i = 0; i < n; i++) {
		cin >> x;
		update (i+1, x);
	}
	
	for (int i = 0; i < q; i++) {
		cin >> c >> x >> val;
		
		if (c == 'S') {
			cout << get(val + 1) - get(x) << endl;
		} else if (c == 'G') {
			update(x + 1, val);
		} else {
			update(x + 1, -val);
		}
	}
}
