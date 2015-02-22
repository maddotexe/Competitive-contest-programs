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

int a[110][110];
vector <ppi> ans;

int main()
{
	ios_base::sync_with_stdio(false);
	int n, m, k, x, y;
	cin >> n >> m >> k;
	mem(a, 0);
	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		a[x][y] = 1;
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == 0) {
				int c = 0, c1 = 0;
				for (k = j + 1; k <= m; k++) {
					if (a[i][k] == 0) {
						c++;
					} else {
						break;
					}
				}
				
				for (k = i + 1; k <= n; k++) {
					if (a[k][j] == 0) {
						c1++;
					} else {
						break;
					}
				}
				
				a[i][j] = 1;
				if (c >= c1) {
					ans.pb(ppi(i, pii(j, 0)));
					for (k = j + 1; k <= m; k++) {
						if (a[i][k] == 0) {
							a[i][k] = 1;
						} else {
							break;
						}
					}
				} else {
					ans.pb(ppi(i, pii(j, 1)));
					for (k = i + 1; k <= n; k++) {
						if (a[k][j] == 0) {
							a[k][j] = 1;
						} else {
							break;
						}
					}
				}
			}
		}
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		printf("%d %d %d\n", ans[i].fr, ans[i].se.fr, ans[i].se.se);
	}
	
	return 0;
}


