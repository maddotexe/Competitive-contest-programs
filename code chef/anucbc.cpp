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

int a[100010], ma[105];
int n, m, q;
ll fact[100010], invmod[100010];
ll dp[105][105], ad[105][105];

ll fast(ll a, ll n) {
	if(n == 0) {
		return 1;
	}
	
	ll c = fast(a, n/2);
	
	c = (c * c) % MOD;
	
	if (n & 1) {
		c = (c * a) % MOD;
	}
	
	return c;
}

void pre()
{
	fact[0] = 1;
	for (int i = 1; i < 100002; i++) {
		fact[i] = (fact[i-1] * i) % MOD;
	}
	
	invmod[0] = 1;
	for (int i = 1; i < 100002; i++) {
		invmod[i] = fast(fact[i], MOD - 2);
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	S(t);
	pre();
	while (t--) {
		S(n);
		S(q);
		
		for (int i = 0; i < n; i++) {
			S(a[i]);
		}
		
		for (int cc = 0; cc < q; cc++) {
			S(m);
			mem(ma, 0);
			for (int i = 0; i < n; i++) {
				ma[((a[i] % m) + m) % m]++;
			}
			
			mem(dp, 0);
			mem(ad, 0);
			
			dp[0][0] = 1;
			ll res;
			for (int i = 0; i < m; i++) {
				for (int j = 0; j <= ma[i]; j++) {
					res = (j * i) % m;
					ad[i][res] = ad[i][res] + ((fact[ma[i]] * invmod[j]) % MOD * invmod[ma[i] - j]) % MOD;
					if (ad[i][res] >= MOD) ad[i][res] -= MOD;
				}
			}
			
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < m; j++) {
					for (int k = 0; k < m; k++) {
						dp[i+1][j] = dp[i+1][j] + (dp[i][(j-k+m)%m] * ad[i][k]) % MOD;
						if (dp[i+1][j] >= MOD) dp[i+1][j] -= MOD;
					}
				}
			}
			printf("%lld\n", dp[m][0]);
		}
	}
	return 0;
}


