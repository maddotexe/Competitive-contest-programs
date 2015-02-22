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
ll n;
vector <int> v;
ll dp[20][2][2];
map<int, int> m;
ll cc[31];
int p[100], c[100];

inline void fastRead(long long int *a)
{
  register char c=0;
  while (c<33) c=getchar_unlocked();
  *a=0;
  while (c>33)
    {
      *a=*a*10+c-'0';
      c=getchar_unlocked();
    }
}


ll solve(int pos, bool flag, bool pflag, int len)
{
	//trace2(pos, len);
	if (pos == len) {
		if (pflag) return 1;
		return 0;
	}
	
	if (dp[pos][flag][pflag] != -1) return dp[pos][flag][pflag];
	
	ll ans = 0;
	bool f = false;
	
	if (flag) {
		if(pos == 0) {
			ans += 4LL*solve(pos+1, flag, 1, len);
			ans += 5LL*solve(pos+1, flag, pflag, len); 
		}
		else {
			ans += 4LL*solve(pos+1, flag, 1, len);
			ans += 6LL*solve(pos+1, flag, pflag, len); 
		}
	} else {
		
		if(pos == 0) {
			if(v[pos]) ans += p[v[pos]-1]*solve(pos+1, 1, 1, len);
			if(v[pos]) ans += (c[v[pos]-1]-1)*solve(pos+1, 1, pflag, len);
		}
		else {
			if(v[pos]) ans += p[v[pos]-1]*solve(pos+1, 1, 1, len);
			if(v[pos]) ans += c[v[pos]-1]*solve(pos+1, 1, pflag, len);
		}	
		if (m[v[pos]]) f = true;
		else f = false;
		ans += solve(pos + 1, flag, pflag | f, len);
	}
	
	
	return dp[pos][flag][pflag] = ans;
}

void pre()
{
	c[0] = 1;
	c[1] = 1;
	c[4] = 1;
	c[6] = 1;
	c[8] = 1;
	c[9] = 1;
	p[2] = 1;
	p[3] = 1;
	p[5] = 1;
	p[7] = 1;
	for(int i = 0; i <= 10; i++) {
		p[i] += p[i-1];
		c[i] += c[i-1];
	}
	for(int i = 0; i < 18; i++) {
		cc[i+1] = cc[i];
		mem(dp, -1);
		cc[i+1] += solve(0, 1, 0, i+1); 
	}
}
int main()
{
	
	int t;
	cin >> t;
	m[2] = 1;
	m[3] = 1;
	m[5] = 1;
	m[7] = 1;
	pre();
	while (t--) {
		fastRead(&n);
		mem(dp, -1);
		ll a = n;
		v.clear();
		while (a != 0) {
			v.pb(a % 10);
			a /= 10;
		}
		reverse(v.begin(), v.end());
		ll ans = 0;
		ans += cc[v.size()-1];
		ans += solve(0, 0, 0, v.size());
		printf("%lld\n", ans);
	}
	return 0;
}


