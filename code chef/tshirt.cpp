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

vector <int> v[101];
ll dp[101][1<<10];

ll solve(int pos, int mask)
{
	//trace2(pos, mask)
	if (pos == 100) {
		if (mask == 0) return 1;
		return 0;
	}
	
	if (dp[pos][mask] != -1) return dp[pos][mask];
	
	ll ans = 0;
	
	for (int i = 0; i < v[pos].size(); i++) {
		//trace1(v[pos].size());
		if (mask & (1 << v[pos][i])) {
			ll temp = solve(pos + 1, mask ^ (1 << v[pos][i]));
			ans = (ans + temp) % MOD;
		}
	}
	
	ll temp = solve(pos + 1, mask);
	ans = (ans + temp ) % MOD;
	
	
	return dp[pos][mask] = ans;
}

int main()
{
	//ios_base::sync_with_stdio(false);
	int t, n, val;
	cin >> t;
	string s;
	while (t--) {
		mem(dp, -1);
		for (int i = 0; i < 101; i++) v[i].clear();
		S(n);
		getchar();
		
		for (int i = 0; i < n; i++) {
			getline(cin, s);
			stringstream ss;
			
			ss << s;
			
			while (ss >> val) {
				v[val-1].pb(i);
			}
		}
		
		cout << solve(0, (1 << n) - 1) << endl;
	}
	return 0;
}


