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
#define MOD 1000000
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

int v[1000002];

int main()
{
	ll t, n, a, b, c, d, maxval, sa, sb, minval;
	
	cin >> t;
	
	while (t--) {
		scanf("%lld%lld%lld%lld%lld", &n, &a, &b, &c, &d);
		for (int i = 0; i < 1000002; i++) {
			v[i] = 0;
		}
		sa = sb = 0;
		maxval = minval = d;
		v[d]++;
		for (int i = 0; i < n - 1; i++) {
			d = (a * d * d + b * d + c) % MOD;
			v[d]++;
			maxval = max(d, maxval);
			minval = min(d, minval);
		}
		bool f = true;
		for (int i = maxval; i >= minval; i--) {
			for (int j = 0; j < v[i]; j++) {
				if (f) {
					sa += i;
					f = false;
				} else {
					sb += i;
					f = true;
				}
			}
		}
		
		printf("%lld\n", sa - sb);
	}
	return 0;
}


