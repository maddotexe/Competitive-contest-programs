#include <iostream>
#include <cstdio>
#include <cstring>

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

int a[6150][6150];
int main()
{
	int n, m, k, x, y;
	
	int t, g = 1;
	cin >> t;
	
	while (t--) {
		
		fastRead(&n);
		fastRead(&m);
		fastRead(&k);
		
		memset(a, 0, sizeof(a));
		for (int l = 0; l < k; l++) {
			fastRead(&x);
			fastRead(&y);
			
			a[x + 1][y + 1] = 999999;
			a[x + 1][y + 2]++;
			a[x + 1][y]++;
			a[x + 2][y + 1]++;
			a[x][y + 1]++;
			a[x][y]++;
			a[x + 2][y]++;
			a[x + 2][y + 2]++;
			a[x][y + 2]++;
		}
		cout << "Scenario #" << g++ << ":\n";
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < m + 1; j++) {
				if (a[i][j] >= 999999) printf("*");
				else if (a[i][j] == 0)
					printf("-");
				else 
					printf("%d", a[i][j]);
			}
			cout << endl;
		}
	}
	return 0;
}
			
