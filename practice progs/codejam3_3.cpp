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

int a[11];
int dp[1000010];

int check(int x)
{
	int c = 0;
	while (x != 0) {
		c++;
		int k = x % 10;
		if (!a[k]) return 9999999;
		x = x / 10;
	}
	return c;
}

int f(int n)
{
	//cout << n << endl;
	if (dp[n] != -1) return dp[n];
	int c, x = check(n);
	if (x) c = x;
	else  c = 9999999;
	
	if (n == 2 || n == 3 || n == 5 || n == 7 || n == 1 || n == 0) {
		if (x == 0) {
			return 9999999;
		} else {
			return 1;
		}
	}
	
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			trace2(i, n / i);
			int x = check(i);
			int y = check(n / i);
			c = min(c, f(i) + f(n/i) + 1);
			
		}
	}
	//trace1(c);
	//cout << c << endl;
	return dp[n] = c;
}

int main()
{
	//ios_base::sync_with_stdio(false);
	//freopen("inp.in", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int t, n;
	
	cin >> t;
	int cs = 1;
	while (t--) {
		cout << "Case #" << cs++ << ": ";
		for (int i = 0; i < 10; i++) {
			cin >> a[i];
		}
		cin >> n;
		mem(dp, -1);
		int ans = 9999999;
		
		ans = check(n);
		for (int i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				trace2(i, n / i);
				int x = f(i);
				int y = f(n / i);
				//if (n / i == 15) cout << y << endl;
				ans = min(ans, x + y + 1);
				
			}
		}
		
		if (ans < 9999999) {
			cout << ans + 1 << endl;
		} else {
			cout << "Impossible\n";
		}
	}
	return 0;
}


