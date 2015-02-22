#include <iostream>
#include <cstdio>
#include <map>

using namespace std;
int h, w;
char a[101][101];
bool check(int x, int y)
{
    if(x < 0 || y < 0 || x > h || y >= w || a[x][y] == 'S') return false;
    return true;
}

int main()
{
	
	int t;
	int n, f;
	
	map<char, pair<int, int> > m;
	
    	m['L'] = pair<int, int>(0, -1);
   	m['R'] = pair<int, int>(0, 1);
    	m['D'] = pair<int, int>(1, 0);
    	
	cin >> t;
	char c;
	int c1 = 0;
	while (t--) {
		cin >> h >> w >> n;
		c1 = 0;
		for(int i = 0; i < w; i++) {
            		a[0][i] = 'E';
        	}
		for (int i = 1; i <= h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> a[i][j];
			}
		}
		
		int x = 0 , y = 0;
		for (int i = 0; i < n; i++) {
			cin >> c;
			if (check (x + m[c].first, y + m[c].second)) {
				x = x + m[c].first;
				y = y + m[c].second;
				
				if (a[x][y] == 'T') {
					
					c1++;
				}
				a[x][y] = 'E';
				while (a[x+1][y] == 'E' && x <= h) x++;
			}
		}
		
		cout << c1 << endl;
	}
			
	return 0;
}
