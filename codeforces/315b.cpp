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

int n, m;
int bit[100010];

void update (int x, int y)
{
	while (x <= n) {
		bit[x] += y;
		x += (x & -x);
	} 
}

int get(int x) {
	int sum = 0;
	while (x > 0) {
		sum += bit[x];
		x -= (x & -x);
	}
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int x, y;
	cin >> n >> m;
	
	int ad = 0;
	
	for (int i = 1; i <= n; i++) {
		cin >> x;
		update(i, x);
		update(i + 1, -x);	
	}
	
	for (int i = 0; i < m; i++) {
		cin >> x;
		if (x == 1) {
			cin >> x >> y;
			int z = get(x);
			update(x, y-z);
			update(x + 1, z-y);
		} else if (x == 2) {
			cin >> x;
			update(1, x);
		} else {
			cin >> x;
			cout << get(x) << endl;
		}
	}
	return 0;
}


