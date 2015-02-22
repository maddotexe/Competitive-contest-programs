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

vector <pii> v;
int val[1001][2];
int a[1001], b[1001][1001], c[1001][1001];

int main()
{
	ios_base::sync_with_stdio(false);
	int n, m, k, t;
	
	cin >> t;
	
	while (t--) {
		v.clear();
		cin >> n >> m >> k;
		
		
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			a[i]--;
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> b[i][j];
			}
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> c[i][j];
			}
		}
		
		for (int i = 0; i < n; i++) {
			val[i][0] = b[i][a[i]];
			val[i][1] = -99999999;
			for (int j = 0; j < m; j++) {
				val[i][1] = max(val[i][1], b[i][j] - c[i][j]);
			}
			//cout << val[i][1] << endl;;
			v.pb(pii(val[i][1] - val[i][0], i));
		}
		int ans = 0;
		
		sort(v.rbegin(), v.rend());
		
		for (int i = 0; i < min(n, k); i++) {
			if (v[i].first > 0) {
				ans += val[v[i].se][1];
			} else {
				ans += val[v[i].se][0];
			}
		}
		
		for (int i = min(n, k); i < n; i++) {
			ans += val[v[i].se][0];
		}
		cout << ans << endl;
	}
	return 0;
}

