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

int a[101], n, m;
pair<char, int> p[30];
int dp[21][1 << 20];
int solve(int pos, int mask)
{
	if (pos == m) return 0;
	if (mask == 0) return 0;
	if (dp[pos][mask] != -1) return dp[pos][mask];
	//cout << mask << " " << p[pos].se << endl;
	int ans;
	if (p[pos].se == 1) {
		ans = -999999999;
		for (int i = 0; i < m; i++) {
			if (!((1 << i) & mask)) continue;
			if (p[pos].fr == 'p')
				ans = max(ans, a[i] + solve(pos + 1, mask ^ (1 << i)));
			else {
				ans = max(ans, solve(pos + 1, mask ^ (1 << i)));
			}
		}
	} else {
		ans = 999999999;
		for (int i = 0; i < m; i++) {
			if (!((1 << i) & mask)) continue;
			if (p[pos].fr == 'p')
				ans = min(ans, solve(pos + 1, mask ^ (1 << i)) - a[i]);
			else 
				ans = min(ans, solve(pos + 1, mask ^ (1 << i)));
		}
	}
	
	return dp[pos][mask] = ans;
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) cin >> a[i];
	
	cin >> m;
	
	for (int i = 0; i < m; i++) {
		cin >> p[i].fr >> p[i].se;
	}
	sort(a, a + n);
	reverse(a, a + n);
	cout << solve(0, (1 << m) - 1) << endl;
	return 0;
}

