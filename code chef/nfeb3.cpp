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

int a[505][505];
int dp[505][505];

int main()
{
//	ios_base::sync_with_stdio(false);
	int n, m, start;
	int t;
	cin >> t;
	
	while (t--) {
	
		cin >> n >> m >> start;
		mem(dp, -1);
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> a[i][j];
			}
		}
		int ans = -99999999;
		if (m == 1 && n != 1) {
			cout << -1 << endl;
			continue;
		}
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (i == 1) {
					dp[i][j] = start - a[i][j];
				} else if (j == 1) {
					if (dp[i-1][j+1] > 0)
						dp[i][j] = dp[i-1][j+1] - a[i][j];
				} else if (j == m) {
					if (dp[i-1][j-1] > 0)
						dp[i][j] = dp[i-1][j-1] - a[i][j];
				} else {
					int x = -1, y = -1;
					if (dp[i-1][j-1] > 0) 
						x = dp[i-1][j-1] - a[i][j];
					
					if (dp[i-1][j+1] > 0) 
						y = dp[i-1][j+1] - a[i][j];
						
					dp[i][j] = max(x, y);
					
				}
				
				if (dp[i][j] < 0) {
					dp[i][j] = -1;
				}
				
				if (dp[i][j] > 100) {
					dp[i][j] = 100;
				}
			}
		}
		
		/*for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}*/
		for (int i = 1; i <= m; i++) {
			ans = max(ans, dp[n][i]);
		}
		cout << ans << endl;
	}
	return 0;
}

