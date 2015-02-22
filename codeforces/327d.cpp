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
#define ppi pair<int, pii>
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

struct node {
	char p;
	int q, r;
};

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

char s[510][510];
int n, m;
int vis[510][510];
vector <node> v;

bool check(int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= m || vis[x][y] || s[x][y] == '#') return false;
	return true;
}

void dfs(int x, int y, int c)
{
	vis[x][y] = 1;
	node res;
	res.p = 'B';
	res.q = x + 1;
	res.r = y + 1;
	v.pb(res);
	for (int i = 0; i < 4; i++) {
		if (check(x + dx[i], y + dy[i])) {
			dfs(x + dx[i], y + dy[i], c+1);
		}
	}
	
	if (c) {
		res.p = 'D';
		res.q = x + 1;
		res.r = y + 1;
		v.pb(res);
		res.p = 'R';
		res.q = x + 1;
		res.r = y + 1;
		v.pb(res);
			
	}
	
}

int main()
{
	//ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!vis[i][j] && s[i][j] == '.') {
				dfs(i, j, 0);
			}
		}
	}
	
	cout << v.size() << endl;
	
	for (int i = 0; i < v.size(); i++) {
		printf("%c %d %d\n", v[i].p, v[i].q, v[i].r);
	}
	return 0;
}


