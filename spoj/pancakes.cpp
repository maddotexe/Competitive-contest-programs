#include <iostream>
#include <cstdio>
#include <vector>

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
	int t, n, c, min, d, r, i, x, g, j;
	double f;
	
	
	while (1) {
		
		fastRead(&n);
		fastRead(&r);
		//cin >> n >> r;
		if (n == 0 && r == 0) 
		      return 0;
		int a[n];
		
		for (i = 0; i < n; i++) {
			fastRead(&x);
			a[i] = x;
			//cin >> a[i];
		}
		
		min = 0;
		c = 1;
		for (i = 1; i <= r; i++) {
			g = 1000001;
			for (j = 0; j < n; j++) {
				fastRead(&x);
				//cin >> x;
				f = double(a[j]) / double(x);
				d = (int)(f * 10);
				if ((d < g)) {
					g = d;
				}
			}
			
			if (g > min) {
			      min = g;
			      c = i;
		      	}
		}
		if (g == 1000001) {
			printf("1 0\n");
		} else {
		       	printf("%d %d\n", c, min);
  			}
	}
	
	return 0;
}
