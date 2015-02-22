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
#define INF 8944674407370955161LL
#define debug(i,st,arr) fori(i,0,st){cout<<arr[i]<<" ";}cout<<endl;
#define forci(i,sw) for((i)=(sw).begin();(i)!=(sw).end();(i)++)
#define forcd(i,sw) for((i)=(sw).rbegin();(i)!=(sw).rend();(i)++)

int abs(int x) {if(x < 0) return -x; return x;}

int a[100010];
int p[100010];
pii ans[500010];

int k = 0;

void solve(int x, int y)
{
	if (x == y) return;
	
	for (int i = y; i > x; i--) {
		if (p[i - x + 1] == 0) {
			swap(a[x], a[i]);
			ans[k].fr = x;
			ans[k++].se = i;
			solve(i, y);
			break;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i+1];
	p[0] = p[1] = 1;
	for (int i = 2; i * i <= 100001; i++) {
		if (p[i] == 0) {
			for (int j = i * i; j <= 100001; j += i) 
				p[j] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		while (i != a[i]) {
			solve(i, a[i]);
		}
	}
	cout << k << endl;
	for (int i = 0; i < k; i++) {
		cout << ans[i].fr << " " << ans[i].se << endl;
	}
	return 0;
}


