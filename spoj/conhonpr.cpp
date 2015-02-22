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

int main()
{
	int t;
	int n, m, c, d, f, x;
	
	scanf("%d", &t);
	
	while (t--) {
		fastRead(&x);
		n = x;
		fastRead(&x);
		m = x;
		int a[n + 2][m + 2];
		
		for (int i = 0; i < n + 2; i++) {
			for(int j = 0; j < m + 2; j++) {
				if(i == 0 || j == 0 || i == n + 1 || j == m + 1) {
					a[i][j] = -1;
				}
				else {
					fastRead(&x);
					a[i][j] = x;
				}
			}
		}

		d = 0;
		for (int i = 1; i < n + 1; i++) {
			for(int j = 1; j < m + 1; j++) {
				if (a[i][j] < 0) {
					continue;
				}
				c = a[i][j];
				f = d;
				if (a[i][j] == a[i - 1][j]) {
					d++;
				} else if (c == a[i - 1][j - 1]) {
					d++;
				}else if (c == a[i][j - 1]) {
					d++;
				}else if (c == a[i][j + 1]) {
					d++;
				}else if (c == a[i + 1][j + 1]) {
					d++;
				}else if (c == a[i + 1][j]) {
					d++;
				}else if (c == a[i + 1][j - 1]) {
					d++;
				}else if (c == a[i - 1][j + 1]) {
					d++;
				}
				
				if (f != d) {
					for (int k = 1; k <= n; k++) {
						for (int l = 1; l <= m; l++) {
							if (a[k][l] == c) {
								a[k][l] = -1;
							}
						}
					}
				}
			}
		}
		printf("%d\n", d);
	}
	return 0;
}
