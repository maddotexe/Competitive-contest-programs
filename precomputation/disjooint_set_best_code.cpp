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
#define SZ(A) ((int)A.size())
#define LEN(A) ((int)A.length())
#define MS(A) memset(A, 0, sizeof(A))
#define MSV(A,a) memset(A, a, sizeof(A))
#define MAX(a,b) ((a >= b) ? (a) : (b))
#define MIN(a,b) ((a >= b) ? (b) : (a))
#define ABS(a) (((a) > 0) ? (a) : (-a))
#define MP make_pair
#define X first
#define Y second
#define PB push_back
#define FOUND(A, x) (A.find(x) != A.end())
#define INF (int(1e9))
#define INFL (LL(1e18))
#define EPS 1e-12

#define chkbit(s, b) (s & (1<<b))
#define setbit(s, b) (s |= (1<<b))
#define clrbit(s, b) (s &= ~(1<<b))

#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REV(i, a, n) for(int i = a; i > n; i--)
#define FORALL(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)
#define ALL(A) A.begin(), A.end()
#define LLA(A) A.rbegin(), A.rend()
//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 1, 0, 0, -1, -1, -1}, dy[] = {1, 0, -1, 1, -1, 1, 0, -1};
#define ppl pair<ll,pll>
#define ppf pair<pll,ll>
#define psi pair<string,int>
#define pis pair<int,string>
#define fr first
#define se second


typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> II;
typedef vector<long long> VLL;
typedef vector<bool> VB;

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

const int MAXN = 100009;
int rank[MAXN], P[MAXN], sz[MAXN];

inline void makeSet(int &x) {
	P[x] = x;
	rank[x] = 1;
	sz[x] = 1;
}

inline void init(int n) {
	for(int i=0; i<=n; i++){
		makeSet(i);
	}
}

int findSet(int x) {
	if (x == P[x]) {
		return x;
	} else {
		return (P[x] = findSet(P[x]));
	}
}

void Union(int x, int y) {
	x = findSet(x);
	y = findSet(y);
	if (rank[x] > rank[y]) {
		P[y] = x;
		sz[x] += sz[y];
	} else {
		P[x] = y;
		sz[y] += sz[x];
		if (rank[x] == rank[y]) {
			rank[y] += 1;
		}
	}
}

struct Edge{
	int x, y, mini;
};

int c[MAXN];

bool comp(const Edge &a, const Edge &b){
	return a.mini > b.mini;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	init(n+5);
	REP(i, n) cin >> c[i];
	Edge edges[m];
	REP(i, m){
		int x, y;
		cin >> x >> y;
		x--, y--;
		edges[i].x = x;
		edges[i].y = y;
		edges[i].mini = min(c[x], c[y]);
	}
	sort(edges, edges+m, comp);
	LL sum = 0;
	REP(i, m){
		trace2(edges[i].x,edges[i].y)
		int x = edges[i].x;
		int y = edges[i].y;
		int p1 = findSet(x);
		int p2 = findSet(y);
		trace2(p1, p2);
		if(findSet(x) != findSet(y)){
			sum += LL(sz[p1]) * sz[p2] * edges[i].mini;
		//	trace3(sz[p1], sz[p2], sum);
			Union(x, y);
		}
	}
	printf("%.6lf\n", 2.0 * sum / LL(n) / (n-1));
	return 0;
}
