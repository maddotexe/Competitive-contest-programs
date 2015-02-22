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
#define ln length()
#define MP(x,y) make_pair(x,y)
#define eps 1e-7
#define vi(x) vector<x>
#define pb(x) push_back(x)
#define mem(x,i) memset(x,i,sizeof(x))
#define fori(i,s,n) for(i=(s);i<(n);i++)
#define ford(i,s,n) for(i=(n);i>=(s);--i)
#define debug(i,st,arr) fori(i,0,st){cout<<arr[i]<<" ";}cout<<endl;
#define forci(i,sw) for((i)=(sw).begin();(i)!=(sw).end();(i)++)
#define forcd(i,sw) for((i)=(sw).rbegin();(i)!=(sw).rend();(i)++)
#define imax numeric_limits<int>::max()
#define imin numeric_limits<int>::min()
#define lmax numeric_limits<ll>::max()
#define lmin numeric_limits<ll>::min()
#define MOD 1000000007
#define INF 8944674407370955161LL

int abs(int x) {if(x < 0) return -x; return x;}
int g;
bool adj[2010][2010];
int match[2010];
bool seen[2010];
bool bpmatch(int u)
{
	for (int i = 0; i < g; i++) {
		if(adj[u][i] && !seen[i]) {
			seen[i] = true;
			if(match[i] == -1 || bpmatch(match[i])) {
				match[i] = u;
				return true;
			}	
		}
	}
	return false;
}
int maxmatch()
{
	int ans = 0;
	memset(match, -1, sizeof(match));
	for (int i = 0; i < g; i++) {
		memset(seen, 0, sizeof(seen));
		if(bpmatch(i)) {
			ans++;
		}
	}
	return ans;
}

int main()
{
	int t, n;
	map<int, int> m;
	cin >> t;
	int a[1010];
	int b[1010];
	int z[2200];
	while (t--) {
		m.clear();
		cin >> n;
		int k = 0;
		g = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &a[i], &b[i]);
			z[k++] = a[i];
			z[k++] = b[i];
		}
		sort(z, z + k);
		
		for (int i = 0; i < k; i++) {
			int j;
			for (j = i + 1; ((j < k) && (z[i] == z[j])); j++);
			m[z[i]] = g++;
			i = j - 1;
		}
		for (int i = 0; i < g; i++) {
			for  (int j = 0; j < g; j++) {
				adj[i][j] = false;
			}
		}
		for (int i = 0; i < n; i++) {
			adj[m[a[i]]][m[b[i]]] = true;
		}
		
		cout << maxmatch() << endl;
		
	}
        return 0;
}

