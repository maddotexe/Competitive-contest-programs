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

int n, k, total = 0;
int a[2010];
int c[2010];
int p2[2010];
int dp[2010][(1 << 11) + 1];

void pre()
{
	p2[0] = 1;
	for (int i = 1; i < 2005; i++) {
		p2[i] = (p2[i-1] * 2) % MOD;
	}
}

int solve(int pos, int mask)
{	//cout << pos << " " << mask << endl;
	if (mask & (1 << k)) return (p2[total - c[pos]] * (a[pos]? 1 : 2)) % MOD;
	//cout << "iiii" << endl;
	if (pos == n) return 0;
	if (dp[pos][mask] != -1) return dp[pos][mask];
	
	int ans = 0;
	int tmask = mask;
	
	if (a[pos]) {
		//cout << "ppp";
		if (mask == 0) {
			return dp[pos][tmask] = solve(pos + 1, a[pos]);
		}
		int cur = log2(a[pos]);
		bool f = false;
		
		for (int i = cur - 1; i >= 0; i--) {
			if (mask & (1 << i)) f = true;
		}
		if (f) {
			return dp[pos][tmask] = solve(pos + 1, a[pos]);
		}
		
		while (mask & (1 << cur)) {
			mask ^= (1 << cur);
			cur++;
		}
		
		mask |= (1 << cur);
		return dp[pos][tmask] = solve(pos + 1, mask);
	} else {
		if (mask == 0) {
			return dp[pos][tmask] = (solve(pos + 1, 2) + solve(pos + 1, 4)) % MOD;
		}
		for (int i = 1; i <= 2; i++) {
			bool f = false;
			mask = tmask;
			for (int j = i - 1; j >= 0; j--) {
				if (mask & (1 << j)) f = true;
			}
			if (f) {
				ans = (ans + solve(pos + 1, (1 << i))) % MOD;
			} else {
				int val = i;
				while (mask & (1 << val)) {
					mask ^= (1 << val);
					val++;
				}
				mask |= (1 << val);
				ans = (ans + solve(pos + 1, mask)) % MOD;
				
			}
		}
		return dp[pos][tmask] = ans;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	pre();
	total = 0;
	cin >> n >> k;
	a[n] = 1;
	mem(dp, -1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i > 0) {
			c[i] = c[i-1];
		}
		
		if (a[i] == 0) {
			c[i]++;
			total++;
		}
	}
	
	c[n] = total;
	
	cout << solve(0, 0) << endl;
	
	return 0;
}


