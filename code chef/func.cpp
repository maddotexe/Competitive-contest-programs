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

ll func(ll x, int i) 
{
	double tmp = pow(x, (double)1/i);
	ll p = tmp;
	ll q = (tmp + 0.5);
	
	if (p == q) return p;
	
	if (pow(q, i) <= x) return q;
	return p;
}


int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	
	cin >> t;
	while (t--) {
	
		ll n, m;
		
		cin >> n >> m;
		ll a[n], b[n];
		a[0] = b[0] = 0;
		for (int i = 1; i <= n; i++) {
			cin >> b[i];
			
			a[i] = (a[i-1] + b[i]) % MOD;
			if (a[i] < 0) {
				a[i] += MOD;
			}
		}
		
		ll k = -1;
		ll val;
		ll x;
		for (int i = 0; i < m; i++) {
			cin >> x;
			ll ans = 0;
			for (int i = 1; i <= n; i++) {
				val = func(x, i);
				k = (ll)(val);
				//trace1(k);
				if (k == 1) {
					ans += ((a[n] - a[i-1]) % MOD);
					ans %= MOD;
					if (ans < 0) {
						ans = ((ans + MOD) % MOD);
					}
					//trace1(a[n] - a[i-1]);
					break;
				} else {
					ans += ((k % MOD) * b[i]) % MOD;
					ans %= MOD;
					if (ans < 0) {
						ans = ((ans + MOD) % MOD);
					}
				}
				//trace1(val);
			}
			cout << ans << " ";
		}
		cout << endl;
	}
	return 0;
}
