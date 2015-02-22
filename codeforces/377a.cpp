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

int n, m ,k;
char a[501][501];
int vis[501][501];

int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};

int ma, c, d;

bool check(int x, int y)
{
	if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y] == -1 || vis[x][y] == -2) return false;
	return true;
}

void bfs(int x, int y) 
{
	queue<pii> pq;
	pq.push(pii(x, y));
	ma = 0;
	c = x, d = y;
	
	while (!pq.empty()) {
		pii p = pq.front();
		pq.pop();
		vis[x][y] = 1;
		for (int i = 0; i < 4; i++) {
			if (vis[p.fr + dx[i]][p.se + dy[i]] == 0 && check(p.fr + dx[i], p.se + dy[i])) {
				vis[p.fr + dx[i]][p.se + dy[i]] = 1 + (vis[p.fr][p.se]);
				if (ma < vis[p.fr + dx[i]][p.se + dy[i]]) {
					ma = vis[p.fr + dx[i]][p.se + dy[i]];
					c = p.fr + dx[i], d = p.se + dy[i];
				}
				pq.push(pii(p.fr + dx[i], p.se + dy[i]));
			}
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> n >> m >> k;
	int x, y;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == '#') vis[i][j] = -1;
			else vis[i][j] = 0;
			if(a[i][j] == '.') {
				x = i, y = j;
			}
		}
	}
	
	bfs(x, y);
	priority_queue<pair <int, pii> > pq;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j] != 1) {
				pq.push(pair <int, pii> (vis[i][j], pii(i, j)));
			}
		}
	}
	
	while (k) {
		pair <int, pii> p = pq.top();
		pq.pop();
		vis[p.se.fr][p.se.se] = -2;
		k--;
		//cout << k << endl;
		//cout << p.se.fr << " " << p.se.se << endl;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j] == -1) cout << "#";
			if (vis[i][j] == -2) cout << "X";
			if (vis[i][j] >= 0) cout << ".";
		}
		cout << endl;
	}
	return 0;
}

