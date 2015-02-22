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
	
	cin >> t;
	string s, a;
	while (t--) {
		cin >> s;
		a = s;
	
		if (a[0] != '?' && a[s.size()-1] != '?' && a[0] == a[s.size() - 1]) {
			cout << "Not found\n";
			continue;
		}
		bool f = false;
		for (int i = 1; i < s.size(); i++) {
			if (a[i] == '?') continue;
			if (a[i] != '?' && a[i-1] != '?' && a[i] == a[i-1]) {
				f = true;
			} 
		}
		
		if (f) {
			cout << "Not found\n";
			continue;
		}
		int n = s.size() - 1;
		if (a[0] == '?') {
			if (a[1] != 'a' && a[n] != 'a') {
				a[0] = 'a';
			} else if (a[1] != 'b' && a[n] != 'b') {
				a[0] = 'b';
			} else if (a[1] != 'c' && a[n] != 'c') {
				a[0] = 'c';
			} 
		}
		
		for (int i = 1; i < s.size() - 1; i++) {
			if (a[i] == '?') {
				if (a[i-1] != 'a' && a[i+1] != 'a') a[i] = 'a';
				else if (a[i-1] != 'b' && a[i+1] != 'b') a[i] = 'b';
				else a[i] = 'c';
			} 
		}
		
		if (a[n] == '?') {
			if (a[0] != 'a' && a[n-1] != 'a') a[n] = 'a';
			else if (a[0] != 'b' && a[n-1] != 'b') a[n] = 'b';
			else a[n] = 'c';
		}
		
		cout << a << endl;
		
	}
	return 0;
}


