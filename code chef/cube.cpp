#include <iostream>
#include <cstdio>
#include <cmath>

#define eps 1e-6

using namespace std;

int a[50][50][50];

int main()
{
	string s, s1;
	int t, n, n1, n2;
	char t1[125000], t2[125000];
	double p;
	
	
	cin >> t;
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			a[i][j][0] = a[i][0][j] = a[0][i][j] = 0;
		}
	}
	while (t--) {
		cin >> n >> p;
		scanf("%s%s", t1, t2);
		s = t1;
		s1 = t2;
		n1 = n2 = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					a[i][j][k] = 0;
					if (s[n1++] == s1[n2++]) {
						a[i][j][k]++;
					}
					a[i][j][k] += a[i-1][j][k] + a[i][j-1][k] + a[i][j][k-1] + a[i-1][j-1][k-1] - a[i-1][j-1][k] - a[i-1][j][k-1] - a[i][j-1][k-1];
				} 
			}
		}
		
		int maxdim = 0;
		int count = 0;
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <=n; k++) {
					int x = i, y = j, z = k;
					
					while (x > 0 && y > 0 && z > 0) {
						int pat = a[i][j][k] - a[i][j][z-1] - a[i][y-1][k] - a[x-1][j][k] - a[x-1][y-1][z-1] + a[x-1][y-1][k] + a[x-1][j][z-1] + a[i][y-1][z-1];
						int currdim = i - x + 1;
						
						double pro = (double)pat / (double)(currdim * currdim * currdim) * 100.0;
						
						if (fabs(pro - p) < eps || pro > p) {
							if (currdim > maxdim) {
								maxdim = currdim;
								count = 1;
							} else if (currdim == maxdim) {
								count++;
							}
						}
						x--;y--;z--;
					}
				}
			}
		}
		
		if (maxdim != 0) {
			cout << maxdim << " " << count << endl;
		} else {
			cout << -1 << endl;
		}
	}
}
