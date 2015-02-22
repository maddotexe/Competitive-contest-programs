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
#define MOD 1000000009
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

ll fast(ll a, ll n) 
{
	if (n == 0) return 1;
	if (n == 1) return a;
	
	ll d = fast(a, n / 2);
	
	d = (d * d) % MOD;
	
	if (n & 1) {
		d = (d * a) % MOD;
	}
	return d;
}


int main()
{
	ios_base::sync_with_stdio(false);
	ll n, k, p2 = 1;
	cin >> k;
	
	for (int i = 0; i < k - 1; i++) {
		p2 = (p2 * 2LL);
	}
//	cout << p2 << endl;
	ll ans = 1, fact = 1;
	for (ll i = 1; i <= p2; i++) {
		fact = (fact * i) % MOD;
	}
	//cout << fact << endl;
	for (int i = 1; i < p2; i++) {
		cout << 0 << endl;
	} 
	ans = (fact * fact) % MOD;
	ans = (ans * 2) % MOD;
	cout << ans << endl;
	ll ans1 = 1;
	for (int i = p2, j = 1; i < p2 * 2; i++, j++) {
		ans1 = (i * ans1) % MOD;
		ans1 = (ans1 * fast(j, MOD - 2)) % MOD;
		cout << (ans * ans1) % MOD << endl;
	}
	//cout << ans << endl;
	return 0;
}


