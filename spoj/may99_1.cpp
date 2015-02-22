#include <iostream>
#include <cstdio>
#include <bitset>

using namespace std;

int main()
{
	int t, i;
	unsigned long long int x, c, d, e;
	char a[60], b[5] = {'m', 'a', 'n', 'k', 'u'};;
	scanf("%d", &t);

	while (t--) {
		c = 1;
		d = 0;
		e = 0;
		scanf("%lld", &x);

		while (e < x) {
			d++;
			c *= 5;
			e += c;
		}
	
		e =  e - c;
//		cout << e << endl;
		x = x - e - 1;
		
		i = 0;
		while (x > 0) {
			a[i++] = b[x % 5];
			x /= 5;
		}

		for (int j = 0; j < d - i; j++) {
			cout << b[0];
		
		}	
		for (int j = i - 1; j >= 0; j--) {
			cout << a[j];
		}

		cout << endl;
	}

	return 0;
}

