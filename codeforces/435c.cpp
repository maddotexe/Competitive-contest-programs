#include<bits/stdc++.h>

using namespace std;

//#define TRACE

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

char a[2000][2000];

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int aa[n];
	for (int i = 0; i < 2000; i++) {
		for (int j = 0; j < 2000; j++) a[i][j] = ' ';
	}
	for (int i = 0; i < n; i++) {
		cin >> aa[i];
	}
	
	bool f = true;
	int x = 1000;
	int y = 0;
	int mxu = 1000;
	int mxd = 1000;
	int my = 0;
	for (int i = 0; i < n; i++) {
		if (f) {
			y++;
			for (int j = 0; j < aa[i]; j++) {
				trace2(x, y);
				a[x][y] = '/';
				if (j != aa[i] - 1) {
					x--;
					y++;
				}
				
			}
	
			trace3(mxu, mxd, my);
			mxu = min(mxu, x);
			my = max(my, y);
		} else {
			y++;
			for (int j = 0; j < aa[i]; j++) {
				trace2(x, y);
				a[x][y] = 'a';
				if (j != aa[i] - 1) {
					x++;
					y++;
				}
			}
			trace3(mxu, mxd, my);
			mxd = max(mxd, x);
			my = max(my, y);
		}
		
		f = !f;
	}
	trace3(mxu, mxd, my);
	for (int i = mxu; i <= mxd; i++) {
		for (int j = 1; j <= my; j++) {
			if (a[i][j] == 'a') cout << "\\";
			else cout << a[i][j];
			
		}
		cout << endl;
	}
	return 0;
}


