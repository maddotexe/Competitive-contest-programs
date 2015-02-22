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

int a[100010];
int main()
{
	
	a[0] = 0;
	for (ll i = 1; i < 100001; i++) {
		ll k = (i * i);
		bool f = false;
		while (k != 0) {
			int g = k % 10;
			if (g != 0 && g != 1 && g != 4 && g != 9) {
				f = true;
				break;
			}
			k /= 10;
		}
		if (!f) {
			a[i] = a[i-1] + 1;
		} else {
			a[i] = a[i-1];
		}
		
	}
	//for (int i = 0; i < 100; i++) cout << a[i] << endl;
	int t, g, g1;
	ll a1, b;
	cin >> t;
	while (t--) {
		cin >> a1 >> b;
		ll sq = (ll)(sqrt(a1));
		if (sq * sq == a1) {
			g = int(sq - 1);
		} else {
			g = int(sq);
		}
		
		sq = (ll)(sqrt(b));
		if (sq * sq == b) {
			g1 = int(sq);
		} else {
			g1 = int(sq);
		}
		
		cout << a[g1] - a[g] << endl;
	}
	return 0;
}

