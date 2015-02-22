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

vector <int> v[100010];

int main()
{
	ios_base::sync_with_stdio(false);
	int n, k, p;
	
	cin >> n >> k >> p;
	int a[n], o[n], e[n];
	int odd = 0, even = 0;
	
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] & 1) {
			odd++;
			o[odd - 1] = a[i];
		}
		else {
			even++;
			e[even - 1] = a[i];
		}
	}
	
	int q = k - p;
	
	if (q > odd || abs((odd - q)) & 1) {
		cout << "NO\n";
		return 0;
	}
	
	int g = odd - q;
	int f = g / 2;
	//trace6(g, f, odd, q, p, even);
	if (p > f + even) {
		cout << "NO\n";
		return 0;
	}
	
	int eve = 0, od = 0, ev = 0, oo = 0;
	
	for (int i = 0; i < k; i++) {
		if (eve != p) {
			if (ev != even) {
				v[i].pb(e[ev++]);
			} else {
				v[i].pb(o[oo++]);
				v[i].pb(o[oo++]);
			}
			eve++;
		} else {
			v[i].pb(o[oo++]);
		}
	}
	//trace2(oo, ev);
	if (ev != even) {
		for (int i = ev; i < even; i++) {
			v[0].pb(e[i]);
		}
	}
	
	if (oo != odd) {
		for (int i = oo; i < odd; i++) {
			v[0].pb(o[i]);
		}
	}
	cout << "YES\n";
	
	for (int i = 0; i < k; i++) {
		cout << v[i].size() << " ";
		for (int j = 0; j < v[i].size();j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}


