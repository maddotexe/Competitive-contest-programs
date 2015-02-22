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

int n;
int a[2010][2010], cc[2010][2010];
int vis[2010][2010], vis1[2010], vis2[2010];
vector <ppi> v;
vector <pii> path;

void dfs(int x, int y)
{
	path.pb(pii(x, y));
	vis1[x] = 1;
	
	for (int i = 0; i < n; i++) {
		if (i == x) continue;
		if (vis[x][i] != 0) {
			if (vis1[i] == 0) {
				dfs(x, i);
			}
		}
	}
}
bool check()
{
	for (int i = 0; i < n; i++) if (a[i][i]) return 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] != a[j][i]) return 1;
			if (i != j && a[i][j] == 0) return 1;
		}
	}
	return 0;
}

bool check1()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//if (cc[i][j] != a[i][j]) return 0;
			cout << cc[i][j] << " ";
		}
		cout << endl;
	}
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			v.pb(ppi(a[i][j], pii(i, j)));
		}
	}
	
	if (check()) {
		cout << "NO\n";
		return 0;
	} 
	
	sort (v.begin(), v.end());
	
	for (int i = 0; i < n * n; i++) {
		int x = v[i].se.fr;
		int y = v[i].se.se;
		if (x == y) continue;
		if (vis2[x] == 0 || vis2[y] == 0) {
			vis[x][y] = vis[y][x] = v[i].fr;
			vis2[x] = vis2[y] = 1;
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//if (cc[i][j] != a[i][j]) return 0;
			cout << vis[i][j] << " ";
		}
		cout << endl;
	}
	
	dfs(0, 0);
	

	
	if (check1()) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
	
	return 0;
}


