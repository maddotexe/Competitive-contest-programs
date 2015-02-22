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
#define ln length()
#define MP(x,y) make_pair(x,y)
#define eps 1e-7
#define vi(x) vector<x>
#define pb(x) push_back(x)
#define mem(x,i) memset(x,i,sizeof(x))
#define fori(i,s,n) for(i=(s);i<(n);i++)
#define ford(i,s,n) for(i=(n);i>=(s);--i)
#define debug(i,st,arr) fori(i,0,st){cout<<arr[i]<<" ";}cout<<endl;
#define forci(i,sw) for((i)=(sw).begin();(i)!=(sw).end();(i)++)
#define forcd(i,sw) for((i)=(sw).rbegin();(i)!=(sw).rend();(i)++)
#define imax numeric_limits<int>::max()
#define imin numeric_limits<int>::min()
#define lmax numeric_limits<ll>::max()
#define lmin numeric_limits<ll>::min()
#define MOD 1000000007
#define INF 8944674407370955161LL

template <typename T>
T abs(T x) {if(x < 0) return -x; return x;}
template <typename T>
T gcd(T a,T b){return b?gcd(b,a%b):a;}

int vis[210];
int v[210][210];
int a[110];
int n;
void dfs(int count, int k, int pos) {
	//cout << pos << " ";
	vis[pos] = 1;
	for (int i = pos+1; i < n; i++){
		if (vis[i] == 0 && v[pos][i] == 1) {
			dfs(count+1, k, i);
			//cout << count << endl;
			//cout << count << " ";
			if ((count+1) > a[k]) a[k] = (count+1);
			
			
		}
		
	}
}

int main()
{
	
	int x, y;
	cin >> n;
	int c[210];
	mem(c, 0);
	int x1[210], y1[210];
	for (int i = 0; i < n-1; i++) {
		cin >> x >> y;
		x--;
		y--;
		x1[i] = x;
		y1[i] = y;
		c[x]++;
		c[y]++;
		v[x][y] = v[y][x] = 1;
	}
	int k = 1, ans = 0;
	for (int i = 0; i < n - 1; i++) {
		if (c[i] == n - 1) {
			cout << 0 << endl;
			return 0;
		}
	}
	for (int j = 0; j < n - 1; j++) {
		mem(vis, 0);
		k = 1;
		v[x1[j]][y1[j]] = 0;
		v[y1[j]][x1[j]] = 0;
		mem(a, 0);
		for (int i = 0; i < n; i++) {
			if (vis[i] == 0) {
				dfs(0, k, i);
				cout << endl;
				k++;
			}
		}
		v[x1[j]][y1[j]] = 1;
		v[y1[j]][x1[j]] = 1;
		if (k > 2) {
			sort(a, a+k);
			for (int ii = 1; ii < k; ii++) {
				cout << a[ii] << " ";
			}
			cout << endl;
			ans = max (ans , a[k-1] * a[k-2]);
		}
	}
	cout << ans << endl;
        return 0;
}

