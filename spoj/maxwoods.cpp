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

int main()
{
	int n, m, t;
	char b[501][501];
	int a[501][501];
	int c[501];
	cin >> t;
	
	while (t--) {
		cin >> n >> m;
		
		memset (a, 0, sizeof(a));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> b[i][j];
			}
		}
		if (b[0][0] == '#') {
			cout << 0 << endl;
			continue;
		} else if (b[0][0] == 'T') {
			a[0][0] = 1;
		} else {
			a[0][0] = 0;
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i == 0 && j == 0) continue;
				if (!(i & 1)) {
					if (i == 0) {
						if (b[i][j-1] == '#' || b[i][j] == '#') {
							a[i][j] = -9999999;
						} else if (b[i][j] == 'T') {
							a[i][j] = a[i][j-1] + 1;
						} else {
							a[i][j] = a[i][j-1];
						}
					} else if (j == 0) {
						if (b[i-1][j] == '#' || b[i][j] == '#') {
							a[i][j] = -9999999;
						} else if (b[i][j] == 'T') {
							a[i][j] = a[i-1][j] + 1;
						} else {
							a[i][j] = a[i-1][j];
						}
					} else {
						if (b[i][j] == '#' || (b[i-1][j] == '#' && b[i][j-1] == '#')) {
							a[i][j] = -9999999;
						} else if (b[i][j] == 'T') {
							a[i][j] = max(a[i-1][j], a[i][j-1]) + 1;
						} else {
							a[i][j] = max(a[i-1][j], a[i][j-1]);
						}
					}
				} else {
					if (m - j == m) {
						if (b[i][m-j-1] == '#' || b[i-1][m-j-1] == '#') {
							a[i][m-j-1] = -9999999;
						} else if (b[i][m-j-1] == 'T') {
							a[i][m-j-1] = a[i-1][m-j-1] + 1;
						} else {
							a[i][m-j-1] = a[i-1][m-j-1];
						}
					} else {
						if (b[i][m-j-1] == '#' || (b[i-1][m-j-1] == '#' && b[i][m-j] == '#')) {
							a[i][m-j-1] = -9999999;
						} else if (b[i][m-j-1] == 'T') {
							a[i][m-j-1] = max(a[i-1][m-j-1], a[i][m-j]) + 1;
						} else {
							a[i][m-j-1] = max(a[i-1][m-j-1], a[i][m-j]);
						}
					}
				}
			}
		}
		
		int max = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (max < a[i][j]) max = a[i][j];
				//cout << a[i][j] << " ";
			} //cout << endl;
		}
		cout << max << endl;
	}
	
	return 0;
}

