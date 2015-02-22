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

int a[1000010];

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	ll x;
	cin >> n;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> x;
		a[x] = 1;
		sum += x - 1;
	}
	ll ans = 0;
	vector <ll> v;
	ll s = max(1000000LL - sum, 1LL);
	int j = 1000000;
	for (int i = 1; i < j; i++, j--) {
		if (a[i] == 1 && a[j] != 1) {
			sum -= 1000000 - j;
			ans++;
			v.pb(j);
			a[j] = 1;
		} else if (a[i] != 1 && a[j] == 1) {
			sum -= 1000000 - i;
			ans++;
			v.pb(i);
			a[i] = 1;
		}
	}
	if (sum != 0) {
		for (int i = 1, j = 1000000; i < j; i++, j--) {
			if (sum == 0) break;
			if (2000000 - i - j <= sum && !a[i] && !a[j]) {
				sum -= 2000000 - i - j;
				ans += 2;
				v.pb(i);
				v.pb(j);
			}
		}
	}
	cout << ans << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	return 0;
}


