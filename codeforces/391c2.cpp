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
#define fori(i,s,n) for(int i=(s);i<(n);i++)
#define ford(i,s,n) for(i=(n);i>=(s);--i)
#define INF 8944674407370955161LL
#define debug(i,st,arr) fori(i,0,st){cout<<arr[i]<<" ";}cout<<endl;
#define forci(i,sw) for((i)=(sw).begin();(i)!=(sw).end();(i)++)
#define forcd(i,sw) for((i)=(sw).rbegin();(i)!=(sw).rend();(i)++)

int abs(int x) {if(x < 0) return -x; return x;}

int n, k;
vector <pii> p;
	
int dp[101][101];

int solve(int pos, int players)
{
	cout << pos << " " << players << " " << dp[pos][players] << endl;;
	if (pos == n) {
		if (players >= n - k + 1) {
			return 0;
		} else {
			return 99999999;
		}
	}
	if (dp[pos][players] != -1) return dp[pos][players];
	
	int ans = 99999999;
	
	ans = min(ans, p[pos].se + solve(pos + 1, players + 1));
	ans = min(ans, solve(pos + 1, players));
	
	return dp[pos][players] = ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int x, y;
	mem(dp, -1);
	cin >> n;
	fori(i, 0, n) {
		cin >> x >> y;
		p.pb(pii(x, y));
	}
	
	sort(p.rbegin(), p.rend());
	solve(0, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			
			cout << dp[i][j] << " ";
		}
		cout << endl << endl;
	}
	
	
	return 0;
}

