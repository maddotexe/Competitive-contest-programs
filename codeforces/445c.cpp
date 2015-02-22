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

int v[501][501];

int main()
{
	ios_base::sync_with_stdio(false);
	int n, m, x, y, z;
	mem(v, -1);
	cin >> n >> m;
	int a[n];
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		x--, y--;
		v[x][y] = v[y][x] = z;
	}
	double ans = 0.0;
	int sum = 0, sum1 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (v[i][j] != -1) {
				double temp = ((double) a[i] + (double) a[j]) /  (double)v[i][j];
				
				if (temp > ans) {
					ans = temp;
					x = i;
					y = j;
					sum = a[i] + a[j];
					sum1 = v[x][y];
				} 
			}
		}
	}
	
	vector <int> v1, v2;
	v1.pb(x), v1.pb(y);
	
	for (int i = 0; i < n; i++) if (i != x && i != y) v2.pb(i);
	
	
	for (int i = 0; i < v2.size(); i++) {
		bool f = 0;
		int temp = sum, temp1 = sum1;
		for (int j = 0; j < v1.size(); j++) {
			if (v[v2[i]][v1[j]] != -1) {
				f = true;
				temp1 += v[v2[i]][v1[j]];
			}	
		}
		if (f) {
			temp += a[v2[i]];
		}
		
		if (ans < (double) temp / (double) temp1) {
			ans = (double) temp / (double) temp1;
			sum = temp;
			sum1 = temp1;
			v1.pb(v2[i]);
			v2.erase(v2.begin() + i);
			i = -1;
		}
		
	}
	printf("%.10lf\n", ans);
	return 0;
}


