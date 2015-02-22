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

vector <pll> v[100010];
int vis[100010];
ll n, m, k;
set <pll> s;
set<pll> ::iterator it;
ll dis[100010]; 
ll train[100010];
map<ll, vector<ll> > mm;
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;
	mm.clear();
	ll x, y, z, yy, c;
	for (int i = 0; i <= n; i++) dis[i+1] = INF;;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		v[x].pb(pll(y, z));
		v[y].pb(pll(x, z));
	}
	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		mm[x].pb(y);
		//dis[x] = min(dis[x], y);
	}
	
	//cout << mm.size();
	//vis[1] = 1;
	dis[1] = 0;
	s.insert(pll(0LL, 1LL));
	while (!s.empty()) {
		pll p = *s.begin();
		s.erase(s.begin());
		x = p.fr;
		y = p.se;
	//	trace1(y);
		//cout << y << endl;
		
		for (int i = 0; i < v[y].size(); i++) {
			ll yy = v[y][i].fr;
	//		trace1(yy);
			ll c = v[y][i].se;
			if (dis[yy] > dis[y] + c) {
				if (dis[yy] != INF) {
					s.erase(s.find(pll(dis[yy], yy)));
				}
			
				dis[yy] = dis[y] + c;
				s.insert(pll(dis[yy], yy));
			}
		}
	
	}
	int ans = 0;
	//for (int i = 0; i < n; i++) cout << dis[i+1] << endl;
	//cout << mm.size();
	for (map<ll, vector <ll> >::iterator it = mm.begin(); it != mm.end(); it++) {
		sort(it->se.begin(), it->se.end());
		
		for (int i = 0; i < it->se.size(); i++) {
			if (dis[it->fr] > it->se[i]) dis[it->fr] = it->se[i];
			else if (dis[it->fr] <= it->se[i]) ans++;
		//	cout << it->se[i] << endl;
		}
		//cout << dis[it->fr] << endl;
	}
	
	cout << ans << endl;
	return 0;
}


