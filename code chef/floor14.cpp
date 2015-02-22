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
#define forci(i,sw) for((i)=(sw).begin();(i)!=(sw).end();(i)++)
#define forcd(i,sw) for((i)=(sw).rbegin();(i)!=(sw).rend();(i)++)
#define INF 8944674407370955161LL
#define all(a)  a.begin(),a.end()

int abs(int x) {if(x < 0) return -x; return x;}

int a[200005], bit[200005], mapx[200005], mapy[200005], z[200005];
int n, m, ans;
vector<int> v, s[200005], l[200005], c[200005];

void update(int pos, int val) 
{
	while (pos < 200004) {
		bit[pos] += val;
		pos += (pos&-pos);
	}
}

int gget(int pos) {
	int sum = 0;
	while (pos > 0) {
		ans += bit[pos];
		pos -= (pos&-pos);
	}
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		v.pb(a[i]);
	}
	sort(v.begin(), v.end());
	
	map<int, int> mm;
	int tmp = 0;
	
	for (int i = 0; i < n; i++) {
		if (!mm[v[i]]) mm[v[i]] = ++tmp;
	}
	for (int i = 0; i < n; i++) {
		c[i].pb(mm[a[i]]);
		a[i] = mm[a[i]];
	}
	
	mm.clear();
	for (int i = 0; i < m; i++) {
		cin >> mapx[i] >> mapy[i];
		mapx[i]--, mapy[i]--;
		c[mapx[i]].pb(a[mapy[i]]);
		c[mapy[i]].pb(a[mapx[i]]);
	}
	ll ans = 0;
	//for (int i = 0; i < n; i++) cout << a[i] << endl;
	for (int i = 0; i < n; i++) {
		if (c[i].size()) cout << "index = " << i << endl;
		for (int j = 0; j < c[i].size(); j++) {
			cout << c[i][j] <<  " ";
			int pp = gget(c[i][j]);
			s[i].pb(pp);
			trace1(pp);
			l[i].pb(i - mm[c[i][j]] - s[i][j]);
			//trace5(pp, i, mm[c[i][j]], s[i].back(), l[i].back());
		}
		//cout << endl;
		mm[a[i]]++;
		ans += l[i][0];
		//trace1(l[i][0]);
		update(a[i] + 1, 1);
		
		//trace3(a[i], mm[a[i]], bit[i]);
	}
	for (int i = 0; i < n; i++) cout << bit[i] << endl;;
	
	trace1(ans);
	for (int i = 0; i < m; i++) {
		ll ans1, ans2;
		if (a[mapx[i]] == a[mapy[i]]) {
			cout << ans << endl;
		} else {
			int x, y;
			x = z[mapx[i]];
			y = z[mapy[i]];
			x = l[mapy[i]][y] - l[mapx[i]][0];
			y = l[mapx[i]][x] - l[mapy[i]][0];
			x += s[mapy[i]][0] - s[mapx[i]][x];
			y -= s[mapy[i]][y] - s[mapx[i]][0];
			cout << ans + x + y << endl;
		}
		z[mapx[i]]++;
		z[mapy[i]]++;
	}
	return 0;
}


