#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	int t, n, k, s, f, p;
	ios_base::sync_with_stdio(false);
	cin >> t;
	map<int, int> m;
	while (t--) {
		m.clear();
		cin >> k >> n;
		vector <pair <int, int> > v[k+2];
		int kk = 1;
		int cc = 0;
		while (k--) {
			cin >> s >> f >> p;			
			if (m[p] == 0) {
				m[p] = kk++;
			}
			v[m[p]].push_back(pair<int, int> (f, s));
		}
		
		for (int i = 1; i < kk; i++) {
			sort(v[i].begin(), v[i].end());
		}
		
		for (int i = 1; i < kk; i++) {
			int ct = 0;
			for (int j = 0; j < v[i].size(); j++) {
				if (v[i][j].second >= ct) {
					cc++;
					ct = v[i][j].first;
				}
			}
		}
		cout << cc << endl;
	}
}
