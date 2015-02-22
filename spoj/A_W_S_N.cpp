#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int w[101][101];
int c = 0;
int ci = 0;
int d = 0;
int a = 0, b = 0;;

void make(int n, int m, int ix, int iy, int ox, int oy, int x, int y) {
	cout << ix << " " << iy << " " << ox << " " << oy << " " << x << " " << y << endl;
	if (w[ix][iy] == 3) {
		d += abs(ix - x) + abs(iy - y);
		cout << "dd = " << d << endl;
		
	}
	
	if (ix == ox && iy == oy && c == ci) {
		w[ox][oy] = -1;
		cout << "break\n";
		return;
	}
	if (w[ix][iy] != 3 && w[ix][iy] != 2 && w[ix][iy] != -1) {
		w[ix][iy] = 0;
	} else if (w[ix][iy] == 3 || w[ix][iy] == -1){
		x = ix;
		y = iy;
		w[ix][iy] = -1;
	}
	
	if (w[ix][iy] == 2) {
		c++;
		w[ix][iy] = 0;
		d += abs(ix - x) + abs(iy - y);
		cout << "d = " << d << endl;
		x = ix;
		y = iy;
		a = ix;
		b = iy;
	}
	
	
	if (iy + 1 < m && w[ix][iy + 1] && w[ix][iy + 1] != -1) make(n, m, ix, iy + 1, ox, oy, x, y);
	if (iy - 1 > -1 && w[ix ][iy - 1] && w[ix][iy - 1] != -1) make(n, m, ix, iy - 1, ox, oy, x, y);
	if (ix + 1 < n && w[ix + 1][iy] && w[ix + 1][iy] != -1) make(n, m, ix + 1, iy, ox, oy, x, y);
	if (ix - 1 > -1 && w[ix - 1][iy] && w[ix - 1][iy] != -1) make(n, m, ix - 1, iy, ox, oy, x, y);
	
	if (w[ix][iy] == -1) {
		cout << "c = " << c << " " << "y = " << y << endl;
		cout << ix << " " << iy << " " << ox << " " << oy << " " << x << " " << y << endl;
		d += abs(ix - a) + abs(iy - b);
		a = ix;
		b = iy;
		x = ix;
		y = iy;
		cout << "df = " << d << endl;
	}
	
}
	
	
	

int main()
{
	int n, m, ix, iy, ox, oy, t;
	cin >> t;
	while (t--) 
	{
		
		c =  a = b = d = ci = 0;
		cin >> n >> m;
		char s;
		for (int i = 0; i < n; i++) {
			getchar();
			for (int j = 0; j < m; j++) {
				s = getchar();
				if (s == '.') w[i][j] = 1;
				else if (s == '#') w[i][j] = 0;
				else if (s == 'T') {
					ix = i;
					iy = j;
					w[i][j] = 3;
				} else if (s == 'W') {
					ox = i;
					oy = j;
					w[i][j] = 3;
				} else if (s == 'C') {
					w[i][j] = 2;
					ci++;
				}
			}
		}
		a = ix;
		b = iy;
		make(n, m, ix, iy, ox, oy, ix, iy);
		if(d && ci == c && w[ox][oy] == -1) {
			cout << d << endl;
		} else {
			cout << "Mission Failed!\n";
		}
	}
	
	return 0;
}
