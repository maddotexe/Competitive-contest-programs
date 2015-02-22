#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int t, n, m, x, y;
int v[110][110], r[110], vis[110];

bool dfs(int x) 
{
	vis[x] = 1;
	for (int i = 0; i < n; i++) {
		if (v[x][i] == 1 && !vis[i]) {
			vis[i] = 1;
			if (r[i] == -1 || dfs(r[i])) {
				r[x] = i;
				r[i] = x;
				return true;
			}
		} 
	}
	return false;
}

int func()
{
	for (int i = 0; i < n; i++) {
		if (r[i] == -1) {
			memset(vis, 0, sizeof(vis));
			dfs(i);
		}
	}
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (r[i] != -1) {
			c++;
		}
	}
	return c;
}

int main()
{
	cin >> t;
	while (t--) {
		memset(v, 0, sizeof(v));
		memset(r, -1, sizeof(r));
		cin >> n >> m;
		
		for (int i = 0; i < m; i++) {
			cin >> x >> y;
			v[x-1][y-1] = v[y-1][x-1] = 1;
		}
		if (func() == n) cout << "YES\n";
		else cout << "NO\n";
	}
}
