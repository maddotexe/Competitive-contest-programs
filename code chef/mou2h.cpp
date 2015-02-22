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
#define MOD 1000000009LL
#define MP(x,y) make_pair(x,y)
#define eps 1e-7
#define V(x) vector<x>
#define pb(x) push_back(x)
#define mem(x,i) memset(x,i,sizeof(x))
#define fori(i,s,n) for(i=(s);i<(n);i++)
#define ford(i,s,n) for(i=(n);i>=(s);--i)
#define INF 8944674407370955161LL
#define all(a)  a.begin(),a.end()

int abs(int x) {if(x < 0) return -x; return x;}

int a[1000010];
int b[1000010];
int dp[1000010];
int pos[10000010];

int main()
{
	ios_base::sync_with_stdio(false);
	int t, n;
	cin >> t;
	mem(pos, -1);
	while (t--) {
		cin >> n;
		int m = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			dp[i] = 0;
			if (i > 0) {
				b[i] = a[i] - a[i-1];
				m = min(m, b[i]);
			}
		}
		dp[0] = 1;
		for (int i = 1; i < n; i++) {
			
			dp[i] = 2 * dp[i-1];
			
		
			if (pos[b[i] - m] != -1) {
				dp[i] -= dp[pos[b[i] - m] - 1];
			}
			
			dp[i] %= MOD;
			if (dp[i] < 0) dp[i] += MOD;
			
			pos[b[i] - m] = i;
			
		}
		for (int i = 1; i < n; i++) pos[b[i] - m] = -1;
		
		printf("%lld\n", ((dp[n-1] + MOD - 1) % MOD));
	}
	return 0;
}


