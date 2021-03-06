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

string s, s1;

int matchstr(int, int);

int matchstart(char c, int x, int y)
{
	do {
		if (matchstr(x, y)) return 1;
	} while (y < s1.size() && s1[y++] == c || c == '.');
	
	return 0;
}

int matchstr(int x, int y)
{
	if (s.size() == x && s1.size() == y) return 1;
	if (x + 1 < s.size() && s[x+1] == '*') {
		return matchstart(s[x], x + 2, y);
	}
	
	if (s[x] == '$' && s.size() - x == 1) {
		return (s1.size() == y);
	} 
	if (x < s.size() && y < s1.size() && s[x] == '.' || (s[x] == s1[y])) {
		return matchstr(x+1, y+1);
	}
	return 0;
}

int match(int x, int y)
{
	if (s[x] == '^') {
		return matchstr(x+1, y);
	}
	
	do {
		if (matchstr(x, y)) return 1;
	} while (++y < s1.size());
	
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	string s, s1;
	cin >> s >> s1;
	cout << match(0, 0);
	return 0;
}


