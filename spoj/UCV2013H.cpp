#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

int vis[255];
int c;
int a[255][255];
void dfs (int x, int y)
{
	if (a[x - 1][y] == 1) {
		c++;
		a[x-1][y] = 2;
		dfs(x-1, y);
	}
	if (a[x][y - 1] == 1) {
		c++;
		a[x][y-1] = 2;
		dfs(x, y-1);
	}
	if (a[x + 1][y] == 1) {
		c++;
		a[x+1][y] = 2;
		dfs(x+1, y);
	}
	
	if (a[x][y+1] == 1) {
		c++;
		a[x][y+1] = 2;
		dfs(x, y+1);
	}
}

int main()
{
	
	int n, d;
	int x, y, m;
	vector <vector <int> > v(252);;
	map <int, int>::iterator it;
	while (1) {
		cin >> n >> m;
		d = 0;
		map<int, int> m1;
		memset(vis, 0, sizeof(vis));
		if (n == 0 && m == 0) return 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 1) {
					c = 0;
					a[i][j] = 2;
					dfs(i, j);
					m1[c]++;
					d++;
				}
			}
		}
		cout << d << endl;
		for (it = m1.begin(); it != m1.end(); it++) {
			printf("%d %d\n", it->first + 1, it->second);
		}
	}
}
