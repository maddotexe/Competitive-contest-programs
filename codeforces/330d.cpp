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
#define ppi pair<int, pii>
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

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};
char a[1001][1001];
int vis[1001][1001];
queue<pii> pq;
int n, m, s, e, se, ee;

bool check(int x, int y){
	if (x < 0 || y < 0 || x >= n || y >= m || vis[x][y] || a[x][y] == 'T') return false;
	return true;
} 

int main()
{
	ios_base::sync_with_stdio(false);
	int x, y;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'S') {
				s = i;
				e = j;
			}
			if (a[i][j] == 'E') {
				se = i;
				ee = j;
			}
		}
	} 
	
	pq.push(pii(se, ee));
	
	while (!pq.empty()) {
		pii p = pq.front();
		pq.pop();
		
		for (int i = 0; i < 4; i++) {
			x = p.fr + dx[i];
			y = p.se + dy[i];
			
			if (check(x, y)) {
				vis[x][y] = vis[p.fr][p.se] + 1;
				pq.push(pii(x, y));
			}
		}	
	}
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == s && j == e || !vis[i][j]) continue;
			if(vis[i][j] <= vis[s][e] && a[i][j] > '0' && a[i][j] <= '9') {
				ans += a[i][j] - '0';
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}


