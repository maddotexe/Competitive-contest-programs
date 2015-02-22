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

vector<vector <ll> > mat, ans;
int n, m;
int a[1000000];
int siz;

vector<vector <ll> > mul(vector<vector <ll> > v1, vector<vector <ll> > v2)
{
	vector<vector <ll> > vv(siz);
	for(int i = 0; i < siz; i++) {
		vv[i].resize(siz);
	}
	for(int i = 0; i < siz; i++) {
		for(int j = 0; j < siz; j++) {
    			for (int k = 0; k < siz; k++) {
				vv[i][j]=(vv[i][j]+(v1[i][k]*v2[k][j])%MOD)%MOD;
			}
		}
    	}
    	return vv;
}


vector<vector <ll> > solve(ll n)
{
	if(n == 1) return mat;
	if(n % 2 == 1) {
		vector<vector <ll> > vv = solve(n-1);
		vv = mul(mat, vv);
		return vv;
	} else {
		vector<vector <ll> > vv = solve(n/2);
		vv = mul(vv,vv);
		return vv;
	}
}

bool checkpalin(string s)
{
	for(int i = 0; i < s.size(); i++) {
		if (s[i] != s[s.size()-i-1]) return false;
	}
	return true;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	siz = n * m;
	string s;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> s;
			map<string, int> mm;
			for (int k = 0; k < s.size(); k++) {
				string ss = "";
				for(int l = k; l < s.size(); l++) {
					ss += s[l];
					if(checkpalin(ss)) mm[ss]++;
				}
			}
			a[i * m + j] = mm.size();
		}
	}

    int t;

	cin >> t;
	mat.resize((siz));
	
	for (int i = 0; i < siz; i++) mat[i].resize(siz);
	int x, y, xx, yy;
	
	for(int i = 0; i < t; i++) {
		cin >> x >> y >> xx >> yy;
		mat[x * m + y][xx * m + yy]++;
		mat[xx * m + yy][x * m + y]++;
	}
	
	for(int i = 0; i < m*n; i++) mat[i][i] = 1;
	int d;
	cin >> d;
	ans = solve(d);
	
	for(int i = 0; i < siz; i++) {
		ll val = 0;
		for(int j = 0; j < siz; j++) {
			val += ans[i][j]*a[j];
			val %= MOD;
		}
		if(i && i % m == 0) cout << endl;
		cout << val << " ";
	}
	return 0;
}
