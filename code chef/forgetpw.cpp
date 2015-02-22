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

int main()
{
	ios_base::sync_with_stdio(false);
	
	int t;
	int n;
	
	cin >> t;
	
	while (t--) {
	
		char c, c1;
		map <char, char> m;
		m.clear();
		cin >> n;
		string s;
		
		for (int i = 33; i < 127; i++) {
			if (i != ' ') {
				m[i] = 'a';
			}
		}
		
		for (int i = 0; i < n; i++) {
			cin >> c >> c1;
			
			m[c] = c1;
		}
		
		cin >> s;
		bool ff = false;
		for (int i = 0; i < s.size(); i++) {
			if (m[s[i]] != 'a') s[i] = m[s[i]];
			if (s[i] == '.') ff = true;
		}
		//cout << s << endl;
		int ss = 0;
		int ee = s.size() - 1;
		
		for (ss; ss < s.size(); ss++) {
			if (s[ss] == '.' || (s[ss] >= '1' && s[ss] <= '9')) break;
		}
		if (ff)
		for (ee; ee >= 0; ee--) {
			if (s[ee] == '.' || (s[ee] >= '1' && s[ee] <= '9')) break;
		}		
		if (s[ee] == '.') ee--;
		bool f = false;
		for (int i = ss; i <= ee; i++) {
			cout << s[i];
			f = true;
		}
		if (!f) {
			cout << 0;
		}
		cout << endl;
	}
	return 0;
}


