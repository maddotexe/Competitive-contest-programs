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

int a[101][101];
int n, m, s;
int ss[10];
int dp[1<<9][101][101];

int solve(int mask, int x, int y) 
{
	//cout << mask << endl;
	if (mask == 0) {
		return 0;
	}
	if (dp[mask][x][y] != -1) return dp[mask][x][y];
	
	int ans = 99999999;
	
	for (int i = 0; i < s; i++) {
		if(mask & (1 << i)) {
			ans = min (ans, solve(mask ^ (1 << i), ss[i], y) + a[x][ss[i]]);
			ans = min (ans, solve(mask ^ (1 << i), x, ss[i]) + a[y][ss[i]]);
		} 
	}
	return dp[mask][x][y] = ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int x, y, z;
	cin >> n >> m;
	mem(dp, -1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = 9999999;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		a[x][y] = a[y][x] = z;
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
			}
		}
	}
	cin >> s;
	for (int i = 0; i < s; i++) {
		cin >> ss[i];
	}
	cin >> x >> y;
	int ans = solve(((1<<s) - 1), x, y);
	cout << ans <<endl;
	return 0;
}

