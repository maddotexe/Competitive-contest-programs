#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	long long int n, a[100010];
	int t;
	long long int k, l, f;
	long long int sum = 0, c, i;
	
	cin >> t;
	
	while (t--) {
		cin >> n;
		sum = 0;
		for (i = 0; i < n; i++) { 
			scanf("%lld", &a[i]);
		}
		c = i = 0;
		while (a[i] == 0) {
			c++;
			i++;
		}
		l = a[i];
		for (i; i < n; i++) {
			f = 0;
			if (a[i] == 0) {
				c++;
				continue;
			}
			if (l + a[i] == 0) {
				c++;
				f = 1;
			}
			
			if ((i + 1) < n && a[i] + a[i + 1] == 0 && f) {
				sum++;
				i++;
				l = a[i];
				continue;
			}
			
			if (a[i] + l != 0 && a[i] + a[i + 1] != 0 && (i + 1) < n) {
				if (a[i - 1] != l) {
					sum += c;
				} else {
					sum += c * (c + 1) / 2;
					c = 0;
				}
			}
			l = a[i];
		}
		
		sum += c * (c + 1) / 2;
		
		cout << sum << endl;
	}
	
	return 0;
}
