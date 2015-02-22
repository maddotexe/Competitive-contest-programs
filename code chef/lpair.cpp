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

ll bit[300001];
int n;
ll get(int pos)
{
	ll sum = 0;
	while (pos > 0) {
		sum += bit[pos];
		pos -= pos & -pos;
	}
	return sum;
}

void update (int pos, int val) {
	while (pos <= n) {
		bit[pos] += val;
		pos += pos & -pos;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	long long int ans = 0;
	
	cin >> n;
	
	int m[n], f[n];
	map<int, int> m1, m2;
	for (int i = 0; i < n; i++) {
		cin >> m[i] >> f[i];
		m1[m[i]] = f[i];
	}
	
	sort(m, m + n);
	sort(f, f + n);
	for (int i = 0; i < n; i++) {
		m2[f[i]] = i + 1;
	}
	ans = 0;
	for (int i = 0; i < n; i++) {
		int x = m1[m[i]];
		x = m2[x];
		ans += get(x);
		update(1, 1);
		update(x + 1, -1);
	}
	cout << ans << endl;
	
	return 0;
}

