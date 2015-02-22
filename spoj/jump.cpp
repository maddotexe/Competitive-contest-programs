#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

#define ull unsigned long long 

void mul(ull a[30][30], ull b[30][30], ull mod, ull l) {
    ull c[30][30];
	ull sum = 0;
	for (ull i = 0; i < l; i++) {
		for (ull j = 0; j < l; j++) {
			for (ull k = 0; k < l; k++) {
				sum += (a[i][k] * b[k][j]) % mod;
				sum %= mod;
			}
			c[i][j] = sum;
			sum = 0;
		}
	}
	
	for (ull i = 0; i < l; i++) {
		for (ull j = 0; j < l; j++) {
			a[i][j] = c[i][j];
		}
	}
}

void fast(ull a[30][30], ull n, ull mod, ull l) {
	if (n == 0) {
		return;
	} else if (n == 1) {
		return;
	}
	ull b[30][30];
	fast(a, n / 2, mod, l);
	
	mul(a, a, mod, l);
	
	if (n & 1) {
		memset(b, 0, sizeof(b));
		for (ull i = 0; i < l - 1; i++) {
			b[i][0] = 1;
			b[i][i + 1] = 1;
	}
	b[l - 1][0] = 1;
	mul(a, b, mod, l);
	}
}

ull cal(ull n, ull l, ull mod) {
	ull a[30][30], b[60], c[30][30];
	ull sum = 0;
	for (int i = 0; i < l; i++) {
		b[i] = i;
		sum += i;
	}	
	b[l] = sum;
	for (int i  = l + 1; i < 2 * l - 1; i++) {
		sum = 0;
		for (int j = i - 1; j >= i - l; j--) {
			sum += b[j];
		}
		b[i] = sum;
	}
	if (n < 2 * l - 1) {
		return b[n];
	}
	for (int i = 0; i < l; i++) {
		int d = i;
		for (int j = 0; j < l; j++) {
			c[i][j] = b[2 * l - d - 2];
			d++;
		}
	}
	n = n - (2 * l - 2);
	memset(a, 0, sizeof(a));
	for (int i = 0; i < l - 1; i++) {
		a[i][0] = 1;
		a[i][i + 1] = 1;
	}
	a[l - 1][0] = 1;
	
	
	fast (a, n, mod, l);
	
	mul(c, a, mod, l);
	
	return c[0][0];
}

int main() 
{
	int t;
	ull n, l, mod;
	
	scanf("%d", &t);
	
	while (t--) {
		
		scanf("%llu%llu%llu", &l, &mod, &n);
		mod = pow(10, mod);
		printf("%llu\n", cal(n, l, mod));
	}
	
	
	
	return 0;
}
	
	
