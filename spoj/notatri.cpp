#include <iostream>
#include <cstdio>
#include <algorithm>

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

int main()
{
	int t;
	int n, c, j, l ,r, x;
	
	scanf("%d", &n);
	
	while (1) {
		if (n == 0) return 0;
		int a[n];
		
		for (int i = 0; i < n; i++) {
			fastRead(&x);
			a[i] = x;
		}
		
		sort(a, a + n);
		c = 0;
		for (int i = n - 1; i >= 2; i--) {
			l = 0;
			r = i - 1;
			
			while (l < r) {
				if (a[l] + a[r] < a[i]) {
					c += r - l;
					l++;
				}
				else {
					r--;
				}
			}
		}
		
		
		printf("%d\n", c);
		
		scanf("%d", &n);
	}
	
	return 0;
}
