#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>

using namespace std;

int min1 = 999999;
int a[100][100];
string final;
int row_min[100][2];
int y;
string convert(int i) 
{
	stringstream ss;
	ss << i;
	return ss.str();
}

int esti(int vis[100], int t, int n)
{
	int est = 0;
	for (int i = 0; i < n; i++) {
		if (i != t && vis[i] != 0) {
			est += row_min[i][0] + row_min [i][1];
		}
	}
	
	return est / 2;
}


void tsp(int p, int n, int sum, int value, int vis[100], string s, int start)
{
	y++;
	if (value + esti(vis, p, n) >= min1) return;
	if (p == start && sum == n) {
		if (min1 > value) {
			min1 = value;
			final = s;
//			cout <<  s << endl << min1 << endl << endl;
		}
		return;
	}
	for (int i = 0; i < n; i++) {
		if(vis[i] != -1 || i == p) {
			continue;
		}
		vis[i] = 0;
		tsp(i, n, sum + 1, value + a[p][i], vis, s + " " + convert(i), start);
		vis[i] = -1;
	}
}

int main()
{
	int n;
	cin >> n;
	int vis[100];
	int l, h;
	for (int i = 0; i < n; i++) {
		l = 9998;
		h = 9999;
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (l > a[i][j]) {
				l = h;
				h = a[i][j];
				
			}
		}
		row_min[i][0] = l;
		row_min[i][1] = h;
	}
	for (int i = 0; i < n; i++) {
		memset(vis, -1, sizeof(vis));
		min1 = 999999;
		y = 0;
		tsp(i, n, 0, 0, vis, convert(i), i);
		cout << final << endl <<  min1 << endl << "number of times recur is called : " << y << endl;;
	}
	return 0;
}
