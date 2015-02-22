#include<bits/stdc++.h>

using namespace std;

vector <pair<int, int> > v;
vector <int> vv[100010], ans[100010];
int k = -1;
int vis[100010];

void dfs(int x, int y)
{
	k = max(k, y);
	vis[x] = 1;
	ans[y].push_back(x);
	for (int i = 0; i < vv[x].size(); i++) {
		if (!vis[vv[x][i]]) {
			dfs(vv[x][i], y + 1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n, x;
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(pair<int, int>(x, i));
	}
	
	sort(v.begin(), v.end());
	x = 0;
	for (int i = 0; i < v.size(); i++) {
		vv[v[i].first].push_back(v[i].second);
	}
	dfs(0, 0);
	for (int i = k; i >= 0; i--) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " " ;
		}
		cout << endl;
	}
	return 0;
}


