#include<bits/stdc++.h>

using namespace std;

#define TRACE

#ifdef TRACE
    #define trace1(x)                cerr << #x << ": " << x << endl;
    #define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
    #define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
    #define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
    #define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
    #define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

    #define trace1(x)
    #define trace2(x, y)
    #define trace3(x, y, z)
    #define trace4(a, b, c, d)
    #define trace5(a, b, c, d, e)
    #define trace6(a, b, c, d, e, f)

#endif


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
#define forci(i,sw) for((i)=(sw).begin();(i)!=(sw).end();(i)++)
#define forcd(i,sw) for((i)=(sw).rbegin();(i)!=(sw).rend();(i)++)
#define INF 8944674407370955161LL
#define all(a)  a.begin(),a.end()

int abs(int x) {if(x < 0) return -x; return x;}

string s, ss;
int dp[2][100010];
int main()
{
	//ios_base::sync_with_stdio(false);
	int a, b, k;
	int t;
	
	cin >> t;
	
	while (t--) {
		cin >> s >> ss;
		cin >> a >> b >> k;
		
		if (2 * a < b) b = 2 * a;
		int n = ss.size();
		int m = s.size();
		if (b == 0) {
			if (a == 0) {
				cout << 0 << endl;
			} else {
				if (abs(m - n) * a <= k) {
					cout << abs(m - n) * a << endl;
				} else {
					cout << -1 << endl;
				}
			}
			continue;
		}
		
		
		
		for (int i = 0; i <= n; i++) {
			dp[0][i] = a * i;
			dp[1][i] = 1e9;
		}
		dp[0][0] = 0;
		dp[0][n] = 1e9;
		
		for (int i = 1; i <= m; i++) {
			bool x = i & 1;
			dp[x][0] = a * i;
			if (i - k - 1 >= 0) dp[x][i - k - 1] = k + 1;
			if (i + k <= n) dp[(i - 1) & 1][i + k] = k + 1;
			
			for (int j = max(1, i - k); j <= min(n, i + k); j++) {
				dp[x][j] = dp[!x][j] + a;
				dp[x][j] = min(dp[x][j-1] + a, dp[x][j]);
				if (s[i-1] != ss[j-1]) {
					dp[x][j] = min(dp[!x][j-1] + b, dp[x][j]);
				} else {
					dp[x][j] = min(dp[!x][j-1], dp[x][j]);
				}
			}
			
			dp[x][min(n + 1, i + k + 1)] = k + 1;
		}
		if (dp[m & 1][n] <= k) cout << dp[m & 1][n] << endl;
		else cout << -1 << endl;
	}
	
	return 0;
}


