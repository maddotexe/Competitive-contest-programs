#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <cstdlib>
#include <string>
#include <list>
#include <bitset>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <deque>
#include <climits>
#include <cassert>

using namespace std;

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
#define pll pair<ll,ll>
#define pps pair<ll,pll>
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
#define MAX 212345
#define mem(x,i) memset(x,i,sizeof(x))
#define fori(i,s,n) for(i=(s);i<(n);i++)
#define ford(i,s,n) for(i=(n);i>=(s);--i)
#define INF 8944674407370955161LL
#define debug(i,st,arr) fori(i,0,st){cout<<arr[i]<<" ";}cout<<endl;
#define forci(i,sw) for((i)=(sw).begin();(i)!=(sw).end();(i)++)
#define forcd(i,sw) for((i)=(sw).rbegin();(i)!=(sw).rend();(i)++)

int abs(int x) {if(x < 0) return -x; return x;}

const int N=1<<18,M=N<<1;

int n, m, k;

int a[N];
int bit[2][M];
int in[N], out[N];
vector<int> v[N];
int level[N];

int get(int x, int *p)
{
	int s = 0;
	while (x > 0) {
		s += p[x];
		x -= x & -x;
	}
	return s;
}

void update(int x, int val, int *p)
{
	while (x < M) {
		p[x] += val;
		x += x & -x;
	}
}

void dfs(int x, int d, int prev)
{
	in[x] = k++;
	
	level[x] = d;
	
	for (int i = 0; i < v[x].size(); i++) {
		if (v[x][i] != prev){
			dfs(v[x][i], 1-d, x);
		}
	}
	out[x] = k++;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int x, y;
	k = 1;
	cin >> n >> m;
	mem(bit, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	for (int i = 0; i < n - 1; i++) {
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1, 0, 0);
	for (int i = 0; i < m; i++) {
		cin >> y;
		if(y == 2) {
			cin >> x;
			cout << a[x] + get(in[x], bit[level[x]]) - get(in[x], bit[1-level[x]]) << endl;
			
		} else {
			cin >> x >> y;
			update(in[x], y, bit[level[x]]);
			update(out[x], -y, bit[level[x]]);
		}
		
	}
	
	return 0;
}

