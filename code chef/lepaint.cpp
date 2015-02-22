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

int t;
int n, m, k, l, r;
double dp[101][101]; 
int a[101];
 
double solve(int pos, int c, int n, int k)
{
	if(pos == n) {
		return c;
	}
	if(dp[pos][c] > -1.0) return dp[pos][c];
	
	double ans = solve(pos+1, c, n, k) / 2.0;
	
	for(int i = 0; i < k; i++) {
		double temp = (solve(pos+1, (c * i) % k, n, k) * (1.0 / k))/ 2.0;
		ans += temp;
	}
	return dp[pos][c] = ans;
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> t;
	
	while(t--) {
		
		cin >> n >> m >> k;
		mem(a,0);
		
		for (int i = 0; i < k; i++) {
			cin >> l >> r;
			l--, r--;
			for (int j = l; j < r+1; j++) {
			    a[j]++;
			}
		}
		
		double ans = 0.0;
		
		for(int i = 0; i < n; i++) {
			mem(dp,-1);
			double v = solve(0, 1, a[i], m);
			ans += v;
		}
		printf("%.10f\n", ans);
	}
	return 0;
}



