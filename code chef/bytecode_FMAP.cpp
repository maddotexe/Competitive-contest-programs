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

vector <int> v[10001];
int a[10001];
int n;
void dfs(int pos, int vis[]) {
	if (vis[pos] != 1) {
		vis[pos] = 1;
		for (int i = 0; i < v[pos].size(); i++) {
			if (!vis[v[pos][i]]) {
				a[v[pos][i]] = pos;
				//vis[v[pos][i]] = 1;
				//cout << v[pos][i] << endl;
				dfs(v[pos][i], vis);
			}
		}
	}
}
int main()
{
	
	int t, c, d, x;
	cin >> t;
	
	while (t--) {
		cin >> n >> c >> d;
		int vis[n];
		
		c--; d--;
		for (int i = 0; i < n; i++) {
			v[i].clear();
			vis[i] = 0;
			a[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			if (i != c) {
				cin >> x;
				x--;
				v[x].push_back(i);
				v[i].push_back(x);
			}
		}
		
		dfs(d, vis);
		
		for (int i = 0; i < n; i++) if(i != d) cout << a[i] + 1 << " ";
		cout << endl;
	}
        return 0;
}

