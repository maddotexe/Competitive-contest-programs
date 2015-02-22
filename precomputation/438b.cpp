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

int rank[100010], tot[100010], s[100010];
int a[100010];
ll sum = 0;

struct node {
	int x, y, m;
};

node tree[100010];

int findset(int x) {
	if (x == s[x]) return x;
	else return (s[x] = findset(s[x]));
}

void uunion (int x, int y)
{
	x = findset(x);
	y = findset(y);
	if(rank[x] > rank[y]) {
		s[y] = x;
		tot[x] += tot[y];
	} else {
		s[x] = y;
		tot[y] += tot[x];
		if(rank[x] == rank[y]) {
			rank[y]++;
		}
	}
}

bool comp(const node &p, const node &q)
{
	return p.m > q.m;
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	int n, m, x, y;
	cin >> n >> m;
	
	for (int i = 0; i <= n; i++) {
		rank[i] = tot[i] = 1;
		s[i] = i;
	}
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		x--, y--;
		tree[i].x = x;
		tree[i].y = y;
		tree[i].m = min(a[x], a[y]);
	}
	
	
	sort(tree, tree + m, comp);
	
	for (int i = 0; i < m; i++) {
		int x = findset(tree[i].x);
		int y = findset(tree[i].y);
		
		//trace2(p[i].se.fr, p[i].se.se);
		if (x != y) {
			sum += (ll)tot[x] * (ll)tot[y] * (ll)tree[i].m;
			//trace3(tot[x], tot[y],sum);
			uunion(tree[i].x, tree[i].y);
		}
	}
	printf("%.6lf\n", sum * 2.0 / (ll)((ll)n * (ll)(n - 1))); 
	return 0;
}


