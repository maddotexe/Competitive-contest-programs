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

char a[8][8];
int dx[] = {2, 2, -2, -2};
int dy[] = {-2, 2, 2, -2};
bool vis[8][8];
bool check(int x, int y) {
	if (x < 0 || x >= 8 || y < 0 || y >= 8) return false;
	return true;
}
bool f;

void solve(int x, int y, int x1, int y1) 
{
	//cout << x << " " << y << endl;
	vis[x][y] = true;
	for (int i = 0; i < 4; i++) {
		
		if(check(x + dx[i], y + dy[i]) && !vis[x+dx[i]][y+dy[i]]) {
			
			solve(x + dx[i], y + dy[i], x1, y1);
			for (int j = 0; j < 4; j++) {
				
				if (check(x1+dx[j], y1+dy[j])) {
					solve(x, y, x1+dx[j], y1+dy[j]);
					if (x == (x1 + dx[j]) && y == y1 + dy[j] && a[x][y] != '#') {
						f = true;
						return;
					}
				}
			}
		}
		if (f) return;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		memset(vis, 0, sizeof(vis));
		f = false;
		int b[2][2], h = 0;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> a[i][j];
				if (a[i][j] == 'K') {
					b[h][0] = i, b[h++][1] = j;	
				}
			}
		}
		//cout << b[0][0]<< b[0][1]<< b[1][0]<< b[1][1] << endl;
		solve(b[0][0], b[0][1], b[1][0], b[1][1]);
		if (f) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}	
	return 0;
}

