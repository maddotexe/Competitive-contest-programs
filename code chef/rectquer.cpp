#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
int a[310][310][11];
int main()
{
	
	
	int n, q, x, y, c, b, ans;
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k < 11; k++) {
				a[i][j][k] = 0;
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> x;
			for (int k = 1; k < 11; k++) 
				a[i][j][k] = a[i-1][j][k] + a[i][j-1][k] - a[i-1][j-1][k];
			a[i][j][x]++;
		}
	}
	cin >> q;
	
	for (int i = 0; i < q; i++) {
		ans = 0;
		cin >> x >> y >> c >> b;
		for (int i = 1; i < 11; i++) {
			if (a[c][b][i] - a[c][y - 1][i] - a[x - 1][b][i] + a[x - 1][y - 1][i]) ans++;
		}
		
		cout << ans << endl;
	}
}
