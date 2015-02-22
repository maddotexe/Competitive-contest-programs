
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

vector <int> dp[100010], dp1[100010];
int vis[10], ans[100010];

int main()
{
	ios_base::sync_with_stdio(false);
	
	string s;
	
	cin >> s;
	
	int val;
	int n = s.size();
	for (int i = 0; i < n; i++) ans[i] = 99999999;
	for (int i = 0; i < n; i++) {
		dp[s[i]-'0'].pb(i);
		if (i) {
			dp1[i].pb(i-1);
		}
		if (i != n - 1) {
			dp1[i].pb(i+1);
		}
	}
	
	priority_queue<pii, vector <pii>, greater<pii> > p;
	
	p.push(pii(0, 0));
	ans[0] = 0;
	mem(vis, 0);
	
	while (!p.empty()) {
		pii pq = p.top();
		p.pop();
		
		int res = pq.se;
		int val = s[res] - '0';
		
		if (res == n - 1) break;
		
		for (int i = 0; i < dp1[res].size(); i++) {
			if (ans[dp1[res][i]] > ans[res] + 1) {
				ans[dp1[res][i]] = ans[res] + 1;
				p.push(pii(ans[res] + 1, dp1[res][i]));
			}
		}
		
		if (!vis[val]) {
			for (int i = 0; i < dp[val].size(); i++) {
				if (ans[dp[val][i]] > ans[res] + 1) {
					ans[dp[val][i]] = ans[res] + 1;
					p.push(pii(ans[res] + 1, dp[val][i]));
				}
			}
			vis[val] = 1;
		}
		
	}
	
	cout << ans[n-1] << endl;
	return 0;
}


