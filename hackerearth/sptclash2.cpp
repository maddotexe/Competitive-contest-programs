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

vector <pll> v;
int n, w;

ll dp[2010][11];

ll pri[] = {29, 23, 19, 17, 13, 11, 7, 5, 3, 2};
void func()
{
	dp[0][0] = 0;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = w; j >= 0; j--) {
			for (int k = 0; k < 11; k++) {
				if (dp[j][k] == -1) continue;
				if (j + v[i].se > w) continue;
				dp[j+v[i].se][k] = max(dp[j+v[i].se][k], v[i].fr + dp[j][k]);
				ans = max(ans, dp[j+v[i].se][k]);
				if (k != 10) dp[j+v[i].se][k+1] = max(dp[j+v[i].se][k+1], pri[k] * v[i].fr + dp[j][k]);
				if (k != 10) ans = max(ans, dp[j+v[i].se][k+1]);
			}
		}
	}
	cout << ans << endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> w;
	ll x, y;
	mem(dp, -1);
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.pb(pll(x, y));
	}
	
	sort(v.rbegin(), v.rend());
	
	func();
	return 0;
}


