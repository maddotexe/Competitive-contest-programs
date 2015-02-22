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

ll fact[100010];
ll t, n, k, a[100010], ans;
void f()
{
	fact[0] =  1;
	for (int i = 1; i < 100005; i++) {
		fact[i] = (fact[i-1] * i) % MOD;
	}
}

ll fast(ll a, ll n) 
{
	if (n == 0) return 1;
	
	ll b = fast(a, n / 2);
	
	b = (b * b) % MOD;
	
	if (n & 1) {
		b = (b * a) % MOD;
	}
	return b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	f();
	
	cin >> t;
	cout << fast(10, 3);
	while (t--) {
		cin >> n >> k;
		ans = 0;
		
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a+n);
		for (int i = 0; i < n; i++) {
			if (n - i < k) break;
			ll x = fact[n-i-1];
			ll y = (fact[k-1] * fact[n-i-1]) % MOD;
			
			y = fast(y, MOD - 2);
			
			x = (x * y) % MOD;
			x = (x * a[i]) % MOD;
			ans = (ans + x) % MOD;
		}
		cout << ans << endl;
	}
	return 0;
}


