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
int a[50001];
bool vis[50001];
vector <int> v[50001];
ll c, ans1;
int node[50001], imp[50001];
vector<int> v1;

int dfs(int x)
{
	if (a[x] == 1) {
		c++;
		ans1++;
		imp[x] = 1;
	}
	v1.push_back(x);
	int val = 0, vv = 0;
	vis[x] = 1;
	for (int i = 0; i < v[x].size(); i++) {
		if (vis[v[x][i]] != 1) {
			int k = dfs(v[x][i]);
			if(k) val++;
			vv += k;	
		}
	}
	
	if(!imp[x]) {
		if(val >= 2) {
			imp[x] = 1;
			ans1++;
		}
	}
	node[x] = vv;
	return vv+a[x];
}

int main()
{
	ios_base::sync_with_stdio(false);
	int x, y;
	cin >> n >> m;
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++) {
		cin >> a[i];	
	}
	
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	ll ans = 0;
	ans1 = 0;
	for (int i = 1; i <= n; i++) {
		c = 0;
		v1.clear();
		if (!vis[i]) {
			dfs(i);
		}
		ans += (c * (c - 1))/2;
		if(c == 1) ans1--;
		else {
			for(int j = 0; j < v1.size(); j++) {
				if(!imp[v1[j]]) {
					if(node[v1[j]] && c-node[v1[j]] > 0) ans1++;
				}	
			}
		}
	}
	cout << ans << " " << ans1 << endl;
	return 0;
}

