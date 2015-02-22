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
	int n;
	cin >> n;
	string s[n];
	
	map<char, int> m, m1;
	map<char, int>:: iterator it;
	set<string> ss;
	set<string>::iterator it1;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		ss.insert(s[i]);
		m[s[i][0]]++;
		m1[s[i][1]]++;
	}
	string sss[n];
	int k = 0;
	for (it1 = ss.begin(); it1 != ss.end(); it1++) {
		sss[k++] = *it1;
	}
	bool ff = 0;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				if (s[i] == s[j]) ff = true;
				break;
			}
		}
	}
	
	if (!ff) {
		cout << k << endl;
		return 0;
	}
	int ans = m.size() - 1 + m1.size() - 1;
	int c = 0;
	
	bool f = true;
	
	for (it = m.begin(); it != m.end(); it++) {
		if (it->se == 1) c++;
	}
	
	if (c >= 2) {
		char aa[2], bb[2];
		int k = 0;
		c = 2;
		for (it = m.begin(); it != m.end(); it++) {
			if (it->se == 1 && c) {
				aa[k++] = it->fr;
				c--;
			}
		}
		k = 0;
		for (int i = 0; i < n; i++) {
			if (s[i][0] == aa[0]) {
				bb[k++] = s[i][1];
			}
		}
		for (int i = 0; i < n; i++) {
			if (s[i][0] == aa[1]) {
				bb[k++] = s[i][1];
			}
		}
		
		if (bb[0] != bb[1]) ans--;
		f = false;
	}
	
	if (f) {
		for (it = m1.begin(); it != m1.end(); it++) {
			if (it->se == 1) c++;
		}
	
		if (c >= 2) {
			char aa[2], bb[2];
			int k = 0;
			c = 2;
			for (it = m1.begin(); it != m1.end(); it++) {
				if (it->se == 1 && c) {
					aa[k++] = it->fr;
					c--;
				}
			}
			k = 0;
			for (int i = 0; i < n; i++) {
				if (s[i][1] == aa[0]) {
					bb[k++] = s[i][0];
				}
			}
			for (int i = 0; i < n; i++) {
				if (s[i][1] == aa[1]) {
					bb[k++] = s[i][0];
				}
			}
			
			if (bb[0] != bb[1]) ans--;
		}	
	}
	
	cout << ans << endl;
	return 0;
}


