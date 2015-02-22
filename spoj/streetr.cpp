#include <iostream>
#include <cstdio>

using namespace std;

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

int gcd(int a, int b) 
{
	if (b % a == 0) 
		return a;
	return gcd(b % a, a);
}

int main()
{
	int n, x;
	
	scanf("%d", &n);
	
	int a[n], b[n], c[n];
	
	for (int i = 0; i < n; i++) {
		fastRead(&x);
		if (i == 0) {
			a[i] = x;
		} else {
			a[i] = x;
			c[i - 1] = x - a[i - 1];
			b[i] = c[i - 1];
			
		}
		if (i >= 2) {
			b[i] = gcd(b[i - 1], c[i - 1]);
		}
	}
	
	cout << (a[n - 1] - a[0])/b[n-1] - n + 1;
	
	return 0;
}
		
