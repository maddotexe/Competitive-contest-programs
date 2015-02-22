#include <iostream>
#include <cstdio>
#include <vector>


using namespace std;

vector <int> a[100001];
int b[100001];
vector <int> v(100001);
int curmin;

void dfs(int p) {
	v[p] = 1;
	if (curmin > b[p] && b[p] >= 0) {
		curmin = b[p];
	}
	for (int i = 0; i < a[p].size(); i++) {
		if (!v[a[p][i]]) {
			dfs(a[p][i]);
		}
	}
}

int main()
{
	int n, m, x, y;
	
	cin >> n >> m;
	
	
	
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		x--;
		y--;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	int val = 0;
	int f = 0;
	int allbst = 999999999;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		curmin = 999999999;
		if (v[i]) continue;
		val++;
		dfs(i);
		if (curmin == 999999999) {
			f = 1;
		} else {
			if (allbst > curmin) {
				allbst = curmin;
			}
			sum += curmin;
		}
		
	}
	
	
	if (val == 1) {
		cout << "0\n";
	} else if (f == 1) {
		cout << -1 << endl;
	} else {
		cout << allbst * (val - 2) + sum << endl;
	}
	return 0;
}
