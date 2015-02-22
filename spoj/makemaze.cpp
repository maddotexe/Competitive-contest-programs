#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

int main()
{
	char s;
	int i, j, n, ix, iy, ox, oy, f, c;
	
	int m, t;
	cin >> t;
	while (t--) {
		queue <pair<int, int> > q;
		scanf("%d%d", &n, &m);
		int w[n][m];
		c = 0;
		f = 0;
		for (i = 0; i < n; i++) {
			getchar();
			for (j = 0; j < m; j++) {
				s = getchar();
				if (s == '.') w[i][j] = 1;
				else if (s == '#') w[i][j] = 0;
				if (s == '.' && (i == n - 1 || i == 0 || j == m - 1 || j == 0)) {
					c++;
					if (f == 0) {
						ix = i; iy = j;
						f++;
					}
					if (f == 1) {
						ox = i;
						oy = j;
					}
				}
				
				
			}
		}
		if (c != 2) {
			printf("invalid\n");
			continue;
		}
		//cout << ix <<  " " << iy << " " << ox << " " << oy <<endl;
		pair<int, int> p(ix, iy);
		q.push(p);
		while (!q.empty()) {
			if (p.first == ox && p.second == oy) break;
			
			p = q.front();
			//cout << p.first << " " << p.second << endl;
			w[p.first][p.second] = -1;
			f = 0;
			if (p.first + 1 < n && w[p.first + 1][p.second] && w[p.first + 1][p.second] != -1) {f = 1;q.push(pair<int, int> (p.first + 1, p.second));}
			if (p.first - 1  >= 0 && w[p.first - 1][p.second] && w[p.first - 1][p.second] != -1) {f = 1;q.push(pair<int, int> (p.first - 1, p.second));}
			if (p.second + 1 < m && w[p.first][p.second + 1]&& w[p.first][p.second + 1] != -1)  {f = 1;q.push(pair<int, int> (p.first, p.second + 1)); }
			if (p.second - 1 >= 0 && w[p.first][p.second - 1] && w[p.first][p.second - 1] != -1)  {f = 1;q.push(pair<int, int> (p.first, p.second - 1));}
			
			if (!f) { w[p.first][p.second] = 0;
				q.pop();
			}
		}
		if (!q.empty()) {
			printf("valid\n");
		} else {
			printf("invalid\n");
		}
		
	}
	
	return 0;
}
