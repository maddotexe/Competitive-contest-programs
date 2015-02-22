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
#define mem(x,i) memset(x,i,sizeof(x))
#define fori(i,s,n) for(i=(s);i<(n);i++)
#define ford(i,s,n) for(i=(n);i>=(s);--i)
#define INF 8944674407370955161LL
#define debug(i,st,arr) fori(i,0,st){cout<<arr[i]<<" ";}cout<<endl;
#define forci(i,sw) for((i)=(sw).begin();(i)!=(sw).end();(i)++)
#define forcd(i,sw) for((i)=(sw).rbegin();(i)!=(sw).rend();(i)++)

int abs(int x) {if(x < 0) return -x; return x;}

int vis[2001];
vector <int> v[2001];
vector <int> v1[2001];
stack <int> s;

void dfs(int x) 
{
	vis[x] = 1;
	for (int i = 0; i < v[x].size(); i++) {
		if (!vis[v[x][i]]) {
			dfs(v[x][i]);
		}
	}
	s.push(x);
}

void dfs1 (int x) 
{
	vis[x] = 1;
	for (int i = 0; i < v1[x].size(); i++) {
		if (!vis[v1[x][i]]) {
			dfs1(v1[x][i]);
		}
	}
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> x;
			if (x) {
				v[i].pb(j);
				v1[j].pb(i);
			}
		}
	}
	mem(vis, 0);
	for (int i = 0; i < n; i++) {
		if (!vis[n - i - 1]) {
			dfs(n - i - 1);
		}
	}
	
	mem(vis, 0);
	int ans = 0;
	while (!s.empty()) {
		x = s.top();
		s.pop();
		
		if (!vis[x]) {
			dfs1(x);
			ans++;
		}
	}
	
	if (ans == 1) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
	return 0;
}


