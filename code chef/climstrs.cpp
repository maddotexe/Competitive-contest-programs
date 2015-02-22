#include <iostream>
#include <cstdio>

#define m 1000000007

using namespace std;

long long int fast(long long int a[2][2], int n) {
	if (n == 0) return 1;
	if (n == 1) {
		return a[0][0];
	} else {
		long long int b[2][2], q, d = fast(a, n / 2);
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

inline void fastRead(int *a)
{
  register char c=0;
  while (c<33) c=getchar_unlocked();
  *a=0;
  while (c>33)
    {
      *a=*a*10+c-'0';
      c=getchar_unlocked();
    }
}

int main()
{
	int n;
	int k;
	int t, c;
	long long int x, a[2][2] = {1, 1, 1, 0};
	scanf("%d", &t);
	
	while (t--) {
		fastRead(&n);
		fastRead(&k);
		
		a[0][0] = a[0][1] = a[1][0] = 1;
		a[1][1] = 0;
		x = fast(a, n);
		c = 0;
		while (x != 0) {
			if (x & 1) {
				c++;
			}
			x = x >> 1;
		}
		if (c == k) {
			printf("CORRECT\n");
		} else {
			printf("INCORRECT\n");
		}
		
	}
	
	return 0;
}
