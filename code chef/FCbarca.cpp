#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define m 1000000007

int main()
{
	long long int t, n ,k;
	
	long long int a[11][1001];
	
	long long int tmp = 1;
	cin >> t;
	for (k = 1; k < 11; k++) {
		tmp = 1;
		a[k][1] = 0;
		for (n = 2; n < 1001; n++) {
			
			tmp = (tmp * k) % m;
			a[k][n] = (tmp - a[k][n - 1] > 0)?  (tmp - a[k][n - 1])%m  : (tmp - a[k][n - 1] % m) + m;
		}
	}
	while (t--) {
		cin >> n >> k;
		cout << a[k][n] << endl;
		
	}
	return 0;
}
