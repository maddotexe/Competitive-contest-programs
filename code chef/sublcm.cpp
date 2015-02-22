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

vector <int> v[1000010];
int p[1000010], a[1000010];;
int ans[1000010];

void sieve()
{
	v[1].pb(1);
	
	for (int i = 2; i < 1000010; i++) {
		if (!p[i]) {
			for (int j = i; j < 1000010; j += i) {
				p[j] = 1;
				v[j].pb(i);
			}
		}
	}

}

int main()
{
	sieve();
	ios_base::sync_with_stdio(false);
	int n, t;
	cin >> t;
	
	while (t--) {
		cin >> n;
		mem(ans, 0);
		int last = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		if (n == 1) {
			cout << -1 << endl;
			continue;
		}
		for (int i = 0; i < v[a[0]].size(); i++) {
			ans[v[a[0]][i]] = 1;
		}
		int res = 1, temp = 1;
		for (int i = 1; i < n; i++) {
			if(a[i] == 1) {
				temp++;
				continue;
			}
			bool f = 0;
			for (int j = 0; j < v[a[i]].size(); j++) {
				if (ans[v[a[i]][j]]) {
					f = true;
					break;
				}
			}
			
			if (!f) {
				for (int j = 0; j < v[a[i]].size(); j++) {
					ans[v[a[i]][j]] = 1;
				}
				temp++;
			} else {
				f = 1;
				while (f) {
					temp--;
					for (int j = 0; j < v[a[last]].size(); j++) {
						ans[v[a[last]][j]] = 0;
					}
					bool k = 0;
					last++;
					for (int j = 0; j < v[a[i]].size(); j++) {
						if (ans[v[a[i]][j]]) {
							k = 1;
							break;
						}
					}
					
					if (k == 0) {
						f = 0;
						for (int j = 0; j < v[a[i]].size(); j++) {
							ans[v[a[i]][j]] = 1;
						}
					}
				}
				temp++;
			}
			res = max(temp, res);
		}
		if (res != 1)
			cout << res << endl;
		else 
			cout << -1 << endl;
	}
	return 0;	
}


