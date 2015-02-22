#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[2001][2001];
char s[2001][2001];

int main()
{
	int n, m, k;
	
	cin >> n >> m >> k;
	memset (a, 0, sizeof(a));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> s[i][j];
			
			
			if (j < k) {
				if (s[i][j] == 'X') {
					a[i][j] = a[i][j-1] + 1;
				} else {
					a[i][j] = a[i][j-1];
				}
			} else {
				if (s[i][j] == 'X') {
					if (s[i][j-k] == 'X') {
						a[i][j] = a[i][j-1];
					} else {
						a[i][j] = a[i][j-1] + 1;
					}
				} else {
					if (s[i][j-k] == 'X') {
						a[i][j] = a[i][j-1] - 1;
					} else {
						a[i][j] = a[i][j-1];
					}
				}
			}
		}
	}
	
	int sum = 0, cur = 0;
	int c = 0;
	for (int j = k - 1; j < m; j++) {
		cur = 0;
		for (int i = 0; i < n; i++) {
			if (i < k) {
				cur += a[i][j];
			} else {
				sum += cur;
				cur += a[i][j] - a[i - k][j];
			}
		}
		sum += cur;
	}
	double ans = (double)sum / ((double)(n - k + 1) * (double)(m - k + 1));
	
	printf("%.6f\n", ans);
	return 0;
}
	
