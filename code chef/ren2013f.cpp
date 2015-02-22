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
	ll a, b, c, sa, sb, sc, ca, cb, cc;
	ll n;
	
	cin >> a >> b >> c >> sa >> sb >> sc >> ca >> cb >> cc >> n;
	
	ll l = 0, h = 100000000000000LL;
	ll ans = 0LL;
	while (l <= h) {
		ll m = (l + h) / 2;
		
		ll x = m * a, y = m * b, z = m * c;
		x = x - sa, y -= sb, z -= sc;
		ll d = n;
		if (x > 0) {
			d -= x * ca;
		} 
		
		if (y > 0) {
			d -= y * cb;
		}
		
		if (z > 0) {
			d -= z * cc;
		}
		
		if (d >= 0) {
			ans = max(ans , m);
			l = m + 1;
		} else {
			h = m - 1;
		}
		
	}
	cout << ans << endl;
	
	return 0;
}

