#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	int a[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	vector <pair <int, int> > v;
	if (k == 0) {
		
		for (int j = 0; j < m; j++) {
			for (int g = j + 1; g < m; g++) {
				for (int i = 0; i < n; i++) {
					if (a[i][j] > a[i][g]) {
						v.push_back(pair<int, int>(j+1, g+1));
						break;
					}
				}
			}
		}
		
	} else {
		for (int j = 0; j < m; j++) {
			for (int g = j + 1; g < m; g++) {
				for (int i = 0; i < n; i++) {
					if (a[i][j] < a[i][g]) {
						v.push_back(pair<int, int>(g+1, j+1));
						break;
					}
				}
			}
		}
	}
	cout << v.size() << endl;
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << endl;
	}
}
