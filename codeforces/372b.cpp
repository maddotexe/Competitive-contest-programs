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

int dp[41][41][41][41];
int a[41][41];
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m, k, p ,q, r, s;
	char x;
	cin >> n >> m >> k;
	

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> x;
			a[i][j] = a[i][j-1];
			if (x - '0' == 0) {
				a[i][j]++;
			} else {
				a[i][j] = 0;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = i; k <= n; k++) {
				for (int l = j; l <= m; l++) {
					dp[i][j][k][l] = dp[i][j][k-1][l] + dp[i][j][k][l-1] - dp[i][j][k-1][l-1];
					int val = l - j + 1;
					//cout << "lll";
					for (int x = k; x >= i; x--) {
						//cout << val << endl;
						val = min(val, a[x][l]);
						dp[i][j][k][l] += val;
					}
				}
			}
		}
	}
	//cout << "kkk";
	for (int i = 0; i < k; i++) {
		cin >> p >> q >> r >> s;
		cout << dp[p][q][r][s] << endl;
	}
	return 0;
}

