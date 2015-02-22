#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;

int main()
{
	string s;
	int i, j, n, ix, iy, ox, oy, f;
	
	int m, t;
	cin >> t;
	while (t--) {
		stack <pair<int, int> > q;
		cin >> n >> m;
		int w[n][m];
		for (i = 0; i < n; i++) {
			cin >> s;
			for (j = 0; j < m; j++) {
				if (s[j] == 'b') w[i][j] = 1;
				else if (s[j] == 'w') w[i][j] = 0;
				else if (s[j] == 's') {
					ix = i;
					iy = j;
					w[i][j] = -1;
				} else if (s[j] == 'f') {
					ox = i;
					oy = j;
					w[i][j] = 1;
				} else {
					w[i][j] = 0;
				}
			}
		}
		
		pair<int, int> p(ix, iy);
		q.push(p);
		i = 1;
		while (!q.empty()) {
			if (p.first == ox && p.second == oy) break;
			
			p = q.top();
			//cout << p.first << " " << p.second <<  " " << i++ << endl;
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
			for (i = 0; i < n; i++) {
				for (j = 0; j < m; j++) {
					if (i == ix && j == iy) cout << 's';
					else if (i == ox && j == oy) cout << 'f';
					else if (w[i][j] == -1) cout << 'b';
					else cout << '-';
				}
			
				cout << endl;
			}
		} else {
			cout << "Path doesn't exist.\n";
		}
		
	}
	
	return 0;
}
