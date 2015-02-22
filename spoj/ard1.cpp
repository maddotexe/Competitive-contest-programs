#include <iostream>
#include <cstdio>

using namespace std;

#define m 123456789
#define ull long long int 

void mul(ull a[2][2], ull b[2][2]) {
    ull c[2][2];
	ull sum = 0;
	for (ull i = 0; i < 2; i++) {
		for (ull j = 0; j < 2; j++) {
			for (ull k = 0; k < 2; k++) {
				sum += (a[i][k] * b[k][j]) % m;
				sum %= m;
			}
			c[i][j] = sum;
			sum = 0;
		}
	}
	
	for (ull i = 0; i < 2; i++) {
		for (ull j = 0; j < 2; j++) {
			a[i][j] = c[i][j];
		}
	}
}

long long int fib(long long int a[2][2], long long int n)
{
	if (n == -1) return 0;
	else if (n == 0) {
		return 1;
	} 
	else if(n == 1) {
		return a[0][0];
	} else {
	
		long long int c = fib(a, n / 2);
	
		long long int b[2][2];
	
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

void fast(ull a[2][2], ull n) 
{
	if (n == 0) return;
	else if (n == 1) return;
	
	fast(a, n / 2);
	mul(a, a);
	ull b[2][2];
	if (n & 1) {
			b[0][0] = 1;
			b[0][1] = 1;
			b[1][0] = 1;
			b[1][1] = 0;
 
			mul(a, b);
	}
	
}
		
long long int fastpower(ull a, ull n)
{
	if (n == 0) {
		return 1;
	} else if (n == 1) {
		return a;
	}
	
	long long int c = fastpower(a, n / 2);
	c = (c * c) % m;
	if (n & 1) {
		c *= a;
		c %= m;
	}
	
	return c;
}
long long int luca(long long int n)
{
	if (n == 0) {
		return 3;
	} else if (n == -2) {
		return 2;
	} else if(n == -1) {
		return 1;
	}
	ull c[2][2];
	c[0][0]  = 3;
	c[0][1] = c[1][0] = 1;
	c[2][2] = 2;
	
	ull a[2][2];
	a[0][0] = a[0][1] = a[1][0] = 1;
	a[1][1] = 0;
	fast (a, n);
	
	mul (c, a);
	
	return c[0][0];
}
	
	

int main()
{
	long long int n, a[2][2], b[2][2], n1;
	int t;
	
	scanf("%d", &t);
	while (t--) {
		scanf("%lld", &n);
		if (n == 1) {
			printf("3\n");
		} else if(n == 2) {
			printf("8\n");
		} else if(n == 3) {
			printf("12\n");
		} else if(n == 4) {
			printf("17\n");
		} else if(n == 5) {
			printf("22\n");
		} else {
			a[0][0] = a[0][1] = a[1][0] = 1;
			a[1][1] = 0;
			n1 = n - 1 - 4;
			long long int f = (2 *fib (a, n1)) % m;
			//cout << f << endl;
			n1--;
			long long int l = luca(n1);
			//cout << l << endl;
			f = (f + l - 1) % m;
		
			l = (5 * (n - 5));
			f = (22 + f + l - (n - 3)) % m;
			printf("%lld\n", f);
		}
	}
	
	return 0;
}
