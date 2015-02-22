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
vector <pii> v, ans;
vector <int> vv, tv;
int main()
{
	ios_base::sync_with_stdio(false);
	int n, k, x, c = 0;
	bool f;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == 0) c++;
		v.pb(pii(x, i+1));
	}
	if (c != 1) {
		cout << -1 << endl;
		return 0;
	}
	sort(v.begin(), v.end());
	vv.pb(v[0].se);
	int i, kk = 2, g = 0;
	c = 0;
	for (i = 1; v[i].fr == 1; i++) {
		if (c == k) {
			cout << -1 << endl;
			return 0;
		}
		tv.pb(v[i].se);
		ans.pb(pii(vv[0], v[i].se));
		c++;
	}
	vv = tv;
	for (i; i < v.size(); i++) {
		c = 0, g = 0;
		f = false;
		tv.clear();
		while (v[i].fr == kk && i < v.size()) {
			if (c == k - 1 && g + 1 < vv.size()) {
				c = 0;
				g++;
			} else if (c == k - 1 && g + 1 == vv.size()) {
				cout << -1 << endl;
				return 0;
			}
			f = true;
			tv.pb(v[i].se);
			ans.pb(pii(vv[g], v[i].se));
			c++;
			i++;
		}
		if (!f) {
			cout << -1 << endl;
			return 0;
		}
		vv = tv;
		kk++;
		i--;
		
		
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].fr << " " << ans[i].se << endl;
	}
	return 0;
}


