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

ll dp[1<<18][101];
ll a[20];
int k;
ll n, m;

ll solve(ll mask, ll mod) 
{
	if (mask == 0) {
		if (mod == 0) return 1;
		else return 0;
	}
	if (dp[mask][mod] != -1) return dp[mask][mod];
	ll pre = -1, ans = 0;
	for (int i = 0; i < k; i++) {
		if (!(mask & (1<<i))) continue;
		if (__builtin_popcount(mask) == k && a[i] == 0) continue;
		else {
			if (a[i] != pre) {
				ans += solve(mask ^ (1 << i) , (mod * 10 + a[i]) % m);
				pre = a[i];
			}
		}
	}
	return dp[mask][mod] = ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> n >> m;
	k = 0;
	while (n != 0) {
		a[k++] = n % 10;
		n /= 10;
	}
	sort(a, a + k);
	mem(dp, -1);
	cout << solve((1 << k) - 1, 0) << endl;
	return 0;
}


