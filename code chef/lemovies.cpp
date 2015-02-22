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

int n, k;
ll a[201];
ll dp[201][201][201][2];
vector <ll> v;
ll m[201];
ll fact[201];

void pre()
{
	fact[0] = 1;
	
	for (int i = 1; i < 201; i++) {
		fact[i] = (fact[i-1] * i) % MOD;
	}
}

ll solve(int pos, int exite, int used, int flag) 
{
	if (exite > k) return 0;
	if (pos == v.size()) {
		return fact[used];
	}
	if (dp[pos][exite][used][flag] != -1) return dp[pos][exite][used][flag];
	ll ans = 0;
	if (used && flag == 0) {
		ans = (used * solve(pos, exite, used - 1, flag)) % MOD;
	}
	
	if (pos != v.size() - 1) {
		ans = (ans + solve(pos + 1, exite, used + m[v[pos]], 1)) % MOD;
	}
	
	ans = (ans + (m[v[pos]] * (solve(pos + 1, exite + 1, used + m[v[pos]] - 1, 0)) % MOD) % MOD) % MOD;
	
	return dp[pos][exite][used][flag] = ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	pre();
	while (t--) {
		cin >> n >> k;
		mem(dp, -1);
		mem(m, 0);
		v.clear();
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			m[a[i]]++;
		}
		for (int i = 1; i < 201; i++) {
			if (m[i]) v.pb(i);
		}
		cout << solve(0, 0, 0, 1) << endl;
	}
	return 0;
}

