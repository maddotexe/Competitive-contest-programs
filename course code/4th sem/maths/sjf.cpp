#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector <int> > proces(vector<vector<int> > v, int n, int &tt) {
	if (n == 0) {
		if (v[n][3] != 1) {
			v[n][4] = v[n][0] + v[n][2];
			tt = v[n][4];
			v[n][3] = 1;
		}
		return v;
	} else {
		tt = v[n][4] = v[n][2] + tt;
		v[n][4] = 1;
	}
}
int main()
{
	int n;
	cin >> n;
	int p, at, bt, j, t, c;
	vector<vector <int> > v;
	vector <int> v1;
	
	for (int i = 0; i < n;  i++) {
		cin >> p >> at >> bt;
		v1.resize(6);
		v1.push_back(at);
		v1.push_back(p);
		v1.push_back(bt);
		v.push_back(v1);
		v1.clear();
	}
	
	sort(v.begin(), v.end());
	int tt = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			v = proces(v, i, tt);
			cout << v[0][4];
		} else {
			j = 1;
			t = tt;
			while(v[j][0] <= t && v[j][3] == 0) {
				c = j;
				t = v[j][0];
				j++;
			}
			
			v = proces(v, c, tt);
		}
			
	}
	
	for (int i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0; 
}
	
