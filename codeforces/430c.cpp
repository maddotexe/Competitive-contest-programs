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
#define ppl pair<ll,pll>
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

vector <int> lvl[100010], v[100010], ans;
int n;
int vis[100010], a[100010], b[100010];

void dfs(int x, int y, bool fo, bool fe)
{
	vis[x] = 1;
	
	if (a[x] != b[x]) {
	//	cout << x << endl;
		if (y & 1) {
			if (!fo) {
				fo = !fo;
				ans.pb(x);
			}
		} else {
			if (!fe) {
				fe = !fe;
				ans.pb(x);
			}
		}
	} else {
		if (y & 1) {
			if (fo) {
				fo = !fo;
				ans.pb(x);
			}
		} else {
			if (fe) {
				fe = !fe;
				ans.pb(x);
			}
		}
	}
	for (int i = 0; i < v[x].size(); i++) {
		if (!vis[v[x][i]]) {
			dfs(v[x][i], y + 1, fo, fe);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int x, y;
	
	cin >> n;
	
	
	for (int i = 0; i < n - 1; i++) {
		cin >> x >> y;
		x--, y--;
		v[x].pb(y);
		v[y].pb(x);
	}
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	
	mem(vis, 0);
	dfs(0, 0, false, false);
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] + 1 << endl;
	}
	return 0;
}


