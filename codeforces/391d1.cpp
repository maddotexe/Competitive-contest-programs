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

int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	ll a[n], b[n], c[n], d[n], a1[m], b1[m], c1[m], d1[m];
	ll x, y , z;
	ll ans = -1;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> z;
		a[i] = x;
		b[i] = y;
		c[i] = x;
		d[i] = y + z;
	}
	
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		a1[i] = x;
		b1[i] = y;
		c1[i] = x + z;
		d1[i] = y;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ll x = a[i];
			ll y = b1[j];
			ll ans1 = INF;
			if (y >= b[i] && y <= d[i]){
				if (x >= a1[j] && x <= c1[j]) {
					//cout << x << " " << y << " " << i << " " << j << endl;
					
					ans1 = min(ans1, y - b[i]);
					ans1 = min(ans1, d[i] - y);
					ans1 = min(ans1, x - a1[j]);
					ans1 = min(ans1, c1[j] - x);
					ans = max(ans, ans1);
				}
			}
		}
	
	}
	
	if (ans != -1) {
		cout << ans << endl;
	} else {
		cout << 0 << endl;
	}
	return 0;
	
}

