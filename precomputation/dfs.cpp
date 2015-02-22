#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int vis[10];


void dfs (vector <vector <int> > v, int x)
{
	vis[x] = 1;
	cout << x << " ";
	for (int i = 0; i < v[x].size(); i++) {
		if(!vis[v[x][i]]) {
			vis[v[x][i]] = 1;
			dfs(v, v[x][i]);
		}
	}
}

int main()
{
	memset(vis, 0, sizeof(vis));
	int n;
	int x, y;
	vector <vector <int> > v(10);;
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 0; i < 5; i++) {
		if (vis[i] == 0){
			dfs(v, i);
		
			cout << endl;
		}
	}
}
