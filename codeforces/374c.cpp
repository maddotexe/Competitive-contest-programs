#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <cstdlib>
#include <string>
#include <list>
#include <bitset>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <deque>
#include <climits>
#include <cassert>

using namespace std;

#define ull unsigned long long
#define ll long long
#define Max(x,y) ((x)>(y)?(x):(y))
#define Min(x,y) ((x)<(y)?(x):(y))
#define Sl(x) scanf("%lld",&x)
#define Su(x) scanf("%llu",&x)
#define S(x) scanf("%d",&x)
#define IS(x) cin>>x
#define ISF(x) getline(cin,x)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pps pair<ll,pll>
#define ppf pair<pll,ll>
#define psi pair<string,int>
#define pis pair<int,string>
#define fr first
#define se second
#define MOD 1000000007
#define MP(x,y) make_pair(x,y)
#define eps 1e-7
#define V(x) vector<x>
#define pb(x) push_back(x)
#define mem(x,i) memset(x,i,sizeof(x))
#define fori(i,s,n) for(i=(s);i<(n);i++)
#define ford(i,s,n) for(i=(n);i>=(s);--i)
#define INF 8944674407370955161LL
#define debug(i,st,arr) fori(i,0,st){cout<<arr[i]<<" ";}cout<<endl;
#define forci(i,sw) for((i)=(sw).begin();(i)!=(sw).end();(i)++)
#define forcd(i,sw) for((i)=(sw).rbegin();(i)!=(sw).rend();(i)++)

int abs(int x) {if(x < 0) return -x; return x;}

int n, m;
char a[1001][1001];
int b[1000010][2];

int vis[1001][1001], dp[1001][1001];
int ans, cycle, h;
string s;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool check(int x, int y)
{
	if (x < 0 || x >= n || y < 0 || y >= m) {
		return false;
	}
	return true;
}

int dfs(int x, int y, int pos) 
{
	if (vis[x][y] == 1) {
		cycle = 1;
		return 9999999;
	}
	if (dp[x][y] != -1) return dp[x][y];
	vis[x][y] = 1;
	int val = 0;
	for (int i = 0; i < 4; i++) {
		if (check(x + dx[i],  y + dy[i])) {
		
			if (a[x+dx[i]][y+dy[i]] == s[(pos + 1) % 4 ]) {
				if ((pos + 1) % 4 == 3) {
					val = max(val, dfs(x+dx[i], y+dy[i], pos+1) + 1);
				} else{
					val = max(val, dfs(x+dx[i], y+dy[i], pos+1));
				}
			} 
		}
	
	}
	vis[x][y] = 0;
	return dp[x][y] = val;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	s = "DIMA";
	cycle = 0, h = 0;
	memset(vis, 0, sizeof(vis));
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'D') {
				b[h][0] = i;
				b[h++][1] = j;
			}
		}
	}
	ans = 0;
	for (int i =0; i < h; i++) {
		if (!vis[b[i][0]][b[i][0]]) {
			ans = max(ans, dfs(b[i][0], b[i][1], 0));
		}
	}
	
	if (!ans) {
		cout << "Poor Dima!\n";
	} else if (cycle) {
		cout << "Poor Inna!\n";
	} else {
		cout << ans << endl;
	}
	return 0;
}

