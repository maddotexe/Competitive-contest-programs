#include <iostream>
#include <cstdio>
 
#define m 1000000007
 
using namespace std;
 
long long int fast(long long int a[2][2], int n) {
	if (n == 0) return 1;
	if (n == 1) {
		return a[0][0];
	} else {
		unsigned long long int b[2][2], q, d = fast(a, n / 2);
		b[0][0] = ((a[0][0]*a[0][0]) + (a[0][1]*a[1][0])) % m ;
		b[0][1] = ((a[0][0]*a[0][1]) + (a[0][1]*a[1][1])) % m;
		b[1][0] = ((a[1][0]*a[0][0]) + (a[1][1]*a[1][0])) % m;
		b[1][1] = ((a[1][0]*a[0][1]) + (a[1][1]*a[1][1])) % m;
 
		a[0][0] = b[0][0];
		a[0][1] = b[0][1];
		a[1][0] = b[1][0];
		a[1][1] = b[1][1];
		
		if (n & 1) {
			b[0][0] = ((a[0][0]*1) + (a[0][1]*1)) % m;
			b[0][1] = ((a[0][0]*1) + (a[0][1]*0)) % m;
			b[1][0] = ((a[1][0]*1) + (a[1][1]*1)) % m;
			b[1][1] = ((a[1][0]*1) + (a[1][1]*0)) % m;
 
			a[0][0] = b[0][0];
			a[0][1] = b[0][1];
			a[1][0] = b[1][0];
			a[1][1] = b[1][1];
		}
 
		return a[0][0];
	}
}

int main()
{
	long long int t, n, m1, a[2][2];
	long long int sum = 0;
	
	scanf("%lld", &t);
	
	while (t--) {
		scanf("%lld%lld", &n, &m1);
		
		sum = 0;
		a[0][0] = a[0][1] = a[1][0] = 1;
		a[1][1] = 0;
		
		n = fast(a, n);
		a[0][0] = a[0][1] = a[1][0] = 1;
		a[1][1] = 0;
		
		m1 = fast (a, m1 + 1);
		sum = m1 - n;
		if ( sum < 0) {
			sum += m;
		}
		printf("%lld\n", sum);
	}
	
	return 0;
}
