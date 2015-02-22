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

const int MAXN = 100009;
int s[MAXN], a[MAXN], r[MAXN], ans[MAXN];

inline void makeSet(int &x) {
	s[x] = x;
	r[x] = -1;
	ans[x] = x;
}

inline void init(int n) {
	for(int i=0; i<=n; i++){
		makeSet(i);
	}
}

int findset(int x) {
	if (x == s[x]) {
		return x;
	} else {
		return findset(s[x]);
	}
}

void Union(int x, int y) {
	if (r[x] > r[y]) {
		if (a[x] < a[y]) {
			swap(a[x], a[y]);
			swap(ans[x], ans[y]);
			s[y] = x;
		}
	} else if (r[x] < r[y]) {
		if (a[x] > a[y]) {
			swap(a[x], a[y]);
			swap(ans[x], ans[y]);
			s[x] = y;
		}
	} else {	
		if (a[x] > a[y]) {
			r[x]++;
			s[y] = x;
		} else if (a[y] > a[x]) {
			r[y]++;
			s[x] = y;
		}
	}
}


int main()
{
	//ios_base::sync_with_stdio(false);
	int t, q, n, x, y, z;
	
	cin >> t;
	
	
	while (t--) {
		S(n);
		init(n+5);
		
		for (int i = 0; i < n; i++) S(a[i]);
		cin >> q;
		
		for (int i = 0; i < q; i++) {
			S(z);
			if (z == 1) {
				S(x);
				printf("%d\n", ans[findset(x-1)] + 1);
			} else {
				S(x);
				S(y);
				x--, y--;
				int xx = findset(x);
				int yy = findset(y);
				
				if (xx == yy) {
					cout << "Invalid query!" << endl;
				} else if (a[xx] == a[yy]) {
					continue;
				} else {
					Union(xx, yy);
				}		
			}
		}
	}
	return 0;
}


