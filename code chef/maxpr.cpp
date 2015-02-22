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
#define INF 8944674407370955161LL
#define all(a)  a.begin(),a.end()

int abs(int x) {if(x < 0) return -x; return x;}

int dpp[101][101], dpn[101][101];
int p2[200100], vis[101];
int a[200100];

int main()
{
	ios_base::sync_with_stdio(false);
	int t, n;
	cin >> t;
	
	p2[0] = 1;
	for (int i = 1; i < 200010; i++) {
		p2[i] = ((ll)p2[i-1] * 2LL) % MOD;
	}
	
	while (t--) {
		mem(dpp, 0);
		mem(dpn, 0);
		mem(vis, 0);
		
		cin >> n;
		
		for (int i = 0; i < n; i++) cin >> a[i];
		
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < a[i]; j++) {
				if (vis[a[i] - j]) {
					dpp[a[i]][j] += dpp[a[i] - j][j] + vis[a[i] - j];
					dpp[a[i]][j] %= MOD;
				}
			}
			for (int j = 1; j + a[i] <= 100; j++) {
				if (vis[a[i] + j]) {
					dpn[a[i]][j] += dpn[a[i] + j][j] + vis[a[i] + j];
					dpn[a[i]][j] %= MOD;
				}
			}
			vis[a[i]]++;
		}
		int res = 1, ans = p2[n];
		
		for (int i = 1; i <= 100; i++) {
			int val = p2[vis[i]] - 1;
			if (val < 0) val += MOD;
			res = (res + val) % MOD;
		}
		
		
		for (int i = 1; i < 101; i++) {
			for (int j = 1; j < 101; j++) {
				res = (res + dpp[i][j]) % MOD;
				res = (res + dpn[i][j]) % MOD;
			}
		}
		
		
		cout << (ans + MOD - res) % MOD << endl;
		
	}
	return 0;
}


